/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_morethanonepe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:14:38 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/14 11:41:26 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_morethanonep(char **map)
{
	int	i;
	int	j;
	int	numberofp;

	i = 0;
	numberofp = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][i])
		{
			if (map[i][j] == 'P')
				numberofp++;
			else if (numberofp > '1')
				ft_error("More than 1 initial position");
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_morethanonee(char **map)
{
	int	i;
	int	j;
	int	numberofe;

	i = 0;
	numberofe = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][i])
		{
			if (map[i][j] == 'E')
				numberofe++;
			else if (numberofe > '1')
				ft_error("More than 1 initial position");
			j++;
		}
		i++;
	}
	return (0);
}
