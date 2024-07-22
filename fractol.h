#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // for debugging only
# include <stdlib.h> // for malloc, free
# include <unistd.h>  // standart functions, eg write
# include <math.h>
# include "minilibx-linux/mlx.h" // use double quotes for a non-system library
# include "X11/X.h"
# include "X11/keysym.h"

# define WIDTH 800
# define HEIGHT 800

# define ERROR_MESSAGE "Incorrect input"

// COLORS ----------------------------------------------------------------
# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF

# define PSYCHEDELIC_RED      0xFF1493   // Deep Pink
# define PSYCHEDELIC_ORANGE   0xFFA500   // Orange
# define PSYCHEDELIC_YELLOW   0xFFFF00   // Yellow
# define PSYCHEDELIC_GREEN    0x00FF7F   // Spring Green
# define PSYCHEDELIC_CYAN     0x00FFFF   // Cyan
# define PSYCHEDELIC_BLUE     0x0000FF   // Blue
# define PSYCHEDELIC_PURPLE   0x800080   // Purple
# define PSYCHEDELIC_MAGENTA  0xFF00FF   // Magenta
# define PSYCHEDELIC_PINK     0xFF69B4   // Hot Pink
# define PSYCHEDELIC_LIME     0x32CD32   // Lime Green
// -----------------------------------------------------------------------

// struct for a complex number 
typedef struct s_complex
{
    double x;
    double y;
}   t_complex;

typedef struct s_image
{
    void    *img_ptr;
    char    *pixels_ptr;
    int     bpp;
    int     endian;
    int     line_len;
}           t_image;

typedef struct s_fractal
{
    char        *name;
    void        *mlx_connection;
    void        *mlx_window;
    t_image     image;
    double      escape_value;
    int         iterations_definition;
    double      shift_x;
    double      shift_y;
    double      zoom;
    double      julia_x;
    double      julia_y;
}               t_fractal;

int			ft_strncmp(char *s1, char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		fractal_init(t_fractal *fractal);
double		map(double unscaled_sum, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void fractal_render(t_fractal *fractal);
static void events_init(t_fractal *fractal);
int key_handler(int keysym, t_fractal *fractal);
int mouse_handler(int button, int x, int y, t_fractal *fractal);
int close_handler(t_fractal *fractal);
double atodbl(char *s);
// int         julia_track(int x, int y, t_fractal *fractal);

#endif
