#include "fractol.h"

int close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_1) // plus iterations
		fractal->iterations_definition += 10;
	else if (keysym == XK_2) // minus iterations
		fractal->iterations_definition -= 10;
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom); // shift should be scaled too
	else if (keysym == XK_Right)				   // -> proportional to zoom
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);

	fractal_render(fractal);

	return (0);
}

// track the mouse to change julia dynamically
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, 0, WIDTH)) * fractal->zoom + fractal->shift_x;
		fractal->julia_y = (map(x, +2, -2, 0, HEIGHT)) * fractal->zoom + fractal->shift_y;
	}
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	x_real;
	double	y_real;

	if (button == Button1 && ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->name = "julia";
		julia_track(x, y, fractal);
	}
	if (button == Button3 && !ft_strncmp(fractal->name, "julia", 5))
		fractal->name = "mandelbrot";
	if (button == Button4)
		fractal->zoom *= 0.95;
	if (button == Button5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}
