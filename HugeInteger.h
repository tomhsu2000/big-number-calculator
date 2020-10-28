// HugeInteger class definition.
#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <vector> // include definition of class vector 

class HugeInteger
{
public:
   HugeInteger( unsigned int n = 0 ); // constructor; construct a zero HugeInteger with size n

   // copy constructor; constructs a HugeInteger with a copy of each of the elements in integerToCopy
   HugeInteger( const HugeInteger &integerToCopy );

   ~HugeInteger(); // destructor; destroys the HugeInteger

   const HugeInteger &operator=( const HugeInteger &right ); // assignment operator

   bool operator==( const HugeInteger &right ) const; // less than or equal to

   bool operator<( const HugeInteger &right ) const;  // less than

   bool operator<=( const HugeInteger &right ) const; // less than or equal to

   // addition operator; HugeInteger + HugeInteger
   HugeInteger operator+( const HugeInteger &op2 ) const;

   // subtraction operator; HugeInteger - HugeInteger provided that
   // the minuend is greater than or equal to the subtrahend
   HugeInteger operator-( const HugeInteger &op2 ) const;

   // multiplication operator; HugeInteger * HugeInteger
   HugeInteger operator*( const HugeInteger &op2 ) const;

   // division operator; HugeInteger / HugeInteger
   // provided that the divisor is not equal to 0
   HugeInteger operator/( const HugeInteger &op2 ) const;

   // modulus operator; HugeInteger % HugeInteger
   // provided that the divisor is not equal to 0
   HugeInteger operator%( const HugeInteger &op2 ) const;

   HugeInteger& operator++(); // prefix increment operator

   HugeInteger operator++( int ); // postfix increment operator

   HugeInteger& operator--(); // prefix decrement operator

   HugeInteger operator--( int ); // postfix decrement operator

   friend std::ostream& operator<<(std::ostream& output, const HugeInteger& hugeInteger)
   {
	   std::vector< int >::const_iterator it = hugeInteger.integer.end() - 1;
	   for (; it != hugeInteger.integer.begin(); --it)
		   if (*it < 10)
			  output << *it;
	   if (*it < 10)
		   output << *it;
	   return output; // enables cout << x << y;
   }

   void assign( std::vector< int > v ); // convert a vector of decimal digits into a HugeInteger
   bool isZero() const;           // return true if and only if all digits are zero
private:
   std::vector< int > integer;

   void divideByTen();            // divides a HugeInteger by 10
   void helpIncrement();          // increments a HugeInteger by 1
   void helpDecrement();          // decrements a HugeInteger by 1
}; // end class HugeInteger


// constructor; construct a zero HugeInteger with size n
HugeInteger::HugeInteger( unsigned int n )
   : integer( ( n == 0 ) ? 1 : n )
{
}

// copy constructor; constructs a HugeInteger with a copy of each of the elements in integerToCopy
HugeInteger::HugeInteger( const HugeInteger &integerToCopy )
   : integer( integerToCopy.integer )
{
}

// destructor; destroys the HugeInteger
HugeInteger::~HugeInteger()
{
}

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const HugeInteger &HugeInteger::operator=( const HugeInteger &right )
{
   if( &right != this ) // avoid self-assignment
      integer = right.integer;

   return *this; // enables x = y = z, for example
}

// function that tests if two HugeIntegers are equal
bool HugeInteger::operator==( const HugeInteger &right ) const
{
   return ( integer == right.integer );
} // end function operator==

// function that tests if one HugeInteger is less than another
bool HugeInteger::operator<( const HugeInteger &right ) const
{
    if (integer.size() == right.integer.size())
		for (int i = integer.size() - 1; i >= 0; i--) {
			if (integer.begin()[i] == right.integer.begin()[i] && i == 0)
				return false;
			else if (integer.begin()[i] == right.integer.begin()[i]);
			else if (integer.begin()[i] < right.integer.begin()[i])
				return true;
			else
				return false;
		}
	else if (integer.size() < right.integer.size())
		return true;
	else
		return false;
} // end function operator<

