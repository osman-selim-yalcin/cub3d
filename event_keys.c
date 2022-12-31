#include "cub3d.h"

int key_event_down(int keycode, t_game *game)
{
	if (keycode == 123)
		game->settings.key_left = 1;
	else if (keycode == 124)
		game->settings.key_right = 1;
	else if (keycode == 126)
		game->settings.key_up = 1;
	else if (keycode == 125)
		game->settings.key_down = 1;
	else if (keycode == 0)
		game->settings.key_a = 1;
	else if (keycode == 2)
		game->settings.key_d= 1;
	else if (keycode == 13)
		game->settings.key_w = 1;
	else if (keycode == 1)
		game->settings.key_s = 1;
	else if (keycode == 53)
		tmp_exit();
	else if (keycode == 53)
		tmp_exit();
	return(0);
}

int key_event_up(int keycode, t_game *game)
{
	if (keycode == 0)
		game->settings.key_a = 0;
	else if (keycode == 1)
		game->settings.key_s = 0;
	else if (keycode == 2)
		game->settings.key_d= 0;
	else if (keycode == 13)
		game->settings.key_w = 0;
	else if (keycode == 123)
		game->settings.key_left = 0;
	else if (keycode == 124)
		game->settings.key_right = 0;
	else if (keycode == 126)
		game->settings.key_up = 0;
	else if (keycode == 125)
		game->settings.key_down = 0;
	
	return(0);
}