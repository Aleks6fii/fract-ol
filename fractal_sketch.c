#include "fractol.h"

int main(int ac, char **av) {
    t_fractal   fractal;

    // strncmp will return 0 if strings are equal
    if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)
        || ac == 4 && !ft_strncmp(av[1], "julia", 5))
    {
        fractal.name = av[1];
        if (ac == 4)
        {
            fractal.julia_x = atodbl(av[2]); // converting input to doubles 
            fractal.julia_y = atodbl(av[3]);
        }
        fractal_init(&fractal);
        fractal_render(fractal);
        mlx_loop(fractal.mlx_connection); // listening for events
    }
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}