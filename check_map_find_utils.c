/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_find_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:50:56 by osmanyalcin       #+#    #+#             */
/*   Updated: 2022/12/31 21:50:57 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_top_num_tmp(char **map, int row, int column)
{
	if (map[row - 1][column] != '2')
		return (1);
	return (0);
}

int	is_left_num_tmp(char **map, int row, int column)
{
	if (map[row][column - 1] != '2')
		return (1);
	return (0);
}

int	is_right_num_tmp(char **map, int row, int column)
{
	if (map[row][column + 1] != '2')
		return (1);
	return (0);
}

int	is_bottom_num_tmp(char **map, int row, int column)
{
	if (map[row + 1][column] != '2')
		return (1);
	return (0);
}
