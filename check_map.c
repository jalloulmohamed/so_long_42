/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:11:49 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/07 18:30:10 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check3_map(char **p, int s, char *m)
{
	if (ft_strchr(m, 'E') == 0 || ft_strchr(m, 'C') == 0
		|| ft_strchr(m, '1') == 0 || ft_strchr(m, '0') == 0
		|| ft_strchr(m, 'P') == 0)
	{
		error_message(2);
		return (1);
	}
	if (ft_strlen(p[0]) == (size_t)s)
	{
		error_message(6);
		return (1);
	}
	return (0);
}

int	check2_map(char **p, int s)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen_newline(p[0]);
	while (p[i])
	{
		if (ft_strlen_newline(p[i]) != len)
		{
			error_message(3);
			return (1);
		}
		i++;
	}
	if (ft_strchr(p[0], 'E') == 1 || ft_strchr(p[0], 'P') == 1
		|| ft_strchr(p[0], '0') == 1 || ft_strchr(p[0], 'C') == 1
		|| ft_strchr(p[s - 1], 'E') == 1 || ft_strchr(p[s - 1], 'P') == 1
		|| ft_strchr(p[s - 1], '0') == 1 || ft_strchr(p[s - 1], 'C') == 1)
	{
		error_message(1);
		return (1);
	}
	return (0);
}

int	check_map(char **p, int i, char *m)
{
	int	r;
	int	j;

	r = 0;
	j = 0;
	if (check2_map(p, i) == 1 || check3_map(p, i, m) == 1)
		return (1);
	while (m[r])
	{
		if (m[r] == 'P')
			j++;
		if ((m[r] != 'E' && m[r] != '1' && m[r] != '0' && m[r] != 'C'
				&& m[r] != 'P' && m[r] != '\n' ) || j > 1)
		{
			error_message(5);
			return (1);
		}
		r++;
	}
	return (0);
}
