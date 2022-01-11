/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:04:32 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/08 13:44:10 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"

typedef struct strc {
	void	*mlx;
	void	*win;
	int		pox;
	int		poy;
	char	**m_2d;
	int		cmp;
	int		cnt;
	int		mov;
	int		z;
	int		e;
	void	*img;
	int		poxp;
	int		poyp;
	int		l;
	int		k;
	int		poxe;
	int		poye;
}	t_strc;

int		check_map(char **p, int i, char *m_1d);
int		enemy(t_strc *v);
void	error_message(int c);
int		exit_game(int keycode, t_strc *s);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen_newline(const char *str);
void	map(int fd);
void	put_image(char *b, t_strc *v, int l, int k);
void	so_long(int fd);
int		mov_player(int keycode, t_strc *v);
void	window_game(int wid, int hei, char **m_2d);
void	window_map(t_strc *v);

#endif
