#include "../fdf.h"

void	project_iso(int x, int y, t_map *map, int z)
{
	float	COS30;
	float	SIN30;

	COS30 = cos(M_PI / 8);
	SIN30 = sin(M_PI / 8);

	map->x_iso = (x + y) * COS30 * map->scale + 1000;
	map->y_iso = ((x - y) * SIN30 - (z / 4)) * map->scale + 1000;
}