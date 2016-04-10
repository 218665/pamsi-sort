#include "../inc/QSTest.hh"
#define MAX 100000
using namespace std;
bool QSTest::prepare (int size)
{
  if(isCorrect()) cout<<"<- Correct!"<<endl;
  else cout<<"<- Uncorrect!"<<endl;
  while(!Tablica.isEmpty())
    Tablica.remove();
  for(int i=0; i< size; ++i)
    //Tablica.add(rand()%MAX);
    Tablica.add(3);
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
    std::cout<<Tablica[i]<<" " ;
  std::cout<<std::endl;
}

void QSTest::quickSort(int left, int right)
{
  while(left < right){
    int  i = podzielTablice(left, right);
    if((i-left) <= (right-i)){ 
    quickSort(left, i-1);
    left=i+1;
    }
    else{
    quickSort(i+1, right);
    right=i-1;
    }
  }
}

int QSTest::podzielTablice(int left, int right)
{
  int indeksPodzialu;
  int wartoscPodzialu;
  try
    {
   indeksPodzialu = punktPodzialu(left, right);
   wartoscPodzialu = Tablica[indeksPodzialu];
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
  //return left+(right-left)/2;
  //return left;
  return (rand()%(right-left)+left);
}

void QSTest::zamien(int i1, int i2)
{
  int aux = Tablica[i2];
  Tablica[i2]=Tablica[i1];
  Tablica[i1]=aux;
}


bool QSTest::isCorrect()
{
  for (int i=0; i<Tablica.nOE()-1; ++i )
    {
      if (Tablica[i]>Tablica[i+1]) return false;
    }
  return true;
}
