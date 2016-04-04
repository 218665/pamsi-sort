#include "../inc/QSTest.hh"
#define MAX 1000
bool QSTest::prepare (int size)
{
  for(int i=0; i< size; ++i)
    Tablica.add(rand()%MAX);
  return true;
}

bool QSTest::run()
{
  int left = 0;
  int right = Tablica.nOE()-1;
    quickSort(left,right);
  return true;
}

void QSTest::wypisz()
{
  for (int i=0; i<Tablica.nOE(); ++i)
    std::cout<<Tablica.show(i)<<" " ;
  std::cout<<std::endl;
}

void QSTest::quickSort(int left, int right)
{
  if(left < right){
    int  i = podzielTablice(left, right);
    quickSort(left, i-1);
    quickSort(i+1, right);
  }
}

int QSTest::podzielTablice(int left, int right)
{
  int indeksPodzialu;
  int wartoscPodzialu;
  try
    {
   indeksPodzialu = punktPodzialu(left, right);
   wartoscPodzialu = Tablica.show(indeksPodzialu);
   zamien(indeksPodzialu, right);
    }
  catch(CriticalException)
    {
      std::cout<< ""<<std::endl;
      exit(-1);
    }
  int  aktualnaPozycja =left;
  for(int i = left; i <= right-1; ++i){
    if (Tablica[i] < wartoscPodzialu)
      {
	zamien(i, aktualnaPozycja);
	++aktualnaPozycja;
      }
  }
  zamien(aktualnaPozycja, right);
  return aktualnaPozycja;
}

int QSTest::punktPodzialu(int left, int right)
{
  return left+(right-left)/2;
}

void QSTest::zamien(int i1, int i2)
{
  int aux = Tablica[i1];
  Tablica[i1]=Tablica[i2];
  Tablica[i2]=aux;
}

