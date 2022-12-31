/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:51:05 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/01 01:28:22 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d_char_arr(char **ptr)
{
	int	i;

	if (ptr == NULL)
		return ;
	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr[i]);
	free(ptr);
}

char	**append_2d_array(char **map, char *line)
{
	int		i;
	char	**tmp;

	if (map == NULL)
	{
		map = malloc(sizeof(char *) * 2);
		map[0] = line;
		map[1] = NULL;
	}
	else
	{
		i = 0;
		while (map[i])
			++i;
		tmp = malloc (sizeof(char *) * (i + 2));
		i = -1;
		while (map[++i])
			tmp[i] = map[i];
		tmp[i] = line;
		tmp[i + 1] = map[i];
		free(map);
		map = tmp;
	}
	return (map);
}

int	is_nl(t_game *game, char *line)
{
	if (line == NULL && game->map.started_reading == 0)
	{
		game->map.started_reading = 1;
		return (1);
	}
	if (line == NULL)
		return (0);
	if (line[0] == '\n')
	{
		free(line);
		return (1);
	}
	return (0);
}

void	add_to_map(t_game *game, char *line)
{
	game->map.map = append_2d_array(game->map.map, line);
}
