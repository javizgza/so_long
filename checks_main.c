/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:25:09 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/14 11:41:23 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checks(char **map)
{
	ft_mapform(map);
	ft_mapchars(map);
	ft_mapfirstandlast(map);
	ft_maplines(map);
	ft_mapgamesetsexit(map);
	ft_mapgamesetsconsum(map);
	ft_mapgamesetspos(map);
}
