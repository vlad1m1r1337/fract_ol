/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_Mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:45:57 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/18 21:07:24 by vgribkov         ###   ########.fr       */
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
		r_temp = pow(r, 2) - pow(i, 2) + cr + mlx -> x;
		i = 2 * r * i + ci + mlx -> y;
		r = r_temp;
		iter++;
	}
	return (iter * 771 + 10000);
}

// void	initial_condition_Mandelbrot(t_mlx *mlx)
// {
	// mlx -> x_min = -2;
	// mlx -> x_max = 1;
	// mlx -> y_min = -1.5;
	// mlx -> y_max = 1.5;
	// mlx -> max_iter = 100;
	// mlx -> zoom = 1;
// }

void	draw_mandelbrot_set(t_mlx *mlx)
{
	int	x;
	int	y;
	double cr;
	double ci;
	//initial_condition_Mandelbrot(mlx);
	double	x_step = (mlx -> x_max - mlx -> x_min) / HW / mlx -> zoom;
	double	y_step = (mlx -> y_max - mlx -> y_min) / HW / mlx -> zoom;
	y = 0;
	while(y < HW)
	{
		x = 0;
		while(x < HW)
		{
			cr = mlx -> x_min + x * x_step;
			ci = mlx -> y_min + y * y_step;
			int iter = mandelbrot(cr, ci, mlx);
			my_mlx_pixel_put(mlx, x, y, iter);
			x++;
		}
		y++;
	}
}