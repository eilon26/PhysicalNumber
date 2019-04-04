#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H
#include "Unit.h"
#include <iostream>

namespace ariel {
	
	class PhysicalNumber {
		double _value;
		Unit _type;
	public:
		// Constructors :
		PhysicalNumber(double _value, Unit _type);

		//mathematics operators
		const PhysicalNumber operator+ (const PhysicalNumber& x)const;
		const PhysicalNumber operator- (const PhysicalNumber& x)const;


		PhysicalNumber&  operator+=(const PhysicalNumber& other);
		PhysicalNumber& operator-= (const PhysicalNumber& other);
		
		const PhysicalNumber operator-() const;
		const PhysicalNumber operator+() const;

		// 6 comparison operators
		friend bool operator==(const PhysicalNumber& x,const PhysicalNumber& y);// Implement at .cpp file
		friend bool operator!=(const PhysicalNumber& x,const PhysicalNumber& y){return !(x==y);};
		friend bool operator>(const PhysicalNumber& x,const PhysicalNumber& y){return (y<x);}
		friend bool operator<(const PhysicalNumber& x,const PhysicalNumber& y); // Implement at .cpp file
		friend bool operator>=(const PhysicalNumber& x,const PhysicalNumber& y){return !(x<y);}
		friend bool operator<=(const PhysicalNumber& x,const PhysicalNumber& y){return !(x>y);};

		// Increasing and decreasing by one operators
		// Postfix: (A--)
		const PhysicalNumber operator++(int);
		const PhysicalNumber operator--(int);
		// Prefix: (--A)
		PhysicalNumber& operator++();
		PhysicalNumber& operator--();

		// I/O
		friend std::ostream& operator<<(std::ostream& os, const PhysicalNumber& other);
		friend std::istream& operator>>(std::istream& is, PhysicalNumber& other);
	};
}


#endif

