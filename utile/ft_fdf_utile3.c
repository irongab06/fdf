#include "../fdf.h"

void	ft_center_map(int x, int y, t_map *map, t_data *img)
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

	map->offset_x = (img->width / 2) - map->x_iso;
	map->offset_y = (img->height / 2) - map->y_iso;
}