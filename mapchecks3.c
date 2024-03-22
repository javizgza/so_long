/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecks3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:34:52 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/19 14:17:48 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mapgamesetsconsum(char **map)
{
	int	i;
	int	j;
	int	consumcounter;

	i = 0;
	consumcounter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				consumcounter++;
			j++;
		}
		i++;
	}
	if (consumcounter >= 1)
		return (1);
	else
		ft_error("No Consum");
	return (0);
}
