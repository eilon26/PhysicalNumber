#include "PhysicalNumber.h"
#include <iostream>
#include <string>

using namespace ariel;
// Constructors :
    PhysicalNumber::PhysicalNumber(double val, Unit unit)
    :_value(val),_type(unit)
    {
    }

//mathematics operators
    const PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& x)const{
        if ((int(x._type)/3)!=(int(this->_type)/3)) throw std::runtime_error("units don't match");
        
        double curr_ratio = ratio[int(x._type)]/ratio[int(this->_type)];
        return PhysicalNumber(x._value*curr_ratio+this->_value,this->_type);
    }
    const PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber& x)const{
        return operator+(-x);
    }
    PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& x){
        if ((int(x._type)/3)!=(int(this->_type)/3)) throw std::runtime_error("units don't match");
        
        double curr_ratio = ratio[int(x._type)]/ratio[int(this->_type)];
        this->_value=(x._value*curr_ratio+this->_value);
        return *this;
    }
    PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber&  x){
        return operator+=(-x);
    }
    const PhysicalNumber PhysicalNumber::operator+()const{
        return PhysicalNumber(this->_value,this->_type);
    }
    const PhysicalNumber PhysicalNumber::operator-()const{
        return PhysicalNumber(-1*this->_value,this->_type);
    }
// 6 comparison operators
	bool ariel::operator==(const PhysicalNumber& x,const PhysicalNumber& y){
        if ((int(x._type)/3)!=(int(y._type)/3)) return false;
        double curr_ratio = ratio[int(y._type)]/ratio[int(x._type)];
        double YNewVal = curr_ratio*y._value;
        return (x._value==YNewVal);
    }
	bool ariel::operator<(const PhysicalNumber& x,const PhysicalNumber& y){
        if ((int(x._type)/3)!=(int(y._type)/3)) return false;
        double curr_ratio = ratio[int(y._type)]/ratio[int(x._type)];
        double YNewVal = curr_ratio*y._value;
        return (x._value<YNewVal);
    }


// Increasing and decreasing by one operators
	// Postfix: (A--)
    const PhysicalNumber PhysicalNumber::operator++(int){
        PhysicalNumber ans(this->_value,this->_type);
        this->_value++;
        return ans;
    }
	const PhysicalNumber PhysicalNumber::operator--(int){
        PhysicalNumber ans(this->_value,this->_type);
        this->_value--;
        return ans;
    }
	// Prefix: (--A)
	PhysicalNumber& PhysicalNumber::operator++(){
        this->_value++;
        return *this;
    }
	PhysicalNumber& PhysicalNumber::operator--(){
        this->_value--;
        return *this;
    }

// I/O
	std::ostream& ariel::operator<<(std::ostream& os, const PhysicalNumber& x){
        return os<<x._value<<type_name[int(x._type)];
    }
	std::istream& ariel::operator>>(std::istream& is, PhysicalNumber& x){
        std::string temp_type;
        if (!(is>>x._value))  throw std::runtime_error("invalid input");
        is >>temp_type;
        int i;
        for(i=1;i<9;i++){
            if (temp_type.compare(type_name[i])==0){
                x._type= Unit(i);
                break;
            }
        }
        if (i==9) 
            throw std::runtime_error("invalid input");
        return is;
    }




