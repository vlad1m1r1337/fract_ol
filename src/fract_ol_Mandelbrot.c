/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_Mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:45:57 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/24 15:51:25 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	mandelbrot(double cr, double ci, t_mlx *mlx)
{
	if (ci || cr)
		;
	double r = 0;
	double i = 0;
	int	iter = 0;
	double	r_temp;
	double ri[2];
	ri[0] = 0;
	ri[1] = 0;
	
	while (ri[0] + ri[1] < 4 && iter < mlx -> max_iter)
	{
		r_temp = ri[0] - ri[1] + cr;
		i = 2 * r * i + ci;
		r = r_temp;
		ri[0] = r * r;
		ri[1] = i * i;
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
			cr = mlx -> x_min + mlx -> mouse_x / HW + mlx -> x * x_step;
			ci = mlx -> y_min + mlx -> mouse_y / HW + mlx -> y * y_step;
			iter = mandelbrot(cr, ci, mlx);
			my_mlx_pixel_put(mlx, mlx -> x, mlx -> y, iter);
			(mlx -> x)++;
		}
		(mlx -> y)++;
	}
}
