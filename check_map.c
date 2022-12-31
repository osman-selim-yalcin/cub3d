/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:50:59 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/01 02:15:56 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_cube(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map_path[i] != '\0')
		i++;
	if (game->map.map_path[i - 1] != 'b' || game->map.map_path[i - 2] != 'u' || \
		game->map.map_path[i - 3] != 'c' || game->map.map_path[i - 4] != '.')
		return (1);
	return (0);
}

int	check_map_3(t_game *game, int i)
{
	if (i == 2)
	{
		printf("Number of player is not 1\n");
		return (1);
	}
	if (put_frame_to_map(game))
	{
		printf("Map is not surrounded by walls\n");
		return (1);
	}
	if (check_door_position(game))
	{
		printf("All doors must have only two empty sides.\n");
		return (1);
	}
	if (check_partition(game))
	{
		printf("Map contains multiple parts that player cannot reach\n");
		return (1);
	}
	return (0);
}

int	check_map_2(t_game *game)
{
	int	i;
	int	i2;

	i2 = 0;
	i = 0;
	if (rgb_check_before(game, 0, i, i2) || rgb_check_before(game, 1, i, i2))
	{
		printf("RGB check failed\n");
		return (1);
	}
	if (read_map(game))
	{
		printf("Invalid map elements\n");
		return (1);
	}
	i = check_component(game);
	if (i == 1)
	{
		printf("Invalid map components\n");
		return (1);
	}
	if (check_map_3(game, i))
		return (1);
	return (0);
}

int	check_map(t_game *game, int ac)
{
	if (ac != 2)
	{
		printf("Invalid arguments\n");
		exit(1);
	}
	if (is_map_cube(game))
	{
		printf(".cub file is not valid\n");
		return (1);
	}
	if (map_element_check(game))
	{
		printf("Map element check failed\n");
		return (1);
	}
	if (get_xpm_files(game, game->map.north_wall, 1) == 1 \
		|| get_xpm_files(game, game->map.south_wall, 3) == 1 || \
		get_xpm_files(game, game->map.east_wall, 4) == 1 \
			|| get_xpm_files(game, game->map.west_wall, 2) == 1)
		return (1);
	if (check_map_2(game))
		return (1);
	return (0);
}
