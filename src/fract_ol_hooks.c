/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:28:20 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/27 18:45:37 by vgribkov         ###   ########.fr       */
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
			return (0);
		mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr,
			mlx -> img_ptr, 0, 0);
	}
	else if (keycode == 2)
	{
		if (mlx -> max_iter > 10)
			mlx -> max_iter = mlx -> max_iter / 1.1;
		else
		{
			write(1, "Too few operations\n", 19);
			return (0);
		}
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	mlx -> mouse_x_norm = (double)x / (double)HW;
	mlx -> mouse_y_norm = (double)y / (double)HW;
	if (keycode == 4)
	{
		ft_zoom_in(mlx);
	}
	else if (keycode == 5)
	{
		ft_zoom_out(mlx);
	}
	return (0);
}

void	ft_zoom_out(t_mlx *mlx)
{
	double	z;

	z = (mlx -> x_max - mlx -> x_min) * mlx -> mouse_x_norm * 0.1;
	mlx -> x_max += (mlx -> x_max - mlx -> x_min)
		* (1 - mlx -> mouse_x_norm) * 0.1;
	mlx -> x_min -= z;
	z = (mlx -> y_max - mlx -> y_min) * mlx -> mouse_y_norm * 0.1;
	mlx -> y_max += (mlx -> y_max - mlx -> y_min)
		* (1 - mlx -> mouse_y_norm) * 0.1;
	mlx -> y_min -= z;
}

void	ft_zoom_in(t_mlx *mlx)
{
	double	z;

	z = (mlx -> x_max - mlx -> x_min) * mlx -> mouse_x_norm * 0.1;
	mlx -> x_max -= (mlx -> x_max - mlx -> x_min)
		* (1 - mlx -> mouse_x_norm) * 0.1;
	mlx -> x_min += z;
	z = (mlx -> y_max - mlx -> y_min) * mlx -> mouse_y_norm * 0.1;
	mlx -> y_max -= (mlx -> y_max - mlx -> y_min)
		* (1 - mlx -> mouse_y_norm) * 0.1;
	mlx -> y_min += z;
}
