/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:21:33 by osmanyalcin       #+#    #+#             */
/*   Updated: 2022/12/31 22:21:36 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixelput(t_game *game, double hypo, double ray_counter)
{
	int	a;
	int	wall;
	int	start;
	int	t;
	int	real_wall;

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
		my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), start + a, \
			take_texture(game, game->img.wall_x, \
				game->img.wall_y, game->img.which_wall));
		if (start + a >= SCREEN_LEN)
			break ;
		++a;
		++real_wall;
	}
	put_floorceil(game, SCREEN_WID - 1 - (ray_counter), real_wall, start);
	if (SCREEN_LEN < 800 || SCREEN_WID < 800)
		put_hand(game, ray_counter);
}

void	put_hand(t_game *game, int ray_counter)
{
	int	hl_x;
	int	hl_y;
	int	hr_x;
	int	hr_y;
	int	i;

	i = 0;
	hl_x = game->img.hand.hand_img[game->img.hand.left_hand].x * \
		ray_counter / SCREEN_WID;
	hr_x = game->img.hand.hand_img[game->img.hand.right_hand].x * \
		ray_counter / SCREEN_WID;
	while (i < SCREEN_LEN)
	{
		hl_y = game->img.hand.hand_img[game->img.hand.left_hand].y \
			* i / SCREEN_LEN;
		hr_y = game->img.hand.hand_img[game->img.hand.right_hand].y * \
			i / SCREEN_LEN;
		if (take_texture(game, hl_x, hl_y, 10) != (unsigned int)-16777216)
			my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), \
				i, take_texture(game, hl_x, hl_y, 10));
		if (take_texture(game, hr_x, hr_y, 11) != (unsigned int)-16777216)
			my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), \
				i, take_texture(game, hr_x, hr_y, 11));
		i++;
	}	
}


void	put_floorceil(t_game *game, int x, int real_wall, int start)
{
	int	y;

	y = 0;
	while (y < start)
	{
		if (y >= SCREEN_LEN)
			break ;
		my_mlx_pixel_put(game, x, y, game->map.ceilling_rgb);
		y++;
	}
	while (y + real_wall < SCREEN_LEN)
	{
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
	dst = game->img.addr + (y * game->img.line_length \
		+ x * (game->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
