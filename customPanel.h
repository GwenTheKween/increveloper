#ifndef CUSTOM_PANEL_HEADER
#define CUSTOM_PANEL_HEADER

#include "panel.h"
#include <vector>

class panelManager{
private:
	std::vector<WINDOW*> windows;
	std::vector<PANEL*> panels;
public:
	panelManager();
	~panelManager();

	WINDOW* addPanel(int,int,int,int);
	void deletePanel(int);
};

#endif
