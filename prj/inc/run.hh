#ifndef _RUN_HH
#define _RUN_HH

/*!
 *\file
 *\brief Plik definiuje interfejs IRunnable, ujednolicający
 * klasy umożliwiające badanie algorytmów.
 */
#include <iostream>


/*!
 * \brief Interfejs ujednolicający sposób uruchamiania klasy badającej
 * algorytm
 */
class IRunnable {
public:
	/*!
	 * \brief Przygotowanie badań
	 */
	virtual bool prepare (int) = 0;
	
	/*!
	 * \brief Przeprowadzanie badań
	 */
	virtual bool run () = 0;
	
	/*!
	 * \brief Destruktor wirtualny IRunnable.
	 */
	virtual ~IRunnable () {}
	
};




#endif
