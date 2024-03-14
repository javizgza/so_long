/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:09:52 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/14 15:13:40 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_moves *moves, int new_x, int new_y)
{
	if (moves->map[new_y][new_x] != '1')
	{
		mlx_put_image_to_window(moves->mlx, moves->win, moves->background_img, \
			moves->pos_x * 50, moves->pos_y * 50);
		if (moves->map[moves->pos_y][moves->pos_x] == 'E')
			mlx_put_image_to_window(moves->mlx, moves->win, moves->exit_img, \
				moves->pos_x * 50, moves->pos_y * 50);
		moves->pos_x = new_x;
		moves->pos_y = new_y;
		mlx_put_image_to_window(moves->mlx, moves->win, moves->char_img, \
			new_x * 50, new_y * 50);
	}
	if (moves->map[new_y][new_x] == 'C')
	{
		moves->collected++;
		moves->map[new_y][new_x] = '0';
	}
	if (moves->map[new_y][new_x] == 'E' && \
		moves->collected == moves->totalconsum)
	{
		mlx_destroy_window(moves->mlx, moves->win);
		ft_printf("SUCCESS.\nCongratulations!\n");
		ft_freemap(moves->map);
		exit(0);
	}
}

void	ft_collectables(t_moves *moves)
{
	int	x;
	int	y;

	y = 0;
	moves->totalconsum = 0;
	while (moves->map[y])
	{
		x = 0;
		while (moves->map[y][x])
		{
			if (moves->map[y][x] == 'C')
				moves->totalconsum++;
			x++;
		}
		y++;
	}
}

int	ft_handle_moves(int keycode, t_moves *moves)
{
	int	new_x;
	int	new_y;
	int	prev_y;
	int	prev_x;

	prev_y = moves->pos_y;
	prev_x = moves->pos_x;
	new_x = moves->pos_x;
	new_y = moves->pos_y;
	if (keycode == 126 || keycode == 13)
		ft_move(moves, moves->pos_x, moves->pos_y - 1);
	if (keycode == 125 || keycode == 1)
		ft_move(moves, moves->pos_x, moves->pos_y + 1);
	if (keycode == 123 || keycode == 0)
		ft_move(moves, moves->pos_x - 1, moves->pos_y);
	if (keycode == 124 || keycode == 2)
		ft_move(moves, moves->pos_x + 1, moves->pos_y);
	if (prev_x != moves->pos_x || prev_y != moves->pos_y)
	{
		moves->move_count++;
		ft_printf("Movements made: %d\n", moves->move_count);
	}
	return (0);
}
