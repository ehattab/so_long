/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:20:19 by ehattab           #+#    #+#             */
/*   Updated: 2025/04/26 16:06:40 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game, char **map)
{
	int	height;
	int	width;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->map = map;
	if (!game->map)
		exit(EXIT_FAILURE);
	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	game->height = height;
	game->width = width;
	game->w = mlx_new_window(game->mlx, width * 64, height * 64, "So_long");
	mlx_key_hook(game->w, keypress, game);
	mlx_hook(game->w, 17, 0, exit_game, game);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		exit_game(game, 0);
	if (keycode == W_KEY && game->player_y > 0)
		move(game, game->player_x, game->player_y - 1);
	if (keycode == A_KEY && game->player_x > 0)
		move(game, game->player_x - 1, game->player_y);
	if (keycode == S_KEY && game->player_y < game->height)
		move(game, game->player_x, game->player_y + 1);
	if (keycode == D_KEY && game->player_x < game->width)
		move(game, game->player_x + 1, game->player_y);
	return (0);
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	game->background = mlx_xpm_file_to_image(game->mlx,
			"xpm/dungeonfloor.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"xpm/lava.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"xpm/player.xpm", &width, &height);
	game->col = mlx_xpm_file_to_image(game->mlx,
			"xpm/chest.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"xpm/portal.xpm", &width, &height);
	if (!game->background || !game->wall || !game->player || !game->col
		|| !game->exit)
	{
		ft_printf("Error:\nxpm file is not avaible\n");
		mlx_destroy_window(game->mlx, game->w);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
}

void	draw_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			mlx_put_image_to_window(g->mlx, g->w, g->background,
				x * 64, y * 64);
			if (g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->w, g->wall, x * 64, y * 64);
			if (g->map[y][x] == 'P')
				mlx_put_image_to_window(g->mlx, g->w, g->player, x * 64,
					y * 64);
			if (g->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->w, g->exit, x * 64, y * 64);
			if (g->map[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->w, g->col, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	move(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] != 'E')
		ft_printf("moove player : %d\n", game->count);
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collected++;
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected == game->nbr_collectible)
			exit_game(game, 0);
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_y = new_y;
	game->player_x = new_x;
	game->count++;
	draw_map(game);
}
