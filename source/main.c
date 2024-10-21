#include "win-c/windows/user32.h"

void output(unsigned short* string) {
	MessageBoxW(nullptr, string, u"Ausgabe", 0);
}

int main(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		MessageBoxA(nullptr, argv[i], "Ausgabe", 0);
	}

	return 0;
}
