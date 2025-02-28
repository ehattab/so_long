/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:21:57 by ehattab           #+#    #+#             */
/*   Updated: 2025/02/28 17:20:39 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_E_P_C(t_pars *pars)
{
	int	i;
	int	j;
	int	k;
	
	j = 0;
	i = 1;
	k = 0;
	while (pars->map[i])
	{
		ft_printf("Prblm \n");
		j += occ_z(pars->map[i], 'E');
		j += occ_z(pars->map[i], 'P');
		ft_printf("j = %d\n", j);
		k += occ_z(pars->map[i], 'C');
		ft_printf("k = %d\n", k);
		i++;
	}
	if (j != 2 || k < 1)
	{
		ft_printf("Prblm collectible ou sortie entrer");
	}
}

// int	map_is_possible(fd)
// {}

// int	check_map(fd)
// {}