#include "../fdf.h"

void	ft_center_map(int x, int y, t_map *map)
{
	float	COS30;
	float	SIN30;
	int		x_iso;
	int		y_iso;

	COS30 = cos(M_PI / 8);
	SIN30 = sin(M_PI / 8);

	x_iso = x / 2;
	y_iso = y / 2;

	map->x_iso = (x_iso + y_iso) * COS30 * map->scale;
	map->y_iso = ((x_iso - y_iso) * SIN30) * map->scale;

	map->offset_x = (map->width / 2) - map->x_iso;
	map->offset_y = (map->height / 2) - map->y_iso;
	//------------------------------------------------------

}

void	ft_height(t_map *map)
{
	int		line;
	int		column;
	int		z_max;
	float	SIN30;

	z_max = 0;
	map->divider = 1;
	SIN30 = sin(M_PI / 8);
	line = 0;
	while (line < map->line_count)
	{
		column = 0;
		while (column < map->column_count)
		{
			if (z_max < map->map_int[line][column])
				z_max = map->map_int[line][column];
			column++;	
		}
		line++;
	}
	printf("z_max %i\n", z_max);
	line = 0;
	while(line < map->line_count)
	{
		column = 0;
		while (column < map->column_count)
		{
			if (map->map_int[line][column] == z_max)
			{
				map->y_iso = ((line - column) * SIN30 - (map->map_int[line][column] / map->divider)) * map->scale + map->offset_y;
				while (map->y_iso < 0)
				{
					printf("map iso %f\n", map->y_iso);	
					if (z_max < 20)
						map->divider = 2;
					else if (z_max < 100)
						map->divider = z_max / 2;	
					else
						map->divider = z_max / 12;	
					break;
				}	
				
			}
			column++;
		}
		line++;
	}
}

int	ft_color(t_map *map, int x, int y)
{
	int	value;

	value = map->map_int[x][y];
	if (value > 0)
		return (0x00FF00FF);
	else
		return (0x00FF0000);
	return (0);

}

void	ft_reset_map(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, &map->line_length,
									&map->endian);
	draw_map(map, 1); 
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}

void	config_map(t_map *map)
{
	
}