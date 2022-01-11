/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:30:52 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/07 18:32:44 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	put_image(char *b, t_strc *v, int l, int k)
{
	void	*im;

	im = mlx_xpm_file_to_image(v->mlx, b, &v->z, &v->e);
	mlx_put_image_to_window(v->mlx, v->win, im, l, k);
	return ;
}
