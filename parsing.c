/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:48:55 by ehattab           #+#    #+#             */
/*   Updated: 2025/04/02 16:52:59 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_has_wall(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pars->map[i])
	{
		while (pars->map[0][j])
		{
			if (pars->map[0][j] != '1'
			|| pars->map[pars->nbrline - 1][j] != '1')
				error("the map is not surrounded by a wall");
			j++;
		}
		if (pars->map[i][0] != '1' || pars->map[i][pars->sizeline - 1] != '1')
			error("the map is not surrounded by a wall");
		i++;
	}
}

void	stock_map(char *av, t_pars *pars)
{
	int	i;

	pars->fd = open(av, O_RDONLY);
	if (pars->fd == -1)
		error("file open error");
	pars->map = malloc(sizeof(char *) * (pars->nbrline + 1));
	if (pars->map == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	pars->ligne = get_next_line(pars->fd);
	if (!pars->ligne)
		error("file is empty");
	while (i < pars->nbrline)
	{
		if (pars->ligne[ft_strlen2(pars->ligne) - 1] == '\n')
			pars->ligne[ft_strlen2(pars->ligne) - 1] = '\0';
		pars->map[i] = ft_strdup2(pars->ligne);
		free(pars->ligne);
		pars->ligne = get_next_line(pars->fd);
		i++;
	}
	pars->map[i] = NULL;
	close(pars->fd);
}

void	sizemap(t_pars *pars, char *av)
{
	int		fd;
	char	*str;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error("file open error");
	pars->nbrline = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		pars->nbrline++;
		str = get_next_line(fd);
	}
	free(str);
}

void	is_rectangle(t_pars *pars)
{
	int	i;

	pars->sizeline = ft_strlen2(pars->map[0]);
	i = 1;
	while (pars->map[i])
	{
		if (ft_strlen2(pars->map[i]) != pars->sizeline)
		{
			ft_printf("error: map not rectangle\n");
			exit(1);
		}
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
