/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color_frac.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/31 15:29:14 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/31 15:42:40 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_color(t_frac *frac)
{
	if (frac->i >= frac->iteration_max)
		put_pixel_in_img(frac, frac->x, frac->y, ft_makergb(frac->i
		* 255 / frac->iteration_max, frac->i * 255
		/ frac->iteration_max, frac->i * 255 / frac->iteration_max, 0));
	else if (frac->i < frac->iteration_max)
		put_pixel_in_img(frac, frac->x, frac->y, ft_makergb(frac->i * 0
		/ frac->iteration_max, frac->i * 255 / frac->iteration_max,
		frac->i * 255 / frac->iteration_max, 0));
	else
		put_pixel_in_img(frac, frac->x, frac->y, ft_makergb(frac->i * 0
		/ frac->iteration_max, frac->i * 0 / frac->iteration_max,
		frac->i * 0 / frac->iteration_max, 0));
}

void	julia_color(t_frac *frac)
{
	if (frac->i >= frac->iteration_max * 3)
		put_pixel_in_img(frac, frac->x, frac->y, ft_makergb(frac->i *
		175 / frac->iteration_max, frac->i * 0 / frac->iteration_max,
		frac->i * 100 / frac->iteration_max, 0));
	if (frac->i < frac->iteration_max * 1)
		put_pixel_in_img(frac, frac->x, frac->y, ft_makergb(frac->i *
		255 / frac->iteration_max, frac->i * 20,
		frac->i * 255 / frac->iteration_max, 0));
	else
		put_pixel_in_img(frac, frac->x, frac->y, ft_makergb(frac->i *
		125, frac->i * 255 / frac->iteration_max,
		frac->i * 125, 0));
}

void	burning_color(t_frac *frac)
{
	if (frac->i == frac->iteration_max)
		put_pixel_in_img(frac, frac->x, frac->y, ft_makergb(frac->i
		* 255 / frac->iteration_max, frac->i * 0 /
		frac->iteration_max, frac->i * 150 / frac->iteration_max, 0));
	if (frac->i < frac->iteration_max)
		put_pixel_in_img(frac, frac->x, frac->y, ft_makergb(frac->i
		* 255 / frac->iteration_max, frac->i * 255 /
		frac->iteration_max, frac->i * 150 / frac->iteration_max, 0));
	else
		put_pixel_in_img(frac, frac->x, frac->y, ft_makergb(frac->i * 0
		/ frac->iteration_max, frac->i * 0 / frac->iteration_max,
		frac->i * 0 / frac->iteration_max, 0));
}
