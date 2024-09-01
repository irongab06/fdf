#include "../fdf.h"

void	proj_iso(int x, int y, t_map *map, int z)
{
	float	add;
	float	cos_angle;
	float	sin_angle;

	add = 0;

	cos_angle = cos(map->rotate);
	sin_angle = sin(map->rotate);

	float	x_rot = x * cos_angle - y * sin_angle;
	float	y_rot = x * sin_angle + y * cos_angle;

	float	COS30 = cos(M_PI / 6);
	float	SIN30 = sin(M_PI / map->new_projection);

	map->x_iso = (x_rot + y_rot) * COS30 * map->scale + map->offset_x;
	add = (x_rot - y_rot) * SIN30;
	map->y_iso = (add - (z / map->divider)) * map->scale + map->offset_y;
	//(x_rot - y_rot) * SIN30;
}

void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->line_count)
	{
		free(map->map_int[i]);
		i++;
	}
	free(map->map_int);
}
void	ft_free_3d(char ***str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != NULL)
		{
			free(str[i][j]);
			j++;
		}
		free(str[i]);
		i++;
	}
	free(str);
}
void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_scale(t_map *map)
{
	float	screen;
	float	size_map;

	screen = (map->height * map->width) / 6;
	size_map = 0.00f;
	map->scale = 0.00f;
	while (size_map < screen)
	{
		size_map = (map->line_count * map->scale);
		size_map *= map->column_count * map->scale;
		if ((map->column_count * map->scale) > map->height)
			break;
		if ((map->line_count * map->scale) > map->width)
			break;
		map->scale += 0.01f;
	}
}