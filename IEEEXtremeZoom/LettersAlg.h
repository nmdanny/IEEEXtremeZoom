#pragma once

#include "Letter.h"
#include <unordered_map>
#include <sstream>

class LettersAlg
{
public:
	int rows, columns;
	std::unordered_map<char, Letter> letters;

	std::string zoomed_string(std::string& string) {
		// The output string would have the following dimensions(not including newlines)
		auto output_cols = columns * string.size();
		auto output_rows = rows;

		if (Util::is_empty(string)) {
			return std::string('\n', output_rows);
		}

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

	std::string run(std::istream& in) {
		//std::cout << "Type the number of lines to zoom:" << std::endl;
		int inputLines;
		in >> inputLines >> Util::ignore_newline;
		//std::cout << "Will be reading " << inputLines << " lines." << std::endl;
		std::stringstream out;
		for (auto i = 0; i < inputLines; i++) {

			//std::cout << "Type the string to zoom: ";
			std::string stringToZoom;
			std::getline(in, stringToZoom);
			out << zoomed_string(stringToZoom) << std::endl;
		}
		return out.str();
	}
};


std::istream& operator>>(std::istream& is, LettersAlg& alg) {
	//std::cout << "Type the columns, rows and number of translated characters" << std::endl;
	is >> alg.columns;
	is >> alg.rows;
	int translated_characters;
	is >> translated_characters;
	//std::cout << alg.columns << " columns, " << alg.rows << " rows, " << alg.translated_characters << " characters." << std::endl;
	for (auto i = 0; i < translated_characters; i++) {
		Letter letter(alg.rows, alg.columns);
		is >> letter;
		alg.letters[letter.character] = letter;
	}
	return is;
}