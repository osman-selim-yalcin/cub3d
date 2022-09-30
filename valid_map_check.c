#include "cub3d.h"

#define LAST_LINE
#define MAP_PATH

int	is_line_valid(char *line)
{
	int	i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != 32 && line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
			return (0);
		++i;
	}
	return (1);
}

void	free_2d_char_arr(char **ptr)
{
	int	i;

	if (ptr == NULL)
		return ;
	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr[i]);
	free(ptr);
}

int	is_nl(t_game *game, char *line)
{
	if (line == NULL && game->map.started_reading == 0)
	{
		game->map.started_reading = 1;
		return (1);
	}
	if (line == NULL)
		return (0);
	if (line[0] == '\n')
	{
		free(line);
		return (1);
	}
	return (0);
}

char	**append_2d_array(char **map, char *line)
{
	int		i;
	char	**tmp;

	if (map == NULL)
	{
		map = malloc(sizeof(char *) * 2);
		map[0] = line;
		map[1] = NULL;
	}
	else
	{
		i = 0;
		while (map[i])
			++i;
		tmp = malloc (sizeof(char *) * (i + 1));
		i = -1;
		while (map[++i])
			tmp[i] = map[i];
		tmp[i] = line;
		tmp[i + 1] = map[i];
		free(map);
		map = tmp;
	}
	return (map);
}

void	add_to_map(t_game *game, char *line)
{
	game->map.map = append_2d_array(game->map.map, line);
}

int	read_map(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(MAP_PATH, O_RDONLY);
	i = 0;
	while (i++ < LAST_LINE)
	{
		line = get_next_line(fd);
		free(line);
	}
	line = NULL;
	while (is_nl(game, line) == 1)
		line = get_next_line();
	if (line == NULL)
		return (1);
	while (line != NULL && !is_nl(game, line))
	{
		add_to_map(game, line);
		line = get_next_line(fd);
	}
	if (after_map_is_valid(line, fd) == 0)
	{
		free_2d_char_arr(game->map.map);
		return (0);
	}
	return (1);

}

int	after_map_is_valid(char *line, int fd)
{
	if (line == NULL)
		return (1);
	while (1)
	{
		if (is_nl(line) == 1)
			get_next_line(fd);
		else if (line == NULL)
			return (1);
		else
		{
			free(line);
			return (0);
		}
	}
}
