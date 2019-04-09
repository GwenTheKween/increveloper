#include "fileHandler.h"
#include <ncurses.h>

void initCurses(){
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
}

void finishCurses(){
	endwin();
}

int main(){
	initCurses();
	std::string file = readFile("codes/hello.c");
	printw(file.c_str());
	refresh();
	getch();
	finishCurses();
	return 0;
}
