/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osmanyalcin <osmanyalcin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:29:58 by osmanyalcin       #+#    #+#             */
/*   Updated: 2022/12/31 23:10:51 by osmanyalcin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (!((y < SCREEN_LEN && y >= 0) && (x >= 0 && x < SCREEN_WID)))
	{
		return ;
	}
	dst = game->img.addr + (y * game->img.line_length \
		+ x * (game->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
