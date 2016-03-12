#ifndef _STOPER_HH
#define _STOPER_HH
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

/*
 * Obliczanie czasu działania fragmentu programu na podstawie przykładu:
 * http://en.cppreference.com/w/cpp/chrono
 */

/*
 * Interfejs IStoper
 * 
 *
 */
 
class IStoper {
public:
	virtual void start(void) = 0;
	virtual void stop(void) = 0;
	virtual long double getElapsedTimeMs(void) = 0;
	virtual void dumpToFile(void) = 0;
	virtual ~IStoper (){}
};

/*
 * Klasa stoper implementująca interfejs IStoper
 */
class Stoper : public IStoper{
private:
	chrono::time_point<chrono::high_resolution_clock> begin, end;
	chrono::duration<long double> work_time;
public:
	virtual void start(void) {
		begin = chrono::high_resolution_clock::now();
	}
	virtual void stop(void) {
		end = chrono::high_resolution_clock::now();
	}
	virtual long double getElapsedTimeMs(void) {
		work_time = end - begin;
		return work_time.count()*1000;
	}
	virtual void dumpToFile(void) { }
};


#endif
