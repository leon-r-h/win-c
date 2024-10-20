#include "win-c/crt_entry.h"

#include "win-c/windows/kernel32.h"
#include "win-c/windows/shell32.h"

#include <stdlib.h>

#include "win-c/windows/user32.h" // TODO: Remove



/* The actual main entry point, defined as weak, so the arguments can be overriden. */
extern int main(int argc, char** argv) __attribute__((weak));


/* Called just before "main" */
extern int __main() {
	MessageBoxA(nullptr, "__main", "Trace", 0);

	return 0;
}

// TODO: uchar.h

static inline int win_c_main() {
	MessageBoxA(nullptr, "win_c_main", "Trace", 0);

	int return_code = main(0, nullptr);

	return return_code;
}


/* The main C start point */
extern int mainCRTStartup() {
	MessageBoxA(nullptr, "mainCRTStartup", "Trace", 0);

	int return_code = win_c_main();

	// n2347 5.1.2.2.3
	ExitProcess((unsigned int) return_code);

	return return_code;
}
