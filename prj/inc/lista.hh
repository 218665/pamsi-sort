#ifndef _LISTA_HH
#define _LISTA_HH

/*!
 *\file Plik definiuje typ danych lista
 *
 */
template <class T>
class ILista {
public:
	virtual void add(T, unsigned int) = 0;
	virtual void remove(unsigned int) = 0;
	virtual bool isEmpty(void) = 0;
	virtual T get(unsigned int) = 0;
	virtual unsigned int size(void) = 0;
	virtual ~ILista() {}
};

class Lista {
private:

public:
};

#endif
