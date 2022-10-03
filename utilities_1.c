#include "cub3d.h"

int	ft_strlen(char *s)
{
	int	p;

	if (!s)
		return (0);
	p = 0;
	while (s[p] != '\0')
		p++;
	return (p);
}

void	*ft_memcpy(void *dst, void *src, int n)
{
	int	a;

	a = 0;
	while (a < n)
	{
		((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
		a++;
	}
	((unsigned char *)dst)[a] = '\0';
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (0);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	string_length(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

int	check_newline(char *ptr)
{
	if (!ptr)
		return (1);
	while (*ptr)
	{
		if (*ptr == '\n')
			return (0);
		ptr++;
	}
	return (1);
}

char	*append_string(char *str, char *buf)
{
	char	*result;
	int		i;
	int		j;

	if (!buf)
		return (NULL);
	if (!str)
	{	
		str = malloc(1);
		*str = '\0';
	}
	result = malloc(string_length(str) + string_length(buf) + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (str[++i])
		result[i] = str[i];
	j = 0;
	while (buf[j])
		result[i++] = buf[j++];
	result[i] = '\0';
	free(str);
	return (result);
}