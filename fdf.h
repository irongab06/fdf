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
	int		line_count;
	int		column_count;
	int		width;
	int		height;
	int		**map_int;
	float	x_iso;
	float	y_iso;
	float	scale;
	char	***map;
}				t_map;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_init_map(char *file, t_data *img);
void	get_line_map(char **str_map, char *file, int size);
void	ft_besenham(t_data *img, int x1, int y1, int x2, int y2, int color);
void	ft_malloc_init_map(t_map *map);
void	draw_map(t_map *map, t_data *img);
void	project_iso(int x, int y, t_map *map, int z);

//--------------------------------------------------------------

int	close_window(t_vars *vars);
int	escape_key(int keycode, t_vars *vars);
int		ft_size_map(char *file);
int	ft_count_line(char **line);
int	ft_count_column(char ***map);

//--------------------------------------------------------------

char	*ft_malloc(int size);

//--------------------------------------------------------------

t_map	ft_split_colomn(char **line);

#endif