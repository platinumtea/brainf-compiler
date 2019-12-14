#include "BrainFInterpreter.h"
#include <iostream>


BrainFInterpreter::BrainFInterpreter(const char instructions[]) {
	d = data;
	int brackets = 0;
	for (int x = 0; x < std::strlen(instructions); x++) {
		if (instructions[x] == '[') {
			brackets++;
		} else if (instructions[x] == ']') {
			brackets--;
		}
	}
	if (!brackets) {
		i = instructions;
	} else {
		i = "a\0";
	}
}

void BrainFInterpreter::dIncr() {
	d++;
}

void BrainFInterpreter::dDcr() {
	d--;
}

void BrainFInterpreter::dValueIncr() {
	(*d)++;
}

void BrainFInterpreter::dValueDcr() {
	(*d)--;
}

void BrainFInterpreter::output() {
	putchar(*d);
}

void BrainFInterpreter::input() {
	*d = getchar();
}

void BrainFInterpreter::brOpen() {
	int layer = 1;
	if (*d == '\0') {
		while (layer != 0) {
			i++;
			if (*i == '[') {
				layer++;
			} else if (*i == ']') {
				layer--;
			}
		}
	}
}

void BrainFInterpreter::brClose() {
	int layer = 1;
	if (*d != '\0') {
		while (layer != 0) {
			i--;
			if (*i == ']') {
				layer++;
			} else if (*i == '[') {
				layer--;
			}
		}
	}
}

void BrainFInterpreter::interpret() {
	while (*i) {
		switch (*i) {
			case '>':
				dIncr();
				break;
			case '<':
				dDcr();
				break;
			case '+':
				dValueIncr();
				break;
			case '-':
				dValueDcr();
				break;
			case '.':
				output();
				break;
			case ',':
				input();
				break;
			case '[':
				brOpen();
				break;
			case ']':
				brClose();
				break;
		}
		i++;
	}
}
