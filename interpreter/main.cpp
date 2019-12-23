#include <iostream>
#include <fstream>
#include <string>
#include "BrainFInterpreter.h"

int main(int argc, char **argv) {
	std::ifstream program("program.txt");
	
	if (program.is_open()) {
		std::string programString, buffer;

		while (std::getline(program, buffer)) {
			programString += buffer;
		}

		BrainFInterpreter interpreter(programString.c_str());
		interpreter.interpret();
		
		program.close();
	} else {
		std::cout << "Cannot open file";
	}

	return 0;
}
