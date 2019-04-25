#ifndef DISPLAYMANAGER
#define DISPLAYMANAGER
#include <vector>
#include <string>
#include <ncurses.h>
#include <menu.h>

class customMenu{
private:
	std::vector<ITEM*> items;
	MENU* pointer;
public:
	customMenu(std::vector<std::string>, std::vector<uintptr_t>);
	~customMenu();

	uintptr_t process();
	void post();
	void unpost();
};

enum{
	MENU_OPTION_DO_NOTHING = 0,
	MENU_OPTION_LOGIN,
	MENU_OPTION_QUIT
};

#endif
