#include "dm.h"

customMenu::customMenu(std::vector<std::string> names){
	for(int i=0;i<names.size(); i++){
		items.push_back(new_item(names[i].c_str(), names[i].c_str()));
	}
	items.push_back(NULL);
	pointer = new_menu(items.data());
}

customMenu::~customMenu(){
	free_menu(pointer);
	pointer = NULL;
	for(int i=0; i<items.size()-1; i++){
		free_item(items[i]);
		items[i] = NULL;
	}
}

void customMenu::process(){
}
