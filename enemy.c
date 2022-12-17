#include "cub3d.h"

int enemy_collision(t_game *game, float x, float y)
{
	t_enemy *tmp_enemy;

	tmp_enemy = game->enemy->head;
	while (tmp_enemy)
	{
		if (tmp_enemy->alive)
		{
			if (tmp_enemy == game->enemy)
			{
				if (!tmp_enemy->next)
					break;
				tmp_enemy = tmp_enemy->next;
			}
			if (hypot(x - tmp_enemy->posx, y - tmp_enemy->posy) < 20)
				return (1);
		}
		tmp_enemy = tmp_enemy->next;
	}
	if (hypot(x - game->player.pos_x, y - game->player.pos_y) < 80)
	{
		return (2);
	}
	if (game->map.map[(int)(y)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y)/ 100][(int)(x + 20)/ 100] != '1' && game->map.map[(int)(y)/ 100][(int)(x - 20)/ 100] != 'C' && game->map.map[(int)(y)/ 100][(int)(x)/ 100] != 'C' && game->map.map[(int)(y)/ 100][(int)(x + 20)/ 100] != 'C')
	{
		if (game->map.map[(int)(y + 20)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y + 20)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y + 20)/ 100][(int)(x + 20)/ 100] != '1' && game->map.map[(int)(y + 20)/ 100][(int)(x - 20)/ 100] != 'C' && game->map.map[(int)(y + 20)/ 100][(int)(x)/ 100] != 'C' && game->map.map[(int)(y + 20)/ 100][(int)(x + 20)/ 100] != 'C')
		{
			if (game->map.map[(int)(y - 20)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y - 20)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y - 20)/ 100][(int)(x + 20)/ 100] != '1' && game->map.map[(int)(y - 20)/ 100][(int)(x - 20)/ 100] != 'C' && game->map.map[(int)(y - 20)/ 100][(int)(x)/ 100] != 'C' && game->map.map[(int)(y - 20)/ 100][(int)(x + 20)/ 100] != 'C')
			{
				return (0);
			}
		}
	}
	return (1);
}

void enemy_walk(t_game *game)
{
	t_enemy *tmp_enemy;
	int x_collision;
	int	y_collision;
	float offset;

	tmp_enemy = game->enemy;
	while (game->enemy)
	{
		if (game->enemy->alive && game->enemy->sleep == 0)
		{
			game->enemy->middle += M_PI;
			if (game->enemy->middle > 2 * M_PI)
				game->enemy->middle -= 2 * M_PI;
			x_collision = enemy_collision(game, game->enemy->posx + round_double(5 * (cos(game->enemy->middle))), game->enemy->posy);
			y_collision = enemy_collision(game, game->enemy->posx, game->enemy->posy - round_double(5 * (sin(game->enemy->middle))));
			if ((x_collision == 2 || y_collision == 2) && game->enemy->attack_state == -1)
			{
				game->enemy->attack_state = 0;
				print_frame(game, 1);
				game->enemy = game->enemy->next;
				continue ;
			}
			offset = game->enemy->posx + round_double(5 * (cos(game->enemy->middle)));
			if (!enemy_collision(game, offset,game->enemy->posy))
			{
				game->enemy->posx = offset;
			}
			offset = game->enemy->posy - round_double(5 * (sin(game->enemy->middle)));
			if (!enemy_collision(game, game->enemy->posx, offset))
			{
				game->enemy->posy = offset;
			}
		}
		else if (game->enemy->sleep != 0)
			--game->enemy->sleep;
		game->enemy = game->enemy->next;
	}
	game->enemy = tmp_enemy;

}

