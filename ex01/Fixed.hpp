#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed_point_value;
		static const int	fractional_bits;
	
	public:
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