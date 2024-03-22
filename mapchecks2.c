/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:47:28 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/19 14:18:16 by jazarago         ###   ########.fr       */
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

void	ft_exploremap(char **map, int i, size_t j)
{
	if (map[i][j] == 'a' || map[i][j] == '1')
		return ;
	map[i][j] = 'a';
	ft_exploremap(map, i + 1, j);
	ft_exploremap(map, i - 1, j);
	ft_exploremap(map, i, j + 1);
	ft_exploremap(map, i, j - 1);
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
		ft_error("Invalid P/P's");
	return (0);
}
