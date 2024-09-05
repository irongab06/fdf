/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utile1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:44:12 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/05 09:44:14 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_besenham_1(t_map *map, t_algo *algo)
{
	ft_init_value(algo);
	while (1)
	{
		if (algo->x1 < map->width && algo->y1 < map->height
			&& algo->x1 >= 0 && algo->y1 >= 0)
			my_mlx_pixel_put(map, algo->x1, algo->y1, map->color);
		if (algo->x1 == algo->x2 && algo->y1 == algo->y2)
			break ;
		algo->e2 = 2 * algo->err;
		if (algo->e2 > -algo->dy)
		{
			algo->err -= algo->dy;
			algo->x1 += algo->sx;
		}
		if (algo->e2 < algo->dx)
		{
			algo->err += algo->dx;
			algo->y1 += algo->sy;
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
	while (map[line])
	{
		column = 0;
		while (map[line][column])
		{
			if (column >= max_column)
				max_column++;
			column++;
		}
		line++;
	}
	return (max_column);
}

void	ft_malloc_init_map(t_map *map)
{
	int	column;
	int	line;

	column = 0;
	line = 0;
	map->map_int = malloc(sizeof(int *) * map->line_count);
	while (line < map->line_count)
	{
		ft_malloc_1(map, line);
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
	int		line;
	int		column;
	t_algo	algo;

	ft_init_algo(&algo);
	line = 0;
	if (inter == 0)
		config_start_draw(map);
	while (line < map->line_count)
	{
		column = 0;
		while (column < map->column_count)
		{
			proj_iso(line, column, map, map->map_int[line][column]);
			if (column > 0)
				ft_draw_column(map, &algo);
			algo.temp_column = map->y_iso;
			algo.temp_line = map->x_iso;
			if (line > 0)
				ft_draw_line(map, &algo, line, column);
			column++;
		}
		line++;
	}
}
