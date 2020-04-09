/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/31 15:30:08 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/31 15:35:54 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_frac *frac)
{
	while (frac->x < X)
	{
		frac->y = 0;
		while (frac->y < Y)
		{
			reset_mandelbrot(frac);
			while (frac->i < frac->iteration_max && frac->z_r * frac->z_r +
			frac->z_i * frac->z_i < 4)
			{
				frac->tmp = frac->z_r;
				frac->z_r = frac->z_r * frac->z_r - frac->z_i * frac->z_i
				+ frac->c_r;
				frac->z_i = 2 * frac->z_i * frac->tmp + frac->c_i;
				frac->i++;
			}
			mandelbrot_color(frac);
			frac->y++;
		}
		frac->x++;
	}
}
