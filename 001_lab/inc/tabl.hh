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
 * * tab:  				wskaźnik na tablicę
 * * allocatedSize: 	aktualny rozmiar tablicy
 * * numberOfElems: 	liczba wpisanych elementów
 *
 * Metody:
 * * tabn:          	konstruktor
 * * ~tabn:	        	destruktor
 * * addElemLast: 		rozszerza tablicę o 1 jeśli ilość elementów ma przekroczyć wielkość tablicy.
 * * addElemDoubleTabl: rozszerza tablicę dwukrotnie, jeśli ilość elementów ma przekroczyć wielkość tablicy
 * * addElem1Tabl5: 	rozszerza tablicę 1.5-krotnie, jeśli ilość elementów ma przekroczyć wielkość tablicy
 * * showElems:    		wyświetla listę elementów (przydatne do debugowania)
 * * nOE:     			zwraca liczbę elementów w tablicy (przydatne do debugowania)
 * * aSize:				zwraca wielkość zaalokowanej tablicy (przydatne do debugowania)
 * * Przeciążenia operatora indeksowania zezwalają na dostęp do dowolnego elementu tablicy, bez sprawdzania zakresu.
 */
 
class tabn {
private:
	int* tab;
	int allocatedSize;
	int numberOfElems;
public:
	tabn() {
		allocatedSize = SIZE;
		numberOfElems = 0;
		tab = new int[SIZE];
	}
	~tabn() {
		delete [] tab;
	}
	
	void addElemLast(int);
	void addElemDoubleTabl(int);
	void addElem1Tabl5(int);
	void showElems(void);
	int nOE(void);
	int aSize(void);
	int& operator [] (int);
	int operator [] (int) const;
};
#endif
