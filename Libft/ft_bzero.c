/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:14:39 by vgribkov          #+#    #+#             */
/*   Updated: 2023/01/24 18:03:23 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int			i;
	unsigned char			*z;

	i = 0;
	z = (unsigned char *) s;
	while (i < n)
	{
		z[i] = '\0';
		i++;
	}
}
