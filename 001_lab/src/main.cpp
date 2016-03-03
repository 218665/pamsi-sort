#include <iostream>
//#include <fstream>
#include "../inc/tabl.hh"
#include "../inc/main.hh"
using namespace std;


int main (void) {
	
	tabn tablica_dynamiczna;
	int liczba = 0;
	
//	cin >> liczba;
	while (!cin.eof()) {
		cin >> liczba;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			tablica_dynamiczna.add_elem_last(liczba);
			}
	}
//	Usunąć przed sprawdzaniem dla >10
//	tablica_dynamiczna.show_elems();
	cout << "SIZE: " << tablica_dynamiczna.tabl_size() << endl;
}
