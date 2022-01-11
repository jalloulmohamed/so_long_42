/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:11:52 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/07 19:29:46 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	pos_player(t_strc *v)
{
	int	f;
	int	s;

	f = 0;
	s = 0;
	while (v->m_2d[f])
	{
		while (v->m_2d[f][s])
		{
			if (v->m_2d[f][s] == 'P')
			{
				v->pox = s;
				v->poy = f;
			}
			s++;
		}
		s = 0;
		f++;
	}
}

void	mov_player_left_right(int keycode, t_strc *v)
{
	if (keycode == 0 && v->m_2d[v->poy][v->pox - 1] != '1'
			&& v->m_2d[v->poy][v->pox - 1] != 'E')
	{
		if (v->m_2d[v->poy][v->pox - 1] == 'C')
			v->cmp++;
		v->m_2d[v->poy][v->pox] = '0';
		put_image("img/vide.xpm", v, v->pox * 50, v->poy * 50);
		v->mov++;
		v->pox--;
		put_image("img/left.xpm", v, v->pox * 50, v->poy * 50);
	}
	if (keycode == 2 && v->m_2d[v->poy][v->pox + 1] != '1'
			&& v->m_2d[v->poy][v->pox + 1] != 'E')
	{
		if (v->m_2d[v->poy][v->pox + 1] == 'C')
			v->cmp++;
		v->m_2d[v->poy][v->pox] = '0';
		put_image("img/vide.xpm", v, v->pox * 50, v->poy * 50);
		v->mov++;
		v->pox++;
		put_image("img/right.xpm", v, v->pox * 50, v->poy * 50);
	}
	return ;
}

void	mov_player_up_down(int keycode, t_strc *v)
{
	if (keycode == 13 && v->m_2d[v->poy - 1][v->pox] != '1'
		&& v->m_2d[v->poy - 1][v->pox] != 'E')
	{
		if (v->m_2d[v->poy - 1][v->pox] == 'C')
			v->cmp++;
		v->m_2d[v->poy][v->pox] = '0';
		put_image("img/vide.xpm", v, v->pox * 50, v->poy * 50);
		v->mov++;
		v->poy--;
		put_image("img/up.xpm", v, v->pox * 50, v->poy * 50);
	}
	else if (keycode == 1 && v->m_2d[v->poy + 1][v->pox] != '1'
			&& v->m_2d[v->poy + 1][v->pox] != 'E')
	{
		if (v->m_2d[v->poy + 1][v->pox] == 'C')
			v->cmp++;
		v->m_2d[v->poy][v->pox] = '0';
		put_image("img/vide.xpm", v, v->pox * 50, v->poy * 50);
		v->mov++;
		v->poy++;
		put_image("img/down.xpm", v, v->pox * 50, v->poy * 50);
	}
	else if (keycode == 53)
		exit_game(keycode, v);
	return ;
}

void	sort(int keycode, t_strc *v)
{
	if ((keycode == 2 && v->m_2d[v->poy][v->pox + 1] == 'E')
			|| (keycode == 1 && v->m_2d[v->poy + 1][v->pox] == 'E')
			|| (keycode == 0 && v->m_2d[v->poy][v->pox - 1] == 'E' )
			|| (keycode == 13 && v->m_2d[v->poy - 1][v->pox] == 'E'))
	{
		exit_game(keycode, v);
	}
}

int	mov_player(int keycode, t_strc *v)
{
	if (v->cmp == v->cnt)
	{
		put_image("img/port_ov.xpm", v, v->poyp, v->poxp);
		sort(keycode, v);
	}
	pos_player(v);
	mov_player_up_down(keycode, v);
	mov_player_left_right(keycode, v);
	if (v->m_2d[v->poy][v->pox] == 'X' || v->m_2d[v->poy][v->pox] == 'f')
		exit_game(keycode, v);
	v->m_2d[v->poy][v->pox] = 'P';
	put_image("img/obstcl.xpm", v, 50, 0);
	put_image("img/obstcl.xpm", v, 2 * 50, 0);
	put_image("img/obstcl.xpm", v, 0, 0);
	mlx_string_put(v->mlx, v->win, 60, 10, 0x01466F, ft_itoa(v->mov));
	mlx_string_put(v->mlx, v->win, 10, 10, 0xffffff, "mov :");
	return (0);
}
