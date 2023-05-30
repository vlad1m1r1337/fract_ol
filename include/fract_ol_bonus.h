/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:57:55 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/30 18:27:11 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_BONUS_H
# define FRACT_OL_BONUS_H
# define HW 600

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "../Libft/libft.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		endian;
	int		scale;
	int		x;
	int		y;
	int		size_l;
	double	center_x;
	double	center_y;
	double	wasd;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		max_iter;
	double	mouse_x_norm;
	double	mouse_y_norm;
	char	*name;
	double	julia_r;
	double	julia_i;
}			t_mlx;

int		ft_strcmp(char *s1, char *s2);

int		ex(void);

void	warning_message(void);

void	bad_parameters(void);

void	warning_zoom(void);

int		key_hook(int keycode, t_mlx *mlx);

void	hooks(t_mlx *mlx);

int		mandelbrot(double cr, double ci, t_mlx *mlx);

void	initial_parametrs(t_mlx *mlx, char *fr_name);

void	drawing_mandelbrot(t_mlx *mlx);

void	drawing_julia(t_mlx *mlx);

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

double	my_atof(char *str);

int		mouse_hook(int keycode, int xx, int yy, t_mlx *mlx);

void	zoom_out(t_mlx *mlx);

void	zoom_in(t_mlx *mlx);

void	digit_checker(char **arg);

void	dot_checker(char *arg1, char *arg2);

void	hooks(t_mlx *mlx);

int		wasd(int keycode, t_mlx *mlx);

int		julia_parametres_check(t_mlx *mlx, int argc, char **argv);

void	drawing_mandelbrot(t_mlx *mlx);

int		alien(double r, double i, t_mlx *mlx);

void	drawing_mandelbrot(t_mlx *mlx);

void	drawing_alien(t_mlx *mlx);

#endif