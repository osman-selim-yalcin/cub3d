#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <time.h>
# include "../minilibx/mlx.h"
# define SCREEN_LEN 800
# define SCREEN_WID 1600
# define D_FOV 60
# define R_FOV (M_PI / 3)
# define SENS 1
# define HP 4
# define ENEMY_COUNT 5

typedef struct s_minimap
{
	//variables
	float	pos_x;
	float	pos_y;
	float	pa;	
	float	step_offset_x;
	float	step_offset_y;
	int		mapx;
	int		mapy;
	int		empty_column;
	int		empty_column2;
	int		full_scale;
	int		shift_x;
	int		shift_y;
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
	int		total_row;
	int		total_column;
	int		player_count;
	int		**doors;
	int		door_number;
}		t_map;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	int		row;
	int		column;
	int horizontal;
	int vertical;
	int	fov;
	int direction;
	double	ray_abs;
	double	ray_start;
	unsigned short int hp;
	unsigned short int hp_count;	
}		t_player;

typedef struct s_template
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_template;

typedef struct s_hand
{
	int attack;
	int left_hand;
	int right_hand;
	t_template	hand_img[27];
} t_hand;

typedef struct s_img
{
	void	*north_img;
	void	*north_addr;
	int		north_bits_per_pixel;
	int		north_line_length;
	int		north_endian;
	int		north_x;
	int		north_y;

	void	*south_img;
	void	*south_addr;
	int		south_bits_per_pixel;
	int		south_line_length;
	int		south_endian;
	int		south_x;
	int		south_y;

	void	*east_img;
	void	*east_addr;
	int		east_bits_per_pixel;
	int		east_line_length;
	int		east_endian;
	int		east_x;
	int		east_y;

	void	*dedge_img;
	void	*dedge_addr;
	int		dedge_bits_per_pixel;
	int		dedge_line_length;
	int		dedge_endian;
	int		dedge_x;
	int		dedge_y;

	void	*west_img;
	void	*west_addr;
	int		west_bits_per_pixel;
	int		west_line_length;
	int		west_endian;
	int		west_x;
	int		west_y;

	void 	*enemy_idle_img[7];
	void 	*enemy_idle_addr[7];
	void	*enemy_attack_img[4];
	void	*enemy_attack_addr[4];
	void	*enemy_vanish_img[7];
	void	*enemy_vanish_addr[7];
	int		enemy_bits_per_pixel[2];
	int		enemy_line_length[2];
	int		enemy_endian[2];
	int		enemy_x;
	int		enemy_y;

	void *img_frame;
	void *addr_f;
	int	line_length_f;
	int bits_per_pixel_f;
	int endian_f;

	void *img;
	void *addr;
	int	line_length;
	int bits_per_pixel;
	int endian;

	void *ceil_img;
	void *ceil_addr;
	int		ceil_bits_per_pixel;
	int		ceil_line_length;
	int		ceil_endian;
	int ceilx;
	int ceily;
	int ceil_index_x;
	int ceil_index_y;

	void	*door_img;
	void	*door_addr;
	int		door_bits_per_pixel;
	int		door_line_length;
	int		door_endian;
	int		door_x;
	int		door_y;
	int door_index_x;
	int door_index_y;

	unsigned int which_wall;
	unsigned int wall_x;
	unsigned int wall_y;

	t_hand		hand;
}			t_img;

typedef struct s_libx
{
	void	*mlx;
	void	*win;
}			t_libx;

typedef struct s_enemy
{
	float posx;
	float posy;
	float	mini_x;
	float	mini_y;
	double start;
	double middle;
	double distance;
	unsigned int e_wall_x;
	unsigned int e_wall_y;
	int width;
	int pixel;
	float forx_count;
	short int alive;
	struct s_enemy	*next;
	struct s_enemy	*head;
	int id;
	short int	attack_state;
	short int	vanish_state;
	short int	frame_counter;
	int			sleep;
}	t_enemy;

typedef struct s_spawn
{
	int pos_x;
	int pos_y;
	struct s_spawn *next;
}	t_spawn;

typedef struct s_settings
{
	int		minimap_scale;
	float	step_size;
	float 	player_size;
	float	ray_len;//tmp
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_w;
	int		key_left;
	int		key_right;
	int		key_up;
	int		key_down;
}	t_settings;

typedef struct s_level
{
	int enemy_spawn_rate;
	int regen;
	int sleep;
	int enemy_speed;
} t_level;

typedef struct s_game
{
	t_libx		libx;
	t_player	player;
	t_map		map;
	t_img		img;
	t_minimap	minimap;
	t_settings	settings;
	t_enemy		*enemy;
	t_spawn		*spawn;
	t_level		level;
	short int	enemy_idle_state;
	short int	enemy_count;
	short int	spawn_count;
	int		mouse_vertical;
	clock_t time;
}			t_game;

//area__start.c
void start(t_game *game);

//area_top_right.c
int find_wall_vertical_one(double hor, double ver, t_game *game);
int find_wall_horizontal_one(double hor, double ver, t_game *game);
void top_right(t_game *game, double ray_counter);

//area_top_left.c
int find_wall_vertical_two(double hor, double ver, t_game *game);
int find_wall_horizontal_two(double hor, double ver, t_game *game);
void top_left(t_game *game, double ray_counter);

