#ifndef _TABL_HH
#define _TABL_HH

/*!
 * \file
 * \brief Definicja interfejsu klasy tabn, klasy tabn oraz klasy tabn_test
 * 
 *
 */
#include <iostream>
#include "main.hh"
#include "run.hh"

#define SIZE 10

using namespace std;

/*
 * \brief Interfejs klasy tabn
 *
 */
class Itabn {
public:
	virtual void setExpandMode (expandType) = 0;
	virtual void add(int) = 0;
//	virtual void addElemLast (int) = 0;
//	virtual void addElemDoubleTabl(int) = 0;
//	virtual void addElem1Tabl5(int) = 0 ;
	virtual void showElems(void) = 0;
	virtual int nOE(void) = 0;
	virtual int aSize(void) = 0;
	virtual int& operator [] (int) = 0;
	virtual int operator [] (int) const = 0;
	virtual ~Itabn(){}
};


/*! \brief Modeluje tablicę dynamicznie rozszerzalną
 *
 * Przechowuje elementy w rozszerzalnej tablicy o 
 * rozmiarze początkowym SIZE
 */
class tabn : public Itabn{
private:
	int* tab;
	int allocatedSize;
	int numberOfElems;
	expandType expandMode;
public:

	/*!
	 * \brief Konstruktor klasy tabn.
	 * 
	 * Ustawia domyślny sposób rozszerzania na dwukrotne.
	 */
	tabn() {
		allocatedSize = SIZE;
		numberOfElems = 0;
		tab = new int[SIZE];
		expandMode = twice;
	}
	
	/*!
	 * \brief Destruktor klasy tabn.
	 */
	virtual ~tabn() {
		delete [] tab;
	}
	
	/*!
	 * \brief Ustawia tryb rozszerzania.
	 * Pozwala na ustawienie trybu rozszerzania tablicy dynamicznej.
	 *
	 * \param[in] type - sposób rozszerzania tablicy
	 */
	virtual void setExpandMode(expandType);
	
	/*!
	 * \brief Dodaje element w zadanym trybie
	 * Dodaje element do tablicy dynamicznej w trybie wybranym
	 *
	 *\param[in] element - liczba do dodania
	 */
	virtual void add(int);
	
private:
	/*!
	 * \brief Rozszerza tablicę o 1 jeśli ilość elementów 
	 * ma przekroczyć wielkość tablicy.
	 *
	 *\param[in] element - liczba do dodania
	 */
	/*virtual*/ void addElemLast(int);
	
	/*!
	 *\brief Rozszerza tablicę dwukrotnie, jeśli ilość elementów 
	 * ma przekroczyć wielkość tablicy.
	 *
	 *\param[in] element - liczba do dodania
	 */
	/*virtual*/ void addElemDoubleTabl(int);
	
	/*!
	 *\brief Rozszerza tablicę półtorakrotnie, jeśli ilość  
	 * elementów ma przekroczyć wielkość tablicy.
	 *
	 *\param[in] element - liczba do dodania
	 */
	/*virtual*/ void addElem1Tabl5(int);
	
public:
	/*!
	 * \brief Wyświetla listę elementów
	 */
	virtual void showElems(void);
	
	/*!
	 *\brief zwraca liczbę elementów w tablicy
	 *
	 *\retval Liczba elementów w tablicy
	 */
	virtual int nOE(void);
	
	/*!
	 *\brief zwraca wielkość zaalokowanej przestrzeni dla tablicy
	 *
	 *\retval Ilość zaalokowanych bloków pamięci
	 */
	virtual int aSize(void);
	
	/*!
	 *\brief Umożliwia dostęp do dowolnego elementu tablicy bez
	 * sprawdzania zakresu
	 *
	 *\param[in] index - numer elementu tablicy
	 *\retval Wskaźnik na wybrany element tablicy
	 */
	virtual int& operator [] (int);
	
	/*!
	 *\brief Umożliwia odczyt dowolnego elementu tablicy bez
	 * sprawdzania zakresu
	 *
	 *\param[in] index - numer elementu tablicy
	 *\retval Element tablicy
	 */
	virtual int operator [] (int) const;
};


/*! \brief Definiuje sposób testowania tablicy tabn
 *
 */
class tabn_test : public Runnable  {
private:
	Itabn * test;
	unsigned int counter;
public:
	/*!
	 * \brief Konstruktor klasy tabn_test.
	 */
	tabn_test () : test (new tabn) {
		seedSrand();
	}
	/*!
 	 * \brief Destruktor klasy tabn_test.
	 */
	virtual ~tabn_test () {
		delete test;
	}
	
	/*!
 	 * \brief Pozwala na zmianę trybu rozszerzania tablicy
 	 *
 	 * \param[in] type - typ rozszerzania tablicy
	 */
	void setTypeOfExpansion(expandType);
	
	/*!
 	 * \brief Przygotowuje rozmiar testu oraz ustawia tryb
 	 * rozszerzania tablicy na podsawie zmiennej globalnej 
 	 * \link typeOfExp \endlink .
 	 *
 	 * \param[in] sizeOfTest - rozmiar testu
 	 * \retval zawsze true
	 */
	virtual bool prepare(unsigned int);
	
	/*!
 	 * \brief Wykonuje test
 	 *
 	 * Pozwala na wykonanie testu w pętli for iterującej
 	 * \link counter \endlink razy. Zasila funkcję dodawania
 	 * generując losowe cyfry w funkcji 
 	 * \link generateRandomDgt() \endlink
 	 *
 	 * \retval zawsze true
	 */
	virtual bool run();	
};

#endif
