#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixed_point_value;
		static const int	fractional_bits;
	
	public:
		int getRawBits(void) const;
		void setRawBits(int const raw);
		const Fixed& operator=(const Fixed &to_assignation);
		Fixed(const Fixed &old);
		Fixed(void);
		~Fixed(void);
};


#endif