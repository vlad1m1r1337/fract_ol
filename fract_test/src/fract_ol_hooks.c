/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:28:20 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/18 21:08:51 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
	{
		printf("up\n");
		printf("%f\n", mlx -> zoom);
	}
	else if (keycode == 125)
	{
		printf("down\n");
		printf("%f\n", mlx -> zoom);
	}
	return (0);
}

void	hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx -> win_ptr, key_hook, &mlx);
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, &mlx);
}