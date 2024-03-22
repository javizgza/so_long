/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:43:56 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/22 14:30:54 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_moves
{
	void	*mlx;
	void	*win;
	int		pos_x;
	int		pos_y;
	int		map_width;
	int		map_height;
	void	*background_img;
	void	*wall_img;
	void	*consum_img;
	void	*exit_img;
	void	*char_img;
	char	**map;
	int		collected;
	int		totalconsum;
	int		move_count;
	void	*img;
	char	*rpath;
	int		height;
	int		width;
}				t_moves;

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

char		**ft_parse(char *path);
void		ft_error(char *msg);
int			ft_mapform(char **map);
int			ft_mapchars(char **map);
int			ft_mapfirstandlast(char **map);
int			ft_maplines(char **map);
int			ft_mapgamesetsexit(char **map);
t_position	ft_checkinitposition(char **map);
void		ft_exploremap(char **map, int i, size_t j);
int			ft_checkfilledcorrect(char **map);
t_position	ft_strlen_map(char **map);
int			ft_draw_walls(t_moves *moves, char **map, void *wall_img);
int			ft_draw_background(t_moves *moves, char **map, \
				void *background_img);
int			ft_draw_consum(t_moves *moves, char **map, void *consum_img);
int			ft_draw_exit(t_moves *moves, char **map, void *exit_img);
int			ft_draw_character(t_moves *moves, char **map, void *char_img);
void		ft_checkinitialcharpos(char **map, t_moves *moves);
void		ft_print_map(char **map);
int			ft_handle_moves(int keycode, t_moves *moves);
void		ft_collectables(t_moves *moves);
void		ft_move(t_moves *moves, int new_x, int new_y);
int			ft_handle_esc(int keycode, t_moves *moves);
int			ft_handle_key(int keycode, t_moves *moves);
int			close_window(int keycode);
int			ft_morethanonep(char **map);
int			ft_morethanonee(char **map);
void		checks(char **map);
int			ft_mapgamesetspos(char **map);
int			ft_mapgamesetsconsum(char **map);
void		ft_freemap(char **map);
int			ft_checkfinally(char **map);
t_moves		*ft_protect(char *path, void *mlx);

#endif