#ifndef _RUN_HH
#define _RUN_HH
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;



class Stoper {
private:
	chrono::time_point<chrono::high_resolution_clock> begin, end;
	chrono::duration<long double> work_time;
public:
	void start(void) {
		begin = chrono::high_resolution_clock::now();
	}
	void stop(void) {
		end = chrono::high_resolution_clock::now();
	}
	long double getElapsedTimeMs(void) {
		work_time = end - begin;
		return work_time.count()*1000;
	}
	void dumpToFile();
};

class IRunnable {
protected:
	
public:
	virtual bool run () = 0;
	virtual bool prepare () = 0;

};


class Sedzia: public IRunnable{
private:
	Stoper stoper;
	
public:
	
	
};



#endif
