#include "cub3d.h"

void	free_copy_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (i < game->map.total_row + 1)
	{
		free(map[i]);
		++i;
	}
	free(map);
}

void	set_bg_to_two(char **tmp_map, int row, int column)
{
	if (is_top_num_tmp(tmp_map, row, column))
	{
		tmp_map[row - 1][column] = '2';
		set_bg_to_two(tmp_map, row - 1, column);
	}
	if (is_left_num_tmp(tmp_map, row, column))
	{
		tmp_map[row][column - 1] = '2';
		set_bg_to_two(tmp_map, row, column - 1);
	}
	if (is_right_num_tmp(tmp_map, row, column))
	{
		tmp_map[row][column + 1] = '2';
		set_bg_to_two(tmp_map, row, column + 1);
	}
	if (is_bottom_num_tmp(tmp_map, row, column))
	{
		tmp_map[row + 1][column] = '2';
		set_bg_to_two(tmp_map, row + 1, column);
	}
}

char	**copy_map(t_game *game)
{
	int		i;
	int		j;
	char	**tmp_map;

	tmp_map = malloc(sizeof(char *) * game->map.total_row + 1);
	i = 0;
	while (i < game->map.total_row)
	{
		tmp_map[i] = malloc(sizeof(char) * game->map.total_column + 1);
		++i;
	}
	i = 0;
	while (i < game->map.total_row)
	{
		j = 0;
		while (j < game->map.total_column)
		{
			tmp_map[i][j] = game->map.map[i][j];
			++j;
		}
		tmp_map[i][j] = '\0';
		++i;
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

void	set_player_index(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'S' || game->map.map[i][j] == 'W' || game->map.map[i][j] == 'E' || game->map.map[i][j] == 'N')
			{
				game->player.row = i;
				game->player.column = j;
				return ;
			}
			++j;
		}
		++i;
	}
}

int	search_non_two(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '2')
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	check_partition(t_game *game)
{
	char	**tmp;

	tmp = copy_map(game);
	set_player_index(game);
	set_bg_to_two(tmp, game->player.row, game->player.column);
	if (search_non_two(tmp))
	{
		free_copy_map(game, tmp);
		return (1);
	}
	free_copy_map(game, tmp);
	return (0);
}
