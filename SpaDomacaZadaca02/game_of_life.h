#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	int susjed = 0;
	bool slucajna_vrijednost();
	void random_grid();

public:
	game_of_life();
	bool generacija[REDAKA][STUPACA];
	void sljedeca_generacija();
	void iscrtaj();
};

#endif