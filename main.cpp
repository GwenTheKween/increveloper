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
	//inicializacao da biblioteca e janelas
	initCurses();

	//chamada de funcoes para teste de bibliotecas
	std::string file = readFile("codes/hello.c");
	ghostPrint(file);
	//renderizacao da tela
	refresh();
	//usado para manter a tela aberta
	getch();


	//termino da biblioteca
	finishCurses();
	return 0;
}
