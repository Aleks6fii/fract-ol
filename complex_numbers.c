/* #include <stdio.h>

typedef struct s_complex
{
    double re; // x
    double im; // y
} t_complex;

int main() {
    t_complex z;
    t_complex c;
    double tmp_real;

    z.re = 0; // 1st point
    z.im = 0;

    c.re = 0.25; // 2nd point
    c.im = 0.4;

    for (int i = 0; i < 42; ++i) {
        // general formula z = z^2 + c
        tmp_real = (z.re * z.re) - (z.im * z.im); // Re part x^2 - y^2
        z.im = 2 * z.re * z.im; // Im part 2xyi
        z.re = tmp_real;

        // add c value
        z.re += c.re; 
        z.im += c.im;

        printf("iteration %d: real %f im %f\n", i, z.re, z.im);

    }
}
*/