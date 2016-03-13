#ifndef _RUN_HH
#define _RUN_HH

/*!
 *\file
 *\brief Plik definiuje klasę Runnable, ujednolicającą
 * klasy umożliwiające badanie algorytmów.
 */
#include <iostream>


using namespace std;

/*!
 * \brief Klasa ujednolica sposób uruchamiania klasy badającej
 * algorytm
 */
class Runnable {
public:
	/*!
	 * \brief Przygotowuje badania
	 *
	 *\retval Zawsze true
	 */
	virtual bool prepare (unsigned int) = 0;
	
	/*!
	 * \brief Przeprowadza badania
	 *
	 *\retval Zawsze true
	 */
	virtual bool run () = 0;
	
	/*!
	 * \brief Destruktor wirtualny klasy Runnable.
	 */
	virtual ~Runnable () {}
	
	/*!
	 * \brief Metoda ustawia punkt startowy generatora
	 * pseudolosowego.
	 */
	void seedSrand (void);
	
	/*!
	 * \brief Metoda generuje liczbę pseudolosową z zakresu 0..9
	 *
	 *\retval Liczba pseudolosowa z zakresu 0..9
	 */
	int generateRandomDgt(void);
};




#endif
