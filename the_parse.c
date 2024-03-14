/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:52:30 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/14 11:40:50 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"   

int	ft_checkber(char *mapname)
{
	int	len;

	len = ft_strlen(mapname);
	if (len < 4 || mapname[len - 4] != '.' || mapname[len - 3] != 'b' \
			|| mapname[len - 2] != 'e' || mapname[len - 1] != 'r')
	{
		return (0);
	}
	return (1);
}

char	**ft_parse(char *argv)
{
	char	**res;
	int		len;
	int		fd;
	char	*line;

	if (!ft_checkber(argv))
		ft_error("Not .ber");
	fd = open(argv, 0);
	len = 0;
	while (get_next_line(fd))
		len++;
	close(fd);
	res = (char **)ft_calloc((len + 1), sizeof(char *));
	fd = open(argv, 0);
	line = get_next_line(fd);
	len = 0;
	while (line)
	{
		res[len] = line;
		len++;
		line = get_next_line(fd);
	}
	close(fd);
	return (res);
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}