// function that tests if one HugeInteger is less than or equal to another
bool HugeInteger::operator<=( const HugeInteger &right ) const
{
   return ( *this == right || *this < right );
}

// addition operator; HugeInteger + HugeInteger
HugeInteger HugeInteger::operator+( const HugeInteger &op2 ) const
{
   unsigned int op1Size = integer.size();
   unsigned int op2Size = op2.integer.size();
   unsigned int sumSize = ( op1Size >= op2Size ) ? op1Size + 1 : op2Size + 1;

   HugeInteger sum( sumSize );

   std::vector< int >::const_iterator it1 = integer.begin();
   std::vector< int >::iterator it3 = sum.integer.begin();
   for( ; it1 != integer.end(); ++it1, ++it3 )
      *it3 = *it1;

   std::vector< int >::const_iterator it2 = op2.integer.begin();
   for( it3 = sum.integer.begin(); it2 != op2.integer.end(); ++it2, ++it3 )
      *it3 += *it2;

   for( it3 = sum.integer.begin(); it3 != sum.integer.end() - 1; ++it3 )
      if( *it3 > 9 )
      {
         *it3 -= 10;
         ( *( it3 + 1 ) )++;
      }

   if( *it3 == 0 )
      sum.integer.erase( sum.integer.end() - 1 );

   return sum;
} // end function operator+

// subtraction operator; HugeInteger - HugeInteger
HugeInteger HugeInteger::operator-( const HugeInteger &op2 ) const
{
    int difSize = integer.size();
	int bor = 0;

	HugeInteger dif(difSize);

	std::vector< int >::const_iterator it1 = integer.begin();
	std::vector< int >::const_iterator it2 = op2.integer.begin();
	std::vector< int >::iterator it3;

	dif.assign(integer);

	for (it3 = dif.integer.begin(); it2 != op2.integer.end(); ++it2, ++it3) {
		*it3 = 10 - *it2 + *it3 + bor;
		bor = 0;
		if (*it3 < 10)
			bor = -1;
		else
			*it3 -= 10;	
	}

	if (bor == -1)
		for (; it3 != dif.integer.end(); ++it3) {
			*it3 = *it3 + 9;
			if (*it3 >= 10) {
				*it3 = *it3 - 10;
				break;
			}
		}

	for (it3 = dif.integer.end() - 1; it3 != dif.integer.begin(); ) {
		if (*it3 == 0) {
			--it3;
			dif.integer.pop_back();
		}
		else
			break;
	}

	return dif;
} // end function operator-

// multiplication operator; HugeInteger * HugeInteger
HugeInteger HugeInteger::operator*( const HugeInteger &op2 ) const
{
    int proSize = integer.size() + op2.integer.size();

	HugeInteger pro(proSize);

	if (isZero() == 1 || op2.isZero() == 1) {
		pro.integer.resize(1);
		return pro;
	}

	std::vector< int >::const_iterator it1 = integer.begin();
	std::vector< int >::const_iterator it2 = op2.integer.begin();
	std::vector< int >::iterator it3;
	std::vector< int >::iterator it4;

	for (it4 = pro.integer.begin(); it1 != integer.end(); ++it1, ++it4) {
		for (it2 = op2.integer.begin(), it3 = it4; it2 != op2.integer.end(); ++it2, ++it3) {
			*it3 += (*it1) * (*it2);
		}
	}

	for (it3 = pro.integer.begin(); it3 != pro.integer.end() - 1; ++it3)
		if (*it3 > 9) {
			*(it3 + 1) += *it3 / 10;
			*it3 %= 10;
		}

	if (*it3 == 0)
		pro.integer.erase(pro.integer.end() - 1);

	return pro;
} // end function operator*

