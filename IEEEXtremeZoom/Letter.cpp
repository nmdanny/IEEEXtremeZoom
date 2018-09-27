#include "Letter.h"

#include <iostream>

// Macro so that we don't print debug stuff/instructions while running through hackerrank


int main(int argc, char **argv) {
	LettersAlg alg;
	std::cin >> alg;

	std::cout << "Type the number of lines to zoom:" << std::endl;
	int inputLines;
	std::cin >> inputLines;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Will be reading " << inputLines << " lines." << std::endl;
	for (auto i = 0; i < inputLines; i++) {

		std::cout << "Type the string to zoom: ";
		std::string stringToZoom;
		std::getline(std::cin, stringToZoom);
		std::cout << alg.zoomed_string(stringToZoom) << std::endl;
	}
	std::cout << "Done." << std::endl;
	return 0;
}