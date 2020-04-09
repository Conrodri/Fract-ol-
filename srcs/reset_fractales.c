/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reset_fractales.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/31 15:30:18 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/01 10:00:07 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	reset_mandelbrot(t_frac *frac)
{
	frac->c_r = frac->x / frac->zoom + frac->x1;
	frac->c_i = frac->y / frac->zoom + frac->y1;
	frac->z_r = 0;
	frac->z_i = 0;
	frac->i = 0;
}

void	reset_julia(t_frac *frac)
{
	if (frac->checkjulia == 0)
	{
		frac->c_r = 0.385;
		frac->c_i = 0.2;
	}
	if (frac->checkjulia == 1)
	{
		frac->c_r = frac->mouse_x / (X / 2) - 1;
		frac->c_i = frac->mouse_y / (Y / 2) - 1;
	}
	frac->z_r = frac->x / frac->zoom + frac->x1;
	frac->z_i = frac->y / frac->zoom + frac->y1;
	frac->i = 0;
}

void	reset_burning(t_frac *frac)
{
	frac->c_r = frac->x / frac->zoom + frac->x1;
	frac->c_i = frac->y / frac->zoom + frac->y1;
	frac->z_r = 0;
	frac->z_i = 0;
	frac->i = 0;
}

void	reset_any_frac(t_frac *frac)
{
	frac->x1 = -3.1;
	frac->y1 = (-1.8);
	frac->z_r = frac->x / frac->zoom + frac->x1;
	frac->z_i = frac->y / frac->zoom + frac->y1;
	frac->zoom = 300;
	frac->iteration_max = 30;
	if (frac->formfract == 1)
		julia(frac);
	if (frac->formfract == 2)
		mandelbrot(frac);
	if (frac->formfract == 3)
		burning(frac);
}

void	check_formfract(t_frac *frac)
{
	if (frac->formfract == 1)
		julia(frac);
	if (frac->formfract == 2)
		mandelbrot(frac);
	if (frac->formfract == 3)
		burning(frac);
}
