#ifndef _STOS_HH
#define _STOS_HH

template <class T>
class IStos {
	virtual void push(int) = 0;
	virtual void pull(void) = 0;
	virtual bool isEmpty(void) = 0;
	virtual T showTop(void) = 0;
};

#endif
