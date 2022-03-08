#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define EPSILON 1.1929093

class Fixed
{
	private:
		int					fixed_point_value;
		static const int	fractional_bits;
	
	public:
		bool operator>(const Fixed &to_compare) const;
		bool operator<(const Fixed &to_compare) const;
		bool operator==(const Fixed &to_compare);
		bool operator!=(const Fixed &to_compare);
		bool operator>=(const Fixed &to_compare);
		bool operator<=(const Fixed &to_compare);

		Fixed operator+(Fixed &to_add);
		Fixed operator-(Fixed &to_substruct);
		Fixed operator*(const Fixed &to_mulptiply) ;
		Fixed operator/(Fixed &to_divide);

		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& min(Fixed &first_value, Fixed &second_value);
		static const Fixed& min(const Fixed &first_value, const Fixed &second_value);

		static Fixed& max(Fixed &first_value, Fixed &second_value);
		static const Fixed& max(const Fixed &first_value, const Fixed &second_value);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		const Fixed& operator=(const Fixed &to_assignation);
		Fixed(const Fixed &old);
		Fixed(const int integer_to_convert);
		Fixed(const float float_to_convert);
		Fixed(void);
		~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &source);

#endif