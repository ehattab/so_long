/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:48:55 by ehattab           #+#    #+#             */
/*   Updated: 2025/02/28 17:03:45 by ehattab          ###   ########.fr       */
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
			if (pars->map[0][j] != '1' || pars->map[pars->nbrline - 1][j] != '1')
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
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error("file open error");
	pars->map = malloc(sizeof(char *) * (pars->nbrline + 1));
	if (pars->map == NULL)
		error();
	i = 0;
	pars->map[i] = get_next_line(fd);
	if (pars->map[i][ft_strlen(pars->map[i]) - 1] == '\n')
		pars->map[i][ft_strlen(pars->map[i]) - 1] = '\0';
	while(++i < pars->nbrline)
	{
		pars->map[i] = get_next_line(fd);
		if (pars->map[i][ft_strlen(pars->map[i]) - 1] == '\n')
			pars->map[i][ft_strlen(pars->map[i]) - 1] = '\0';
	}
	pars->map[i] = NULL;
	close(fd);
}

void sizemap(t_pars *pars, char *av)
{
	int	fd;
	char *str;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error();
	pars->nbrline = 0;
	str = get_next_line(fd);
	while(str)
	{
		free(str);
		pars->nbrline++;
		str = get_next_line(fd);
	}
}

void	is_rectangle(t_pars *pars)
{
	int i;
	pars->sizeline = ft_strlen(pars->map[0]);
	i = 1;
	while (pars->map[i])
	{
		if (ft_strlen(pars->map[i]) != pars->sizeline)
		{
			ft_printf("error: map not rectangle\n");
			exit(1);
		}
		i++;
	}
}

// int main(int ac, char **av)
// {
// 	t_pars pars;
// 	(void)ac;
// 	(void)av;
// 	sizemap(&pars, av[1]);
// 	stock_map(av[1], &pars);
// 	is_rectangle(&pars);
// 	map_has_wall(&pars);
// }
