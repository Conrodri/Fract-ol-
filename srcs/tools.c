/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/31 15:30:25 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/31 16:14:08 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putstr(" Les arguments sont: mandelbrot , julia ou burning\n");
	exit(1);
}

void	put_pixel_in_img(t_frac *frac, int x, int y, t_rgb color)
{
	int	pos;

	if (x < 0 || x >= X)
		return ;
	if (y < 0 || y >= Y)
		return ;
	pos = y * frac->sl + x * 4;
	frac->string_image[pos] = (char)color.b;
	frac->string_image[pos + 1] = (char)color.g;
	frac->string_image[pos + 2] = (char)color.r;
	frac->string_image[pos + 3] = (char)color.a;
}

t_rgb	ft_makergb(int r, int g, int b, int a)
{
	t_rgb color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

int		checkargv(char *str, t_frac *frac)
{
	int i;

	i = -1;
	if (i == -1 && ft_strcmp(str, frac->julia) == 0)
		i = 1;
	if (i == -1 && ft_strcmp(str, frac->mandelbrot) == 0)
		i = 2;
	if (i == -1 && ft_strcmp(str, frac->burning) == 0)
		i = 3;
	if (i == -1)
		ft_error();
	return (i);
}

void	actualisation(t_frac *frac)
{
	frac->x = (frac->x / frac->zoom + frac->x1) - (frac->x / (frac->zoom));
	frac->y = (frac->y / frac->zoom + frac->y1) - (frac->y / (frac->zoom));
	if (frac->formfract == 1)
		julia(frac);
	if (frac->formfract == 2)
		mandelbrot(frac);
	if (frac->formfract == 3)
		burning(frac);
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->image, 0, 0);
}
