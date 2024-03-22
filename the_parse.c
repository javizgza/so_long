/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:52:30 by jazarago          #+#    #+#             */
/*   Updated: 2024/03/22 14:24:19 by jazarago         ###   ########.fr       */
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

int	count_lines_in_file(const char *filename)
{
	int		len;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

char	**ft_parse(char *argv)
{
	char	**res;
	int		len;
	int		i;
	int		fd;
	char	*line;

	if (!ft_checkber(argv))
		ft_error("Not .ber");
	len = count_lines_in_file(argv);
	res = (char **)ft_calloc((len + 1), sizeof(char *));
	fd = open(argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		res[i] = line;
		line = get_next_line(fd);
		i += 1;
	}
	res[i] = NULL;
	return (res);
}
