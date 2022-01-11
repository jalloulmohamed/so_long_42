/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:50:19 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/07 18:52:48 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	window_game(int wid, int hei, char **map_2d)
{
	t_strc	a;

	a.m_2d = map_2d;
	a.z = 0;
	a.e = 0;
	a.mov = 0;
	a.cnt = 0;
	a.cmp = 0;
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, wid, hei, "so_long");
	window_map(&a);
	mlx_hook(a.win, 2, 1L, mov_player, &a);
	mlx_hook(a.win, 17, 1L, exit_game, &a);
	mlx_loop(a.mlx);
	return ;
}
