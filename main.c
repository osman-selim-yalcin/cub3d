/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:11:12 by osyalcin          #+#    #+#             */
/*   Updated: 2022/10/23 11:20:28 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int tmp_exit(void)
{
	printf("çıkış yapıom\n");
	exit(0);
}

void tmp(t_game *game)
{
	double ray_counter = 0;
	double hypo_tmp = 0;
	while (ray_counter < SCREEN_WID)
	{
		hypo_tmp = 0;
		game->player.ray_absoulete = (game->player.direction - game->player.fov / 2) + (ray_counter / SCREEN_WID * D_FOV);
		if (game->player.ray_absoulete < 0)
			game->player.ray_absoulete += 360;
		else if (game->player.ray_absoulete >= 360)
			game->player.ray_absoulete -= 360;
		ray_counter += 1;
	}
	display(game);
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img, 0, 0);
}

int main(int ac, char **av)
{
	t_game game;

	fill_struct_map(&game, av);
	if (check_map(&game, ac))
		return (1);
	get_value(&game);
	put_floorceil(&game);
	tmp(&game);

	mlx_hook(game.libx.win, 2, 1L << 0, key_event, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return (0);
}