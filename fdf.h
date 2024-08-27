#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <math.h>

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
	float	color;
	float	divider;
	float	x_iso;
	float	y_iso;
	float	scale;
	float	offset_x;
	float	offset_y;
	char	***map;
	char	*addr;
}				t_map;

typedef struct	s_data 
{
	//void	*img;
	//char	*addr;
	//int		bits_per_pixel;
	//int		line_length;
	//int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

//---------------------------------------------------------------

void	my_mlx_pixel_put(t_map *data, int x, int y, int color);
void	ft_init_map(char *file, t_map *map);
void	get_line_map(char **str_map, char *file, int size);
void	ft_besenham(t_map *map, int x1, int y1, int x2, int y2, int color);
void	ft_malloc_init_map(t_map *map);
void	draw_map(t_map *map, int inter);
void	project_iso(int x, int y, t_map *map, int z);
void	ft_free(t_map *map);
void	ft_free_3d(char ***str);
void	ft_free_str(char **str);
void	ft_scale(t_map *map);
void	ft_center_map(int x, int y, t_map *map);
void	ft_height(t_map *map);
void	ft_reset_map(t_map *map);

//--------------------------------------------------------------

int	close_window(t_map *map);
int	escape_key(int keycode, t_map *map);
int	ft_size_map(char *file);
int	ft_count_line(char **line);
int	ft_count_column(char ***map);
int	key_hook(int key, t_map *map);
int	mouse_scroll(int scroll, int x, int y, t_map *map);

//--------------------------------------------------------------

char	*ft_malloc(int size);

//--------------------------------------------------------------

void	ft_split_colomn(char **line, t_map *map);

#endif