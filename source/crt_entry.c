#include "win-c/crt_entry.h"

#include <stdlib.h>

#include "win-c/windows/kernel32.h"
#include "win-c/windows/shell32.h"

// TODO: More C like types

// Weak declaration of main, allowing arguments to be overridden.
extern int main(int argc, char **argv) __attribute__((weak));

// Called just before "main"
extern int __main(void) {
	return 0;
}

static int win_c_main(void) {
	// Decode command-line arguments
	int argc = -1;
	unsigned short **argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	if (argc <= 0 || argv == nullptr) {
		// Failed to decode arguments
		return EXIT_FAILURE;
	}

	// Call the main function. You can pass the decoded argc and argv as
	// needed.
	int return_code = main(0, nullptr);

	// n2347 5.1.2.2.3 - End the process with the return code from main.
	ExitProcess((unsigned int)return_code);

	// This return is technically unnecessary as ExitProcess never returns.
	return return_code;
}

extern int mainCRTStartup(void) {
	return win_c_main();
}
