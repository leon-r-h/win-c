#include "win-c/windows/user32.h"

void output(unsigned short* string) {
	MessageBoxW(nullptr, string, u"Ausgabe", 0);
}

int main(int argc, char** argv) {
	int i = 0;
	while(argv[i] != nullptr) {
		MessageBoxA(nullptr, argv[i], "", 0);
		
		i++;
	}

	return 0;
}
