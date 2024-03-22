/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_closings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:27:20 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/22 13:58:16 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "so_long.h"

int	ft_handle_esc(int keycode, t_moves *moves)
{
	if (keycode == 53)
	{
		ft_printf("DEFEAT.\nReally? You can't pass it?\n");
		ft_freemap(moves->map);
		exit(0);
	}
	return (0);
}

int	close_window(int keycode)
{
	(void)keycode;
	ft_printf("DEFEAT.\nReally? You can't pass it?\n");
	exit(0);
	return (0);
}
