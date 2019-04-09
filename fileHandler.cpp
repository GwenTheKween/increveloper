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

void ghostPrint(std::string message){
	int old_y,old_x;
	attr_t old_attr;
	short color_pair;
	//save old screen state
	getyx(stdscr, old_y,old_x);
	attr_get(&old_attr, &color_pair, NULL);

	//start new state
	attr_set(A_DIM, 0, NULL);
	//prints the message in ghostPrint state
	mvprintw(0,0,"%s",message.c_str());

	//retorns to old state
	attr_set(old_attr, color_pair, NULL);
	move(old_y,old_x);
}