void get_enemy(t_game *game)
{
	t_enemy *tmp_enemy;

	tmp_enemy = game->enemy;
	while (game->enemy)
	{
		if (game->enemy->alive)
		{
			double middle;
			double middle_tmp;
			double k;
			game->player.ray_start = (game->player.direction - game->player.fov / 2);
			if (game->player.ray_start < 0)
				game->player.ray_start += 360;

			game->enemy->distance = hypot(game->enemy->posx - game->player.pos_x, game->enemy->posy - game->player.pos_y);
			game->enemy->width = ((70 * SCREEN_WID) / (game->enemy->distance * 2));
			
			middle = atan((game->enemy->posx - game->player.pos_x) / (game->enemy->posy - game->player.pos_y));
			if (game->player.pos_x > game->enemy->posx)
			{
				if (game->player.pos_y > game->enemy->posy)
					middle += deg_to_rad(90);
				else
					middle = middle + deg_to_rad(270);
			}
			else
			{
				if (game->player.pos_y > game->enemy->posy)
					middle += deg_to_rad(90);
				else
					middle += deg_to_rad(270);
			}
			k = 0;
			middle_tmp = middle;
			if (deg_to_rad(game->player.ray_start) > middle)
				middle_tmp = middle + 2 * M_PI;
			while (deg_to_rad(game->player.ray_start )< middle_tmp && !take_approximate(deg_to_rad(game->player.ray_start) + k, middle_tmp))
				k += 0.00001;

			game->enemy->pixel = (float)SCREEN_WID * (k * (180 / M_PI)) / D_FOV;
			while (game->enemy->pixel > SCREEN_WID * (360 / D_FOV - 1))
				game->enemy->pixel -= SCREEN_WID * (360 / D_FOV);

			game->enemy->middle = middle;
			game->enemy->forx_count = 0;
		}
		game->enemy = game->enemy->next;
	}
	game->enemy = tmp_enemy;
	while (tmp_enemy)
	{
		tmp_enemy->id = game->enemy_count;
		while (game->enemy)
		{
			if (tmp_enemy->distance > game->enemy->distance)
				tmp_enemy->id--;
			game->enemy = game->enemy->next;			
		}
		game->enemy = tmp_enemy->head;
		tmp_enemy = tmp_enemy->next;
	}
}

void enemy_print(t_game *game, int ray_counter, int hypo_tmp)
{
	int cnt;
	int which_enemy;
	int a;
	int start;
	t_enemy *tmp_enemy;
	
	tmp_enemy = game->enemy;
	which_enemy = 1;
	while (tmp_enemy && which_enemy < game->enemy_count + 1)
	{
		while (game->enemy->id != which_enemy && game->enemy->next)
			game->enemy = game->enemy->next;
		if (game->enemy->alive)
		{
			if (ray_counter > game->enemy->pixel - (game->enemy->width / 2) && ray_counter < game->enemy->pixel + (game->enemy->width / 2))
			{
				game->enemy->forx_count += 1;
				if (game->enemy->distance < hypo_tmp)
				{
					game->enemy->e_wall_x = game->img.enemy_x * game->enemy->forx_count / game->enemy->width;
					a = 0;
					cnt = 0;
					while ((double)a < (150 / game->enemy->distance) * (SCREEN_LEN / 2))
						a++;
					if (a % 2 == 1)
						a++;
					start = (SCREEN_LEN - a) / 2;
					start += game->mouse_horizontal;
					if (start < 0)
						cnt = -start;
					while (cnt < a)
					{
						if ((start + cnt < SCREEN_LEN && start + cnt >= 0) && (SCREEN_WID - 1 - (ray_counter) >= 0 && SCREEN_WID - 1 - (ray_counter) < SCREEN_WID))
						{
							game->enemy->e_wall_y = cnt * game->img.enemy_y / a;
							if (take_texture(game, game->enemy->e_wall_x, game->enemy->e_wall_y, 5) != (unsigned int)-16777216) // can be optimized
								my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), start + cnt, take_texture(game, game->enemy->e_wall_x, game->enemy->e_wall_y, 5));
						}
						if (start + cnt >= SCREEN_LEN)
							break;
						cnt++;
					}
				}
			}
		}
		which_enemy++;
		game->enemy = tmp_enemy;
	}
	game->enemy = tmp_enemy;
}
