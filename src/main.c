/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:21:23 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/29 14:52:52 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	initial_parametrs(t_mlx *mlx, char *fr_name)
{
	mlx -> name = fr_name;
	mlx -> x_min = -2;
	mlx -> x_max = 2;
	mlx -> y_min = -2;
	mlx -> y_max = 2;
	mlx -> max_iter = 50;
	mlx -> wasd = 1.0;
	mlx -> center_x = 0;
	mlx -> center_y = 0;
	mlx -> x = 0;
	mlx -> y = 0;
	mlx -> mouse_x_norm = 0;
	mlx -> mouse_y_norm = 0;
	mlx -> julia_r = -0.4;
	mlx -> julia_i = 0.6;
}

void	window_creating(t_mlx *mlx)
{
	mlx -> mlx_ptr = mlx_init();
	mlx -> win_ptr = mlx_new_window(mlx -> mlx_ptr, HW, HW, "fract_ol");
	mlx -> img_ptr = mlx_new_image(mlx -> mlx_ptr, HW, HW);
	mlx -> data = mlx_get_data_addr(mlx -> img_ptr, &mlx -> bpp,
			&mlx -> size_l, &mlx -> endian);
}

int	render_check(t_mlx *mlx, int argc, char **argv)
{
	if (mlx -> win_ptr != NULL)
	{
		if (ft_strcmp("Mandelbrot", mlx -> name) == 0)
			drawing_mandelbrot(mlx);
		else if (ft_strcmp("Julia", mlx -> name) == 0
			&& julia_parametres_check(mlx, argc, argv))
			drawing_julia(mlx);
		mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr,
			mlx -> img_ptr, 0, 0);
	}
	return (0);
}

int	julia_parametres_check(t_mlx *mlx, int argc, char **argv)
{
	if (argc == 2)
		return (1);
	if (argc == 3)
		bad_parameters();
	digit_checker(argv);
	dot_checker(argv[2], argv[3]);
	if (argc == 4)
	{
		mlx -> julia_r = atof(argv[2]);
		mlx -> julia_i = atof(argv[3]);
	}
	else
	{
		bad_parameters();
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (argc == 1)
	{
		warning_message();
	}
	window_creating(mlx);
	initial_parametrs(mlx, argv[1]);
	hooks(mlx);
	mlx_loop_hook(mlx -> mlx_ptr, &render_check, mlx);
	mlx_loop(mlx -> mlx_ptr);
	return (0);
}

