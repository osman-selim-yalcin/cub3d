#include "cub3d.h"

void	set_idle_state(t_game *game)
{
	static int	idle_counter;

	game->enemy_idle_state = idle_counter / 3;
	++idle_counter;
	if (idle_counter == 21)
		idle_counter = 0;
	

	t_enemy *tmp;
	tmp = game->enemy;
	while (game->enemy)
	{
		if (game->enemy->attack_state != -1)
		{
			++game->enemy->frame_counter;
			if (game->enemy->frame_counter <= 7)
				game->enemy->attack_state = game->enemy->frame_counter / 4;
			else if (game->enemy->frame_counter > 7 && game->enemy->frame_counter < 40)
			{
				game->enemy->attack_state = 2 + game->enemy->frame_counter % 2;
			}
			else
			{
				game->enemy->attack_state = -1;
				game->enemy->frame_counter = 0;
				game->enemy->sleep = 70;
			}
		}
		game->enemy = game->enemy->next;
	}
	game->enemy = tmp;
}

int hook_event(t_game *game)
{
	mlx_clear_window(game->libx.mlx, game->libx.win);
	mlx_destroy_image(game->libx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	get_enemy(game);
	enemy_walk(game);
	start(game);
	display_minimap(game);
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img, 0, 0);
	set_idle_state(game);
	return (0);
}