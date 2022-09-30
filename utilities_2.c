#include "cub3d.h"

char	*newk(char *k)
{
	char	*temp;
	int		p;
	int		p2;

	p = 0;
	while (k[p] != '\n' && k[p] != '\0')
		p++;
	if (k[p] == '\0')
	{
		free(k);
		return (NULL);
	}
	temp = malloc((ft_strlen(k) - p + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	p2 = 0;
	p++;
	while (k[p + p2])
	{
		temp[p2] = k[p + p2];
		p2++;
	}
	temp [p2] = '\0';
	free(k);
	return (temp);
}

char	*gnl_print(char *k)
{
	char	*last;
	int		p;

	p = 0;
	if (k[p] == '\0')
		return (NULL);
	while (k[p] != '\n' && k[p] != '\0')
		p++;
	if (!k[p])
		last = malloc((p + 1) * sizeof(char));
	else
		last = malloc((p + 2) * sizeof(char));
	if (!last)
		return (NULL);
	p = 0;
	while (k[p] != '\n' && k[p] != '\0')
	{
		last[p] = k[p];
		p++;
	}
	if (k[p] == '\n')
		last[p++] = '\n';
	last[p] = '\0';
	return (last);
}

char	*rd(char *k, int fd)
{
	int		p;
	char	*buffer;

	buffer = malloc(2 + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	p = 1;
	while (ft_check(k, '\n') == 1 && p != 0)
	{
		p = read(fd, buffer, 2);
		if (p == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[p] = '\0';
		k = ft_strjoin(k, buffer);
	}
	free(buffer);
	return (k);
}

char	*get_next_line(int fd)
{
	static char	*k;
	char		*last;

	if (fd < 0)
		return (0);
	k = rd(k, fd);
	if (!k)
		return (NULL);
	last = gnl_print(k);
	k = newk(k);
	return (last);
}
