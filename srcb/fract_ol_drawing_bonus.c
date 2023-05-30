/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_drawing_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:45:57 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/30 18:09:18 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol_bonus.h"

int	mandelbrot(double r, double i, t_mlx *mlx)
{
	int		iter;
	double	r_temp;
	double	start_r;
	double	start_i;

	iter = 0;
	start_r = r;
	start_i = i;
	while (r * r + i * i < 4 && iter < mlx -> max_iter)
	{
		r_temp = r * r - i * i + start_r;
		i = 2 * r * i + start_i;
		r = r_temp;
		iter++;
	}
	return (iter * 371 + 10000);
}

int	julia(double r, double i, t_mlx *mlx)
{
	int		iter;
	double	r_temp;

	iter = 0;
	while (r * r + i * i < 4 && iter < mlx -> max_iter)
	{
		r_temp = r * r - i * i + mlx -> julia_r;
		i = 2 * r * i + mlx -> julia_i;
		r = r_temp;
		iter++;
	}
	return (iter * 371 + 10000);
}

void	drawing_mandelbrot(t_mlx *mlx)
{
	double	cr;
	double	ci;
	double	x_step;
	double	y_step;
	int		iter;

	x_step = ((mlx -> x_max - mlx -> x_min) / HW);
	y_step = ((mlx -> y_max - mlx -> y_min) / HW);
	mlx -> y = 0;
	while (mlx -> y < HW)
	{
		mlx -> x = 0;
		while (mlx -> x < HW)
		{
			cr = mlx -> x_min + mlx -> x * x_step;
			ci = mlx -> y_min + mlx -> y * y_step;
			iter = mandelbrot(cr, ci, mlx);
			my_mlx_pixel_put(mlx, mlx -> x, mlx -> y, iter);
			(mlx -> x)++;
		}
		(mlx -> y)++;
	}
}

void	drawing_julia(t_mlx *mlx)
{
	double	cr;
	double	ci;
	double	x_step;
	double	y_step;
	int		iter;

	x_step = ((mlx -> x_max - mlx -> x_min) / HW);
	y_step = ((mlx -> y_max - mlx -> y_min) / HW);
	mlx -> y = 0;
	while (mlx -> y < HW)
	{
		mlx -> x = 0;
		while (mlx -> x < HW)
		{
			cr = mlx -> x_min + mlx -> x * x_step;
			ci = mlx -> y_min + mlx -> y * y_step;
			iter = julia(cr, ci, mlx);
			my_mlx_pixel_put(mlx, mlx -> x, mlx -> y, iter);
			(mlx -> x)++;
		}
		(mlx -> y)++;
	}
}

//Julia set. Interesting parametres:0.285 0.01;0.285, 0;−0.8 0.156; 