/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:49:11 by ehattab           #+#    #+#             */
/*   Updated: 2025/02/28 16:48:09 by ehattab          ###   ########.fr       */
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
// # include <mlx.h>

typedef struct s_pars
{
	char				**map;
	long unsigned int	sizeline;
	int					nbrline;
	char				*ligne;
}		t_pars;
void	is_rectangle(t_pars *pars);
void	stock_map(char *av, t_pars *pars);
void	sizemap(t_pars *pars, char *av);
void	map_has_wall(t_pars *pars);
void	error();
int		occ_z(char *str, char c);
void	map_E_P_C(t_pars *pars);
#endif