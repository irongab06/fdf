#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define M_PI 3.14159265358979323846

typedef struct	s_map
{
	void	*img;
	void	*mlx;
	void	*win;
	float	rotate;
	int		line_count;
	int		column_count;
	int		width;
	int		width_screen;
	int		height;
	int		height_screen;
	int		**map_int;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		new_projection;
	int		color;
	int		z_max;
	int		index_color;
	float	divider;
	float	x_iso;
	float	y_iso;
	float	scale;
	float	offset_x;
	float	offset_y;
	float	x_rot;
	float	y_rot;
	float	COS;
	float	SIN;
	char	***map;
	char	*addr;
}				t_map;

typedef struct	s_algo 
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	float	temp_column;
	float	temp_line;
}				t_algo;

//---------------------------------------------------------------

void	my_mlx_pixel_put(t_map *data, int x, int y, int color);
void	ft_init_map(char *file, t_map *map);
void	get_line_map(char **str_map, char *file, int size);
void	ft_malloc_init_map(t_map *map);
void	draw_map(t_map *map, int inter);
void	proj_iso(int x, int y, t_map *map, int z);
void	ft_free(t_map *map);
void	ft_free_3d(char ***str);
void	ft_free_str(char **str);
void	ft_scale(t_map *map);
void	ft_center_map(int x, int y, t_map *map);
void	ft_height(t_map *map);
void	ft_reset_map(t_map *map);
void	config_start_draw(t_map *map);
void	ft_movement(int keycode, t_map *map);
void	ft_up_down(int keycode, t_map *map);
void	ft_rotate(int keycode, t_map *map);
void	ft_projection(int keycode, t_map *map);
void	ft_color(int keycode, t_map *map);
void	ft_besenham_1(t_map *map, t_algo *algo);
void	ft_switch(t_map *map, t_algo *algo);
void	ft_switch_1(t_map *map, t_algo *algo);
void	ft_init_value(t_algo *algo);
void	ft_malloc_1(t_map *map, int line);
void	ft_draw_line(t_map *map, t_algo *algo, int line, int column);
void	ft_draw_column(t_map *map, t_algo *algo);
void	ft_height_2(t_map *map, int	line, int column, float SIN30);

//--------------------------------------------------------------

int		close_window(t_map *map);
int		escape_key(int keycode, t_map *map);
int		ft_size_map(char *file);
int		ft_count_line(char **line);
int		ft_count_column(char ***map);
int		key_hook(int key, t_map *map);
int		mouse_scroll(int scroll, int x, int y, t_map *map);

//--------------------------------------------------------------

char	*ft_malloc(int size);

//--------------------------------------------------------------

void	ft_split_colomn(char **line, t_map *map);

#endif