/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map_v2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:51:14 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/01 00:55:25 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
