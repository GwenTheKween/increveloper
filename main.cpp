#include "fileHandler.h"
#include "player.h"
#include "customMenu.h"
#include "customPanel.h"

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
	printf("veio aqui\n");
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

void print_enter(){
	mvprintw(10,0,"enter\n");
	refresh();
}

void print_exit(){
	mvprintw(10,0,"exit\n");
	refresh();
}

void mainLoop(){
	std::vector<std::string> v1;
	std::vector<uintptr_t> v2;
	uintptr_t mainMenuAction;
	panelManager p;
	try{
		v1.push_back("enter");
		v2.push_back(MENU_OPTION_LOGIN);
		v1.push_back("exit");
		v2.push_back(MENU_OPTION_DO_NOTHING);
		customMenu m(v1,v2);

		p.addPanel(25,25,15,15);

		mvprintw(0,0,"menu test, they all just print");
		mvprintw(1,0,"press q to leave");
		mainMenuAction = m.process();
		switch(mainMenuAction){
			case MENU_OPTION_LOGIN:
				print_enter();
				break;
			case MENU_OPTION_DO_NOTHING:
				print_exit();
				break;
			default:
				throw std::runtime_error("invalid menu action");
		}

		getch();
	}catch (std::exception e){
		mvprintw(0,0,"%s\n",e.what());
		getch();
	}
	mvprintw(0,0,"all is well");
	getch();
}

int main(){
	//inicializacao da biblioteca e janelas
	initCurses();

	//loop principal do programa
	mainLoop();

	//termino da biblioteca
	finishCurses();
	return 0;
}
