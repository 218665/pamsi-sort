#include "../inc/tabl.hh"

void tabn::add_elem_last(int elem) {
		 if (size <SIZE) {
		 	tab[size++] = elem; 
		 }
		 else if(size >= SIZE) {
		 	int* nowy = new int[size+1];
		 	for (int i=0; i<=(size-1); i++) {
		 		nowy[i] = tab[i];
		 	}		 	
		 	nowy[size] = elem;
		 	size++;
		 	delete [] tab;
		 	tab = nowy;
		 }
	}
	
void tabn::show_elems (void) {
		for (int i=0; i<size; i++) {
			cout << tab[i] << " ";
		}
		cout << endl;
	}
	
