/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:51:07 by osmanyalcin       #+#    #+#             */
/*   Updated: 2022/12/31 22:00:13 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_len_wo_last_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		++i;
	while (line[i - 1] == 32)
		--i;
	return (i);
}

void	set_length_width(t_game *game)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (game->map.map[i])
	{
		if (ft_strlen(game->map.map[i]) > max)
			max = ft_strlen(game->map.map[i]);
		++i;
	}
	game->map.length = i;
	game->map.width = max;
	game->map.total_row = i + 2;
	game->map.total_column = max + 2;
}

char	**open_up_space(t_game *game)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (game->map.length + 3));
	i = 0;
	while (i < game->map.length + 2)
	{
		tmp[i] = malloc(sizeof(char) * game->map.width + 3);
		tmp[i++][game->map.width + 2] = '\0';
	}
	tmp[i] = NULL;
	return (tmp);
}

void	get_line_from_map(t_game *game, char *map, char *tmp)
{
	int	i;

	i = 0;
	tmp[i] = '2';
	while (map[i])
	{
		tmp[i + 1] = map[i];
		++i;
	}
	if (map[i - 1] == '\n')
		tmp[i] = '2';
	++i;
	while (i <= game->map.width + 1)
		tmp[i++] = '2';
}

void	get_map_to_tmp(t_game *game, char **tmp)
{
	int	i;

	i = 0;
	while (i <= game->map.width + 1)
	{
		tmp[0][i] = '2';
		tmp[game->map.length + 1][i] = '2';
		++i;
	}
	i = 0;
	while (game->map.map[i])
	{
		get_line_from_map(game, game->map.map[i], tmp[i + 1]);
		++i;
	}
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

void	fill_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 32)
				map[i][j] = '2';
			++j;
		}
		++i;
	}
}

int	put_frame_to_map(t_game *game)
{
	char	**tmp;

	set_length_width(game);
	tmp = open_up_space(game);
	get_map_to_tmp(game, tmp);
	fill_spaces(tmp);
	if (!check_all_twos(tmp))
	{
		free_2d_char_arr(tmp);
		return (1);
	}
	free_2d_char_arr(game->map.map);
	game->map.map = tmp;
	find_first_empty_columns(game);
	find_last_empty_columns(game);
	return (0);
}
