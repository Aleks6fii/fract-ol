//*** All functions for string processing ***//

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// like atoi but for double
double atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;

	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)			// handle integer part
		integer_part = (integer_part * 10) + (*s++ - 48);
	if (*s == '.')					// if reached fractional part
		s++;						// skip dot '.'
	while (*s)						// and handle fractional part
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	
	return ((integer_part + fractional_part) * sign);
}

