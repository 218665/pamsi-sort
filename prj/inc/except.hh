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
public:
	std::string cause;

	Exception() {}
	
    Exception(std::string description) : cause(description) {
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
	std::string cause;
private:
	//CriticalException() {}
public:
	CriticalException(std::string description) : cause(description) {
    }
    
    std::string getError() {
    	return cause;
    }
};

/*!
 *\brief Wyjątek, który mimo pojawienia się, pozwala na dalsze poprawne działanie programu
 */
 class ContinueException : public Exception {
 public:
	std::string cause;
 private:
 	//ContinueException() {}
 public:
 	ContinueException(std::string description) : cause(description) {
    }
    
    std::string getError() {
    	return cause;
    }
 };


#endif
