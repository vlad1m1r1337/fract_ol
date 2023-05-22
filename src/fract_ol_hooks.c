/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:28:20 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/22 17:27:47 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(0);
	return (0);
}

int mouse_hook(int keycode, int xx, int yy, t_mlx *mlx)
{
	double x = xx - 350;
	double y = yy - 350;
	
	if (keycode == 4)
	{
		//mlx -> down = 1;
		mlx -> x_min = x / HW * 4 + ((mlx -> x_min - x / HW * 4) * 0.9);
		mlx -> y_min = y / HW * 4 + ((mlx -> y_min - y / HW * 4) * 0.9);
		mlx -> y_max = y / HW * 4 + ((mlx -> y_max - y / HW * 4) * 0.9);
		mlx -> x_max = x / HW * 4 + ((mlx -> x_max - x / HW * 4) * 0.9);
		draw_mandelbrot_set(mlx);
		mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, mlx -> img_ptr, 0, 0);
	}
	else if (keycode == 5)
	{
		//mlx -> up = 1;
		mlx -> x_min = x / HW * 4 + ((mlx -> x_min - x / HW * 4) + (mlx -> x_min - x / HW * 4) * 0.1);
		mlx -> y_min = y / HW * 4 + ((mlx -> y_min - y / HW * 4) + (mlx -> y_min - y / HW * 4) * 0.1);
		mlx -> y_max = y / HW * 4 + ((mlx -> y_max - y / HW * 4) + (mlx -> y_max - y / HW * 4) * 0.1);
		mlx -> x_max = x / HW * 4 + ((mlx -> x_max - x / HW * 4) + (mlx -> x_max - x / HW * 4) * 0.1);
		draw_mandelbrot_set(mlx);
		mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, mlx -> img_ptr, 0, 0);
	}
	return (0);
}

// mouse_hook_draw(t_mlx *mlx)
// {
// 	if (mlx -> down = 1)
// 	{
// 		mlx -> x_min = x / HW + ((mlx -> x_min - x / HW) * 0.9);
// 		mlx -> y_min = y / HW + ((mlx -> y_min - y / HW) * 0.9);
// 		mlx -> y_max = y / HW + ((mlx -> y_max - y / HW) * 0.9);
// 		mlx -> x_max = x / HW + ((mlx -> x_max - x / HW) * 0.9);
// 		draw_mandelbrot_set(mlx);
// 		mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, mlx -> img_ptr, 0, 0);
// 	}
// }

void	hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx -> win_ptr, key_hook, mlx);
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, mlx);
	mlx_mouse_hook(mlx -> win_ptr, mouse_hook, mlx);
}