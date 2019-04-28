#include "game_of_life.h"
using namespace std;

game_of_life::game_of_life() {
	random_grid();
}

bool game_of_life::slucajna_vrijednost() {
	return rand() & 1 & rand() & 1;
}

void game_of_life::random_grid() {

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija() {
	// prolazak kroz svaku celiju
	for (int i = 1; i < REDAKA - 1; i++) {
		for (int j = 1; j < STUPACA - 1; j++) {
			//provjera zivucih susjeda
			for (int k = -1; k <= 1; k++) {
				for (int l = -1; l <= 1; l++) {
					susjed += generacija[i + k][j + l];
				}
			}
			//oduzmi trenutnu celiju
			susjed -= generacija[i][j];

			if (susjed < 2) 
				generacija[i][j] = 0;

			else if (susjed > 3)
				generacija[i][j] = 0;

			else if (susjed == 3)
				generacija[i][j] = 1;

			//resetiraj broj susjeda
			susjed = 0;
		}
	}
}

void game_of_life::iscrtaj() {
	//samo za konzolu
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			generacija[i][j] ? cout << "*" : cout << "-";
		}
		cout << endl;
	}
}

