#include <iostream>
#include <fstream>
#include "HugeInteger.h"
using namespace std;

int main()
{
    HugeInteger n1,n2;
    vector< int > v1,v2;

    char digit;
    while( (digit = cin.get()) != '\n' )
        v1.insert( v1.begin(), digit - '0' );
    
    while ( (digit = cin.get()) != '\n' )
        v2.insert( v2.begin(), digit - '0' );

    n1.assign(v1);
    n2.assign(v2);

    if( n1.isZero() )
      cout << n1 << endl;
   else
   {
      --n1;
      cout << ++n1 << endl;
   }

   cout << n2++ << endl;
   n2--;

   cout << n1 + n2 << endl;

   if( n1 < n2 )
      cout << '-' << n2 - n1 << endl;
   else
       cout << n1 - n2 << endl;
   
   cout << n1 * n2 << endl;

   if( n2.isZero() )
      cout << "DivideByZero!\n";
   else
      cout << n1 / n2 << endl;
   
   if( n2.isZero() )
      cout << "DivideByZero!\n";
   else
      cout << n1 % n2 << endl;

   cout << endl;
}