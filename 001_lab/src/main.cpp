
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
			cin.ignore(10000, '\n');
		}
		else {
			tablica_dynamiczna.add_elem_last(liczba);
			}
	}
	
	// Zakończenie liczenia czasu
	end = chrono::high_resolution_clock::now();
	
	// Czas trwania
	chrono::duration<double> work_time = end - begin;
	
	cout << "-----------------------------------------------" << endl;
	cout << "Operacja wykonana w " << work_time.count()*1000 << " ms." << endl;

	// Kontrola poprawności działania
	cout << "SIZE: " << tablica_dynamiczna.tabl_size() << endl;
}
