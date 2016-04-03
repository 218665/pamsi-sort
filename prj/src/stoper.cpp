#include "../inc/stoper.hh"
using namespace std;

void Stoper::start(void) {
	begin = chrono::high_resolution_clock::now();
}

void Stoper::stop(void) {
	end = chrono::high_resolution_clock::now();
}

long double Stoper::getElapsedTimeMs(void) {
	work_time = end - begin;
	return work_time.count()*1000;
}

