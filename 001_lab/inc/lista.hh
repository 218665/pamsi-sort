#ifndef _LISTA_HH
#define _LISTA_HH

template <class T>
class ILista {
public:
	virtual void add(int, unsigned int) = 0;
	virtual void remove(unsigned int) = 0;
	virtual bool isEmpty(void) = 0;
	virtual void get(unsigned int) = 0;
	virtual unsigned int size(void) = 0;
};

#endif
