#ifndef _TABL_HH
#define _TABL_HH

/*!
 * \file
 * \brief Definicja interfejsu Itabn, klasy tabn oraz klasy tabn_test
 */
#include <iostream>
#include <exception>
#include "run.hh"

#define SIZE 10

using namespace std;

/*!
 * \brief Interfejs klasy tabn
 *
 * Definiuje jednolity sposób dostępu do tablicy rozszerzalnej.
 */
template <class T>
class Itabn {
public:

	/*!
	 *\brief Sprawdza, czy tablica jest pusta
	 */
	 virtual bool isEmpty(void) = 0;
	 
	/*!
	 *\brief Dodaje element na koniec tablicy
	 */
	virtual void add(T) = 0;
	
	/*!
	 *\brief Dodaje element w dane miejsce do tablicy, przesuwając wszystkie następne elementy o miejsce w prawo
	 *\param element - wstawiany element
	 *\param positionShifted - indeks pola, w które ma być wstawiony element.
	 */
	virtual void add(T,int) = 0;
	
	/*!
	 *\brief Usuwa element z końca tablicy
	 */
	virtual void remove() = 0;
	
	/*!
	 *\brief Usuwa wybrany element z listy
	 *\param positionShifted - indeks pola, z którego ma być usunięty element.
	 */
	virtual void remove(int) = 0;
	
	/*!
	 *\brief Wyświetla elementy listy
	 */
	virtual void showElems(void) = 0;
	
	/*!
	 *\brief Zwraca liczbę elementów w tablicy
	 */
	virtual int nOE(void) = 0;
	
	/*!
	 *\brief Zwraca ilość miejsca w tablicy
	 */
	virtual int aSize(void) = 0;
	
	/*!
	 *\brief Pozwala na dostęp do dowolnego elementu
	 */
	virtual T& operator [] (int) = 0;
	
	/*!
	 *\brief Pozwala na dostęp do dowolnego elementu
	 */
	virtual T operator [] (int) const = 0;
	
	/*!
	 *\brief Destruktor witrualny interfejsu
	 */
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
	 *\brief Konstruktor klasy tabn.
	 */
	tabn() {
		allocatedSize = SIZE;
		numberOfElems = 0;
		tab = new T[SIZE];
	}
	
	/*!
	 *\brief Destruktor klasy tabn.
	 */
	virtual ~tabn() {
		delete [] tab;
	}
	
private:
	
	/*!
	 *\brief Rozszerza tablicę dwukrotnie
	 *
	 * Rozszerzanie wykonywane jest poprzez stworzenie dwa razy większej tablicy,
	 * skopiowanie do niej danych, usunięcie mniejszej i zastąpienie jej nową.
	 */
	void expand2(void);
	
	/*!
	 *\brief Zmniejsza tablicę dwukrotnie
	 *
	 * Metoda pozwala na skopiowanie danych do dwa razy mniejszej tablicy i zastąpienie nią
	 * dotychczasowej.
	 */
	void reduce2(void);
	
	/*!
	 *\brief Wyrzuca wyjątek, gdy tablica jest pusta
	 */
	void isEmptyException (void);
	
	/*!
	 *\brief Przesuwa elementy od pozycji \link positionShifted \endlink w prawo
	 *\param element - wstawiany element
	 *\param positionShifted - indeks pola, w które ma być wstawiony element. Elementy po nim następujące zostaną przesunięte o 1 w prawo
	 */
	 void shiftRight (T,int);
	 
	 /*!
	 *\brief Przesuwa elementy od pozycji \link positionShifted \endlink w lewo
	 *\param positionShifted - indeks pola, z którego ma być usuniety element. Elementy po nim następujące zostaną przesunięte o 1 w lewo
	 */
	 void shiftLeft (int);
	
public:	
	
	/*!
	 *\brief Sprawdza, czy tablica jest pusta
	 *
	 *\retval 0 gdy tablica nie jest pusta
	 *\retval 1 gdy tablica jest pusta
	 */
	 virtual bool isEmpty(void);
	
	
	/*!
	 * \brief Dodaje element
	 * Dodaje element do tablicy dynamicznej, odpowiednio ją rozszerzając
	 *
	 *\param element - element do dodania
	 */
	virtual void add(T);
	
	/*!
	 *\brief Dodaje element w dane miejsce do tablicy, przesuwając wszystkie następne elementy o miejsce w prawo.
	 *\param element - wstawiany element
	 *\param positionShifted - indeks pola, w które ma być wstawiony element.
	 */
	virtual void add(T,int);
	
	/*!
	 * \brief Usuwa ostatni element z listy.
	 */
	virtual void remove();
	
