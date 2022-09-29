#include "cub3d.h"

#define LAST_LINE

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

void	read_map()
{
	
}