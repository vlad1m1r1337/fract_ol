/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_Mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:45:57 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/19 20:31:27 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	mandelbrot(double cr, double ci, t_mlx *mlx)
{
	double r = 0;
	double i = 0;
	int	iter = 0;
	double	r_temp;
	
	while (pow(r, 2) + pow(i, 2) < 4 && iter < mlx -> max_iter)
	{
		r_temp = pow(r, 2) - pow(i, 2) + cr;
		i = 2 * r * i + ci;
		r = r_temp;
		iter++;
	}
	return (iter * 771 + 10000);
}

void	draw_mandelbrot_set(t_mlx *mlx)
{
	double cr;
	double ci;
	double	x_step;
	double	y_step;
    int iter;
    
    x_step = ((mlx -> x_max - mlx -> x_min) / HW);
    y_step = ((mlx -> y_max - mlx -> y_min) / HW);
	mlx -> y = 0;
	while(mlx -> y < HW)
	{
		mlx -> x = 0;
		while(mlx -> x < HW)
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
