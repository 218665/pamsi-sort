#ifndef _RUN_HH
#define _RUN_HH
#include <iostream>
//#include "tabl.hh"

using namespace std;

class IRunnable {
public:
	virtual bool prepare (int) = 0;
	virtual bool run () = 0;
	virtual ~IRunnable () {}
};




#endif
