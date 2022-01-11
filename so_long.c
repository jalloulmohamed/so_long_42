/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:44:29 by mjalloul          #+#    #+#             */
/*   Updated: 2022/01/08 13:38:38 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 2 || argc < 2)
	{
		perror("Error: ");
	}
	else
	{
		fd = open(argv[1], O_RDONLY, 777);
		if (fd == -1)
		{
			perror("Error: ");
			return (0);
		}
		map(fd);
	}
}