// division operator; HugeInteger / HugeInteger provided that the divisor is not equal to 0
HugeInteger HugeInteger::operator/( const HugeInteger &op2 ) const
{
    int quoSize = integer.size() - op2.integer.size() + 1;

	HugeInteger quo(1);

	if (isZero() == true)
		return quo;

	if (*this<op2);
	else {
		quo.integer.resize(quoSize);

		HugeInteger buf(integer.size());
		HugeInteger rem(*this);
		HugeInteger temRem(*this);

		std::vector< int >::const_iterator it1;
		std::vector< int >::reverse_iterator it2;
		std::vector< int >::iterator it3 = buf.integer.end() - 1;

		for (it1 = op2.integer.end() - 1; it1 != op2.integer.begin(); --it1, --it3)
			*it3 = *it1;
		*it3 = *it1;

		if (*this<buf) {
			buf.divideByTen();
			quo.integer.erase(quo.integer.end() - 1);
		}

		for (it2 = quo.integer.rbegin(); it2 != quo.integer.rend(); ++it2) {
			while (buf<=rem) {
				temRem=rem-buf;
				rem=temRem;
				++(*it2);
				if (rem.isZero() == true)
					return quo;
			}
			buf.divideByTen();
		}
	}

	return quo;
} // end function operator/

// modulus operator; HugeInteger % HugeInteger provided that the divisor is not equal to 0
HugeInteger HugeInteger::operator%( const HugeInteger &op2 ) const
{
   HugeInteger quotient = ( *this ) / op2;
   HugeInteger remainder = ( *this ) - ( quotient * op2 );
   return remainder;
}

// overloaded prefix increment operator 
HugeInteger& HugeInteger::operator++()
{
    helpIncrement();
	return *this;
}

// overloaded postfix increment operator;
// note that the dummy integer parameter does not have a parameter name
HugeInteger HugeInteger::operator++( int )
{
    HugeInteger tem = *this;
	helpIncrement();
    return tem;
}

// overloaded prefix decrement operator 
HugeInteger& HugeInteger::operator--()
{
    helpDecrement();
    return *this;
}

// overloaded postfix decrement operator;
// note that the dummy integer parameter does not have a parameter name
HugeInteger HugeInteger::operator--( int )
{
	HugeInteger tem = *this;
	helpDecrement();
	return tem;
}

// convert a vector of decimal digits into a HugeInteger
void HugeInteger::assign( std::vector< int > v )
{
   integer = v;
} // end function convert

// function that tests if a HugeInteger is zero
bool HugeInteger::isZero() const
{
   std::vector< int >::const_iterator it = integer.begin();
   for( ; it != integer.end(); ++it )
      if( *it != 0 )
         return false;
         
   return true;
}

// function that divides a HugeInteger by 10; shift a HugeInteger one position to the right
void HugeInteger::divideByTen()
{
   std::vector< int >::iterator it = integer.begin() + 1;
   for( ; it != integer.end(); ++it )
      *( it - 1 ) = *it;
   integer.erase( integer.end() - 1 );
}

// function to help increment the integer
void HugeInteger::helpIncrement()
{
   std::vector< int >::iterator it = integer.begin();
   ( *it )++;
   std::vector< int >::iterator it2 = it;
   for( ++it2; it2 != integer.end(); ++it, ++it2 )
      if( *it == 10 )
      {
         *it = 0;
         ( *it2 )++;
      }

   if( ( *it ) == 10 )
   {
      *( it ) = 0;
      integer.resize( integer.size() + 1 );
      it = integer.end();
      --it;
      *it = 1;
   }
}

// function to help decrement the integer
void HugeInteger::helpDecrement()
{
    std::vector< int >::iterator it = integer.begin();

	for (; it != integer.end(); ++it) {
		*it = *it + 9;
		if (*it >= 10) {
			*it = *it - 10;
			break;
		}
	}

	it = integer.end() - 1;
	if (*it == 0 && integer.size() != 1)
		integer.resize(integer.size() - 1);
}

#endif