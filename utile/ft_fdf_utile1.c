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
void	ft_besenham(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	//int x1 = 0, y1 = 8;
	//int x2 = 8, y2 = 3;

	// int ey = abs(y2 -y1);
	// int ex = abs(x2 - x1);
	// int dx = 2 * ex;
	// int dy = 2 * ey;
	// int Dx = ex;
	// int Dy = ey;

	// int i = 0;
	// int Xincr = 1;
	// int Yincr = 1;

	// if (x1 > x2)
	// 	Xincr = -1;
	// if (y1 > y2)
	// 	Yincr = -1;
	// if (Dx > Dy)
	// {
	// 	while (i <= Dx)
	// 	{
	// 		my_mlx_pixel_put(img, x1, y1, color);
	// 		i++;
	// 		x1 += Xincr;
	// 		ex -= dy;
	// 		if (ex <0)
	// 		{
	// 			y1 += Yincr;
	// 			ex += dx;		
	// 		}
	// 	}
	// }
	// if (Dy > Dx)
	// {
	// 	while (i <= Dy)
	// 	{
	// 		my_mlx_pixel_put(img, x1, y1, color);
	// 		i++;
	// 		y1 += Yincr;
	// 		ey -= dx;
	// 		if (ey <0)
	// 		{
	// 			x1 += Xincr;
	// 			ey += dy;		
	// 		}
	// 	}
	// }
//---------------------------------------------------------------	
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
		if (x1 < img->width && y1 < img->height && x1 >= 0 && y1 >= 0)
			my_mlx_pixel_put(img, x1, y1, color);
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
			//printf(" %s", map[line][column]);
			column++;
		}
		//printf("\n");
		
		line++;
		//printf("line : %i \n", line);
	}
	return(max_column);
 }

void	ft_malloc_init_map(t_map *map)
{
	int	column;
	int	line;

	column = 0;
	line = 0;
	printf("map->column %i\n", map->column_count);
	printf("map->line %i\n", map->line_count);
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
void	draw_map(t_map *map, t_data *img)
{
	int	line;
	int	column;
	float	temp_column;
	float	temp_line;

	//map->scale = 8.0f;
	line = 0;
	ft_scale(map, img);
	ft_center_map(map->line_count, map->column_count, map, img);
	while (line < map->line_count)
	{
		column = 0;
		while (column < map->column_count)
		{
			project_iso(line, column, map, map->map_int[line][column]);
			if (column > 0)
				ft_besenham(img, temp_line, temp_column, map->x_iso, map->y_iso, 0x00FF0000);
			temp_column = map->y_iso;
			temp_line = map->x_iso;
			if(line > 0)
			{
				project_iso(line - 1, column, map, map->map_int[line - 1][column]);
                ft_besenham(img, map->x_iso, map->y_iso, temp_line, temp_column, 0x00FF0000);
                project_iso(line, column, map, map->map_int[line][column]);
			}
			column++;
		}
		line++;
	}
	//mlx_get_screen_size(vars.mlx, &map->width, &map->height);
}