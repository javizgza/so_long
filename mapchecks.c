/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:18:48 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/14 11:32:43 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mapform(char **map)
{
	int		i;
	size_t	len;

	i = 1;
	while (!map || !map[0])
		ft_error("Invalid form");
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			ft_error("Invalid form");
		i++;
	}
	return (1);
}

int	ft_mapchars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' \
				&& map[i][j] != 'E' && map[i][j] != 'C')
				ft_error("Invalid characters");
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_mapfirstandlast(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[0][j] && map[0][j] != '\n')
	{
		if (map[0][j] != '1')
			ft_error("Invalid  first line walls");
		j++;
	}
	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (map[i - 1][j] && map[0][j] != '\n')
	{
		while (map[i - 1][j] != '1')
			ft_error("Invalid  last line walls");
		j++;
	}
	return (1);
}

int	ft_maplines(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			ft_error("Invalid line walls");
		i++;
	}
	return (1);
}

int	ft_mapgamesetsexit(char **map)
{
	int	i;
	int	j;
	int	exitcounter;

	i = 0;
	exitcounter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exitcounter++;
			j++;
		}
		i++;
	}
	if (exitcounter == 1)
		return (1);
	else
		ft_error("Invalid game");
	return (0);
}
