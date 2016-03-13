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
expandType typeOfExp = one;


int main (void) {
	Starter sedzia;
	sedzia.setTestSize(1000);
	sedzia.test();
	sedzia.printResults();
	sedzia.dumpToFile("test1000");	
}
