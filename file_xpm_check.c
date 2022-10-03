#include "cub3d.h"

int is_this_xpm(char *texture)
{
	int a;

	a = 0;
	while (texture[a] != '\0' && texture[a] != ' ' && texture[a] != '\n')
		a++;
	if (texture[a - 1] == 'p' && texture[a - 2] == 'm' && texture[a - 3] == 'x' && texture[a - 4] == '.')
		return (1);
	return (0);
}

int is_xpm_exist(t_game *game, char *texture, int i)
{
	int fd;
	char *tmp;
	int a;

	a = 0;
	tmp = malloc(sizeof(char) * ft_strlen(texture) + 1);
	while (texture[a] != '\0' && texture[a] != ' ' && texture[a] != '\n')
	{
		tmp[a] = texture[a];
		a++;
	}
	tmp[a] = '\0';
	while (texture[a] != '\0')
	{
		if (texture[a] != ' ' && texture[a] != '\n')
			return(1);
		a++;
	}
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		free(tmp);
		return (1);
	}
	if (i == 1)
		game->map.north_wall = ft_strdup(tmp);
	else if (i == 3)
		game->map.south_wall = ft_strdup(tmp);
	else if (i == 2)
		game->map.west_wall = ft_strdup(tmp);
	else if (i == 4)
		game->map.east_wall = ft_strdup(tmp);
	free(tmp);
	close(fd);
	return (0);
}

int get_xpm_files(t_game *game, char *texture, int i)
{
	int a;

	a = 0;
	while (texture[a] == ' ')
		a++;
	while (texture[a] != ' ')
		a++;
	while (texture[a] == ' ')
		a++;
	if (is_xpm_exist(game, texture + a, i))
		return (1);
	if (is_this_xpm(texture + a))
		return (1);
	return (0);
}