	/*!
	 *\brief Usuwa wybrany element z listy, przesuwając wszystkie następne elementy o miejsce w lewo
	 *\param positionShifted - indeks pola, z którego ma być usunięty element.
	 */
	virtual void remove(int);

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
	 * sprawdzania zakresu (debug)
	 *
	 *\param index - numer elementu tablicy
	 *\retval T* Wskaźnik na wybrany element tablicy
	 */
	virtual T& operator [] (int);
	
	/*!
	 *\brief Umożliwia odczyt dowolnego elementu tablicy bez
	 * sprawdzania zakresu (debug)
	 *
	 *\param index - numer elementu tablicy
	 *\retval T Element tablicy
	 */
	virtual T operator [] (int) const;
};



template <class T>
void tabn<T>::add (T element) {
	numberOfElems++;
	if (((numberOfElems) > allocatedSize))
		expand2(); 	
	tab[numberOfElems-1] = element;
}

template <class T>
void tabn<T>::add (T element, int position) {
	try {
		shiftRight(element,position);
	}
	catch (string ex) {
		cout << "Exception: " << ex << endl;
		delete [] tab;
		terminate();
	}
	tab[position] = element;
}

template <class T>
void tabn<T>::shiftRight (T element, int positionShifted) {
	if (positionShifted>numberOfElems) {
		string ex = "WrongPositionToShiftFromException";
		throw ex;
	}
	numberOfElems++;
	if (((numberOfElems) > allocatedSize))
		expand2(); 	
	T* nowy = new T[numberOfElems-positionShifted-1];
	for(int i = positionShifted,j=0;i<(numberOfElems-1);i++,j++) {
			nowy[j]=tab[i];
	}
	tab[positionShifted] = element;
	for(int i = positionShifted+1,j=0;i<(numberOfElems);i++,j++) {
			tab[i]=nowy[j];
	}
	delete [] nowy;
}

template <class T>
void tabn<T>::remove() {
	try {
		isEmptyException();
	}
	catch (string ex) {
		cout << "Exception: " << ex << endl;
		delete [] tab;
	}
	numberOfElems--;
	if ((((numberOfElems) <= (allocatedSize/2)) && (allocatedSize > SIZE))) {
		try {
			reduce2();
		}
		catch (string ex) {
			cout << "Exception: " << ex << endl;
			delete [] tab;
		}
	}
}

template <class T>
void tabn<T>::remove(int position) {
	try {
		isEmptyException();
	}
	catch (string ex) {
		cout << "Exception: " << ex << endl;
		delete [] tab;
	}
	
	try {
		shiftLeft(position);
	}
	catch (string ex) {
		cout << "Exception: " << ex << endl;
		delete [] tab;
	}
	
	if ((((numberOfElems) <= (allocatedSize/2)) && (allocatedSize > SIZE))) {
		try {
			reduce2();
		}
		catch (string ex) {
			cout << "Exception: " << ex << endl;
			delete [] tab;
		}
	}
}

template <class T>
void tabn<T>::shiftLeft(int positionShifted) {
	if (positionShifted>numberOfElems) {
		string ex = "WrongPositionToShiftFromException";
		throw ex;
	}
	
	T* nowy = new T[numberOfElems-positionShifted-1];
	for(int i = positionShifted+1,j=0;i<(numberOfElems);i++,j++) {
			nowy[j]=tab[i];
	}
	numberOfElems--;
	for(int i = positionShifted,j=0;i<(numberOfElems);i++,j++) {
			tab[i]=nowy[j];
	}
	delete [] nowy;
}

template <class T>
void tabn<T>::expand2(void) {
	T* nowy = new T[allocatedSize*2];
	allocatedSize*=2;
	for (int i=0; i<=(numberOfElems-2); i++) {
		nowy[i] = tab[i];
	}
	delete [] tab;
	tab = nowy;
}

template <class T>
void tabn<T>::reduce2(void) {
	if(allocatedSize <= SIZE) {
		string ex = "SmallestTableException";
		throw ex;
	}
	T* nowy = new T[allocatedSize/2];
	allocatedSize=allocatedSize/2;
	for (int i=0;i<=(numberOfElems-1);i++){
		nowy[i] = tab[i];
	}
	delete [] tab;
	tab = nowy;
}

template <class T>
bool tabn<T>::isEmpty(void) {
	if (numberOfElems <= 0) {
		return 1;
	}
	else return 0;
}

template <class T>
void tabn<T>::isEmptyException (void) {
	if (numberOfElems <= 0) {
		string ex = "EmptyTableException";
		throw ex;
	}
	else {}
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

/*! \brief Definiuje sposób testowania wypełniania tablicy tabn
 *
 */
class tabn_test : public IRunnable  {
private:
	Itabn<int> * test;
	int counter;
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
	virtual bool prepare(int sizeOfTest) {
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
		//test->showElems();
		cerr << "SIZE:  " << test->aSize() << endl;
		cerr << "Elems: " << test->nOE() << endl;
		return true;
	}
};


#endif
