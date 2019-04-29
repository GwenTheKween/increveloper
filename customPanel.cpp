#include "customPanel.h"

panelManager::panelManager(){
}

panelManager::~panelManager(){
	while(!panels.empty()){
		deletePanel(panels.size()-1);
	}
}

WINDOW* panelManager::addPanel(int height, int width, int y,int x){
	WINDOW* new_window;
	new_window = newwin(height,width,y,x);
	keypad(new_window,true);
	windows.push_back(new_window);
	box(new_window,0,0);
	panels.push_back(new_panel(new_window));
	update_panels();
	return new_window;
}

void panelManager::deletePanel(int position){
	//first, delete the panel
	del_panel(panels[position]);
	//then, clear window border format
	wborder(windows[position],' ',' ',' ',' ',' ',' ',' ',' ');
	wrefresh(windows[position]);
	delwin(windows[position]);

	//finally, remove from list:
	panels.erase(panels.begin()+position);
	windows.erase(windows.begin()+position);
}
