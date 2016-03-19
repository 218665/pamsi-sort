#ifndef _STOS_HH
#define _STOS_HH

/*!
 *\file Plik definiuje typ danych stos
 *
 */

template <class T>
class IStos {
	virtual void push(T) = 0;
	virtual void pull(void) = 0;
	virtual bool isEmpty(void) = 0;
	virtual T showTop(void) = 0;
	virtual ~IStos(){}
};

class Stos {
private:

public:
};

#endif
