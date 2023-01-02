/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burak <burak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:27:48 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/02 13:40:44 by burak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_cursor(int *fd, t_game *game, char **line)
{
	int	i;

	*fd = open(game->map.map_path, O_RDONLY);
	i = 0;
	while (i++ < game->map.gnl_count)
	{
		*line = get_next_line(*fd);
		free(*line);
	}
	*line = NULL;
	i = 0;
	while (is_nl(game, *line) == 1)
	{
		++i;
		*line = get_next_line(*fd);
	}
	if (*line == NULL)
	{
		close(*fd);
		return (1);
	}
	return (0);
}

int	read_map(t_game *game)
{
	int		fd;
	char	*line;

	if (move_cursor(&fd, game, &line) == 1)
		return (1);
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
