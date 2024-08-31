#include "../fdf.h"

int	ft_count_line(char **line)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (line[x])
	{
		x++;
		i++;
	}
	return (i);
}

void	ft_besenham(t_map *map, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		if (x1 < map->width && y1 < map->height && x1 >= 0 && y1 >= 0)
			my_mlx_pixel_put(map, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
 }

 int	ft_count_column(char ***map)
 {
	int	line;
	int	column;
	int	max_column;

	line = 0;
	max_column = 0;
	while(map[line])
	{
	
		column = 0;
		while(map[line][column])
		{
			if (column >= max_column)
				max_column++;
			column++;
		}
		line++;
	}
	return(max_column);
 }

void	ft_malloc_init_map(t_map *map)
{
	int	column;
	int	line;

	column = 0;
	line = 0;
	map->map_int = malloc(sizeof(int*) * map->line_count);
	while (line < map->line_count)
	{
		map->map_int[line] = malloc(sizeof(int) * map->column_count);
		ft_bzero(map->map_int[line], sizeof(int) * map->column_count);
		line++;
	}
	line = 0;
	while (line < map->line_count)
	{
		column = 0;
		while (column < map->column_count)
		{
			if (map->map[line] != NULL && map->map[line][column] != NULL)
				map->map_int[line][column] = ft_atoi(map->map[line][column]);
			else
				map->map_int[line][column] = 0;
			column++;
		}
		line++;
	}
}
void	draw_map(t_map *map, int inter)
{
	int	line;
	int	column;
	float	temp_column;
	float	temp_line;

	line = 0;
	if (inter == 0)
		config_start_draw(map);
	while (line < map->line_count)
	{
		column = 0;
		while (column < map->column_count)
		{
			project_iso(line, column, map, map->map_int[line][column]);
			if (column > 0)
				ft_besenham(map, temp_line, temp_column, map->x_iso, map->y_iso, 0x00FF0000);
			temp_column = map->y_iso;
			temp_line = map->x_iso;
			if (line > 0)
			{
				project_iso(line - 1, column, map, map->map_int[line - 1][column]);
                ft_besenham(map, map->x_iso, map->y_iso, temp_line, temp_column, 0x00FF0000);
                project_iso(line, column, map, map->map_int[line][column]);
			}
			column++;
		}
		line++;
	}
}	