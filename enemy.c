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
	if (game->map.map[(int)(y)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y)/ 100][(int)(x + 20)/ 100] != '1')
	{
		if (game->map.map[(int)(y + 20)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y + 20)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y + 20)/ 100][(int)(x + 20)/ 100] != '1')
		{
			if (game->map.map[(int)(y - 20)/ 100][(int)(x - 20)/ 100] != '1' && game->map.map[(int)(y - 20)/ 100][(int)(x)/ 100] != '1' && game->map.map[(int)(y - 20)/ 100][(int)(x + 20)/ 100] != '1')
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
			while (game->enemy->pixel > SCREEN_WID * 5)
				game->enemy->pixel -= SCREEN_WID * 6;

			game->enemy->middle = middle;
			game->enemy->forx_count = 0;
		}
		game->enemy = game->enemy->next;
	}
	game->enemy = tmp_enemy;
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