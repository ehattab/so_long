/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:21:57 by ehattab           #+#    #+#             */
/*   Updated: 2025/03/25 17:04:33 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_e_p_c(t_pars *pars)
{
	int	i;
	int	e;
	int	p;

	e = 0;
	i = 1;
	p = 0;
	pars->collectible = 0;
	while (pars->map[i])
	{
		e += occ_z(pars->map[i], 'E');
		p += occ_z(pars->map[i], 'P');
		pars->collectible += occ_z(pars->map[i], 'C');
		i++;
	}
	if (pars->collectible < 1)
		error("There are not enough collectibles");
	else if (e != 1)
		error("There is a problem with the exit");
	else if (p != 1)
		error("There is a problem with the spawn player");
}

void	position_p(t_pars *pars)
{
	pars->y = 1;
	pars->x = 0;
	while (pars->map[pars->y])
	{
		while (pars->map[pars->y][pars->x])
		{
			if (pars->map[pars->y][pars->x] == 'P')
				return ;
			pars->x++;
		}
		pars->y++;
		pars->x = 0;
	}
}

void	flood_fill(int x, int y, t_pars *pars)
{
	if (x < 0 || y < 0 || y >= pars->nbrline || x >= pars->sizeline
		|| ft_strchr2("1FE", pars->cmap[y][x]))
		return ;
	pars->cmap[y][x] = 'F';
	flood_fill(x + 1, y, pars);
	flood_fill(x - 1, y, pars);
	flood_fill(x, y + 1, pars);
	flood_fill(x, y - 1, pars);
}

void	copymap(t_pars *pars)
{
	int	i;

	pars->cmap = malloc(sizeof(char *) * (pars->nbrline + 1));
	if (!pars->cmap)
		exit(EXIT_FAILURE);
	i = 0;
	while (i != pars->nbrline)
	{
		pars->cmap[i] = ft_strdup2(pars->map[i]);
		i++;
	}
	pars->cmap[i] = NULL;
}

void	check_collectible_and_exit(t_pars *pars)
{
	int	c;

	c = 0;
	pars->j = 0;
	pars->i = 1;
	while (pars->cmap[pars->i])
	{
		while (pars->cmap[pars->i][pars->j])
		{
			if (pars->cmap[pars->i][pars->j] == 'E')
			{
				if (pars->cmap[pars->i + 1][pars->j] != 'F'
					&& pars->cmap[pars->i - 1][pars->j] != 'F'
					&& pars->cmap[pars->i][pars->j + 1] != 'F'
					&& pars->cmap[pars->i][pars->j - 1] != 'F')
					error("the exit is not accessible");
			}
			pars->j++;
		}
		c += occ_z(pars->cmap[pars->i], 'C');
		pars->i++;
		pars->j = 0;
	}
	if (c != 0)
		error("not all collectibles are available");
}
