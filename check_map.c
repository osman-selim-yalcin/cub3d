#include "cub3d.h"

int map_element_check(t_game *game)
{
	char *tmp;
	int i;
	int a;
	int fd;

	fd = open(game->map.map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while (i < 6)
	{
		a = 0;
		tmp = get_next_line(fd);
		game->map.gnl_count++;
		if (!tmp)
			break ;
		while (tmp[a] == ' ' && tmp[a] != '\0')
			a++;
		if (element_strncmp(tmp + a, "N", 2) == 0 || element_strncmp(tmp + a, "NO", 3) == 0)
			game->map.north_wall = ft_strdup(tmp + a);
		else if (element_strncmp(tmp + a, "S", 2 == 0) || element_strncmp(tmp + a, "SO", 3) == 0)
			game->map.south_wall = ft_strdup(tmp + a);
		else if (element_strncmp(tmp + a, "W", 2 == 0) || element_strncmp(tmp + a, "WE", 3) == 0)
			game->map.west_wall = ft_strdup(tmp + a);
		else if (element_strncmp(tmp + a, "E", 2 == 0) || element_strncmp(tmp + a, "EA", 3) == 0)
			game->map.east_wall = ft_strdup(tmp + a);
		else if (element_strncmp(tmp + a, "F", 2) == 0 || element_strncmp(tmp + a, "FL", 3) == 0)
			game->map.floor_char = ft_strdup(tmp + a);
		else if (element_strncmp(tmp + a, "C", 2) == 0 || element_strncmp(tmp + a, "CE", 3) == 0)
			game->map.ceilling_char = ft_strdup(tmp + a);
		if (tmp[0] != '\0' && tmp[0] != '\n')
			i++;
		free(tmp);
	}
	close(fd);
	if (i != 6 || !game->map.north_wall || !game->map.south_wall || \
		!game->map.east_wall || !game->map.west_wall || !game->map.floor_char || !game->map.ceilling_char)
		return (1);
	if (get_xpm_files(game, game->map.north_wall, 1) == 1 || get_xpm_files(game, game->map.south_wall, 3) == 1 || \
		get_xpm_files(game, game->map.east_wall, 4) == 1 || get_xpm_files(game, game->map.west_wall, 2) == 1)
		return (1);
	return (0);
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
	a = 0;
	while (tmp_2[a] != ' ')
		a++;
	while (tmp_2[a] == ' ')
		a++;
	b = a;
	while (tmp_2[a] != '\0' && tmp_2[a] != '\n' && tmp_2[a] != ' ')
	{
		if (!(tmp_2[a] >= '0' && tmp_2[a] <= '9') && tmp_2[a] != ',')
			return (1);
		a++;
	}
	while (tmp_2[a] != '\0')
	{
		if (tmp_2[a] != ' ' && tmp_2[a] != '\n')
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

int is_map_cube(t_game *game)
{
	int i;

	i = 0;
	while (game->map.map_path[i] != '\0')
		i++;
	if (game->map.map_path[i - 1] != 'b' || game->map.map_path[i - 2] != 'u' || \
		game->map.map_path[i - 3] != 'c' || game->map.map_path[i - 4] != '.')
		return (1);
	return (0);
}

int check_map(t_game *game, int ac)
{
	int	i;

	if (ac != 2)
	{
		printf("Invalid arguments\n");
		exit(1);
	}
	if (is_map_cube(game))
	{
		printf(".cub file is not valid\n");
		return (1);
	}
	if (map_element_check(game))//mapdeki ilk 6 şeye bakılacak ve kaç kere gnl çağrıldığı döndürülecek isimcheckaa
	{
		printf("Map element check failed\n");
		return (1);
	}
	if (rgb_check(game, 0) || rgb_check(game, 1))//rgb check
	{
		printf("RGB check failed\n");
		return (1);
	}
	if (read_map(game))
	{
		printf("Invalid map elements\n");
		return (1);
	}
	i = check_component(game);
	if (i == 1)
	{
		printf("Invalid map components\n");
		return (1);
	}
	else if (i == 2)
	{
		printf("Number of player is not 1\n");
		return (1);
	}
	if (put_frame_to_map(game))
	{
		printf("Map is not surrounded by walls\n");
		return (1);
	}
	if (check_partition(game))
	{
		printf("Map contains multiple parts that player cannot reach\n");
		return (1);
	}
	return (0);
}