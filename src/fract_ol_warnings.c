/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_warnings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:11:13 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/27 21:35:21 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	warning_message(void)
{
	write(1, "Write name of fractal please\n", 29);
	exit(0);
}

void	bad_parameters(void)
{
	write(1, "Write correct Julia parameters\n", 31);
	exit(0);
}

void	digit_checker(char **arg)
{
	int	i;
	int	j;

	i = 2;
	while (arg[i])
	{
		j = 0;
		if (arg[i][j] == '-')
			j++;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]) && arg[i][j] != '.')
				bad_parameters();
			j++;
		}
		i++;
	}
}

void	dot_checker(char *arg1, char *arg2)
{
	int	count;
	int	i;
	int	j;

	i = -1;
	j = -1;
	count = 0;
	if (arg1[0] == '.' || arg2[0] == '.')
		bad_parameters();
	while (arg1[++i])
	{
		if (arg1[i] == '.')
			count++;
	}
	if (count >= 2)
		bad_parameters();
	count = 0;
	while (arg2[++j])
	{
		if (arg2[j] == '.')
			count++;
	}
	if (count >= 2)
		bad_parameters();
}
