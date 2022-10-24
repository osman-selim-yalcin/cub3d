#include "cub3d.h"

void key_e(t_game *game)
{
	int left;
	int right;
	int posx_100;
	int posy_100;

	left = game->player.direction + D_FOV;
	right = game->player.direction + D_FOV;
	posx_100 = game->player.pos_x / 100;
	posy_100 = game->player.pos_y / 100;
	if (degree_angle(left) == 1 || degree_angle(right) == 1)
	{
		if (game->map.map[posy_100 - 1][posx_100] == '1' || game->map.map[posy_100][posx_100 + 1] == '1' || game->map.map[posy_100 - 1][posx_100 + 1] == '1')
		{
			printf("wall\n");
		}
	}
	if (degree_angle(left) == 2 || degree_angle(right) == 2)
	{
		if (game->map.map[posy_100 - 1][posx_100] == '1' || game->map.map[posy_100][posx_100 - 1] == '1' || game->map.map[posy_100 - 1][posx_100 - 1] == '1')
		{
			printf("wall 2\n");
		}
	}
	if (degree_angle(left) == 3 || degree_angle(right) == 3)
	{
		if (game->map.map[posy_100 + 1][posx_100] == '1' || game->map.map[posy_100][posx_100 - 1] == '1' || game->map.map[posy_100 + 1][posx_100 - 1] == '1')
		{
			printf("wall 3\n");
		}
	}
	if (degree_angle(right) == 4 || degree_angle(right) == 4)
	{
		if (game->map.map[posy_100 + 1][posx_100] == '1' || game->map.map[posy_100][posx_100 + 1] == '1' || game->map.map[posy_100 + 1][posx_100 + 1] == '1')
		{
			printf("wall 4\n");
		}
	}
}

int key_event(int keycode, t_game *game)
{
	if (keycode == 123) // left
	{
		game->player.direction += 5;
		if (game->player.direction >= 360)
			game->player.direction -= 360;
		game->minimap.pa -= 2 * M_PI / 36;
		if (game->minimap.pa < 0)
		{
			game->minimap.pa += 2 * M_PI;
		}
		game->minimap.pdx = cos(game->minimap.pa) * 2;
		game->minimap.pdy = sin(game->minimap.pa) * 2;
	}
	if (keycode == 124) // right
	{
		game->player.direction -= 5;
		if (game->player.direction < 0)
			game->player.direction += 360;
		game->minimap.pa += 2 * M_PI / 36;
		if (game->minimap.pa > 2 * M_PI)
		{
			game->minimap.pa -= 2 * M_PI;
		}
		game->minimap.pdx = cos(game->minimap.pa) * 2;
		game->minimap.pdy = sin(game->minimap.pa) * 2;
	}
	if (keycode == 0) //5 yaptım çok hızlı gibiydi
		key_a(game);
	if (keycode == 2)//5 yaptım çok hızlı gibiydi
		key_d(game);
	if (keycode == 13)
		key_w(game);
	if (keycode == 1)
		key_s(game);
	if (keycode == 53)
		tmp_exit();
	if (keycode == 14)
		key_e(game);
	return(0);
}