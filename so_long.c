/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:48:00 by ehattab           #+#    #+#             */
/*   Updated: 2025/04/02 16:16:02 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_pars	pars;
	t_game	game;

	(void)ac;
	(void)av;
	if (ac != 2)
	{
		ft_printf("error\nThere are no 2 arguments");
		return (0);
	}
	file_is_ok(av[1]);
	sizemap(&pars, av[1]);
	stock_map(av[1], &pars);
	compil_parsing(&pars, &game);
	init_map(&game, pars.map);
	load_textures(&game);
	draw_map(&game);
	mlx_key_hook(game.w, keypress, &game);
	mlx_loop(game.mlx);
	free_map(pars.map);
	free_map(game.map);
	return (0);
}
