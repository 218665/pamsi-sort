#ifndef _LISTA_HH
#define _LISTA_HH

/*!
 *\file Plik definiuje typ danych lista
 *
 */
#include "tabl.hh"
using namespace std;
 
 /*!
  *\brief Interfejs listy
  *
  * Definiuje dostępne operacje na klasie Lista
  */
template <class T>
class ILista {
public:
	/*!
	 *\brief Dodaje element do zadanego miejsca listy
	 *
	 * Jeśli następuje próba dodania elementu w miejscu istniejącego, następuje przesunięcie następujących po nim
	 * elementów na następne pozycje
	 */
	virtual void add(T, int) = 0;
	
	/*!
	 *\brief Usuwa element z zadanego miejsca listy
	 *
	 * Jeśli usunięcie następuje w środku listy, następujące po usuwanym elementy są przesuwane
	 * o jedną pozycję wcześniej.
	 * \retval T Usunięty element
	 */
	virtual T remove(int) = 0;
	
	/*!
	 *\brief Sprawdza, czy lista jest pusta
	 *\retval 0 gdy niepusta
	 *\retval 1 gdy pusta
	 */
	virtual bool isEmpty(void) = 0;
	
	/*!
	 *\brief Zwraca element z zadanego miejsca bez usunięcia
	 *\retval T element w zadanym miejscu
	 */
	virtual T get(int) = 0;
	
	/*!
	 *\brief Zwraca ilość elementów w liście
	 *\retval int ilość elementów
	 */
	virtual int size(void) = 0;
	
	/*!
	 *\brief Destruktor wirtualny interfejsu ILista
	 */
	virtual ~ILista() {}
};

/*!
 *\brief Klasa lista
 *
 * Modeluje pojęcie listy
 */
template <class T>
class Lista : public ILista<T>{
private:
	Itabn<T> * tablica/* = new tabn<T>*/;
public:
	/*!
	 *\brief Konstruktor tablicy obsługującej listę
	 */
	Lista () : tablica (new tabn<T>) {}
	
	/*!
	 *\brief Dodaje element do zadanego miejsca listy
	 *
	 * Jeśli następuje próba dodania elementu w miejscu istniejącego, następuje przesunięcie następujących po nim
	 * elementów na następne pozycje
	 */
	virtual void add (T,int);
	
	/*!
	 *\brief Usuwa element z zadanego miejsca listy
	 *
	 * Jeśli usunięcie następuje w środku listy, następujące po usuwanym elementy są przesuwane
	 * o jedną pozycję wcześniej.
	 * \retval T Usunięty element
	 */
	virtual T remove (int position);
	
	/*!
	 *\brief Sprawdza, czy lista jest pusta
	 *\retval 0 gdy niepusta
	 *\retval 1 gdy pusta
	 */
	virtual bool isEmpty (void);
	
	/*!
	 *\brief Zwraca element z zadanego miejsca bez usunięcia
	 *\retval T element w zadanym miejscu
	 */
	virtual T get (int position);
	
	/*!
	 *\brief Zwraca ilość elementów w liście
	 *\retval int ilość elementów
	 */
	virtual int size (void);
	
	/*!
	 *\brief Destruktor Listy
	 */
	virtual ~Lista () {
		delete tablica;
	}
};

template <class T>
void Lista<T>::add(T element, int position) {
		tablica->add(element,position);
}

template <class T>
T Lista<T>::remove(int position) {
	T toRet = get(position);
	tablica->remove(position);
	return toRet;
}

template <class T>
bool Lista<T>::isEmpty(void) {
		return tablica->isEmpty();
}

template <class T>
T Lista<T>::get(int position) {
	T toRet;
	try {
		toRet = tablica->show(position);
	}
	catch (string ex) {
		cout << "Exception: " << ex << endl;
		cout << "Proba dostepu do elementu na nieistniejacej pozycji o indeksie " << position << ". Stop." << endl;;
		//Aby zapobiec zwracaniu niewłaściwej wartości, program zostanie zakończony.
		delete tablica;
		exit(-1);
		
	}
	return toRet;
}

template <class T>
int Lista<T>::size(void) {
	return tablica->nOE();
}


#endif
