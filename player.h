#ifndef PLAYER
#define PLAYER

#include "string"
#include <fstream>
#include <exception>

class player{
private:
	double score; //double stores bigger numbers
	double increment;
	double multiplier;

	std::string playerName;
public:
	player();

	double getScore();
	double getIncrement();

	void increaseScore(double);
	void increaseIncrement(double);
	void incrementScore();

	void login(std::string);
	void readSave();
	void writeSave();
};

#endif
