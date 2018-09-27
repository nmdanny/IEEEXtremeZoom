#include "LettersAlg.h"
#include <fstream>

int alt_main() {
	LettersAlg alg;
	std::ifstream input("sample_input.txt");
	assert(input.good());
	input >> alg;
	auto output = alg.run(input);
	std::cout << "Output:\n---------------\n" << output << "---------------";
	return 0;
}

int main(int argc, char **argv) {
	LettersAlg alg;
	std::cin >> alg;
	auto output = alg.run(std::cin);
	std::cout << output;
	
	return 0;
}