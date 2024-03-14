/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:25:09 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/14 15:46:45 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checks(char **map)
{
	int i;
	int	j;
	int	map_height;

	i = 0;
	j = 0;
	map_height = 0;
	ft_mapform(map);
	ft_mapchars(map);
	ft_mapfirstandlast(map);
	ft_maplines(map);
	ft_mapgamesetsexit(map);
	ft_mapgamesetsconsum(map);
	ft_mapgamesetspos(map);
	ft_exploremap(map, i, j, map_height);
}
