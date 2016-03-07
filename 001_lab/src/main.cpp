
/*
 * Obliczanie czasu działania fragmentu programu na podstawie przykładu:
 * http://en.cppreference.com/w/cpp/chrono
 */

#include <iostream>
#include <chrono>
#include <ctime>
#include "../inc/tabl.hh"
#include "../inc/main.hh"
#include "../inc/run.hh"
using namespace std;


int main (void) {
	
	tabn tablica_dynamiczna;
	int liczba = 0;
	Stoper stoper;
	
	// Rozpoczęcie liczenia czasu 
	stoper.start();
	
	// Czynność
	while (!cin.eof()) {
		cin >> liczba;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000000000, '\n');
		}
		else {
			//tablica_dynamiczna.addElemLast(liczba);
			//tablica_dynamiczna.addElemDoubleTabl(liczba);
			tablica_dynamiczna.addElem1Tabl5(liczba);
			}
	}
	
	// Zakończenie liczenia czasu
	stoper.stop();
	
	cout << "-----------------------------------------------" << endl;
	cout << "Operacja wykonana w " << stoper.getElapsedTimeMs() << " ms." << endl;

	// Kontrola poprawności działania
	cout << "Elementów:        " << tablica_dynamiczna.nOE() << endl;
	cout << "Wielkość tablicy: " << tablica_dynamiczna.aSize() << endl;
}
