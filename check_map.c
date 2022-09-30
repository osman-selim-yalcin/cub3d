#include "cub3d.h"

int is_that_xpm(char *texture)
{
	int a;

	a = 0;
	while (texture[a] != '\0' && texture[a] != ' ')
		a++;
	if (texture[a - 1] == 'p' && texture[a - 2] == 'm' && texture[a - 3] == 'x' && texture[a - 4] == '.')
		return (1);
	return (0);
}

int is_xpm_exist(char *texture)
{
	int fd;

	fd = open(texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int get_xpm_files(t_game *game, char *texture)
{
	int a;

	a = 0;
	(void)game;
	while (texture[a] != ' ')
		a++;
	while (texture[a] == ' ')
		a++;
	if (is_xpm_exist(texture + a))
		return (1);
	if (is_that_xpm(texture + a))
		return (1);
	return (0);
}

int map_element_check(t_game *game)
{
	char *tmp;
	int i;
	int fd;

	fd = open(game->map.map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while (i < 6)
	{
		tmp = get_next_line(fd);
		game->map.gnl_count++;
		if (!tmp)
			break ;
		if (element_strncmp(tmp, "N", 2) == 0 || element_strncmp(tmp, "NO", 3) == 0)
			game->map.north_wall = ft_strdup(tmp);
		else if (element_strncmp(tmp, "S", 2 == 0) || element_strncmp(tmp, "SO", 3) == 0)
			game->map.south_wall = ft_strdup(tmp);
		else if (element_strncmp(tmp, "W", 2 == 0) || element_strncmp(tmp, "WE", 3) == 0)
			game->map.west_wall = ft_strdup(tmp);
		else if (element_strncmp(tmp, "E", 2 == 0) || element_strncmp(tmp, "EA", 3) == 0)
			game->map.east_wall = ft_strdup(tmp);
		else if (element_strncmp(tmp, "F", 2) == 0)
			game->map.floor_char = ft_strdup(tmp);
		else if (element_strncmp(tmp, "C", 2) == 0)
			game->map.ceilling_char = ft_strdup(tmp);
		if (tmp[0] != '\0')
			i++;
		free(tmp);
	}
	// printf("north: %s\n", game->map.north_wall);
	// printf("south: %s\n", game->map.south_wall);
	// printf("east: %s\n", game->map.east_wall);
	// printf("west: %s\n", game->map.west_wall);
	// printf("floor: %s\n", game->map.floor_char);
	// printf("ceiling: %s\n", game->map.ceilling_char);
	// printf("i: %d\n", i);
	close(fd);
	if (i != 6 || !game->map.north_wall || !game->map.south_wall || \
		!game->map.east_wall || !game->map.west_wall || !game->map.floor_char || !game->map.ceilling_char)
		return (1);
	if (get_xpm_files(game, game->map.north_wall) == 1 || get_xpm_files(game, game->map.south_wall) == 1 || \
		get_xpm_files(game, game->map.east_wall) == 1 || get_xpm_files(game, game->map.west_wall) == 1)
		return (1);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int rgb_check(t_game *game, int i)
{
	char **tmp;
	char *tmp_2;
	int a;
	int b;

	if (i == 0)
		tmp_2 = ft_strdup(game->map.floor_char);
	else
		tmp_2 = ft_strdup(game->map.ceilling_char);
	a = 1;
	while (tmp_2[a] == ' ')
		a++;
	b = a;
	while (tmp_2[a] != '\0' && tmp_2[a] != '\n')
	{
		if (!(tmp_2[a] >= '0' && tmp_2[a] <= '9') && tmp_2[a] != ',')
			return (1);
		a++;
	}
	tmp = ft_split(tmp_2 + b, ',');
	a = 0;
	while (tmp[a] != NULL)
		a++;
	if (a != 3)
		return (1);
	a = 0;
	while (a < 3)
	{
		if (ft_atoi(tmp[a]) < 0 || ft_atoi(tmp[a]) > 255)
			return (1);
		a++;
	}
	if (i == 0)
		game->map.floor_rgb = create_trgb(0, ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	else
		game->map.ceilling_rgb = create_trgb(0, ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free(tmp_2);
	while(a > 0)
	{
		a--;
		free(tmp[a]);
	}
	free(tmp);
	return (0);
}

int check_map(t_game *game)
{
	if (map_element_check(game))//mapdeki ilk 6 şeye bakılacak ve kaç kere gnl çağrıldığı döndürülecek isimcheckaa
		return (1);
	if (rgb_check(game, 0) || rgb_check(game, 1))//rgb check
		return (1);
	//buraka
	return (0);
}