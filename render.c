#include "fractol.h"

static void my_pixel_put(int x, int y, t_image *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void mb_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int i;
	int color;

	i = 0;

	z.x = (map(x, -2, +2, 0, WIDTH)) * fractal->zoom + fractal->shift_x; // value * zoom + shift
	z.y = (map(y, +2, -2, 0, HEIGHT)) * fractal->zoom + fractal->shift_y;

	mb_vs_julia(&z, &c, fractal);

	// how many iterations are needed to understand that point is escaped?
	// points at the edge of the Mandelbrot set (but doesn't belong to it) require many iterations for escaping
	// more iterations => more "clean" is the image
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);

		// if the value escaped?
		// if hypotenuse > 2, assume point is escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, WHITE, 0xFCBE11, 0, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->image, color);
			return;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->image, 0xFFE8F6);
}

void fractal_render(t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.img_ptr, 0, 0);
}
