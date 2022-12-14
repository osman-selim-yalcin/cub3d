#include "cub3d.h"

void pixelput(t_game *game, double hypo, double ray_counter)
{
	int a;
	int wall;
	int start;
	int t;
	int real_wall;

	a = 0;
	real_wall = 0;
	if (hypo == 0)
		return ;
	while ((double)a < (150 / hypo) * (SCREEN_LEN / 2))
		a++;
	if (a % 2 == 1)
		a++;
	wall = a;
	start = (SCREEN_LEN - a) / 2;

	a = 0;
	if (game->img.which_wall == 1)
		t = game->img.north_y;
	if (game->img.which_wall == 2)
		t = game->img.west_y;
	if (game->img.which_wall == 3)
		t = game->img.south_y;
	if (game->img.which_wall == 4)
		t = game->img.east_y;
	if (game->img.which_wall == 7)
		t = game->img.door_y;
	start += game->mouse_horizontal;
	if (start < 0)
		a = -start;
	while (a < wall)
	{
		game->img.wall_y = a * t / wall;
		my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), start + a, take_texture(game, game->img.wall_x, game->img.wall_y, game->img.which_wall));
		if (start + a >= SCREEN_LEN)
			break;
		++a;
		++real_wall;
	}
	put_floorceil(game, SCREEN_WID - 1 - (ray_counter), real_wall, start, wall);
	enemy_print(game, ray_counter, hypo);
	if (SCREEN_LEN < 800 || SCREEN_WID < 800)
		put_hand(game, ray_counter);
}

void put_hand(t_game *game, int ray_counter)
{
	int hand_l_x;
	int hand_l_y;
	int hand_r_x;
	int hand_r_y;
	int i = 0;
	hand_l_x = game->img.hand.hand_img[game->img.hand.left_hand].x * ray_counter / SCREEN_WID;
	hand_r_x = game->img.hand.hand_img[game->img.hand.right_hand].x * ray_counter / SCREEN_WID;
	while (i < SCREEN_LEN)
	{
		hand_l_y = game->img.hand.hand_img[game->img.hand.left_hand].y * i / SCREEN_LEN;
		hand_r_y = game->img.hand.hand_img[game->img.hand.right_hand].y * i / SCREEN_LEN;
		if (take_texture(game, hand_l_x, hand_l_y, 10) != (unsigned int)-16777216)
		{
			my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), i, take_texture(game, hand_l_x, hand_l_y, 10));
		}
		if (take_texture(game, hand_r_x, hand_r_y, 11) != (unsigned int)-16777216)
		{
			my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), i, take_texture(game, hand_r_x, hand_r_y, 11));
		}
		i++; 
	}	
}

void put_floorceil(t_game *game, int x, int real_wall, int start, int wall)
{
	int y;
	int a;

	a = start + wall / 2;
	y = wall / 2;
	game->img.ceil_index_x = game->img.ceilx * game->player.ray_abs / 360;	
	while (y < start + (wall / 2))
	{
		if (y >= SCREEN_LEN)
			break;
		game->img.ceil_index_y = (game->img.ceily * (SCREEN_LEN - y) / (SCREEN_LEN)) - 1;
		if ((y < SCREEN_LEN && y >= 0) && (x >= 0 && x < SCREEN_WID))
			my_mlx_pixel_put(game, x, a - y, take_texture(game, game->img.ceil_index_x, game->img.ceil_index_y, 6));
		y++;
	}
	y -= wall / 2;
	while (y + real_wall < SCREEN_LEN)
	{
		if ((y < SCREEN_LEN && y >= 0) && (x >= 0 && x < SCREEN_WID))
			my_mlx_pixel_put(game, x, y + real_wall, game->map.floor_rgb);
		y++;
	}
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (!((y < SCREEN_LEN && y >= 0) && (x >= 0 && x < SCREEN_WID)))
	{
		return ;
	}
	dst = game->img.addr + (y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
