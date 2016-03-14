#ifndef _KOLEJKA_HH
#define _KOLEJKA_HH

/*!
 *\file Plik definiuje typ danych kolejka
 *
 */

template <class T>
class IKolejka {
	virtual void enqueue(T) = 0;
	virtual void dequeue(void) = 0;
	virtual bool isEmpty(void) = 0;
	virtual T showBack(void) = 0;
	virtual ~IKolejka() {}
};

class Kolejka {
private:

public:
};

#endif
