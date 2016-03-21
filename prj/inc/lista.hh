#ifndef _LISTA_HH
#define _LISTA_HH

/*!
 *\file Plik definiuje typ danych lista
 *
 */
#include "tabl.hh"
#include "main.hh"
#include <fstream>
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
	 * \note Próba dodania elementu na miejsce dalsze niż pierwsze następujące po obecnie istniejącym spowoduje wyrzucenie wyjątku i niewykonanie akcji.
	 */
	virtual void add(T, int) = 0;
	
	/*!
	 *\brief Dodaje element na koniec listy
	 */
	virtual void add(T)=0;
	
	/*!
	 *\brief Usuwa element z zadanego miejsca listy
	 *
	 * Jeśli usunięcie następuje w środku listy, następujące po usuwanym elementy są przesuwane
	 * o jedną pozycję wcześniej.
	 * \retval T Usunięty element
	 * \warning Próba usunięcia elementu nieistniejącego lub z pustej listy spowoduje wyrzucenie wyjątku, zakończenie programu
	 * \warning i zwrócenie -1.
	 * \warning Sprawdź dokumentację metody Lista<T>::remove(int).
	 */
	virtual T remove(int) = 0;
	
	/*!
	 *\brief Usuwa element z końca listy
	 */
	virtual T remove(void) = 0;
	
	/*!
	 *\brief Sprawdza, czy lista jest pusta
	 *\retval 0 gdy niepusta
	 *\retval 1 gdy pusta
	 */
	virtual bool isEmpty(void) = 0;
	
	/*!
	 *\brief Zwraca element z zadanego miejsca bez usunięcia
	 *\retval T element w zadanym miejscu
	 * \warning Próba podglądu elementu nieistniejącego spowoduje wyrzucenie wyjątku, zakończenie programu
	 * \warning i zwrócenie -1.
	 * \warning Sprawdź dokumentację metody Lista<T>::get(int).
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
	 * \note Próba dodania elementu na miejsce dalsze niż pierwsze następujące po obecnie istniejącym spowoduje wyrzucenie wyjątku i niewykonanie akcji.
	 */
	virtual void add (T,int);
	
	/*!
	 *\brief Dodaje element na koniec listy
	 */
	virtual void add(T);
	
	/*!
	 *\brief Usuwa element z zadanego miejsca listy
	 *
	 * Jeśli usunięcie następuje w środku listy, następujące po usuwanym elementy są przesuwane
	 * o jedną pozycję wcześniej.
	 * \retval T Usunięty element
	 * \warning Próba usunięcia elementu nieistniejącego lub z pustej listy spowoduje wyrzucenie wyjątku, zakończenie programu
	 * \warning i zwrócenie -1. Najpierw sprawdź, czy dany element istnieje a następnie usuń element.
	 * \warning
	 	\code{.cpp}
	 	//Przykład sprawdzenia poprawności usuwania
	 	ILista<int> * list = new Lista<int>;
	 	list->add(2); //skomentuj odpowiednio linię aby sprawdzić działanie obu przypadków
	 	int positionToCheckAndRemove = 0;
	 	if(list->size()>positionToCheckAndRemove) {
	 		list->remove(positionToCheckAndRemove);
	 	}
	 	else
	 		cerr << "Element nie istnieje!" << endl;
	 	\endcode
	 */
	virtual T remove (int position);
	
	/*!
	 *\brief Usuwa element z końca listy
	 */
	virtual T remove(void);
	
	/*!
	 *\brief Sprawdza, czy lista jest pusta
	 *\retval 0 gdy niepusta
	 *\retval 1 gdy pusta
	 */
	virtual bool isEmpty (void);
	
	/*!
	 *\brief Zwraca element z zadanego miejsca bez usunięcia
	 *\retval T element w zadanym miejscu
	 * \warning Próba podglądu elementu nieistniejącego spowoduje wyrzucenie wyjątku, zakończenie programu
	 * \warning i zwrócenie -1. Najpierw sprawdź, czy dany element istnieje.
	 * \warning
	 	\code{.cpp}
	 	//Przykład sprawdzenia poprawności podglądu
	 	ILista<int> * list = new Lista<int>;
	 	list->add(2); //skomentuj odpowiednio linię aby sprawdzić działanie obu przypadków
	 	int positionToCheckAndShow = 0;
	 	if(list->size()>positionToCheckAndShow) {
	 		cout << list->get(positionToCheckAndShow) << endl;
	 	}
	 	else
	 		cerr << "Element nie istnieje!" << endl;
	 	\endcode
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
void Lista<T>::add(T element) {
	tablica->add(element);
}

template <class T>
T Lista<T>::remove(int position) {
	T toRet = get(position);
	tablica->remove(position);
	return toRet;
}

template <class T>
T Lista<T>::remove(void) {
	T toRet = get((tablica->nOE())-1);
	tablica->remove((tablica->nOE())-1);
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
		cout << "Proba dostepu do elementu na nieistniejacej pozycji o indeksie " << position << ". Aby zapobiec zwracaniu niewłaściwej wartości, program zostanie zakończony." << endl;;
		delete tablica;
		exit(-1);
		
	}
	return toRet;
}

template <class T>
int Lista<T>::size(void) {
	return tablica->nOE();
}











//------------------------------------------------------------------------------

/*! \brief Definiuje sposób testowania wypełniania listy
 *
 */
class lista_test : public IRunnable  {
private:
	ILista<string> * test;
	int counter = 0;
	fstream plik;
	string wordToSearch;
public:
	
	/*!
	 *\brief Konstruktor klasy testującej
	 */
	lista_test () : test(new Lista<string>) {
	}
	
	/*!
	 *\brief Destruktor klasy testującej
	 */
	~lista_test () {
		plik.close();
		delete test;
	}
	
private:

	/*!
	 *\brief Porównywanie słów
	 */
	bool wordSearch(string word) {
		int i = 0;
		while(i<counter) {
		 	if(test->get(i) == word) {
		 		//cout << "Word found at position " << i <<endl;
		 		return true;
		 	}
		 	i+=1;
		}
		//cout << "Word not found"<< endl << endl;
		return false;
	}

public:
	/*!
 	 * \brief Przygotowuje rozmiar testu
 	 *
 	 * \param sizeOfTest - rozmiar testu
 	 * \retval true gdy plik ze słownikiem został pomyślnie otwarty
 	 * \retval false gdy otwieranie pliku zakończyło się błędem
	 */
	virtual bool prepare(int sizeOfTest) {
		counter = sizeOfTest;
		int i = 0;
		string word;
		wordToSearch = "reminder";
		plik.open("dictionary",ios::in);
		if (plik.good() == true) {
			while (plik >> word || i<sizeOfTest) {
				test->add(word);
				i+=1;
			}
			//cout << "FND at: " << i << endl;
			return true;
		}
		else
			return false;
		
	}
	
	/*!
 	 * \brief Wykonuje test
 	 *
 	 * Pozwala na wykonanie testu.
 	 *
 	 * \retval true zawsze
	 */
	virtual bool run() {
		wordSearch(wordToSearch);
		return true;
	}
	
};

#endif
