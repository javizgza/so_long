/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:27:20 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/13 17:14:09 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "so_long.h"

int	ft_handle_esc(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	ft_handle_key(int keycode, void *param)
{
	if (!param)
		ft_printf("%i\n", keycode);
	return (0);
}

int	close_window(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	exit(0);
}
