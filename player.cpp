#include  "player.h"

//=========================================================================================================
//Score manipulation

double player::getScore(){
	return score;
}

double player::getIncrement(){
	return increment;
}

void player::increaseScore(double amnt){
	score += amnt;
}

void player::increaseIncrement(double amnt){
	increment += amnt;
}

void player::incrementScore(){
	score += increment*multiplier;
}

//=========================================================================================================
//Login and save manipulation

void player::login(std::string user){
	playerName = user;
}

void player::readSave(){
	std::ifstream inFile("saves/"+playerName,std::ios::in);
	if(inFile.is_open()){
		inFile >> score;
		inFile >> increment;
		inFile >> multiplier;
	}
}

void player::writeSave(){
	std::ofstream outFile("saves/"+playerName,std::ios::out);
	if(!outFile.is_open()){
		throw std::runtime_error("Unable to create save file");
	}else{
		outFile << score << std::endl;
		outFile << increment << std::endl;
		outFile << multiplier << std::endl;
	}
}

//=========================================================================================================
//Constructor declaration

player::player():
	score(0),
	increment(1),
	multiplier(1)
{}
