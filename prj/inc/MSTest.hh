#ifndef MSTEST_HH
#define MSTEST_HH
#include "run.hh"
#include "tabl.hh"
#include <iostream>
class MSTest: public IRunnable 
{
private:
  tabn<int> Tablica;
  void mergeSort(int left, int right);
  bool isCorrect();
  void merge(int, int, int);
public:
  virtual bool prepare (int size);
  virtual bool run ();
  void wypisz();
};

#endif 
