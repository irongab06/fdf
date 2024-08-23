#include "../fdf.h"

void	project_iso(int x, int y, t_map *map, int z)
{
	float	COS30;
	float	SIN30;

	COS30 = cos(M_PI / 8);
	SIN30 = sin(M_PI / 8);

	map->x_iso = (x + y) * COS30 * map->scale + map->offset_x;
	map->y_iso = ((x - y) * SIN30 - (z / 4)) * map->scale + map->offset_y;
	//printf("point iso : %f\n", map->y_iso);
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

void	ft_scale(t_map *map, t_data *img)
{
	float	screen;
	float	size_map;

	screen = (img->height * img->width) / 6;
	size_map = 0.00f;
	map->scale = 0.00f;
	while (size_map < screen)
	{
		size_map = (map->line_count * map->scale);
		size_map *= map->column_count * map->scale;
		if ((map->column_count * map->scale) > img->height)
			break;
		if ((map->line_count * map->scale) > img->width)
			break;
		map->scale += 0.01f;
	}
}