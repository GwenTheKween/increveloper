#include "fileHandler.h"
#include <ncurses.h>

//========================================================================================================
//Startup and finish functions
void initCurses(){
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
}

void finishCurses(){
	endwin();
}

//========================================================================================================
//Auxiliary/temporary functions

void inputProcess(std::string toMatch){
	int currPos = 0;
	char c;
	while(currPos < toMatch.length()){
		c = getch();
		if(c == toMatch[currPos]){
			currPos ++;
			addch(c);
		}
		refresh();
	}
}


int main(){
	//inicializacao da biblioteca e janelas
	initCurses();

	//chamada de funcoes para teste de bibliotecas
	std::string file = readFile("codes/hello.c");
	ghostPrint(file);
	//renderizacao da tela
	refresh();
	inputProcess(file);


	//termino da biblioteca
	finishCurses();
	return 0;
}
