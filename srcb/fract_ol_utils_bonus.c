/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:46:39 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/30 18:09:13 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 - *s2 == 0)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1 - *s2));
}

int	ex(void)
{
	exit(0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx -> data + (y * mlx -> size_l + x * (mlx -> bpp / 8));
	*(unsigned int *)dst = color;
}

double	my_atof(char *str)
{
	double	num_int;
	double	num_fract;
	int		len_fract;

	num_int = (double)ft_atoi(str);
	while (str && *str && *str != '.')
		str++;
	str++;
	num_fract = (double)ft_atoi(str);
	len_fract = ft_strlen(str);
	while (ft_isdigit(*str))
	{
		num_fract /= 10;
		str++;
	}
	if (num_int >= 0)
		return (num_int + num_fract);
	else
		return (num_int - num_fract);
}

int	wasd(int keycode, t_mlx *mlx)
{
	if (keycode == 1)
	{
		mlx -> y_max = (mlx -> y_max + mlx -> wasd);
		mlx -> y_min = (mlx -> y_min + mlx -> wasd);
	}
	if (keycode == 13)
	{
		mlx -> y_max = (mlx -> y_max - mlx -> wasd);
		mlx -> y_min = (mlx -> y_min - mlx -> wasd);
	}
	if (keycode == 2)
	{
		mlx -> x_max = (mlx -> x_max + mlx -> wasd);
		mlx -> x_min = (mlx -> x_min + mlx -> wasd);
	}
	if (keycode == 0)
	{
		mlx -> x_max = (mlx -> x_max - mlx -> wasd);
		mlx -> x_min = (mlx -> x_min - mlx -> wasd);
	}
	return (0);
}
