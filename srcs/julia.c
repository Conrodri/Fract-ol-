/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/31 15:29:52 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/31 15:32:21 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_frac *frac)
{
	while (frac->x < X)
	{
		frac->y = 0;
		while (frac->y < Y)
		{
			reset_julia(frac);
			while (frac->z_r * frac->z_r + frac->z_i * frac->z_i < 4 &&
			frac->i < frac->iteration_max * 3)
			{
				frac->tmp = frac->z_r;
				frac->z_r = frac->z_r * frac->z_r - frac->z_i * frac->z_i
				+ frac->c_r;
				frac->z_i = 2 * frac->z_i * frac->tmp + frac->c_i;
				frac->i++;
			}
			julia_color(frac);
			frac->y++;
		}
		frac->x++;
	}
}
