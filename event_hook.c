#include "cub3d.h"

int hook_event(t_game *game)
{
	mlx_clear_window(game->libx.mlx, game->libx.win);
	mlx_destroy_image(game->libx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->libx.mlx, SCREEN_WID, SCREEN_LEN);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	start(game);
	display_minimap(game);
	move(game);
	mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.img, 0, 0);
	if (SCREEN_LEN >= 1024 && SCREEN_WID >= 1024)
	{
		mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.hand.hand_img[0].img, SCREEN_WID / 2  - 1024 / 2, SCREEN_LEN - 1024);
		mlx_put_image_to_window(game->libx.mlx, game->libx.win, game->img.hand.hand_img[1].img, SCREEN_WID / 2  - 1024 / 2, SCREEN_LEN - 1024);
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