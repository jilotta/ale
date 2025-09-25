//asd
#include <iostream>
#include <fstream>
#include <string>

std::string sample;
std::string actual;
int position;

#define WRONG_ANSWER (1)
#define IO_ERROR (2)
#define POSITION "position " << position << ": "

int main() {
	std::ifstream sample_stream("sample.txt");
	std::ifstream actual_stream("actual.txt");

	while (sample_stream.good()) {
		position = actual_stream.tellg();
		sample_stream >> sample;

		if (actual_stream.eof()) {
			std::cerr << POSITION << "expected `" << sample << "`, found end of file" << std::endl;
			return WRONG_ANSWER;
		} else if (actual_stream.bad()) {
			std::cerr << POSITION << "i/o error" << std::endl;
			return IO_ERROR;
		}
		
		actual_stream >> actual;


		if (sample != actual) {
			std::cerr << POSITION << "expected `" << sample << "`, found `" << actual << "`" << std::endl;
			return WRONG_ANSWER;
		}
	}

	return 0;
}
