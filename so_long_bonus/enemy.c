/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:33:36 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/07 20:02:41 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	pos_enemy(t_strc *v)
{
	int	f;
	int	s;

	f = 0;
	s = 0;
	while (v->m_2d[f])
	{
		while (v->m_2d[f][s])
		{
			if (v->m_2d[f][s] == 'X')
			{
				v->poxe = s;
				v->poye = f;
			}
			s++;
		}
		s = 0;
		f++;
	}
}

int	enemy(t_strc *v)
{
	pos_enemy(v);
	if (v->m_2d[v->poye][v->poxe + 1] != 'E'
		&& v->m_2d[v->poye][v->poxe + 1] != '1'
		&& v->m_2d[v->poye][v->poxe + 1] != 'C')
	{
		v->m_2d[v->poye][v->poxe] = 'f';
		put_image("img/vide.xpm", v, v->poxe * 50, v->poye * 50);
		put_image("img/enemy1.xpm", v, v->poxe * 50, v->poye * 50);
		v->poxe++;
		usleep(50000);
		put_image("img/enemy3.xpm", v, v->poxe * 50, v->poye * 50);
	}
	else if (v->m_2d[v->poye][v->poxe - 1] != 'E'
			&& v->m_2d[v->poye][v->poxe - 1] != '1'
			&& v->m_2d[v->poye][v->poxe - 1] != 'C')
	{
		v->m_2d[v->poye][v->poxe] = 'f';
		put_image("img/vide.xpm", v, v->poxe * 50, v->poye * 50);
		put_image("img/enemy1.xpm", v, v->poxe * 50, v->poye * 50);
		v->poxe--;
		usleep(50000);
		put_image("img/enemy3.xpm", v, v->poxe * 50, v->poye * 50);
	}
	v->m_2d[v->poye][v->poxe] = 'X';
	return (0);
}
