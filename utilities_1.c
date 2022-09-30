#include "cub3d.h"

int	ft_check(char *look, int c)
{
	int	l;

	l = 0;
	if (!look)
		return (1);
	while (look[l] != '\0')
	{
		if (look[l] == (char)c)
			return (0);
		l++;
	}
	return (1);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*last;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	last = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!last)
		return (0);
	ft_memcpy(last, s1, ft_strlen(s1));
	ft_memcpy(&last[ft_strlen(s1)], s2, ft_strlen(s2));
	free(s1);
	return (last);
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