#include "win-c/crt_entry.h"
#include "win-c/windows/kernel32.h"
#include "win-c/windows/shell32.h"

#include <stdlib.h>

// Weak declaration of main, allowing arguments to be overridden.
extern int main(int argc, char** argv) __attribute__((weak));

// Called just before "main"
extern int __main(void) {
	return 0;
}

static int win_c_main(void) {
	int argc = -1;
	unsigned short** wide_arguments = CommandLineToArgvW(GetCommandLineW(), &argc);
	if (argc <= 0 || wide_arguments == NULL) {
		// Failed to decode arguments
		return EXIT_FAILURE;
	}

	// Allocate argv buffer
	char** argv = LocalAlloc(0, ((unsigned)argc + 1) * sizeof(char*));
	argv[argc] = NULL;	// n2347 5.1.2.2.1

	for (int i = 0; i < argc; i++) {
		unsigned short* wide_argument = wide_arguments[i];
		// Get length of string
		int length = lstrlenW(wide_argument);
		int size = WideCharToMultiByte(WIN_C_KERNEL32_CP_UTF8, 0, wide_argument, length, NULL, 0, NULL, NULL);
		// Make sure, that buffer allocation wont fail
		if (size < 0) { size = 0; }

		// Convert wide string, ignore if argv invalid	
		char* buffer = LocalAlloc(0, (unsigned)size + 1);
		buffer[size] = '\0';
		WideCharToMultiByte(WIN_C_KERNEL32_CP_UTF8, 0, wide_argument, length, buffer, size, NULL, NULL);

		// Assign argv
		argv[i] = buffer;
	}

	LocalFree(wide_arguments);

	// Call the main function. You can pass the decoded argc and argv as
	// needed.
	int return_code = main(argc, argv);

	// Free argv
	for (int i = 0; i < argc; i++) {
		LocalFree(argv[i]);
	}
	LocalFree(argv);

	return return_code;
}

#include "win-c/windows/user32.h"  // TODO: REMOVE

extern int mainCRTStartup(void) {
	int return_code = win_c_main();

	MessageBoxA(nullptr, "No segfault!", "Success", 0);

	// n2347 5.1.2.2.3
	ExitProcess((unsigned int)return_code);

	return return_code;
}
