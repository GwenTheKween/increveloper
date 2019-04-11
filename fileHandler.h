#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <string>
#include <fstream>
#include <exception>
#include <ncurses.h>

std::string readFile(std::string);

void ghostPrint(std::string,int,int);

#endif
