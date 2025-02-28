/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:48:00 by ehattab           #+#    #+#             */
/*   Updated: 2025/02/28 17:18:43 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_pars pars;
	(void)ac;
	(void)av;
	sizemap(&pars, av[1]);
	stock_map(av[1], &pars);
	is_rectangle(&pars);
	map_has_wall(&pars);
	map_E_P_C(&pars);
}