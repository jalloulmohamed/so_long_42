/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:45:28 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/07 18:47:34 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error_message(int c)
{
	if (c == 1)
		printf("the map is not completely closed");
	if (c == 2)
	{
		printf("Map should have one and only one player and at ");
		printf("lest one collectable and one exit and one enemy");
	}
	if (c == 3)
		printf("the map doesn't have equal lines");
	if (c == 4)
		printf("Map !!!!!!");
	if (c == 5)
		printf("Map with caracter no !!!!!!");
	if (c == 6)
		printf("The map must be rectangular");
	return ;
}
