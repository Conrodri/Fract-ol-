/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   burning.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/31 15:30:33 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/31 15:34:02 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		burning(t_frac *frac)
{
	while (frac->x < X)
	{
		frac->y = 0;
		while (frac->y < Y)
		{
			reset_burning(frac);
			while (frac->z_r * frac->z_r + frac->z_i * frac->z_i < 4
			&& frac->i < frac->iteration_max)
			{
				frac->tmp = frac->z_r * frac->z_r - frac->z_i * frac->z_i
				+ frac->c_r;
				frac->z_i = fabs(2 * frac->z_r * frac->z_i) + frac->c_i;
				frac->z_r = frac->tmp;
				frac->i++;
			}
			burning_color(frac);
			frac->y++;
		}
		frac->x++;
	}
}
