/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:21:23 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/24 20:29:22 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	initial_parametrs(t_mlx *mlx, char *fr_name, char *j_r, char *j_i)
{
	if (ft_strcmp("Julia", fr_name) == 0)
	{
		mlx -> julia_r = atof(j_r);
		mlx -> julia_i = atof(j_i);
	}
	mlx -> name = fr_name;
	mlx -> x_min = -2;
	mlx -> x_max = 2;
	mlx -> y_min = -2;
	mlx -> y_max = 2;
	mlx -> max_iter = 50;
	mlx -> zoom = 1.0;
	mlx -> center_x = 0;
	mlx -> center_y = 0;
	mlx -> x = 0;
	mlx -> y = 0;
	mlx -> mouse_x = 0;
	mlx -> mouse_y = 0;
}

void	window_creating(t_mlx *mlx)
{
	mlx -> mlx_ptr = mlx_init();
	mlx -> win_ptr = mlx_new_window(mlx -> mlx_ptr, HW, HW, "fract_ol");
	mlx -> img_ptr = mlx_new_image(mlx -> mlx_ptr, HW, HW);
	mlx -> data = mlx_get_data_addr(mlx -> img_ptr, &mlx -> bpp, &mlx -> size_l, &mlx -> endian);
}

int main(int argc ,char **argv)
{
	t_mlx *mlx;
	
	mlx = malloc(sizeof(t_mlx)); 
	if (argc == 1)
		warning_message();
	window_creating(mlx);
	initial_parametrs(mlx, argv[1], argv[2], argv[3]);
	if (ft_strcmp("Mandelbrot", argv[1]) == 0)
	{
		drawing_mandelbrot(mlx);
	}
	else if (ft_strcmp("Julia", argv[1]) == 0)
	{
		drawing_julia(mlx);
	}
	else
		warning_message();
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, mlx -> img_ptr, 0, 0);
	mlx_key_hook(mlx -> win_ptr, key_hook, mlx);
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, mlx);
	mlx_hook(mlx->win_ptr, 4, 1, mouse_hook, mlx);
	mlx_loop(mlx -> mlx_ptr);
	return(0);
}