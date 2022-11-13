/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <bmat@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:11:12 by osyalcin          #+#    #+#             */
/*   Updated: 2022/11/13 15:50:52 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int tmp_exit(void)
{
	exit(0);
}

int main(int ac, char **av)
{
	t_game game;
	fill_struct_map(&game, av);
	if (check_map(&game, ac))
		return (1);
	get_value(&game);

	printf("door coor: %d, %d\n", game.map.doors[0][0], game.map.doors[0][1]);
	printf("player coor: %f, %f\n", game.player.pos_x, game.player.pos_y);
	mlx_mouse_hide();
	mlx_mouse_move(game.libx.win, SCREEN_WID / 2, SCREEN_LEN / 2);
	mlx_loop_hook(game.libx.mlx, hook_event, &game);
	mlx_hook(game.libx.win, 2,  0, key_event, &game); //0L ile farkı?
	mlx_hook(game.libx.win, 3,  0, key_event_2, &game); //0L ile farkı?
	mlx_hook(game.libx.win, 6, 0L, mouse_move, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return (0);
}
