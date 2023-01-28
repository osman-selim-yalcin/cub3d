/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 02:11:09 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/28 13:01:46 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_char(t_game *game, char *tmp)
{
	int	a;

	a = 0;
	while (tmp[a] == ' ' && tmp[a] != '\0')
		a++;
	if (element_strncmp(tmp + a, "N", 2) == 0 \
		|| element_strncmp(tmp + a, "NO", 3) == 0)
		game->map.north_wall = ft_strdup(tmp + a);
	else if (element_strncmp(tmp + a, "S", 2 == 0) \
		|| element_strncmp(tmp + a, "SO", 3) == 0)
		game->map.south_wall = ft_strdup(tmp + a);
	else if (element_strncmp(tmp + a, "W", 2 == 0) \
		|| element_strncmp(tmp + a, "WE", 3) == 0)
		game->map.west_wall = ft_strdup(tmp + a);
	else if (element_strncmp(tmp + a, "E", 2 == 0) \
		|| element_strncmp(tmp + a, "EA", 3) == 0)
		game->map.east_wall = ft_strdup(tmp + a);
	else if (element_strncmp(tmp + a, "F", 2) == 0 \
		|| element_strncmp(tmp + a, "FL", 3) == 0)
		game->map.floor_char = ft_strdup(tmp + a);
	else if (element_strncmp(tmp + a, "C", 2) == 0 \
		|| element_strncmp(tmp + a, "CE", 3) == 0)
		game->map.ceilling_char = ft_strdup(tmp + a);
}

int	map_element_check(t_game *game)
{
	char	*tmp;
	int		i;
	int		fd;

	fd = open(game->map.map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while (i < 6)
	{
		tmp = get_next_line(fd);
		game->map.gnl_count++;
		if (!tmp)
			break ;
		get_map_char(game, tmp);
		if (tmp[0] != '\0' && tmp[0] != '\n')
			i++;
		free(tmp);
	}
	close(fd);
	if (i != 6 || !game->map.north_wall || !game->map.south_wall || \
		!game->map.east_wall || !game->map.west_wall \
			|| !game->map.floor_char || !game->map.ceilling_char)
		return (1);
	return (0);
}

int	rgb_check_before(t_game *game, int i, int a, int b)
{
	char	*tmp_2;

	if (i == 0)
		tmp_2 = game->map.floor_char;
	else
		tmp_2 = game->map.ceilling_char;
	while (tmp_2[a] != ' ')
		a++;
	while (tmp_2[a] == ' ')
		a++;
	while (tmp_2[a] != '\0' && tmp_2[a] != '\n' && tmp_2[a] != ' ')
	{
		if (!(tmp_2[a] >= '0' && tmp_2[a] <= '9') && tmp_2[a] != ',')
			return (1);
		a++;
	}
	while (tmp_2[a] != '\0')
	{
		if (tmp_2[a] != ' ' && tmp_2[a] != '\n')
			return (1);
		a++;
	}
	if (rgb_check(game, i, tmp_2 + b))
		return (1);
	return (0);
}

int	rgb_2d_check(char **tmp)
{
	int	a;

	a = 0;
	while (tmp[a] != NULL)
		a++;
	if (a != 3)
		return (1);
	a = 0;
	while (a < 3)
	{
		if (ft_atoi(tmp[a]) < 0 || ft_atoi(tmp[a]) > 255)
			return (1);
		a++;
	}
	return (0);
}

int	rgb_check(t_game *game, int i, char *rgb_char)
{
	char	**tmp;
	int		a;

	tmp = ft_split(rgb_char, ',');
	if (rgb_2d_check(tmp))
		return (1);
	if (i == 0)
		game->map.floor_rgb = \
			create_trgb(0, ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	else
		game->map.ceilling_rgb = \
			create_trgb(0, ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	a = 0;
	while (a < 3)
	{
		free(tmp[a]);
		a++;
	}
	free(tmp);
	return (0);
}
