#ifndef _KOLEJKA_HH
#define _KOLEJKA_HH

template <class T>
class IKolejka {
	virtual void enqueue(int) = 0;
	virtual void dequeue(void) = 0;
	virtual bool isEmpty(void) = 0;
	virtual T showBack(void) = 0;
};

#endif
