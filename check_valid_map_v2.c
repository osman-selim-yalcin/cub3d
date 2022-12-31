/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_v2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:27:48 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/01 01:28:44 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_map(t_game *game)
{
	int		i;
	int		fd;
	char	*line;
	int		a;

	fd = open(game->map.map_path, O_RDONLY);
	i = 0;
	while (i++ < game->map.gnl_count)
	{
		line = get_next_line(fd);
		free(line);
	}
	line = NULL;
	a = 0;
	while (is_nl(game, line) == 1)
	{
		a++;
		line = get_next_line(fd);
	}
	if (line == NULL)
	{
		close(fd);
		return (1);
	}
	while (line != NULL && !is_nl(game, line))
	{
		add_to_map(game, line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		line = NULL;
	if (after_map_is_valid(game, line, fd) == 0)
	{
		free_2d_char_arr(game->map.map);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	after_map_is_valid(t_game *game, char *line, int fd)
{
	while (1)
	{
		if (game->map.started_reading == 1 && is_nl(game, line) == 1)
		{
			line = get_next_line(fd);
		}
		else if (line == NULL && game->map.started_reading == 1)
		{
			line = get_next_line(fd);
			game->map.started_reading = 0;
		}
		else if (line == NULL)
			return (1);
		else
		{
			free(line);
			return (0);
		}
	}
}
