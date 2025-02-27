/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:21:44 by ehattab           #+#    #+#             */
/*   Updated: 2025/02/27 18:06:44 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int occ_z(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

void	error(char *str)
{
	ft_printf("error: %s\n", str);
	exit(1);
}
