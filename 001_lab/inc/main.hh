#ifndef _MAIN_HH
#define _MAIN_HH
/*!
 * \file
 * \brief Plik posiada wspólne definicje
 *
 */


/*!
 * \brief Typ wyliczeniowy decydujący o sposobie rozszerzania
 * tablicy dynamicznej 
 *
 */
enum expandType {one, twice, onehalf}; 

/*!
 * \brief Decyduje o typie rozszerzania tablicy
 *
 * Zdefiniuj zmienną expandType w main, aby zmienić tryb rozszerzania
 * tablicy w funkcji tabn.
 *
 * Nie jest to idealne rozwiązanie, ale każda klasa implementująca
 * interfejs IRunnable może być inna. Musi także istnieć możliwość 
 * wyboru trybu rozszerzania tablicy. Stworzenie oddzielnych klas 
 * tabn dla każdego trybu oddzielnie znacznie zwiększa rozmiary kodu
 * i komplikuje go. Obecne obejście:
 * + Nie powoduje konieczności zmiany IRunnable zależnie od
 *   badanej funkcji
 * + Nie wymusza tworzenia trzech oddzielnych klas dla każdego trybu,
 *   następnie stworzenia trzech klas tabn_test itd.
 * - Wymaga jedynie od użytkownika użycia dodatkowej definicji.
 * Bardzo proszę o kontakt, jeśli można to rozwiązać lepiej. 
 */
extern expandType typeOfExp;


#endif
