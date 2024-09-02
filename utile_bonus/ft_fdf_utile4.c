#include "../fdf.h"

void	ft_init_value(t_algo *algo)
{
	algo->dx = abs(algo->x2 - algo->x1);
	algo->dy = abs(algo->y2 - algo->y1);
	if (algo->x1 < algo->x2)
		algo->sx = 1;
	else
		algo->sx = -1;
	if (algo->y1 < algo->y2)
		algo->sy = 1;
	else
		algo->sy = -1;
	algo->err = algo->dx - algo->dy;
}

void	ft_malloc_1(t_map *map, int line)
{
	map->map_int[line] = malloc(sizeof(int) * map->column_count);
	if (map->map_int[line] == NULL)
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit (1);
	}
	ft_bzero(map->map_int[line], sizeof(int) * map->column_count);
}

void	ft_draw_line(t_map *map, t_algo *algo, int line, int column)
{
	proj_iso(line - 1, column, map, map->map_int[line - 1][column]);
	ft_switch_1(map, algo);
	ft_besenham_1(map, algo);
	proj_iso(line, column, map, map->map_int[line][column]);
}

void	ft_draw_column(t_map *map, t_algo *algo)
{
	ft_switch(map, algo);
	ft_besenham_1(map, algo);
}

void	ft_switch(t_map *map, t_algo *algo)
{
	algo->x1 = algo->temp_line;
	algo->y1 = algo->temp_column;
	algo->x2 = map->x_iso;
	algo->y2 = map->y_iso;
}
