/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:25:09 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/22 12:26:58 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checks(char **map)
{
	t_position	pos;

	pos = ft_checkinitposition(map);
	ft_mapform(map);
	ft_mapchars(map);
	ft_mapfirstandlast(map);
	ft_maplines(map);
	ft_mapgamesetsexit(map);
	ft_mapgamesetsconsum(map);
	ft_mapgamesetspos(map);
	ft_exploremap(map, pos.y, pos.x);
	ft_checkfinally(map);
}

int	ft_checkfinally(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				ft_error("Consum or exit impossible to reach");
			x++;
		}
		y++;
	}
	return (0);
}
