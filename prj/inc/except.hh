#ifndef _EXCEPT_HH
#define _EXCEPT_HH

/*!
 *\file
 *\brief Plik zawiera definicje wyjątków
 */

#include <iostream>
#include <string>
#include <exception>
/*!
 *\brief Ogólny wyjątek
 */
class Exception {
protected:
	std::string cause;

public:
    Exception(std::string description) : cause(description){
    }
    
    std::string getError() {
    	return cause;
    }
};

/*!
 *\brief Wyjątek krytyczny, wymagający zamknięcia programu
 */
class CriticalException : public Exception {
public:
	
	CriticalException() : Exception("none") {
	}
	
	CriticalException(std::string description) : Exception(description) {
    }

};

/*!
 *\brief Wyjątek, który może spowodować nieprzewidziane działanie programu, ale program mógłby dalej działać.
 */
class ContinueException : public Exception {
public:

	ContinueException() : Exception("none") {
	}
	
 	ContinueException(std::string description) : Exception(description) {
    }

 };


#endif
