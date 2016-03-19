#ifndef _TABL_HH
#define _TABL_HH

/*!
 * \file
 * \brief Definicja interfejsu klasy tabn, klasy tabn oraz klasy tabn_test
 * 
 *
 */
#include <iostream>
#include "run.hh"

#define SIZE 10

using namespace std;

/*
 * \brief Interfejs klasy tabn
 *
 */
template <class T>
class Itabn {
public:

	virtual void add(T) = 0;
	//virtual void remove(int) = 0;
	virtual void showElems(void) = 0;
	virtual int nOE(void) = 0;
	virtual int aSize(void) = 0;
	virtual T& operator [] (int) = 0;
	virtual T operator [] (int) const = 0;
	virtual ~Itabn(){}
};


/*! \brief Modeluje tablicę dynamicznie rozszerzalną
 *
 * Przechowuje elementy w rozszerzalnej tablicy o 
 * rozmiarze początkowym SIZE
 */
template <class T>
class tabn : public Itabn<T> {
private:
	T* tab;
	int allocatedSize;
	int numberOfElems;

public:

	/*!
	 * \brief Konstruktor klasy tabn.
	 * 
	 */
	tabn() {
		allocatedSize = SIZE;
		numberOfElems = 0;
		tab = new T[SIZE];
		//expandMode = twice;
	}
	
	/*!
	 * \brief Destruktor klasy tabn.
	 */
	virtual ~tabn() {
		delete [] tab;
	}
	
	
	/*!
	 * \brief Dodaje element
	 * Dodaje element do tablicy dynamicznej, odpowiednio ją rozszerzając
	 *
	 *\param element - element do dodania
	 */
	virtual void add(T);
	
private:
	
	/*!
	 *\brief Dodaje element. Rozszerza tablicę dwukrotnie, jeśli ilość elementów 
	 * ma przekroczyć wielkość tablicy.
	 *
	 *\param element - element do dodania
	 */
	/*virtual*/ void addElemDoubleTabl(T);
	
	
public:
	/*
	 * \brief Usuwa ostatni element z listy,
	 *
	 */

	/*!
	 * \brief Wyświetla listę elementów
	 */
	virtual void showElems(void);
	
	/*!
	 *\brief zwraca liczbę elementów w tablicy
	 *
	 *\retval int Liczba elementów w tablicy
	 */
	virtual int nOE(void);
	
	/*!
	 *\brief zwraca wielkość zaalokowanej przestrzeni dla tablicy
	 *
	 *\retval int Ilość zaalokowanych pól
	 */
	virtual int aSize(void);
	
	/*!
	 *\brief Umożliwia dostęp do dowolnego elementu tablicy bez
	 * sprawdzania zakresu
	 *
	 *\param index - numer elementu tablicy
	 *\retval T* Wskaźnik na wybrany element tablicy
	 */
	virtual T& operator [] (int);
	
	/*!
	 *\brief Umożliwia odczyt dowolnego elementu tablicy bez
	 * sprawdzania zakresu
	 *
	 *\param index - numer elementu tablicy
	 *\retval T Element tablicy
	 */
	virtual T operator [] (int) const;
};



template <class T>
void tabn<T>::add (T element) {
		addElemDoubleTabl(element); 
}

	
template <class T>
void tabn<T>::addElemDoubleTabl(T elem) {
		numberOfElems++;
		if (numberOfElems <= allocatedSize) {
			tab[numberOfElems-1] = elem; 
		}
		else {
			T* nowy = new T[allocatedSize*2];
		 	allocatedSize*=2;
		 	for (int i=0; i<=(numberOfElems-2); i++) {
		 		nowy[i] = tab[i];
		 	}		 	
		 	nowy[numberOfElems-1] = elem;
		 	delete [] tab;
		 	tab = nowy;
		}
}

template <class T>
T& tabn<T>::operator [] (int index) {
	return tab[index];
}

template <class T>
T tabn<T>::operator [] (int index) const {
	return tab[index];
}

template <class T>
void tabn<T>::showElems (void) {
		for (int i=0; i<numberOfElems; i++) {
			cout << tab[i] << " ";
		}
		cout << endl;
	}
	
template <class T>
int tabn<T>::nOE(void) {
		return numberOfElems;
	}
	
template <class T>
int tabn<T>::aSize(void) {
		return allocatedSize;
	}

//------------------------------------------------------------------------------

/*! \brief Definiuje sposób testowania tablicy tabn
 *
 */
class tabn_test : public IRunnable  {
private:
	Itabn<int> * test;
	unsigned int counter;
public:
	/*!
	 * \brief Konstruktor klasy tabn_test.
	 */
	tabn_test () : test (new tabn<int>) {
		seedSrand();
	}
	/*!
 	 * \brief Destruktor klasy tabn_test.
	 */
	virtual ~tabn_test () {
		delete test;
	}
	
private:

	/*!
	 * \brief Metoda ustawia punkt startowy generatora
	 * pseudolosowego.
	 */
	void seedSrand (void) {
		srand(time(NULL));
	}
	
	/*!
	 * \brief Metoda generuje liczbę pseudolosową z zakresu 0..9
	 *
	 *\retval Liczba pseudolosowa z zakresu 0..9
	 */
	int generateRandomDgt (void) {
		return rand()%10;
	}


public:		
	/*!
 	 * \brief Przygotowuje rozmiar testu
 	 *
 	 * \param sizeOfTest - rozmiar testu
 	 * \retval bool zawsze true
	 */
	virtual bool prepare(unsigned int sizeOfTest) {
		counter = sizeOfTest;
		return true;
	}
	
	/*!
 	 * \brief Wykonuje test
 	 *
 	 * Pozwala na wykonanie testu w pętli for iterującej
 	 * \link counter \endlink razy. Zasila funkcję dodawania
 	 * generując losowe cyfry w funkcji 
 	 * \link generateRandomDgt() \endlink
 	 *
 	 * \retval bool zawsze true
	 */
	virtual bool run() {
		for (;counter>0;counter--) {
			test->add(generateRandomDgt());
		}
		cerr << "SIZE:  " << test->aSize() << endl;
		cerr << "Elems: " << test->nOE() << endl;
		return true;
	}
};


#endif
