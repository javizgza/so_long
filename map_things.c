/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:06:18 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/13 16:35:53 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw_walls(t_moves *moves, char **map, void *wall_img)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(moves->mlx, moves->win, wall_img, \
					j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_draw_background(t_moves *moves, char **map, void *background_img)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			mlx_put_image_to_window(moves->mlx, moves->win, background_img, \
				j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_draw_consum(t_moves *moves, char **map, void *consum_img)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(moves->mlx, moves->win, consum_img, \
					j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_draw_exit(t_moves *moves, char **map, void *exit_img)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				mlx_put_image_to_window(moves->mlx, moves->win, exit_img, \
					j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_draw_character(t_moves *moves, char **map, void *char_img)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				mlx_put_image_to_window(moves->mlx, moves->win, char_img, \
					j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (0);
}
