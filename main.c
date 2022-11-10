/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <bmat@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:11:12 by osyalcin          #+#    #+#             */
/*   Updated: 2022/11/10 15:22:40 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int tmp_exit(void)
{
	printf("çıkış yapıom\n");
	exit(0);
}

int main(int ac, char **av)
{
	t_game game;
	fill_struct_map(&game, av);
	if (check_map(&game, ac))
		return (1);
	get_value(&game);

	mlx_mouse_hide();
	mlx_loop_hook(game.libx.mlx, hook_event, &game);
	mlx_hook(game.libx.win, 2, 1L << 0, key_event, &game); //0L ile farkı?
	mlx_hook(game.libx.win, 6, 0L, mouse_move, &game);
	mlx_mouse_hook(game.libx.win, &temporary_killer, &game); //to be changed
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return (0);
}