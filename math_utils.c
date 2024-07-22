#include "fractol.h"

// this is a function for linear interpolation
// allows to convert pixel values eg [0-799] to complex plane values eg [-2; +2]
// if norminette error: old min is 0, can ignore that

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

// sum of complex numbers
t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

// square of a complex number
// (x + yi) * (x + yi) = x^2 + 2xyi - y^2
// Re = (x^2 - y^2)
// Im = 2xy
t_complex square_complex(t_complex z)
{
	t_complex result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
