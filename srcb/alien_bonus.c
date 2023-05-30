/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alien_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:55:42 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/30 18:15:38 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol_bonus.h"

int	alien(double r, double i, t_mlx *mlx)
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
		r_temp = r * r * r - 3 * r * i * i + start_r;
		i = 3 * r * r * i - i * i * i + start_i;
		r = r_temp;
		iter++;
	}
	return (iter * 371 + 10000);
}

void	drawing_alien(t_mlx *mlx)
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
			iter = alien(cr, ci, mlx);
			my_mlx_pixel_put(mlx, mlx -> x, mlx -> y, iter);
			(mlx -> x)++;
		}
		(mlx -> y)++;
	}
}
