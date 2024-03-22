/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:58:04 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/22 14:34:16 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_moves(t_moves *moves, char **map)
{
	t_position	map_size;

	map_size = ft_strlen_map(map);
	moves->map = map;
	moves->map_width = map_size.x;
	moves->map_height = map_size.y;
	moves->mlx = mlx_init();
	moves->win = mlx_new_window(moves->mlx, moves->map_width * 50, \
		moves->map_height * 50, "so_long game");
}

void	load_images(t_moves *moves)
{
	int	width;
	int	height;

	moves->background_img = mlx_xpm_file_to_image(moves->mlx, \
		"./sprites/grass.xpm", &width, &height);
	if (!moves->background_img)
		ft_error("Failed load image");
	moves->wall_img = mlx_xpm_file_to_image(moves->mlx, \
		"./sprites/wood.xpm", &width, &height);
	if (!moves->wall_img)
		ft_error("Failed load image");
	moves->consum_img = mlx_xpm_file_to_image(moves->mlx, \
		"./sprites/ball.xpm", &width, &height);
	if (!moves->consum_img)
		ft_error("Failed load image");
	moves->exit_img = mlx_xpm_file_to_image(moves->mlx, \
		"./sprites/goal1.xpm", &width, &height);
	if (!moves->exit_img)
		ft_error("Failed load image");
	moves->char_img = mlx_xpm_file_to_image(moves->mlx, \
		"./sprites/character.xpm", &width, &height);
	if (!moves->char_img)
		ft_error("Failed load image");
}

void	draw_game(t_moves *moves)
{
	ft_draw_background(moves, moves->map, moves->background_img);
	ft_draw_walls(moves, moves->map, moves->wall_img);
	ft_draw_consum(moves, moves->map, moves->consum_img);
	ft_draw_exit(moves, moves->map, moves->exit_img);
	ft_draw_character(moves, moves->map, moves->char_img);
}

void	game_setup(t_moves *moves)
{
	ft_checkinitialcharpos(moves->map, moves);
	ft_collectables(moves);
	draw_game(moves);
	mlx_hook(moves->win, 2, 0, ft_handle_moves, moves);
	mlx_key_hook(moves->win, ft_handle_esc, moves);
	mlx_hook(moves->win, 17, 0L, close_window, moves);
}

int	main(int argc, char **argv)
{
	t_moves	moves;
	char	**map;

	if (argc == 2)
	{
		map = ft_parse(argv[1]);
		checks(map);
		ft_freemap(map);
		moves.map = ft_parse(argv[1]);
		initialize_moves(&moves, moves.map);
		load_images(&moves);
		game_setup(&moves);
		mlx_loop(moves.mlx);
	}
	return (0);
}
