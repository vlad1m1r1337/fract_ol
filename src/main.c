/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:21:23 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/19 20:58:10 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	ic_m(t_mlx *mlx)
{
	mlx -> x_min = -1;
	mlx -> x_max = 1;
	mlx -> y_min = -1;
	mlx -> y_max = 1;
	mlx -> max_iter = 20;
	mlx -> zoom = 1.0;
	mlx -> center_x = 0;
	mlx -> center_y = 0;
	mlx -> x = 0;
	mlx -> y = 0;
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
	if (ft_strcmp("Mandelbrot", argv[1]) == 0)
	{
		ic_m(mlx);
		draw_mandelbrot_set(mlx);
	}
	else
		warning_message();
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, mlx -> img_ptr, 0, 0);
	hooks(mlx);
	mlx_loop(mlx -> mlx_ptr);
	return(0);
}