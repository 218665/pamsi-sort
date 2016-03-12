#ifndef _TABL_HH
#define _TABL_HH
#include <iostream>
#include "run.hh"

#define SIZE 10

using namespace std;

enum expandType {one, twice, onehalf}; 

class Itabn {
public:
	virtual void setExpandMode (expandType) = 0;
	virtual void add(int) = 0;
	virtual void addElemLast (int) = 0;
	virtual void addElemDoubleTabl(int) = 0;
	virtual void addElem1Tabl5(int) = 0 ;
	virtual void showElems(void) = 0;
	virtual int nOE(void) = 0;
	virtual int aSize(void) = 0;
	virtual int& operator [] (int) = 0;
	virtual int operator [] (int) const = 0;
	virtual ~Itabn(){}
};

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
 
class tabn : public Itabn{
private:
	int* tab;
	int allocatedSize;
	int numberOfElems;
	expandType expandMode;
public:
	tabn() {
		allocatedSize = SIZE;
		numberOfElems = 0;
		tab = new int[SIZE];
		expandMode = one;
	}
	virtual ~tabn() {
		delete [] tab;
	}
	virtual void setExpandMode(expandType);
	virtual void add(int);
	virtual void addElemLast(int);
	virtual void addElemDoubleTabl(int);
	virtual void addElem1Tabl5(int);
	virtual void showElems(void);
	virtual int nOE(void);
	virtual int aSize(void);
	virtual int& operator [] (int);
	virtual int operator [] (int) const;
};



class tabn_test : public IRunnable  {
	private:
		Itabn * test;
		int randomDgtToWrite;
		int counter;
	public:
		tabn_test () : test (new tabn) {
			seedSrand();
			randomDgtToWrite = generateRandomDgt();
		}
		~tabn_test () {
			delete test;
		}
		void seedSrand (void);
		int generateRandomDgt (void);
		void setTypeOfExpansion(expandType);
		virtual bool prepare(int);
		virtual bool run();	
};



#endif
