#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

const Fixed& Fixed::operator=(const Fixed &to_assignation){
	if (this != &to_assignation) {
		fixed_point_value = to_assignation.fixed_point_value;
	}
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

Fixed::Fixed(const Fixed &old){
	*this = old;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::Fixed(void){
	this->fixed_point_value = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float float_to_convert) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(float_to_convert * (float)(1 << fractional_bits))); //256 = 2^8
	return ;
}

Fixed::Fixed(const int integer_to_convert) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(integer_to_convert * (1 << fractional_bits));
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
	return (this->fixed_point_value);
}

float Fixed::toFloat(void) const {
	return (getRawBits() / (float)(1 << fractional_bits));
}

int Fixed::toInt(void) const {
	return (getRawBits() / (1 << fractional_bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &source) {
	out << source.toFloat();
	return out;
}
