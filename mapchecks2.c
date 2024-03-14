/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:47:28 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/14 11:39:07 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	ft_strlen_map(char **map)
{
	t_position	size;
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
			size.x = j - 1;
		}
		i++;
	}
	size.y = i;
	return (size);
}

t_position	ft_checkinitposition(char **map)
{
	t_position	pos;
	int			i;
	int			j;

	pos.x = -1;
	pos.y = -1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

void	ft_exploremap(char **map, int i, size_t j, int map_height)
{
	if (i < 0 || i >= map_height || j < 0 || j >= ft_strlen(map[i]))
		ft_error("Not in map");
	if (map[i][j] == 'a' || map[i][j] == '1')
		return ;
	map[i][j] = 'a';
	ft_exploremap(map, i + 1, j, map_height);
	ft_exploremap(map, i - 1, j, map_height);
	ft_exploremap(map, i, j + 1, map_height);
	ft_exploremap(map, i, j - 1, map_height);
}

int	ft_checkfilledcorrect(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_mapgamesetspos(char **map)
{
	int	i;
	int	j;
	int	poscounter;

	i = 0;
	poscounter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				poscounter++;
			j++;
		}
		i++;
	}
	if (poscounter == 1)
		return (1);
	else
		ft_error("Invalid game");
	return (0);
}
