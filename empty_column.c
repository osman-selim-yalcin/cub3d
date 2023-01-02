/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burak <burak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:58:39 by burak             #+#    #+#             */
/*   Updated: 2023/01/02 14:59:19 by burak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_first_empty_columns(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (1)
	{
		i = 0;
		while (i < game->map.length + 2 && game->map.map[i][j] == '2')
			++i;
		if (i < game->map.length + 2)
		{
			game->minimap.empty_column = j - 1;
			return ;
		}
		++j;
	}
}

void	find_last_empty_columns(t_game *game)
{
	int	i;
	int	j;

	game->minimap.empty_column2 = 1;
	j = game->map.total_column - 1;
	while (1)
	{
		i = 0;
		while (i < game->map.total_row && game->map.map[i] \
			[j - game->minimap.empty_column2] == '2')
			++i;
		if (i < game->map.total_row)
			return ;
		++game->minimap.empty_column2;
	}
}
