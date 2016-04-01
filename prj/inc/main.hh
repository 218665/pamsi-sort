#ifndef _MAIN_HH
#define _MAIN_HH
/*!
 * \file 
 *
 */
#include <iostream>
#include <fstream>
#include "stoper.hh"
#include "tabl.hh"
#include "run.hh"
#include "lista.hh"
#include "stos.hh"
#include "kolejka.hh"

using namespace std;
/*! \mainpage 
 *
 *	\section Dokumentacja Dokumentacja klas w repozytorium pamsi.
 *	Ten dokument zawiera dokumentację klas znajdujących się w plikach repozytorium pamsi.
 *
 * \section Przykład Przykład uruchomienia testu
 * \code
 	IRunnable * runner = new lista_test;
	IStoper * stoper = new Stoper;
	unsigned int testSize = 100;
	string outputFile = "file123";
	try {
		runner->prepare(testSize);
		stoper->start();
		runner->run();
		stoper->stop();
		printOnscreen(testSize,stoper);
		dumpToFile(outputFile,testSize,stoper);
		}
	catch (...) {
		cout << "EXCEP" << endl;
	}
	delete runner;
	delete stoper;
	\endcode
 *
 */

/*!
 *\brief Zrzuca dane wynikowe do pliku
 *
 *\param nameOfFile nazwa pliku wynikowego
 *\param testsize rozmiar testu 
 *\param stoper klasa stopera
 */
void dumpToFile (string, unsigned int, IStoper *);

/*!
 *\brief Wyświetla wynik na standardowym wyjściu
 *
 *\param testSize rozmiar testu
 *\param stoper klasa stopera
 */
void printOnscreen (unsigned int, IStoper *);


#endif
