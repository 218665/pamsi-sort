#include <fstream>
#include "../inc/stoper.hh"


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

void Stoper::dumpToFile (string filename) {
	fstream file;
	string result;
	file.open(filename, ios::app);
	result = to_string(getElapsedTimeMs());
	if (file.good()) {
		file << result << endl;
	}
	file.close();
}
