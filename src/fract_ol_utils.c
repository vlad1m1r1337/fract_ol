/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:46:39 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/24 21:36:17 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 - *s2 == 0)
	{
		s1++;
		s2++;
	}
	return((unsigned char)(*s1 - *s2));
}

int ex(void)
{
	exit(0);
}

void	warning_message(void)
{
	write(1, "Write name of fractal please\n", 29);
	exit(0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	dst = mlx -> data + (y * mlx -> size_l + x * (mlx -> bpp / 8));
	*(unsigned int*)dst = color;
}

double	my_atof(char *str)
{
	double	mcount;
	int		i;
	int     beg;
	double	result;
	double	after_dot;

	after_dot = 0;
	i = 0;
	result = 0;
	mcount = 1;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-')
	{
		mcount = mcount * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= 9 + '0' && str[i] >= 0 + '0')
	{
		result = 10 * result + str[i] - '0';
		i++;
		if (str[i] == '.')
		{
		    beg = i;
		    i++;
		    while (str[i] && str[i] <= 9 + '0' && str[i] >= 0 + '0')
        	{
        		after_dot++;
        		i++;
        	}
        	i = beg++;
		}
	}
	printf("%f\n", result);
	return (result * mcount / (10 * after_dot));
}