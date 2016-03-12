#ifndef _STARTER_HH
#define _STARTER_HH
#include "stoper.hh"
#include "run.hh"
#include "tabl.hh"


class Starter {
private:
	IRunnable * runner;
	IStoper * stoper;
public:
	Starter () : runner(new tabn_test), stoper(new Stoper){
	}
	virtual ~Starter () {
		delete runner;
		delete stoper;
	}
	void printResults(void);
	void test (void);
	
};

#endif
