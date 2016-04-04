#ifndef QSTEST_HH
#define QSTEST_HH
#include "run.hh"
#include "tabl.hh"
#include <iostream>
class QSTest: public IRunnable 
{
private:
  tabn<int> Tablica;
public:
  void quickSort(int left, int right);
  int podzielTablice(int left, int right);
  int punktPodzialu(int left, int right);
  bool prepare (int size);
  bool run ();
  void wypisz();
  void zamien(int i1, int i2);
};

#endif 
