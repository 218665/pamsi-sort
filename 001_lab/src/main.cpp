/*!
 *\file
 *\brief Główny plik programu
 */

#include <iostream>
#include <chrono>
#include <ctime>
#include "../inc/main.hh"
#include "../inc/tabl.hh"
#include "../inc/run.hh"
#include "../inc/starter.hh"
#include "../inc/stoper.hh"
using namespace std;

// Zmień wartość, aby zmienić sposób rozszerzania tablicy:
// one 		- rozszerzaj o jeden element
// twice 	- rozszerzaj dwukrotnie
// onehalf 	- rozszerzaj 1,5 razy
// Można redefiniować przy kolejnych testach.
expandType typeOfExp = twice;


int main (void) {
	for (unsigned int i = 0; i < 10; i++) {
		Starter sedzia;
		sedzia.setTestSize(100);
		sedzia.test();
		sedzia.printResults();
		sedzia.dumpToFile("test_twice_100");	
	}
	
}
