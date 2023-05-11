/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:21:23 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/11 17:41:37 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	warning_message(void)
{
	write(1, "Write name of fractal please\n", 29);
	exit(0);
}

int ex(void)
{
	exit(0);
}

int	key_hook(int keycode, t_mlx mlx)
{
	//(void)keycode;
	(void)mlx;
	
	if (keycode == 53)
		exit(0);
	return (0);
}

void	hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx -> win_ptr, key_hook, &mlx);
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, &mlx);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	
	dst = mlx -> data + (y * mlx -> size_l + x * (mlx -> bpp / 8));
	*(unsigned int*)dst = color;
}

void	circle(t_mlx *mlx)
{
	int x = -HW;
	int y = 0;
	
	while (x < HW)
	{
		my_mlx_pixel_put(mlx, x + mlx -> comp_x, y + mlx -> comp_y, 0x00FF0000);
		x++;
		y = sqrt(pow(HW / 2, 2) - pow(x, 2));
	}
}

int	mandelbrot(double cr, double ci, t_mlx *mlx)
{
	int r = 0;
	int i = 0;
	int	iter = 0;
	double	r_temp;
	while (pow(r, 2) + pow(i, 2) < 4 && iter < mlx -> max_iter)
	{
		r_temp = pow(r, 2) - pow(i, 2) + cr;
		i = 2 * r * i + ci;
		r = r_temp;
		iter = iter + 100;
	}
	return (iter/ mlx -> max_iter);
}

void	initial_condition(t_mlx *mlx)
{
	mlx -> x_min = -2;
	mlx -> x_max = 1;
	mlx -> y_min = -1.5;
	mlx -> y_max = 1.5;
	mlx -> max_iter = 1000;
}

void	draw_mandelbrot_set(t_mlx *mlx)
{
	double	x_step = (mlx -> x_max - mlx -> x_min) / HW; // 3
	double	y_step = (mlx -> y_max - mlx -> y_min) / HW; // 3

	for (int y = 0; y < HW; y++)
	{
		for (int x = 0; x < HW; x++)
		{
			double cr = mlx -> x_min + x * x_step;
			double ci = mlx -> y_min + y * y_step;
			int iter = mandelbrot(cr, ci, mlx);
			int color = iter * 16777215;
			printf("%d %d \n", color, iter);
			my_mlx_pixel_put(mlx, x, y, color);
		}
	}
}

int main(int argc ,char **argv)
{
	t_mlx *mlx;
	
	mlx = malloc(sizeof(t_mlx));
	mlx -> comp_x = HW / 2;
	mlx -> comp_y = HW / 2;
	

	if (argc != 2 || !**argv)
		warning_message();
	mlx -> mlx_ptr = mlx_init();
	mlx -> win_ptr = mlx_new_window(mlx -> mlx_ptr, HW, HW, "fract_ol");
	mlx -> img_ptr = mlx_new_image(mlx -> mlx_ptr, HW, HW);
	mlx -> data = mlx_get_data_addr(mlx -> img_ptr, &mlx -> bpp, &mlx -> size_l, &mlx -> endian);
	hooks(mlx);
	initial_condition(mlx);
	draw_mandelbrot_set(mlx);
	// my_mlx_pixel_put(mlx, 250, 250, 16777215);
	// int color = 0;
	// for (int y = 0; y < HW; y++)
	// {
	// 	for (int x = 0; x < HW; x++)
	// 	{
	// 		my_mlx_pixel_put(mlx, x, y, color);
	// 		color++;
	// 	}
	// }
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, mlx -> img_ptr, 0, 0);
	mlx_loop(mlx -> mlx_ptr);
	return(0);
}
