#ifndef _STARTER_HH
#define _STARTER_HH

/*!
 *\file
 *\brief Plik definiuje klasę Starter
 */
#include "stoper.hh"
#include "run.hh"
#include "tabl.hh"
#include "lista.hh"
#include <fstream>

/*!
 *\brief Klasa pozwala na przeprowadzenie testów
 *
 */
class Starter {
private:
	IRunnable * runner;
	IStoper * stoper;
	unsigned int testSizeToDump;
public:
	
	/*!
	 * \brief Konstruktor klasy tabn.
	 */
	Starter () : runner(new lista_test), stoper(new Stoper) {
	}
	
	/*!
	 * \brief Destruktor klasy tabn.
	 */
	virtual ~Starter () {
		delete runner;
		delete stoper;
	}
	
	/*!
	 * \brief Metoda ustawia wielkość testu
	 *
	 *\param testsize - wielkość testu
	 */
	void setTestSize(unsigned int);
	
	/*!
	 * \brief Metoda wyświetla czas trwania testu 
	 * na standardowym wyjściu.
	 */
	void printResults(void);
	
	/*!
	 * \brief Metoda przeprowadza test
	 */
	void test (void);
	
	/*!
	 * \brief Metoda dopisuje dane do pliku
	 *
	 * Format zapisu:
	 * wielkość_testu czas_trwania_ms
	 *
	 *\param nameOfFile - nazwa pliku wyjściowego
	 */
	void dumpToFile (string);
};

#endif
