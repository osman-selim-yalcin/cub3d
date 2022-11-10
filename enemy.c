#include "cub3d.h"

int enemy_collision(t_game *game, float x, float y)
{
	t_enemy *tmp_enemy;

	tmp_enemy = game->enemy->head;
	while (tmp_enemy)
	{
		if (tmp_enemy == game->enemy)
		{
			if (!tmp_enemy->next)
				break;
			tmp_enemy = tmp_enemy->next;
		}
		if (hypot(x - tmp_enemy->posx, y - tmp_enemy->posy) < 20)
			return (0);
		tmp_enemy = tmp_enemy->next;
	}
	if (hypot(x - game->player.pos_x, y - game->player.pos_y) < 80)
	{
		return (0);
	}
	if (game->map.map[(int)(y)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y)/ 100][(int)(x + 20)/ 100] != '1' && game->map.map[(int)(y)/ 100][(int)(x - 20)/ 100] != 'C' && game->map.map[(int)(y)/ 100][(int)(x)/ 100] != 'C' && game->map.map[(int)(y)/ 100][(int)(x + 20)/ 100] != 'C')
	{
		if (game->map.map[(int)(y + 20)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y + 20)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y + 20)/ 100][(int)(x + 20)/ 100] != '1' && game->map.map[(int)(y + 20)/ 100][(int)(x - 20)/ 100] != 'C' && game->map.map[(int)(y + 20)/ 100][(int)(x)/ 100] != 'C' && game->map.map[(int)(y + 20)/ 100][(int)(x + 20)/ 100] != 'C')
		{
			if (game->map.map[(int)(y - 20)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y - 20)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y - 20)/ 100][(int)(x + 20)/ 100] != '1' && game->map.map[(int)(y - 20)/ 100][(int)(x - 20)/ 100] != 'C' && game->map.map[(int)(y - 20)/ 100][(int)(x)/ 100] != 'C' && game->map.map[(int)(y - 20)/ 100][(int)(x + 20)/ 100] != 'C')
			{
				return (1);
			}
		}
	}
	return (0);
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
			game->enemy->width = ((30 * SCREEN_WID) / (game->enemy->distance * 2));
			
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
		tmp_enemy->id = tmp_enemy->head->enemy_count;
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

void enemy_walk(t_game *game)
{
	t_enemy *tmp_enemy;

	tmp_enemy = game->enemy;
	while (game->enemy)
	{
		if (game->enemy->alive)
		{
			float offset;
			game->enemy->middle += M_PI;
			if (game->enemy->middle > 2 * M_PI)
				game->enemy->middle -= 2 * M_PI;
			offset = game->enemy->posx + round_double(5 * (cos(game->enemy->middle)));
			if (enemy_collision(game, offset,game->enemy->posy))
			{
				game->enemy->posx = offset;
			}
			offset = game->enemy->posy - round_double(5 * (sin(game->enemy->middle)));
			if (enemy_collision(game, game->enemy->posx, offset))
			{
				game->enemy->posy = offset;
			}
		}
		game->enemy = game->enemy->next;
	}
	game->enemy = tmp_enemy;
}

void enemy_print(t_game *game, int ray_counter, int hypo_tmp)
{
	int cnt;
	int o;
	int a;
	int start;
	t_enemy *tmp_enemy;
	
	tmp_enemy = game->enemy;
	o = 1;
	while (tmp_enemy && o < tmp_enemy->head->enemy_count + 1)
	{
		while (game->enemy->id != o && game->enemy->next)
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
					while (cnt < a)
					{
						if ((start + cnt < SCREEN_LEN && start + cnt >= 0) && (SCREEN_WID - 1 - (ray_counter) >= 0 && SCREEN_WID - 1 - (ray_counter) < SCREEN_WID))
						{
							game->enemy->e_wall_y = cnt * game->img.enemy_y / a;
							if (take_texture(game, game->enemy->e_wall_x, game->enemy->e_wall_y, 5) != (unsigned int)-16777216)
							{
								my_mlx_pixel_put(game, SCREEN_WID - 1 - (ray_counter), start + cnt, take_texture(game, game->enemy->e_wall_x, game->enemy->e_wall_y, 5));
							}
							
						}
						if (start + cnt >= SCREEN_LEN)
							break;
						cnt++;
					}
				}
			}
		}
		o++;
		game->enemy = tmp_enemy;
	}
	game->enemy = tmp_enemy;
}
