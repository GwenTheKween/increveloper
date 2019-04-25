#include "customMenu.h"

customMenu::customMenu(std::vector<std::string> names, std::vector<uintptr_t> actions){
	for(int i=0;i<names.size(); i++){
		items.push_back(new_item(names[i].c_str(), names[i].c_str()));
		set_item_userptr(items[i], (void*)actions[i]);
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

uintptr_t customMenu::process(){
	int c;
	ITEM* curr;
	while((c = getch())!='q'){
		switch (c){
			case KEY_UP:
			case 'k':
				menu_driver(pointer, REQ_UP_ITEM);
				break;
			case KEY_DOWN:
			case 'j':
				menu_driver(pointer, REQ_DOWN_ITEM);
				break;
			case ' ':
			case 10: //enter
				curr = current_item(pointer);
				return (uintptr_t) item_userptr(curr);
		}
	}
	return MENU_OPTION_DO_NOTHING;
}

void customMenu::post(){
	post_menu(pointer);
}

void customMenu::unpost(){
	unpost_menu(pointer);
}
