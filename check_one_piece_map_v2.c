/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one_piece_map_v2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:32:55 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/01 00:33:07 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_partition(t_game *game)
{
	char	**tmp;

	tmp = copy_map(game);
	set_player_index(game);
	set_bg_to_two(tmp, game->player.row, game->player.column);
	if (search_non_two(tmp))
	{
		free_copy_map(game, tmp);
		return (1);
	}
	free_copy_map(game, tmp);
	return (0);
}
