#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "minilibx/mlx.h"
# define SCREEN_LEN 1080
# define SCREEN_WID 1920
# define D_FOV 60
# define R_FOV M_PI / 3

typedef struct s_minimap
{
	void	*win;
	void	*img;
	int		endian;
	void *addr;
	int	line_length;
	int	bits_per_pixel;
	//variables
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	pos_x;
	float	pos_y;
	float	pa;	
	float	step_offset_x;
	float	step_offset_y;
	int		mapx;
	int		mapy;
	int		mapsize;
} 	t_minimap;

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
	int		length;
	int		width;
	char	*map_path;
	int		gnl_count;
	int		started_reading;
	int		player_count;
}		t_map;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	int horizontal;
	int vertical;
	int	fov;
	int direction;
	double ray_absoulete; 
}		t_player;

typedef struct s_img
{
	void	*north_img;
	void	*north_addr;
	int		north_bits_per_pixel;
	int		north_line_length;
	int		north_endian;
	int		north_wall_index;

	void	*south_img;
	void	*south_addr;
	int		south_bits_per_pixel;
	int		south_line_length;
	int		south_endian;
	int		south_wall_index;
	
	void	*east_img;
	void	*east_addr;
	int		east_bits_per_pixel;
	int		east_line_length;
	int		east_endian;
	int		east_wall_index;

	void	*west_img;
	void	*west_addr;
	int		west_bits_per_pixel;
	int		west_line_length;
	int		west_endian;
	int		west_wall_index;

	void *img;
	void *addr;
	int	line_length;
	int bits_per_pixel;
	int endian;

	int			color;
	int		color_wall;
}			t_img;

typedef struct s_libx
{
	void	*mlx;
	void	*win;
}			t_libx;

typedef struct s_settings
{
	int		minimap_scale;
	float	step_size;
	float 	player_size;
	float	ray_len;//tmp
}	t_settings;

typedef struct s_game
{
	t_libx		libx;
	t_player	player;
	t_map		map;
	t_img		img;
	t_minimap	minimap;
	t_settings	settings;
}			t_game;

//check_map.c
int map_element_check(t_game *game);
int rgb_check(t_game *game, int i);
int check_map(t_game *game, int ac);

//valid_map_check.c
int		read_map(t_game *game);
int		after_map_is_valid(t_game *game, char *line, int fd);
void	add_to_map(t_game *game, char *line);
char	**append_2d_array(char **map, char *line);
int		is_nl(t_game *game, char *line);
void	free_2d_char_arr(char **ptr);
int		is_line_valid(t_game *game, char *line, int coor_y);
int		check_component(t_game *game);
int	put_frame_to_map(t_game *game);

//direction_check.c
int	is_bottom_valid(char **map, int row, int column);
int	is_top_valid(char **map, int row, int column);
int	is_left_valid(char **map, int row, int column);
int	is_right_valid(char **map, int row, int column);
int	check_all_twos(char **map);

//file_xpm_check.c
int is_this_xpm(char *texture);
int is_xpm_exist(t_game *game,char *texture, int i);
int get_xpm_files(t_game *game, char *texture, int i);

//get_value.c
void fill_struct_map(t_game *game, char **av);
void get_value(t_game *game);
void fill_struct_minimap(t_game *game);
void fill_struct_libx_and_img(t_game *game);

//utilities_1/2.c functions
char	*newk(char *k);
char	*gnl_print(char *k);
char	*rd(char *k, int fd);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
void	*ft_memcpy(void *dst, void *src, int n);
char	*ft_strdup(char *s1);
int	string_length(char *str);
int	check_newline(char *ptr);
char	*append_string(char *str, char *buf);

//utilities_3
int	element_strncmp(char *s1, char *s2, size_t size);
int	ft_atoi(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t b);
char	**ft_split(char *s, char c);
int	create_trgb(int t, int r, int g, int b);

//find_wall.c
int find_wall_vertical(double hor, double ver, t_game *game);
int find_wall_horizontal(double hor, double ver, t_game *game);

//key_event.c
int key_event(int keycode, t_game *game);

//pixel.c
void 	pixelput(t_game *game, double hypo_tmp, double ray_counter);
void 	put_floorceil(t_game *game);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);

//angle_utils.c
int	rad_to_deg(double rad);
double deg_to_rad(double degree);
int	round_double(double num);

//find_area.c
int	direction_angle(t_game *game);
int	ray_angle(t_game *game);

//minimap.c
void display(t_game *game);
void draw_64(int x, int y, t_game *game);
void draw_map(t_game *game);
void draw_player(t_game *game);
void draw_ray(t_game *game, float ray_len);


void tmp(t_game *game);
void print_map(char **map);
int tmp_exit(void);
double take_approximate(double a, double b);
#endif