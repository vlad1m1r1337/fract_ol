/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:46:39 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/18 17:47:49 by vgribkov         ###   ########.fr       */
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
