/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/31 15:29:21 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/01 15:42:30 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_frac		*init_frac(t_frac *frac, int argc, char **argv)
{
	frac->mlx_ptr = mlx_init();
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, X, Y, "Fractol");
	frac->x1 = -3.1;
	frac->y1 = (-1.8);
	frac->x = 0;
	frac->y = 0;
	frac->checkjulia = 0;
	frac->zoom = 300;
	frac->iteration_max = 30;
	frac->i = 0;
	frac->j = 0;
	frac->x = 0;
	frac->y = 0;
	frac->image = mlx_new_image(frac->mlx_ptr, X, Y);
	frac->string_image = mlx_get_data_addr(frac->image,\
	&frac->bpp, &frac->sl, &frac->end);
	frac->stopjulia = 1;
	frac->mandelbrot = "mandelbrot";
	frac->julia = "julia";
	frac->burning = "burning";
	frac->argv = argv;
	frac->argc = argc;
	return (frac);
}

int			deal_key(int key, t_frac *frac)
{
	if (key == 53)
		exit(0);
	if (key == 69)
		frac->iteration_max += 5;
	if (key == 78)
		frac->iteration_max -= 5;
	if (key == 123)
		frac->x1 = (frac->x1 + frac->x1 / 10);
	if (key == 124)
		frac->x1 = (frac->x1 - frac->x1 / 10);
	if (key == 125)
		frac->y1 = (frac->y1 - frac->y1 / 10);
	if (key == 126)
		frac->y1 = (frac->y1 + frac->y1 / 10);
	if (key == 35)
		frac->stopjulia = 1;
	if (key == 31)
		frac->stopjulia = 0;
	actualisation(frac);
	return (0);
}

int			deal_mouse(int mouse, int x, int y, t_frac *frac)
{
	frac->xx = x;
	frac->yy = y;
	if (mouse == 5 || mouse == 4)
		frac->zoom *= (mouse == 5) ? 1.1 : 0.9;
	if (mouse == 2)
		reset_any_frac(frac);
	actualisation(frac);
	return (0);
}

int			motion_notify(int x, int y, t_frac *frac)
{
	if (frac->stopjulia == 1)
	{
		frac->mouse_x = x;
		frac->mouse_y = y;
		frac->c_r = frac->mouse_x / (X / 2) - 1;
		frac->c_i = frac->mouse_y / (Y / 2) - 1;
		frac->checkjulia = 1;
		actualisation(frac);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_frac		*frac;

	if (argc != 2)
		ft_putstr(" Les arguments sont: mandelbrot , julia ou burning\n");
	else if (argc == 2)
	{
		if (!(frac = (t_frac*)malloc(sizeof(t_frac) * 1)))
			return (0);
		frac = init_frac(frac, argc, argv);
		frac->formfract = checkargv(argv[1], frac);
		if (frac->formfract != -1)
		{
			check_formfract(frac);
			mlx_put_image_to_window(frac->mlx_ptr,\
			frac->win_ptr, frac->image, 0, 0);
			mlx_key_hook(frac->win_ptr, deal_key, frac);
			mlx_mouse_hook(frac->win_ptr, deal_mouse, frac);
			mlx_hook(frac->win_ptr, 6, 1L << 6, motion_notify, frac);
			mlx_loop(frac->mlx_ptr);
		}
	}
	return (0);
}
