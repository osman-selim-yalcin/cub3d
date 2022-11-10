/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <bmat@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:11:12 by osyalcin          #+#    #+#             */
/*   Updated: 2022/11/10 10:35:50 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int tmp_exit(void)
{
	printf("çıkış yapıom\n");
	exit(0);
}

void start(t_game *game)
{
	double ray_counter = 0;
	t_enemy *tmp_enemy;

	tmp_enemy = game->enemy;
	while (game->enemy)
	{
		if (0 > game->enemy->pixel - game->enemy->width / 2 && 0 < game->enemy->pixel + game->enemy->width / 2)
			game->enemy->forx_count -= game->enemy->pixel - game->enemy->width / 2;
		game->enemy = game->enemy->next;
	}
	game->enemy = tmp_enemy;
	while (ray_counter < SCREEN_WID)
	{
		game->player.ray_abs = (game->player.direction - game->player.fov / 2) + (ray_counter / SCREEN_WID * D_FOV);
		if (game->player.ray_abs < 0)
			game->player.ray_abs += 360;
		else if (game->player.ray_abs >= 360)
			game->player.ray_abs -= 360;
		if (ray_angle(game) == 1)
		{
			top_right(game, ray_counter);
		}
		else if (ray_angle(game) == 2)
		{
			top_left(game, ray_counter);
		}
		else if (ray_angle(game) == 3)
		{
			bottom_left(game,ray_counter);
		}
		else if (ray_angle(game) == 4)
		{
			bottom_right(game, ray_counter);
		}
		else
		{
			printf("wtf\n");
		}
		ray_counter += 1;
	}
}

int	temporary_killer(int code, int x, int y, t_game *game) // to be changed
{
	(void)x;
	(void)y;
	printf("code %d\n", code);
	if (code == 1)
	{
		kill_all(game);
	}
	else if (code == 2)
	{
		revive_all(game);
	}
	return (0);
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
	printf("game address %p\n", &game);
	mlx_mouse_hook(game.libx.win, &temporary_killer, &game); //to be changed
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return (0);
}