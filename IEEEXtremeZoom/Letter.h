#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>


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

std::ostream& operator<<(std::ostream& os, Letter& letter) {
	os << "Letter '" << letter.character << "'" << std::endl;
	for (auto rowIx = 0; rowIx < letter.rows; rowIx++) {
		auto lineStart = letter.zoomed.cbegin() + rowIx * letter.columns;
		auto lineEnd = lineStart + letter.columns;
		std::string line(lineStart, lineEnd);
		os << line << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Letter& letter) {
	std::cout << "Type a character" << std::endl;
	std::string blank;
	is >> letter.character;
	std::getline(is, blank);
	std::cout << "Type the zoomed representation of " << letter.character <<  std::endl;
	for (auto rowIx = 0; rowIx < letter.rows; rowIx++) {
		std::string currentLine;
		std::getline(is, currentLine);
		assert(currentLine.size() == letter.columns);
		std::copy(currentLine.cbegin(), currentLine.cend(), letter.zoomed.begin() + rowIx * letter.columns);
	}
	std::cout << "Got the following letter: " << letter;

	return is;
}

class LettersAlg
{
public:
	int rows, columns, translated_characters;
	std::unordered_map<char, Letter> letters;

	std::string zoomed_string(std::string& string) {
		// The output string would have the following dimensions(not including newlines)
		auto output_cols = columns * string.size();
		auto output_rows = rows;

		std::stringstream outs;
		// We shall build the output string line by line, column by column, like filling a 2D matrix
		for (auto rowIx = 0; rowIx < output_rows; rowIx++) {
			for (auto colIx = 0; colIx < output_cols; colIx++) {
				// determine to which letter the current outputted character belongs
				auto letterIx = colIx / columns;
				auto letter = letters[string[letterIx]];

				// map the column index of our output string, to a column index of the letter's matrix
				auto letterColIx = colIx % columns;

				outs << letter.index(rowIx, letterColIx);
			}
			// to ensure we don't have a trailing newline at the end of the string
			if (rowIx < output_rows - 1) {
				outs << std::endl;
			}
		}
		return outs.str();
	}
};

std::istream& operator>>(std::istream& is, LettersAlg& alg) {
	std::cout << "Type the columns, rows and number of translated characters" << std::endl;
	is >> alg.columns;
	is >> alg.rows;
	is >> alg.translated_characters;
	std::cout << alg.columns << " columns, " << alg.rows << " rows, " << alg.translated_characters << " characters." << std::endl;
	for (auto i = 0; i < alg.translated_characters; i++) {
		Letter letter(alg.rows, alg.columns);
		is >> letter;
		alg.letters[letter.character] = letter;
	}
	return is;
}


std::istream& read_blank_line(std::istream& is) {
	std::string blank;
	is >> blank;
	return is;
}