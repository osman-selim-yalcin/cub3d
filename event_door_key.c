#include "cub3d.h"

void key_e_area1(t_game *game, int posx_100, int posy_100)
{
	if (game->map.map[posy_100 - 1][posx_100] == 'C' || game->map.map[posy_100][posx_100 + 1] == 'C' || game->map.map[posy_100 - 1][posx_100 + 1] == 'C')
	{
		printf("door\n");
		if (game->map.map[posy_100 - 1][posx_100] == 'C')
			game->map.map[posy_100 - 1][posx_100] = 'O';
		if (game->map.map[posy_100][posx_100 + 1] == 'C')
			game->map.map[posy_100][posx_100 + 1] = 'O';
		if (game->map.map[posy_100 - 1][posx_100 + 1] == 'C')
			game->map.map[posy_100 - 1][posx_100 + 1] = 'O';
	}
	else if (game->map.map[posy_100 - 1][posx_100] == 'O' || game->map.map[posy_100][posx_100 + 1] == 'O' || game->map.map[posy_100 - 1][posx_100 + 1] == 'O')
	{
		printf("open\n");
		if (game->map.map[posy_100 - 1][posx_100] == 'O')
			game->map.map[posy_100 - 1][posx_100] = 'C';
		if (game->map.map[posy_100][posx_100 + 1] == 'O')
			game->map.map[posy_100][posx_100 + 1] = 'C';
		if (game->map.map[posy_100 - 1][posx_100 + 1] == 'O')
			game->map.map[posy_100 - 1][posx_100 + 1] = 'C';
	}
}

void key_e_area2(t_game *game, int posx_100, int posy_100)
{
	if (game->map.map[posy_100 - 1][posx_100] == 'C' || game->map.map[posy_100][posx_100 - 1] == 'C' || game->map.map[posy_100 - 1][posx_100 - 1] == 'C')
	{
		printf("door 2\n");
		if (game->map.map[posy_100 - 1][posx_100] == 'C')
			game->map.map[posy_100 - 1][posx_100] = 'O';
		if (game->map.map[posy_100][posx_100 - 1] == 'C')
			game->map.map[posy_100][posx_100 - 1] = 'O';
		if (game->map.map[posy_100 - 1][posx_100 - 1] == 'C')
			game->map.map[posy_100 - 1][posx_100 - 1] = 'O';
	}
	else if (game->map.map[posy_100 - 1][posx_100] == 'O' || game->map.map[posy_100][posx_100 - 1] == 'O' || game->map.map[posy_100 - 1][posx_100 - 1] == 'O')
	{
		printf("open 2\n");
		if (game->map.map[posy_100 - 1][posx_100] == 'O')
			game->map.map[posy_100 - 1][posx_100] = 'C';
		if (game->map.map[posy_100][posx_100 - 1] == 'O')
			game->map.map[posy_100][posx_100 - 1] = 'C';
		if (game->map.map[posy_100 - 1][posx_100 - 1] == 'O')
			game->map.map[posy_100 - 1][posx_100 - 1] = 'C';
	}
}

void key_e_area3(t_game *game, int posx_100, int posy_100)
{
	if (game->map.map[posy_100 + 1][posx_100] == 'C' || game->map.map[posy_100][posx_100 - 1] == 'C' || game->map.map[posy_100 + 1][posx_100 - 1] == 'C')
	{
		printf("door 3\n");
		if (game->map.map[posy_100 + 1][posx_100] == 'C')
			game->map.map[posy_100 + 1][posx_100] = 'O';
		if (game->map.map[posy_100][posx_100 - 1] == 'C')
			game->map.map[posy_100][posx_100 - 1] = 'O';
		if (game->map.map[posy_100 + 1][posx_100 - 1] == 'C')
			game->map.map[posy_100 + 1][posx_100 - 1] = 'O';
	}
	else if (game->map.map[posy_100 + 1][posx_100] == 'O' || game->map.map[posy_100][posx_100 - 1] == 'O' || game->map.map[posy_100 + 1][posx_100 - 1] == 'O')
	{
		printf("open 3\n");
		if (game->map.map[posy_100 + 1][posx_100] == 'O')
			game->map.map[posy_100 + 1][posx_100] = 'C';
		if (game->map.map[posy_100][posx_100 - 1] == 'O')
			game->map.map[posy_100][posx_100 - 1] = 'C';
		if (game->map.map[posy_100 + 1][posx_100 - 1] == 'O')
			game->map.map[posy_100 + 1][posx_100 - 1] = 'C';
	}
}

void key_e_area4(t_game *game, int posx_100, int posy_100)
{
	if (game->map.map[posy_100 + 1][posx_100] == 'C' || game->map.map[posy_100][posx_100 + 1] == 'C' || game->map.map[posy_100 + 1][posx_100 + 1] == 'C')
	{
		printf("door 4\n");
		if (game->map.map[posy_100 + 1][posx_100] == 'C')
			game->map.map[posy_100 + 1][posx_100] = 'O';
		if (game->map.map[posy_100][posx_100 + 1] == 'C')
			game->map.map[posy_100][posx_100 + 1] = 'O';
		if (game->map.map[posy_100 + 1][posx_100 + 1] == 'C')
			game->map.map[posy_100 + 1][posx_100 + 1] = 'O';
	}
	else if (game->map.map[posy_100 + 1][posx_100] == 'O' || game->map.map[posy_100][posx_100 + 1] == 'O' || game->map.map[posy_100 + 1][posx_100 + 1] == 'O')
	{
		printf("open 4\n");
		if (game->map.map[posy_100 + 1][posx_100] == 'O')
			game->map.map[posy_100 + 1][posx_100] = 'C';
		if (game->map.map[posy_100][posx_100 + 1] == 'O')
			game->map.map[posy_100][posx_100 + 1] = 'C';
		if (game->map.map[posy_100 + 1][posx_100 + 1] == 'O')
			game->map.map[posy_100 + 1][posx_100 + 1] = 'C';
	}
}

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
		key_e_area1(game, posx_100, posy_100);
	if (degree_angle(left) == 2 || degree_angle(right) == 2)
		key_e_area2(game, posx_100, posy_100);
	if (degree_angle(left) == 3 || degree_angle(right) == 3)
		key_e_area3(game, posx_100, posy_100);
	if (degree_angle(right) == 4 || degree_angle(right) == 4)
		key_e_area4(game, posx_100, posy_100);
}