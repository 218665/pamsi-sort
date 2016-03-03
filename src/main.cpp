#include <iostream>
#include "../inc/tabl.hh"
#include "../inc/main.hh"
using namespace std;


int main (void) {
	
	tabn tablica_dynamiczna;
	char selection = 'a';
	
	while (selection != 'q') {
		cin >> selection;
		switch (selection) {
			case 'a':
				int nowy_elem;
				cin >> nowy_elem;
				if (cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						//cout << "! Wrong input!" << endl;
					}
				else tablica_dynamiczna.add_elem_last(nowy_elem);
				break;
			case 's':
				tablica_dynamiczna.show_elems();
				break;
			case 'q':
				break;
			default :
				break;
			}
	}
}
