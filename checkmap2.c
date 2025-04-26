/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:09:22 by ehattab           #+#    #+#             */
/*   Updated: 2025/04/26 16:08:43 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_is_ok(char *file)
{
	int	fd;
	int	len;

	len = strlen(file);
	if (len < 4 || strcmp(file + len - 4, ".ber") != 0)
		return (error("please insert a file .ber"));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("file open error");
	close(fd);
}

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_printf(map[i]);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	compil_parsing(t_pars *pars, t_game *game)
{
	is_rectangle(pars);
	map_has_wall(pars);
	map_e_p_c(pars);
	copymap(pars);
	position_p(pars);
	flood_fill(pars->x, pars->y, pars);
	check_collectible_and_exit(pars);
	free_map(pars->cmap);
	game->nbr_collectible = pars->collectible;
	game->collected = 0;
	game->player_x = pars->x;
	game->player_y = pars->y;
	game->count = 1;
	game->background = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->col = NULL;
	game->exit = NULL;
}

int	exit_game(t_game *game, int flag)
{
	if (game->background)
		mlx_destroy_image(game->mlx, game->background);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->col)
		mlx_destroy_image(game->mlx, game->col);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->w);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(flag);
}
