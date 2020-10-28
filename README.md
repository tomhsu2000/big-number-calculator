# big-number-calculatot
在C++中實現超長整數的運算
## Description
創建超長整數的class實現加減乘除餘等運算
## Getting Started
``` c++
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
```
## Roadmap
* 支援浮點數
* 開根號運算
* 次方運算
## Known Bugs
