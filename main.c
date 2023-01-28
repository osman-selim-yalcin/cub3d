/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:51:21 by osmanyalcin       #+#    #+#             */
/*   Updated: 2023/01/28 12:49:48 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	tmp_exit(void)
{
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

	fill_struct_map(&game, av);
	if (check_map(&game, ac))
		return (1);
	get_value(&game);
	mlx_mouse_hide();
	mlx_mouse_move(game.libx.win, SCREEN_WID / 2, SCREEN_LEN / 2);
	mlx_loop_hook(game.libx.mlx, hook_event, &game);
	mlx_hook(game.libx.win, 2, 0, key_event_down, &game);
	mlx_hook(game.libx.win, 3, 0, key_event_up, &game);
	mlx_hook(game.libx.win, 6, 0L, mouse_move, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return (0);
}
