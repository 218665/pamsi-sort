/*!
 *\file
 *\brief Główny plik programu
 */

#include <iostream>
//#include <chrono>
//#include <ctime>
#include "../inc/main.hh"
#include "../inc/tabl.hh"
#include "../inc/run.hh"
#include "../inc/starter.hh"
#include "../inc/stoper.hh"
#include "../inc/lista.hh"
#include "../inc/stos.hh"
#include "../inc/kolejka.hh"
using namespace std;



int main (void) {
	Starter sedzia;
	sedzia.setTestSize(100);
	sedzia.test();
	sedzia.printResults();
	sedzia.dumpToFile("przeszukiwanie");
}


