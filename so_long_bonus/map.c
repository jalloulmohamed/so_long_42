/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:05:30 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/07 19:11:28 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	map(int fd)
{
	char	*map_1d;
	int		htr;
	char	*s;
	char	**map_2d;

	htr = 0;
	map_1d = ft_strdup("");
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		if (*s == '\n' || s[0] != '1' || s[ft_strlen(s) - 2] != '1')
			return (error_message(1));
		map_1d = ft_strjoin_free(map_1d, s);
		htr++;
		free(s);
	}
	if (*map_1d == '\0')
		return (error_message(4));
	map_2d = ft_split(map_1d, '\n');
	if (check_map(map_2d, htr, map_1d) == 1)
		return ;
	window_game((ft_strlen(map_2d[0])) * 50, htr * 50, map_2d);
	return ;
}
