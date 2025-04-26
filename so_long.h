/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:49:11 by ehattab           #+#    #+#             */
/*   Updated: 2025/04/26 16:07:00 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/Header/libft.h"
# include "../libft/Header/get_next_line.h"
# include "../libft/Header/ft_printf.h"
# include "mlx/mlx.h"

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_pars
{
	char	**map;
	int		sizeline;
	int		nbrline;
	char	*ligne;
	int		collectible;
	char	**cmap;
	int		x;
	int		y;
	int		i;
	int		j;
	int		fd;
	int		count;
}		t_pars;

typedef struct s_game
{
	int		height;
	int		width;
	void	*mlx;
	void	*w;
	char	**map;
	void	*background;
	void	*wall;
	void	*player;
	void	*col;
	void	*exit;
	void	*img;
	int		x;
	int		y;
	int		count;
	int		player_x;
	int		player_y;
	int		collected;
	int		nbr_collectible;
	int		new_x;
	int		new_y;
	t_pars	*pars;
}	t_game;

void	file_is_ok(char *file);
void	is_rectangle(t_pars *pars);
void	stock_map(char *av, t_pars *pars);
void	sizemap(t_pars *pars, char *av);
void	map_has_wall(t_pars *pars);
void	error(char *str);
int		occ_z(char *str, char c);
int		ft_strlen2(char *str);
char	*ft_strdup2(const char *s);
char	*ft_strchr2(const char *str, int c);
void	map_e_p_c(t_pars *pars);
void	map_is_possible(t_pars *pars);
void	position_p(t_pars *pars);
void	copymap(t_pars *pars);
void	print_map(char **map);
void	flood_fill(int x, int y, t_pars *pars);
void	check_collectible_and_exit(t_pars *pars);
void	compil_parsing(t_pars *pars, t_game *game);
void	init_map(t_game *game, char **map);
int		exit_game(t_game *game, int flag);
void	draw_map(t_game *g);
void	load_textures(t_game *game);
int		keypress(int keycode, t_game *game);
void	move(t_game *g, int new_x, int new_y);
void	free_map(char **map);
#endif
