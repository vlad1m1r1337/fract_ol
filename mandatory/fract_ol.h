/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:27:02 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/11 14:42:40 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define HW 500

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data;
	int		bpp;
	int 	endian;
	int		scale;
	double	center_y;
	double	center_x;
	int 	size_l;
	double	comp_x;
	double	comp_y;
	//-------------------------ic--------------------------//
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		max_iter;	
}			t_mlx;


int ft_strcmp(char *s1, char *s2);

#endif