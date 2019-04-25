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
	customMenu(std::vector<std::string>);
	~customMenu();

	void process();
};

#endif
