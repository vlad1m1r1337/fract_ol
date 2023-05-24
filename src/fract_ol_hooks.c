/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:28:20 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/24 21:05:59 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(0);
	else if (keycode == 34)
	{
		if (mlx -> max_iter < 2000)
			mlx -> max_iter = mlx -> max_iter * 1.1;
		else
			return 0;
		mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, mlx -> img_ptr, 0, 0);
	}
	else if (keycode == 2)
	{
		if (mlx -> max_iter > 10)
			mlx -> max_iter = mlx -> max_iter / 1.1;
		else
		{
			write(1, "Too few operations\n", 19);	
			return 0;
		}
	}
	if (ft_strcmp("Mandelbrot", mlx -> name) == 0)
		drawing_mandelbrot(mlx);
	else if (ft_strcmp("Julia", mlx -> name) == 0)
		drawing_julia(mlx);
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, mlx -> img_ptr, 0, 0);
	return (0);
}

int mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	mlx -> mouse_x = (double)x;
	mlx -> mouse_y = (double)y;
	
	if (keycode == 4)// in
	{
		mlx -> x_min = mlx -> x_min * 0.95;
		mlx -> x_max = mlx -> x_max * 0.95;
		mlx -> y_min = mlx -> x_min * 0.95;
		mlx -> y_max = mlx -> x_max * 0.95;	
	}
	else if (keycode == 5)// out
	{
		mlx -> x_min = mlx -> x_min / 0.95;
		mlx -> x_max = mlx -> x_max / 0.95;
		mlx -> y_min = mlx -> x_min / 0.95;
		mlx -> y_max = mlx -> x_max / 0.95;
	}
	if (ft_strcmp("Mandelbrot", mlx -> name) == 0)
		drawing_mandelbrot(mlx);
	else if (ft_strcmp("Julia", mlx -> name) == 0)
		drawing_julia(mlx);
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, mlx -> img_ptr, 0, 0);
	return (0);
}

void	hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx -> win_ptr, key_hook, mlx);
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, mlx);
	mlx_mouse_hook(mlx -> win_ptr, mouse_hook, mlx);
}