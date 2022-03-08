#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed(const Fixed &old){
	*this = old;
	return ;
}

Fixed::Fixed(void){
	this->fixed_point_value = 0;
	return ;
}

Fixed::Fixed(const float float_to_convert) {
	setRawBits(roundf(float_to_convert * (float)(1 << fractional_bits)));
	return ;
}

Fixed::Fixed(const int integer_to_convert) {
	setRawBits(integer_to_convert * (1 << fractional_bits));
	return ;
}

Fixed::~Fixed(){
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

const Fixed& Fixed::operator=(const Fixed &to_assignation){
	if (this != &to_assignation) {
		this->fixed_point_value = to_assignation.fixed_point_value;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &source) {
	out << source.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &to_compare) const {
	if (this->getRawBits() > to_compare.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &to_compare) const {
	if (this->getRawBits() < to_compare.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &to_compare) {
	if (fabs(this->getRawBits() - to_compare.getRawBits()) < EPSILON)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &to_compare) {
	if (fabs(this->getRawBits() - to_compare.getRawBits()) > EPSILON)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &to_compare) {
	if (operator>(to_compare) || operator==(to_compare))
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &to_compare) {
	if (operator<(to_compare) || operator==(to_compare))
		return (true);
	return (false);
}

Fixed Fixed::operator+(Fixed &to_add) {
	Fixed result;
	result.setRawBits((this->getRawBits() * to_add.getRawBits()) / (1 << this->fractional_bits));
	return (result);
}

Fixed Fixed::operator-(Fixed &to_substruct) {
	Fixed result;
	result.setRawBits((this->getRawBits() - to_substruct.getRawBits()) / (1 << this->fractional_bits));
	return (result);
}

Fixed Fixed::operator*(const Fixed &to_multiply) {
	Fixed result;
	result.setRawBits((this->getRawBits() * to_multiply.getRawBits()) / (1 << this->fractional_bits));
	return (result);
}

Fixed Fixed::operator/(Fixed &to_divide) {
	Fixed result;
	result.setRawBits((this->getRawBits() / to_divide.getRawBits()) / (1 << this->fractional_bits));
	return (result);
}

Fixed& Fixed::operator++(void) {
	this->fixed_point_value += 1;
	return (*this);
}

Fixed& Fixed::operator--(void) {
	this->fixed_point_value -= 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);

	this->fixed_point_value += 1;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);

	this->fixed_point_value -= 1;
	return (tmp);
}

const Fixed& Fixed::min(const Fixed &first_value, const Fixed &second_value) {
	if (first_value < second_value)
		return (first_value);
	return (second_value);
}

Fixed& Fixed::min(Fixed &first_value, Fixed &second_value) {
	if (first_value < second_value)
		return (first_value);
	return (second_value);
}

const Fixed& Fixed::max(const Fixed &first_value, const Fixed &second_value) {
	if (first_value > second_value)
		return first_value;
	return (second_value);
}

Fixed& Fixed::max(Fixed &first_value, Fixed &second_value) {
	if (first_value > second_value)
		return (first_value);
	return (second_value);
}