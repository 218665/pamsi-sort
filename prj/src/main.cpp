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
//	Starter sedzia;
//	sedzia.setTestSize(100);
//	sedzia.test();
//	sedzia.printResults();
//	sedzia.dumpToFile("przeszukiwanie");

//test bubblesort
	Itabn<int> * tablica = new tabn<int>;
	tablica->add(7);
	tablica->add(4);
	tablica->add(1);
	tablica->add(9);
	tablica->add(10);
	tablica->add(94);
	tablica->add(4);
	tablica->add(5);
	tablica->add(15);
	tablica->add(8);
	tablica->add(9);
	tablica->showElems();
	tablica->bubblesort();
	tablica->showElems();
}


