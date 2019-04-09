#include "dm.h"

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
	printw("hello World");
	refresh();
	getch();
	finishCurses();
	return 0;
}
