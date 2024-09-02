#include "../fdf.h"

void	ft_center_map(int x, int y, t_map *map)
{
	float	cos30;
	float	sin30;
	int		x_iso;
	int		y_iso;

	cos30 = cos(PI / 8);
	sin30 = sin(PI / 8);
	x_iso = x / 2;
	y_iso = y / 2;
	map->x_iso = (x_iso + y_iso) * cos30 * map->scale;
	map->y_iso = ((x_iso - y_iso) * sin30) * map->scale;
	map->offset_x = (map->width / 2) - map->x_iso;
	map->offset_y = (map->height / 2) - map->y_iso;
}

void	ft_height(t_map *map)
{
	int		line;
	int		column;
	float	sin30;

	map->divider = 1;
	sin30 = sin(PI / 8);
	line = 0;
	while (line < map->line_count)
	{
		column = 0;
		while (column < map->column_count)
		{
			if (map->z_max < map->map_int[line][column])
				map->z_max = map->map_int[line][column];
			column++;
		}
		line++;
	}
	line = 0;
	column = 0;
	ft_height_2(map, line, column, sin30);
}

void	ft_reset_map(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel,
			&map->line_length, &map->endian);
	draw_map(map, 1);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}

void	config_start_draw(t_map *map)
{
	ft_scale(map);
	ft_center_map(map->line_count, map->column_count, map);
	ft_height(map);
	map->rotate = 6;
	map->new_projection = 6;
	map->color = 0x00FF0000;
	map->index_color = 0;
}

void	ft_switch_1(t_map *map, t_algo *algo)
{
	algo->x1 = map->x_iso;
	algo->y1 = map->y_iso;
	algo->x2 = algo->temp_line;
	algo->y2 = algo->temp_column;
}
