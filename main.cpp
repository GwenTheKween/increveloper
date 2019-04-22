#include "fileHandler.h"
#include "player.h"
#include <ncurses.h>
#include <menu.h>

player p;

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
	int xmax,ymax,y,x;
	getmaxyx(stdscr, ymax,xmax);
	while(currPos < toMatch.length()){
		c = getch();
		if(c == toMatch[currPos]){
			currPos ++;
			addch(c);
			p.incrementScore();
		}
		//save old position
		getyx(stdscr, y,x);
		//print player score
		mvprintw(0,0,"%e",p.getScore());
		move(y,x);
		refresh();
	}
}

int main(){
	//inicializacao da biblioteca e janelas
	initCurses();

	try{
		//Login control
		p.login("billionai");
		p.readSave();

		//chamada de funcoes para teste de bibliotecas
		std::string file = readFile("codes/hello.c");
		ghostPrint(file,1,0);
		move(1,0);
		//renderizacao da tela
		refresh();
		inputProcess(file);

		p.increaseIncrement(1.0);
		p.writeSave();
	}catch (std::exception e){
		mvprintw(0,0,"%s\n",e.what());
		getch();
	}
	//termino da biblioteca
	finishCurses();
	return 0;
}
