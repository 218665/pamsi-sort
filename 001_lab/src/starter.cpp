#include "../inc/starter.hh"

void Starter::printResults(void) {
	cout << "-----------------------------------------------" << endl;
	cout << "Operacja wykonana w " << stoper->getElapsedTimeMs() << " ms." << endl;
}


void Starter::test (void) {
	runner->prepare(1000);
	stoper->start();
	runner->run();
	stoper->stop();
	printResults();
	stoper->dumpToFile("testfile");
	
}
	
