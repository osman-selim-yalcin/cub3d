#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "minilibx/mlx.h"
# include <stdlib.h>

typedef struct s_map
{
	char	*north_wall;
	char	*south_wall;
	char	*east_wall;
	char	*west_wall;
	int		floor_rgb;
	int		ceilling_rgb;
	char	**map;
}		t_map;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}		t_player;

typedef struct s_img
{
	void	*north_img;
	void	*south_img;
	void	*east_img;
	void	*west_img;
}			t_img;

typedef struct s_libx
{
	void	*mlx;
	void	*win;
}			t_libx;

typedef struct s_game
{
	t_libx		libx;
	t_player	layer;
	t_map		map;
}			t_game;

#endif