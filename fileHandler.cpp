#include "fileHandler.h"

std::string readFile(std::string filename){
	std::string contents;
	std::ifstream inFile(filename, std::ios::in);

	if(!inFile.is_open()){
		throw std::runtime_error("unable to open file");
	}

	char c;

	while((c = inFile.get()) != EOF){
		//read a character and checks that is not EOF
		contents += c;
	}

	return contents;
}