//area_bottom_left.c
void bottom_left(t_game *game, double ray_counter);
int find_wall_vertical_three(double hor, double ver, t_game *game);
int find_wall_horizontal_three(double hor, double ver, t_game *game);

//area_bottom_right.c
int find_wall_vertical_four(double hor, double ver, t_game *game);
int find_wall_horizontal_four(double hor, double ver, t_game *game);
void bottom_right(t_game *game, double ray_counter);

//check_closed_map.c
int	line_len_wo_last_spaces(char *line);
void	set_length_width(t_game *game);
char	**open_up_space(t_game *game);
void	get_line_from_map(t_game *game, char *map, char *tmp);
void	get_map_to_tmp(t_game *game, char **tmp);
void print_map(char **map); //tmp
void	fill_spaces(char **map);
int	put_frame_to_map(t_game *game);

//check_component.c
int		is_line_valid(t_game *game, char *line, int coor_y);
int		check_component(t_game *game);
void	append_enemy(t_game *game);

//check_direction.c
int	is_bottom_valid(char **map, int row, int column);
int	is_top_valid(char **map, int row, int column);
int	is_left_valid(char **map, int row, int column);
int	is_right_valid(char **map, int row, int column);
int	check_all_twos(char **map);

//check_door.c
int		check_door_position(t_game *game);
void	add_door_position(t_game *game);
void	get_door_position(t_game *game);

//check_file_xpm.c
int is_xpm_exist(t_game *game,char *texture, int i);
int get_xpm_files(t_game *game, char *texture, int i);

//check_map_find_utils.c
int	is_top_num_tmp(char **map, int row, int column);
int	is_left_num_tmp(char **map, int row, int column);
int	is_right_num_tmp(char **map, int row, int column);
int	is_bottom_num_tmp(char **map, int row, int column);

//check_map.c
int map_element_check(t_game *game);
int rgb_check(t_game *game, int i);
int check_map(t_game *game, int ac);
int is_map_cube(t_game *game);

//check_one_piece_map.c
int	check_partition(t_game *game);
void	free_copy_map(t_game *game, char **map);
void	set_bg_to_two(char **tmp_map, int row, int column);
char	**copy_map(t_game *game);
void	set_player_index(t_game *game);
int	search_non_two(char **map);

//check_valid_map.c
int		read_map(t_game *game);
int		after_map_is_valid(t_game *game, char *line, int fd);
void	add_to_map(t_game *game, char *line);
char	**append_2d_array(char **map, char *line);
int		is_nl(t_game *game, char *line);
void	free_2d_char_arr(char **ptr);

//enemy.c
void get_enemy(t_game *game);
void enemy_walk(t_game *game);
int enemy_collision(t_game *game, float x, float y);
void enemy_print(t_game *game, int ray_counter, int hypo_tmp);

//event_door_key.c
void key_e(t_game *game);

//event_hook.c
int hook_event(t_game *game);
void	set_idle_state(t_game *game);
void move(t_game *game);

//event_keys_walk.c
int player_collision(t_game *game, float x, float y);
void key_a(t_game *game);
void key_d(t_game *game);
void key_w(t_game *game);
void key_s(t_game *game);

//event_keys.c
int key_event_down(int keycode, t_game *game);
void	synchronize_settings(t_game *game);
int key_event_up(int keycode, t_game *game);

//event_kill.c
void	kill_all(t_game *game);
void	revive_all(t_game *game);

//event_mouse.c
int mouse_move(int x, int y, t_game *game);
int	temporary_killer(int code, int x, int y, t_game *game); // to be changed


//get_value.c
void fill_struct_map(t_game *game, char **av);
void get_value(t_game *game);
void fill_struct_minimap(t_game *game);
void fill_struct_libx_and_img(t_game *game);
void	game_settings(t_game *game);
void	find_first_empty_columns(t_game *game);
void	find_last_empty_columns(t_game *game);
void	set_scale_factor(t_game *game);

//main.c
int tmp_exit(void);
int main(int ac, char **av);

//minimap.c
void	set_enemy_mini_position(t_game *game);
void display_minimap(t_game *game);
void draw_64(int x, int y, t_game *game);
void draw_map(t_game *game);
void draw_player(t_game *game);
void draw_ray(t_game *game, float ray_len);

//player_attack.c
void p_attack(t_game *game);

//print_frame.c
void	my_mlx_pixel_put_frame(t_game *game, int x, int y, int color);
void print_frame(t_game *game, int action);

//print_pixel.c
void 	pixelput(t_game *game, double hypo_tmp, double ray_counter);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void put_floorceil(t_game *game, int x, int real_wall, int start, int wall);
void put_hand(t_game *game, int ray_counter);

//print_texture.c
unsigned int take_texture(t_game *game, int x, int y, int which_wall);

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

//utilities_angle.c
int	rad_to_deg(double rad);
double deg_to_rad(double degree);
int	round_double(double num);
double take_approximate(double a, double b);

//utilities_find_area.c
int	direction_angle(t_game *game);
int	ray_angle(t_game *game);
int	degree_angle(int degree);

//game_over.c
int game_over(t_game *game);


#endif
