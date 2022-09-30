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