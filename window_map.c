/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:55:30 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/07 19:04:35 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	condition_map(char b, t_strc *v)
{
	if (b == 'C')
	{
		put_image("img/vide.xpm", v, v->l, v->k);
		put_image("img/cole.xpm", v, v->l + 7, v->k + 7);
		v->cnt++;
	}
	if (b == 'E')
	{
		put_image("img/port.xpm", v, v->l, v->k);
		v->poxp = v->k;
		v->poyp = v->l;
	}
	if (b == '0')
		put_image("img/vide.xpm", v, v->l, v->k);
	if (b == 'P')
		put_image("img/down.xpm", v, v->l, v->k);
	if (b == '1')
		put_image("img/obstcl.xpm", v, v->l, v->k);
}

void	window_map(t_strc *v)
{
	int	f;
	int	s;

	v->k = 0;
	v->l = 0;
	f = 0;
	s = 0;
	while (v->m_2d[f])
	{
		while (v->m_2d[f][s])
		{
			condition_map(v->m_2d[f][s], v);
			if ((size_t)s == ft_strlen(v->m_2d[f]) - 1)
			{
				v->k = v->k + 50;
				v->l = 0;
			}
			else
				v->l = v->l + 50;
			s++;
		}
		s = 0;
		f++;
	}
	return ;
}
