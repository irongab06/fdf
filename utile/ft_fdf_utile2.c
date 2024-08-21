#include "../fdf.h"

void	project_iso(int x, int y, t_map *map, int z)
{
	float	COS30;
	float	SIN30;

	COS30 = cos(M_PI / 8);
	SIN30 = sin(M_PI / 8);

	map->x_iso = (x + y) * COS30 * map->scale + 1000;
	map->y_iso = ((x - y) * SIN30 - (z)) * map->scale + 1000;
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