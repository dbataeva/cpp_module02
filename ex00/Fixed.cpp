#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed(const Fixed &old){
	std::cout << "Copy constructor called" << std::endl;
	*this = old;
	return ;
}

const Fixed& Fixed::operator=(const Fixed &to_assignation){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &to_assignation) {
		this->fixed_point_value = to_assignation.getRawBits();
	}
	return *this;
}

Fixed::Fixed(void){
	this->fixed_point_value = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
	return ;
}

void Fixed::setRawBits(int const raw){
	this->fixed_point_value = raw;
	return ;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point_value;
}