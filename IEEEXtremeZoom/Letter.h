#pragma once

#include "Util.h"
#include <vector>
#include <iostream>
#include <string>

class Letter
{
public:
	char character;
	int rows;
	int columns;
	std::vector<char> zoomed;
	
	Letter() {}

	Letter(int rows, int columns) {
		this->zoomed = std::vector<char>(rows * columns);
		this->rows = rows;
		this->columns = columns;
	}

	char& index(int row, int col) {
		return zoomed[row * columns + col];
	}

};

std::istream& operator>>(std::istream& is, Letter& letter) {
	//std::cout << "Type a character" << std::endl;
	std::string blank;
	is >> letter.character >> Util::ignore_newline;
	//std::cout << "Type the zoomed representation of " << letter.character <<  std::endl;
	for (auto rowIx = 0; rowIx < letter.rows; rowIx++) {
		std::string currentLine;
		std::getline(is, currentLine);
		std::copy(currentLine.cbegin(), currentLine.cend(), letter.zoomed.begin() + rowIx * letter.columns);
	}
	//std::cout << "Got the following letter: " << letter;
	return is;
}
