#include <iostream>
#include "bst.h"

using namespace std;
typedef int T1;
int main()
{
  CBinaryTree<T1>(obj);

  T1 x=20, y=18, z=15,k=19, a=30, b=25, c=39;

  obj.insert(x);
  //cout<<"prueba 1"<<endl;
  obj.insert(y);
  //cout<<"prueba 2"<<endl;
  obj.insert(z);
  //cout<<"prueba 3"<<endl;
  obj.insert(k);
  //cout<<"prueba 4"<<endl;
  obj.insert(a);
  //cout<<"prueba 5"<<endl;
  obj.insert(b);
  //cout<<"prueba 6"<<endl;
  obj.insert(c);
  //cout<<"prueba 7"<<endl;

  obj.printbase();

   return 0;
}
