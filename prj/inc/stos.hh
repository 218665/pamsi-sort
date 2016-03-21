#ifndef _STOS_HH
#define _STOS_HH

/*!
 *\file Plik definiuje typ danych stos
 *
 */
 #include "tabl.hh"
 using namespace std;

 /*!
  *\brief Interfejs stosu
  *
  * Definiuje dostępne operacje na klasie Stos
  */
template <class T>
class IStos {
public:
	/*!
	 *\brief Umieszcza element na szczycie stosu
	 *
	 * \param element - element do umieszczenia na stosie
	 */
	virtual void push(T) = 0;
	
	/*!
	 *\brief Zdejmuje element ze szczytu stosu
	 *
	 * \retval T element ze szczytu stosu
	 *\warning Uwaga! Próba zdjęcia elementu z pustego stosu spowoduje wyrzucenie wyjątku, zamknięcie programu i zwrócenie -1. 
	 *\warning Sprawdź dokumentację metody Stos<T>::pull(void).
	 */
	virtual T pull(void) = 0;
	
	/*!
	 *\brief Sprawdza, czy stos jest pusty
	 *\retval 0 gdy niepusty
	 *\retval 1 gdy pusty
	 */
	virtual bool isEmpty(void) = 0;
	
	/*!
	 *\brief Zwraca element ze szczytu stosu bez jego usuwania
	 *
	 *\retval T element ze szczytu stosu
	 *\warning Uwaga! Próba odczytania elementu z pustego stosu spowoduje wyrzucenie wyjątku, zamknięcie programu i zwrócenie -1. 
	 *\warning Sprawdź dokumentację metody Stos<T>::get(void).
	 */
	virtual T get(void) = 0;
	
	/*!
	 *\brief Destruktor wirtualny IStos
	 */
	virtual ~IStos(){}
};


/*!
 *\brief Klasa Stos
 *
 * Modeluje pojęcie stosu
 */
template <class T>
class Stos : public IStos<T> {
private:
	Itabn<T> * tablica/* = new tabn<T>*/;
public:
	/*!
	 *\brief Konstruktor tablicy obsługującej stos
	 */
	Stos() : tablica (new tabn<T>) {}
	
	/*!
	 *\brief Umieszcza element na szczycie stosu
	 *
	 * \param element - element do umieszczenia na stosie
	 */
	virtual void push(T);
	
	/*!
	 *\brief Zdejmuje element ze szczytu stosu
	 *
	 * \retval T element ze szczytu stosu
	 *\warning Uwaga! Próba zdjęcia elementu z pustego stosu spowoduje wyrzucenie wyjątku, zamknięcie programu i zwrócenie -1. 
	 *\warning Aby zapewnić poprawne działanie, sprawdź najpierw, czy stos nie jest pusty i uwarunkuj od tego wykonanie funkcji pull().
	 *\warning Przykład:
	 *\code{.cpp}
	 	//Przykład korzystania z get()
	 	IStos<int> * stos = new Stos<int>;
	 	if (stos->isEmpty() == false) {
			cout << stos->pull() << endl;
			}
		else
			cerr << "Stos pusty" << endl;
		\endcode
	 */
	virtual T pull(void);
	
	/*!
	 *\brief Sprawdza, czy stos jest pusty
	 *\retval 0 gdy niepusty
	 *\retval 1 gdy pusty
	 */
	virtual bool isEmpty(void);
	
	/*!
	 *\brief Zwraca element ze szczytu stosu bez jego usuwania
	 *
	 *\retval T element ze szczytu stosu
	 *\warning Uwaga! Próba odczytania elementu z pustego stosu spowoduje wyrzucenie wyjątku, zamknięcie programu i zwrócenie -1. 
	 *\warning Aby zapewnić poprawne działanie, sprawdź najpierw, czy stos nie jest pusty i uwarunkuj od tego wykonanie funkcji get().
	 *\warning Przykład:
	 *\code{.cpp}
	 	//Przykład korzystania z get()
	 	IStos<int> * stos = new Stos<int>;
	 	if (stos->isEmpty() == false) {
			cout << stos->get() << endl;
			}
		else
			cerr << "Stos pusty" << endl;
		\endcode
	 */
	virtual T get(void);
	
	/*!
	 *\brief Destruktor stosu
	 */
	virtual ~Stos(){
		delete tablica;
	}
};

template <class T>
void Stos<T>::push(T element) {
	tablica->add(element);
}

template <class T>
T Stos<T>::pull(void) {
	T toRet = get();
	tablica->remove();
	return toRet;
}

template <class T>
bool Stos<T>::isEmpty(void) {
	return tablica->isEmpty();
}

template <class T>
T Stos<T>::get(void) {
	T toRet;
	try {
		toRet = tablica->show((tablica->nOE())-1);
	}
	catch (string ex) {
		cout << "Exception: " << ex << endl;
		cout << "Stos pusty. Aby zapobiec zwracaniu niewłaściwej wartości, program zostanie zakończony." << endl;
		delete tablica;
		exit(-1);
	}
	return toRet;
}

#endif
