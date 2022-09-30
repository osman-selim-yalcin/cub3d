#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "minilibx/mlx.h"
typedef struct s_map
{
	char	*north_wall;
	char	*south_wall;
	char	*east_wall;
	char	*west_wall;
	char	*floor_char;
	char	*ceilling_char;
	int		floor_rgb;
	int		ceilling_rgb;
	char	**map;
	char	*map_path;
	int		gnl_count;
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
	//deneme
	void	*big_img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}			t_img;

typedef struct s_libx
{
	void	*mlx;
	void	*win;
}			t_libx;

typedef struct s_game
{
	t_libx		libx;
	t_player	player;
	t_map		map;
	t_img		img;
}			t_game;

//check_map.c
int rgb_check(t_game *game, int i);

//get_value.c
void fill_map(t_game *game, char **av);
void get_value(t_game *game, char **av);

//utilities_1/2.c functions
int check_map(t_game *game);
char	*newk(char *k);
char	*gnl_print(char *k);
char	*rd(char *k, int fd);
char	*get_next_line(int fd);
int	ft_check(char *look, int c);
int	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, void *src, int n);
char	*ft_strdup(char *s1);

//utilities_3
int	element_strncmp(char *s1, char *s2, size_t size);
int	ft_atoi(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t b);
char	**ft_split(char *s, char c);







#endif