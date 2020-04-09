/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/31 15:29:40 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/01 15:50:44 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# define X 1920
# define Y 1080
# define ITERATION_MAX 50

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_rgb;

typedef struct	s_frac
{
	int			j;
	char		*julia;
	char		*mandelbrot;
	char		*burning;
	int			formfract;
	int			argc;
	char		**argv;
	char		*string_image;
	int			stopjulia;
	void		*image;
	void		*mlx_ptr;
	void		*win_ptr;
	int			bpp;
	int			sl;
	int			end;
	float		x1;
	float		y1;
	float		x;
	float		y;
	float		mouse_x;
	float		mouse_y;
	int			zoom;
	int			checkjulia;
	float		xx;
	float		yy;
	float		image_x;
	float		image_y;
	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	float		i;
	float		tmp;
	int			iteration_max;
}				t_frac;

t_frac			*init_frac(t_frac *frac, int argc, char **argv);
int				deal_mouse(int mouse, int x, int y, t_frac *frac);
int				deal_key(int key, t_frac *frac);
int				motion_notify(int x, int y, t_frac *frac);

int				checkargv(char *str, t_frac *frac);
void			check_formfract(t_frac *frac);

void			mandelbrot(t_frac *frac);
void			julia(t_frac *frac);
void			burning(t_frac *frac);
void			put_pixel_in_img(t_frac *frac, int x, int y, t_rgb color);
t_rgb			ft_makergb(int r, int g, int b, int a);

void			reset_mandelbrot(t_frac *frac);
void			reset_julia(t_frac *frac);
void			reset_burning(t_frac *frac);
void			reset_any_frac(t_frac *frac);

void			julia_color(t_frac *frac);
void			burning_color(t_frac *frac);
void			mandelbrot_color(t_frac *frac);

void			actualisation(t_frac *frac);

#endif
