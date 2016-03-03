#ifndef _TABL_HH
#define _TABL_HH
#include <iostream>

#define SIZE 10

using namespace std;

class tabn {
private:
	int* tab;
	int size;
public:
	tabn() {
		size = 0;
		tab = new int[SIZE];
	}
	~tabn() {
		delete [] tab;
	}
	
	void add_elem_last(int);
	void show_elems(void);
	int tabl_size(void) {
		return size;
	}
};
#endif
