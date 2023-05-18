/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:21:23 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/18 21:11:11 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int main(int argc ,char **argv)
{
	t_mlx mlx;
	
	if (argc == 1)
		warning_message();
		
	mlx.x_min = -2;
	mlx.x_max = 1;
	mlx.y_min = -1.5;
	mlx.y_max = 1.5;
	mlx.max_iter = 100;
	mlx.zoom = 1;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, HW, HW, "fract_ol");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, HW, HW);
	mlx.data = mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_l, &mlx.endian);
	if (ft_strcmp("Mandelbrot", argv[1]) == 0)
		draw_mandelbrot_set(&mlx);
	else
		warning_message();
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	hooks(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return(0);
}



/* int main(int argc ,char **argv)
{
	t_mlx *mlx;
	
	mlx = malloc(sizeof(t_mlx)); 
	if (argc == 1)
		warning_message();
	
	mlx -> mlx_ptr = mlx_init();
	mlx -> win_ptr = mlx_new_window(mlx -> mlx_ptr, HW, HW, "fract_ol");
	mlx -> img_ptr = mlx_new_image(mlx -> mlx_ptr, HW, HW);
	mlx -> data = mlx_get_data_addr(mlx -> img_ptr, &mlx -> bpp, &mlx -> size_l, &mlx -> endian);
	printf("%f\n", mlx -> zoom);
	if (ft_strcmp("Mandelbrot", argv[1]) == 0)
		draw_mandelbrot_set(&mlx);
	else
		warning_message();
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, mlx -> img_ptr, 0, 0);
	hooks(mlx);
	mlx_loop(mlx -> mlx_ptr);
	return(0);
} */