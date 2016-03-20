/*!
 *\file
 *\brief Główny plik programu
 */

#include <iostream>
#include <chrono>
#include <ctime>
//#include "../inc/main.hh"
#include "../inc/tabl.hh"
#include "../inc/run.hh"
#include "../inc/starter.hh"
#include "../inc/stoper.hh"
using namespace std;



int main (void) {
//	for (unsigned int i = 0; i < 10; i++) {
//		Starter sedzia;
//		sedzia.setTestSize(1000);
//		sedzia.test();
//		sedzia.printResults();
//		//sedzia.dumpToFile("test_twice_100");	
//	}
	
Itabn<string>* table = new tabn<string>;
cout << "noe" << table->nOE() << endl;
cout << "siz" << table->aSize() << endl;
table->add("hello");
cout << "noe" << table->nOE() << endl;
cout << "siz" << table->aSize() << endl;
table->showElems();
table->add("My");
cout << "noe" << table->nOE() << endl;
cout << "siz" << table->aSize() << endl;
table->showElems();
cout << "adding name\n";
table->add("name",1);
cout << "noe" << table->nOE() << endl;
cout << "siz" << table->aSize() << endl;
table->showElems();
cout << "removing name\n";
table->remove(1);
cout << "noe" << table->nOE() << endl;
cout << "siz" << table->aSize() << endl;
table->showElems();
for(int i=0;i<15;i++) {
	table->add("a",0);
	table->showElems();
	}
cout << "noe" << table->nOE() << endl;
cout << "siz" << table->aSize() << endl;
for(int i=0;i<15;i++) {
	table->remove(0);
	table->showElems();
	}
cout << "noe" << table->nOE() << endl;
cout << "siz" << table->aSize() << endl;
table->showElems();
}
