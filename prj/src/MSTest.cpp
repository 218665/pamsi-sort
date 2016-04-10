#include "../inc/MSTest.hh"
#define MAX 100000
using namespace std;
bool MSTest::prepare (int size)
{
  if(isCorrect()) cout<<"<- Correct!"<<endl;
  else cout<<"<- Uncorrect!"<<endl;
  while(!Tablica.isEmpty())
    Tablica.remove();
  for(int i=0; i< size; ++i)
    Tablica.add(rand()%MAX);
    //Tablica.add(i);
  return true;
}

bool MSTest::run()
{
  int left = 0;
  int right = Tablica.nOE()-1;
  mergeSort(left,right);
  return true;
}
void MSTest::wypisz()
{
  for (int i=0; i<Tablica.nOE(); ++i)
    std::cout<<Tablica[i]<<" " ;
  std::cout<<std::endl;
}
bool MSTest::isCorrect()
{
  for (int i=0; i<Tablica.nOE()-1; ++i )
    {
      if (Tablica[i]>Tablica[i+1]) return false;
    }
  return true;
}

void MSTest::mergeSort(int left, int right)
{
  if(right > left)
    {
      int q=(left+right)/2;
      mergeSort(left, q);
      mergeSort(q+1, right);
      merge(left, q, right);
    }
}

void MSTest::merge(int left, int mid, int right)
{
  
  int i, j, q;
  tabn<int> TablicaPomocnicza;
  for( i=left; i<=right; ++i) TablicaPomocnicza.add(Tablica[i]);
  i=left; j=mid+1; q=left;
  while (i<=mid && j<=right) {
    if (TablicaPomocnicza[i-left]<TablicaPomocnicza[j-left])
      Tablica[q++]=TablicaPomocnicza[(i++)-left];
    else
      Tablica[q++]=TablicaPomocnicza[(j++)-left];
  }
  while (i<=mid) Tablica[q++]=TablicaPomocnicza[(i++)-left]; 

}
