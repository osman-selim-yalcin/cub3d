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

void	set_hand_state(t_game *game)
{
	static int counter;

	if (++counter > 2)
	{
		counter = 0;
		if (++game->img.hand.left_hand == 4)
			game->img.hand.left_hand = 0;
		if (++game->img.hand.right_hand == 16 && !game->img.hand.attack)
			game->img.hand.right_hand = 10;
		else if (game->img.hand.right_hand == 27)
		{
			game->img.hand.attack = 0;
			game->img.hand.right_hand = 4;
		}
	}
}

void	set_heal(t_game *game)
{
	if (game->player.hp != 4 && game->player.hp_count-- <= 0)
	{
		print_frame(game, 0);
		game->player.hp_count = 50;
	}
}

void	spawn_enemy(t_game *game)
{
	static int counter;
	int i;
	t_enemy *tmp_enemy;
	t_spawn *tmp_spawn;

	if (counter >= 100)
	{
		counter = 0;
		i = 0;
		tmp_enemy = game->enemy;
		while (tmp_enemy)
		{
			if (tmp_enemy->alive == 0)
			{
				i = rand() % game->spawn_count;
				tmp_spawn = game->spawn;
				while (tmp_spawn && i != 0)
				{
					tmp_spawn = tmp_spawn->next;
					--i;
				}
				tmp_enemy->posx = tmp_spawn->pos_x;
				tmp_enemy->posy = tmp_spawn->pos_y;
				tmp_enemy->alive = 1;
				break ;
			}
			tmp_enemy = tmp_enemy->next;
		}
	}
	++counter;
}

int hook_event(t_game *game)
{
	mlx_clear_window(game->libx.mlx, game->libx.win);
	mlx_destroy_image(game->libx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	spawn_enemy(game);
	get_enemy(game);
	enemy_walk(game);
	start(game);
	display_minimap(game);
	move(game);
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img, 0, 0);
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img_frame, 0, 0);
	set_hand_state(game);
	set_idle_state(game);
	set_heal(game);
	if (SCREEN_LEN >= 800 && SCREEN_WID >= 800)
	{
		mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.hand.hand_img[game->img.hand.left_hand].img, SCREEN_WID / 2  - game->img.hand.hand_img[game->img.hand.left_hand].x / 2 - SCREEN_WID / 12.8 , SCREEN_LEN - game->img.hand.hand_img[game->img.hand.left_hand].y);
		mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.hand.hand_img[game->img.hand.right_hand].img, SCREEN_WID / 2  - game->img.hand.hand_img[game->img.hand.right_hand].x / 2 + SCREEN_WID / 19.2, SCREEN_LEN - game->img.hand.hand_img[game->img.hand.right_hand].y);
	}
	return (0);
}

void move(t_game *game)
{
	if (game->settings.key_a == 1)
		key_a(game);
	if (game->settings.key_s == 1)
		key_s(game);
	if (game->settings.key_d == 1)
		key_d(game);
	if (game->settings.key_w == 1)
		key_w(game);
	if (game->settings.key_left == 1)
	{
		game->player.direction += 3;
		if (game->player.direction >= 360)
			game->player.direction -= 360;
		game->minimap.pa += 3 * M_PI / 180;
		if (game->minimap.pa > 2 * M_PI)
			game->minimap.pa -= 2 * M_PI;
		game->minimap.step_offset_x = cos(game->minimap.pa) * game->settings.minimap_scale / 10;
		game->minimap.step_offset_y = sin(game->minimap.pa) * game->settings.minimap_scale / 10;
	}
	if (game->settings.key_right == 1)
	{
		game->player.direction -= 3;
		if (game->player.direction < 0)
			game->player.direction += 360;
		game->minimap.pa -= 3 * M_PI / 180;
		if (game->minimap.pa < 0)
			game->minimap.pa += 2 * M_PI;
		game->minimap.step_offset_x = cos(game->minimap.pa) * game->settings.minimap_scale / 10;
		game->minimap.step_offset_y = sin(game->minimap.pa) * game->settings.minimap_scale / 10;
	}
	if (game->settings.key_up == 1)
	{
		game->mouse_horizontal += 30;
		if (game->mouse_horizontal > (SCREEN_LEN / 2))
			game->mouse_horizontal = (SCREEN_LEN / 2);
	}
	if (game->settings.key_down == 1)
	{
		game->mouse_horizontal -= 30;
		if (game->mouse_horizontal < -(SCREEN_LEN / 2))
			game->mouse_horizontal = -(SCREEN_LEN / 2);
	}
	
	
	
}