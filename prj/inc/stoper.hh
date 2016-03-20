#ifndef _STOPER_HH
#define _STOPER_HH
/*!
 * \brief Plik definiuje stoper, obliczający czas wykonywania
 * badanych funkcji.
 *
 * Obliczanie czasu działania fragmentu programu na podstawie 
 * przykładu: \url http://en.cppreference.com/w/cpp/chrono \endurl
 */

#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

/*!
 * \brief Interfejs IStoper
 * 
 */
 
class IStoper {
public:
	virtual void start(void) = 0;
	virtual void stop(void) = 0;
	virtual long double getElapsedTimeMs(void) = 0;
//	virtual void dumpToFile(string) = 0;
	virtual ~IStoper (){}
};

/*!
 * \brief Klasa stoper implementująca interfejs IStoper
 *
 * Klasa symuluje działanie stopera - zapisuje początkowy i końcowy
 * moment działania (użycie start i stop), oraz odejmuje obie te
 * wartości od siebie, by uzyskać czas działania.
 */
class Stoper : public IStoper{
private:
	chrono::time_point<chrono::high_resolution_clock> begin, end;
	chrono::duration<long double> work_time;
public:

	/*!
	 * \brief Uruchamia zegar
	 */
	virtual void start(void);
	
	/*!
	 * \brief Zatrzymuje zegar
	 */
	virtual void stop(void);
	
	/*!
	 * \brief Oblicza i zwraca czas pomiędzy uruchomieniem 
	 * zegara a jego zatrzymaniem.
	 *
	 * \retval long_double Czas pomiędzy startem a zatrzymaniem zegara
	 */
	virtual long double getElapsedTimeMs(void);

	
};


#endif
