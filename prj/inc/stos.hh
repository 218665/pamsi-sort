#ifndef _STOS_HH
#define _STOS_HH

/*!
 *\file Plik definiuje typ danych stos
 *
 */

 /*!
  *\brief Interfejs stosu
  *
  * Definiuje dostępne operacje na klasie Stos
  */
template <class T>
class IStos {

	
	virtual void push(T) = 0;
	virtual T pull(void) = 0;
	virtual bool isEmpty(void) = 0;
	virtual T showTop(void) = 0;
	virtual ~IStos(){}
};

class Stos {
private:

public:
};

#endif
