#ifndef _RUN_HH
#define _RUN_HH

/*!
 *\file
 *\brief Plik definiuje interfejs IRunnable, ujednolicający
 * klasy umożliwiające badanie algorytmów.
 */
#include <iostream>


using namespace std;

/*!
 * \brief Interfejs ujednolicający sposób uruchamiania klasy badającej
 * algorytm
 */
class IRunnable {
public:
	/*!
	 * \brief Przygotowanie badań
	 *
	 *\retval true zawsze 
	 */
	virtual bool prepare (int) = 0;
	
	/*!
	 * \brief Przeprowadzanie badań
	 *
	 *\retval true zawsze
	 */
	virtual bool run () = 0;
	
	/*!
	 * \brief Destruktor wirtualny IRunnable.
	 */
	virtual ~IRunnable () {}
	
};




#endif
