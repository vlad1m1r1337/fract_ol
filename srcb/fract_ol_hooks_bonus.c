/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_hooks_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:28:20 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/30 18:51:25 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol_bonus.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(0);
	else if (keycode == 34)
	{
		mlx -> max_iter = mlx -> max_iter * 1.1;
	}
	else if (keycode == 40)
	{
		if (mlx -> max_iter > 10)
			mlx -> max_iter = mlx -> max_iter / 1.1;
		else
		{
			write(1, "Too few operations\n", 19);
			return (0);
		}
	}
	wasd(keycode, mlx);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	mlx -> mouse_x_norm = (double)x / (double)HW;
	mlx -> mouse_y_norm = (double)y / (double)HW;
	if (keycode == 4)
	{
		mlx -> wasd /= 1.1;
		zoom_in(mlx);
	}
	else if (keycode == 5)
	{
		mlx -> wasd *= 1.1;
		zoom_out(mlx);
	}
	return (0);
}

void	zoom_out(t_mlx *mlx)
{
	double	temp;

	temp = (mlx -> x_max - mlx -> x_min) * mlx -> mouse_x_norm * 0.1;
	mlx -> x_max += (mlx -> x_max - mlx -> x_min)
		* (1 - mlx -> mouse_x_norm) * 0.1;
	mlx -> x_min -= temp;
	temp = (mlx -> y_max - mlx -> y_min) * mlx -> mouse_y_norm * 0.1;
	mlx -> y_max += (mlx -> y_max - mlx -> y_min)
		* (1 - mlx -> mouse_y_norm) * 0.1;
	mlx -> y_min -= temp;
}

void	zoom_in(t_mlx *mlx)
{
	double	temp;

	temp = (mlx -> x_max - mlx -> x_min) * mlx -> mouse_x_norm * 0.1;
	mlx -> x_max -= (mlx -> x_max - mlx -> x_min)
		* (1 - mlx -> mouse_x_norm) * 0.1;
	mlx -> x_min += temp;
	temp = (mlx -> y_max - mlx -> y_min) * mlx -> mouse_y_norm * 0.1;
	mlx -> y_max -= (mlx -> y_max - mlx -> y_min)
		* (1 - mlx -> mouse_y_norm) * 0.1;
	mlx -> y_min += temp;
}

void	hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx -> win_ptr, wasd, mlx);
	mlx_key_hook(mlx -> win_ptr, key_hook, mlx);
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, mlx);
	mlx_hook(mlx -> win_ptr, 4, 1, mouse_hook, mlx);
}
