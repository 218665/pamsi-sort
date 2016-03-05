
/*
 * Obliczanie czasu działania fragmentu programu na podstawie przykładu:
 * http://en.cppreference.com/w/cpp/chrono
 */

#include <iostream>
#include <chrono>
#include <ctime>
#include "../inc/tabl.hh"
#include "../inc/main.hh"
using namespace std;


int main (void) {
	
	tabn tablica_dynamiczna;
	int liczba = 0;
	chrono::time_point<chrono::high_resolution_clock> begin, end;
	
	// Rozpoczęcie liczenia czasu 
	begin = chrono::high_resolution_clock::now();
	
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
	end = chrono::high_resolution_clock::now();
	
	// Czas trwania
	chrono::duration<long double> work_time = end - begin;
	
	cout << "-----------------------------------------------" << endl;
	cout << "Operacja wykonana w " << work_time.count()*1000 << " ms." << endl;

	// Kontrola poprawności działania
	cout << "Elementów:        " << tablica_dynamiczna.nOE() << endl;
	cout << "Wielkość tablicy: " << tablica_dynamiczna.aSize() << endl;
	//tablica_dynamiczna.showElems();
}
