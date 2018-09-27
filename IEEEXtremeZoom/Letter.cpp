#include "Letter.h"
#include <fstream>

void print_sample_input() {
	LettersAlg alg;
	std::ifstream input("sample_input.txt");
	assert(input.good());
	input >> alg;
	auto output = alg.run(input);
	std::cout << "Output:\n---------------\n" << output << "---------------";

}

int main(int argc, char **argv) {
	print_sample_input();
	/*
	LettersAlg alg;
	std::cin >> alg;
	auto output = alg.run(std::cin);
	std::cout << output;
	*/
	return 0;
}