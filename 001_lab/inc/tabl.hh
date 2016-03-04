#ifndef _TABL_HH
#define _TABL_HH
#include <iostream>

#define SIZE 10

using namespace std;

/*
 * Klasa tabn
 *
 * Przechowuje elementy w rozszerzalnej tablicy o rozmiarze początkowym SIZE
 *
 * Pola:
 * * tab:  wskaźnik na tablicę
 * * size: aktualny rozmiar tablicy
 *
 * Metody:
 * * tabn:          konstruktor
 * * ~tabn:	        destruktor
 * * add_elem_last: rozszerza listę o 1 jeśli ilość elementów ma przekroczyć SIZE
 * * show_elems:    wyświetla listę elementów (przydatne do debugowania)
 * * tabl_size:     zwraca liczbę elementów w tablicy (przydatne do debugowania)
 */
 
class tabn {
private:
	int* tab;
	int size;
public:
	tabn() {
		size = 0;
		tab = new int[SIZE];
	}
	~tabn() {
		delete [] tab;
	}
	
	void add_elem_last(int);
	void show_elems(void);
	int tabl_size(void) {
		return size;
	}
};
#endif
