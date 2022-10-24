/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:11:12 by osyalcin          #+#    #+#             */
/*   Updated: 2022/10/24 17:56:53 by osyalcin         ###   ########.fr       */
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
	display(game); //minimapB
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img, 0, 0);
}

int main(int ac, char **av)
{
	t_game game;

	fill_struct_map(&game, av);
	if (check_map(&game, ac))
		return (1);
	get_value(&game);
	// printf("game.map.length, %d\n game.map.width %d\n", game.map.length, game.map.width);
	// printf("game.player posx %d, posy %d\n\n\n", game.player.pos_x, game.player.pos_y);
	// printf("%s\n", game.map.map[0]);
	// printf("%s\n", game.map.map[1]);
	// printf("%s\n", game.map.map[2]);
	// printf("%s\n", game.map.map[3]);
	// printf("%s\n", game.map.map[4]);
	// printf("%s\n", game.map.map[5]);
	// printf("%s\n", game.map.map[6]);
	// printf("%s\n", game.map.map[7]);
	// printf("%s\n", game.map.map[8]);
	// printf("%s\n", game.map.map[9]);
	//tam köşeyi kandırabilirsin rayabs +=1;
	mlx_mouse_hide();
	mlx_loop_hook(game.libx.mlx, hook_event, &game);
	mlx_hook(game.libx.win, 2, 1L << 0, key_event, &game); //0L ile farkı?
	mlx_hook(game.libx.win, 6, 0L, mouse_move, &game);
	mlx_hook(game.libx.win, 17, 0L, tmp_exit, &game);
	mlx_loop(game.libx.mlx);
	return (0);
}