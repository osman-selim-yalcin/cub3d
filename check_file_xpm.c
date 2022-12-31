/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_xpm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:50:54 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/01 01:26:13 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_tmp(char *texture)
{
	char	*tmp;
	int		a;

	a = 0;
	tmp = malloc(sizeof(char) * ft_strlen(texture) + 1);
	while (texture[a] != '\0' && texture[a] != ' ' && texture[a] != '\n')
	{
		tmp[a] = texture[a];
		a++;
	}
	tmp[a] = '\0';
	while (texture[a] != '\0')
	{
		if (texture[a] != ' ' && texture[a] != '\n')
		{
			if (tmp)
				free(tmp);
			tmp = malloc(sizeof(char) * 1);
			tmp[0] = '\0';
		}
		a++;
	}
	return (tmp);
}

void	take_file_name(t_game *game, char *tmp, int i)
{
	if (i == 1)
	{
		free(game->map.north_wall);
		game->map.north_wall = ft_strdup(tmp);
	}
	else if (i == 2)
	{
		free(game->map.west_wall);
		game->map.west_wall = ft_strdup(tmp);
	}
	else if (i == 3)
	{
		free(game->map.south_wall);
		game->map.south_wall = ft_strdup(tmp);
	}
	else if (i == 4)
	{
		free(game->map.east_wall);
		game->map.east_wall = ft_strdup(tmp);
	}
}

int	is_xpm_exist(t_game *game, char *texture, int i)
{
	int		fd;
	char	*tmp;

	tmp = get_tmp(texture);
	if (tmp[0] == '\0')
		return (1);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		free(tmp);
		return (1);
	}
	take_file_name(game, tmp, i);
	free(tmp);
	close(fd);
	return (0);
}

int	get_xpm_files(t_game *game, char *texture, int i)
{
	int	a;

	a = 0;
	while (texture[a] == ' ')
		a++;
	while (texture[a] != ' ')
		a++;
	while (texture[a] == ' ')
		a++;
	if (is_xpm_exist(game, texture + a, i))
		return (1);
	return (0);
}
