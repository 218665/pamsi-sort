#ifndef _KOLEJKA_HH
#define _KOLEJKA_HH
/*!
 *\file Plik definiuje typ danych kolejka
 *
 */
 #include "tabl.hh"


/*!
 *\brief Interfejs klasy Kolejka
 * Definiuje operacje dostępne dla klasy Kolejka
 */
template <class T>
class IKolejka {
public:
	/*!
	 *\brief Dodaje element na koniec kolejki
	 *
	 *\param element - element do umieszczenia w kolejce
	 */
	virtual void enqueue(T) = 0;
	
	/*!
	 *\brief Usuwa i zwraca element z początku kolejki
	 *\retval T element z początku kolejki
	 */
	virtual T dequeue(void) = 0;
	
	/*!
	 *\brief Sprawdza, czy kolejka nie jest pusta
	 *\retval 0 gdy niepusta
	 *\retval 1 gdy pusta
	 */
	virtual bool isEmpty(void) = 0;
	
	/*!
	 *\brief Zwraca element z początku kolejki bez usuwania
	 *\warning Uwaga! Próba podglądu elementu z pustej kolejki spowoduje wyrzucenie wyjątku, zamknięcie programu i zwrócenie -1. 
	 *\warning Sprawdź dokumentację metody Kolejka<T>::get(void).
	 */
	virtual T get(void) = 0;
	
	/*!
	 *\brief Destruktor wirtualny interfejsu
	 */
	virtual ~IKolejka() {}
};

/*!
 *\brief Klasa modeluje kolejkę
 */
template <class T>
class Kolejka : public IKolejka<T>{
private:
	Itabn<T> * tablica/* = new tabn<T>*/;
public:
	/*!
	 *\brief Konstruktor tablicy obsługującej kolejkę
	 */
	Kolejka() : tablica (new tabn<T>) {}
	
	/*!
	 *\brief Dodaje element na koniec kolejki
	 *
	 *\param element - element do umieszczenia w kolejce
	 */
	virtual void enqueue(T);
	
	/*!
	 *\brief Usuwa i zwraca element z początku kolejki
	 *\retval T element z początku kolejki
	 */
	virtual T dequeue(void);
	
	/*!
	 *\brief Sprawdza, czy kolejka nie jest pusta
	 *\retval 0 gdy niepusta
	 *\retval 1 gdy pusta
	 */
	virtual bool isEmpty(void);
	
	/*!
	 *\brief Zwraca element z początku kolejki bez usuwania
	 *
	 *\warning Uwaga! Próba odczytania elementu z pustej kolejki spowoduje wyrzucenie wyjątku, zamknięcie programu i zwrócenie -1. 
	 *\warning Aby zapewnić poprawne działanie, sprawdź najpierw, czy kolejka nie jest pusta i uwarunkuj od tego wykonanie funkcji get().
	 *\warning Przykład:
	 *\code{.cpp}
	 	//Przykład korzystania z get()
	 	IKolejka<int> * kolejka = new Kolejka<int>;
	 	if (kolejka->isEmpty() == false) {
			cout << kolejka->get() << endl;
			}
		else
			cerr << "Kolejka pusta" << endl;
		\endcode
	 */
	virtual T get(void);
	
	/*!
	 *\brief Destruktor klasy Kolejka
	 */
	virtual ~Kolejka() {
		delete tablica;
	}
};

template <class T>
void Kolejka<T>::enqueue(T element) {
	tablica->add(element,(tablica->nOE()));
}


template <class T>
T Kolejka<T>::dequeue(void) {
	T toRet = get();
	tablica->remove(0);
	return toRet;
}

template <class T>
bool Kolejka<T>::isEmpty(void) {
	return tablica->isEmpty();
}

template <class T>
T Kolejka<T>::get(void) {
	T toRet;
	try {
		toRet = tablica->show(0);
	}
	catch (std::string ex) {
		std::cout << "Exception: " << ex << std::endl;
		std::cout << "Kolejka pusta. Aby zapobiec zwracaniu niewłaściwej wartości, program zostanie zakończony." << std::endl;
		delete tablica;
		exit(-1);
	}
	return toRet;
}











#endif
