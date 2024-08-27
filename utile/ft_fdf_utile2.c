#include "../fdf.h"

// void rotate_x(float *y, float *z, float alpha) {
//     float cos_a = cos(alpha);
//     float sin_a = sin(alpha);

//     float y_new = *y * cos_a - *z * sin_a;
//     float z_new = *y * sin_a + *z * cos_a;

//     *y = y_new;
//     *z = z_new;
// }


void	project_iso(int x, int y, t_map *map, int z)
{
	// float	COS30;
	// float	SIN30;

	// COS30 = cos(M_PI / 8);
	// SIN30 = sin(M_PI / map->rotate);

	// map->x_iso = (x + y) * COS30 * map->scale + map->offset_x;
	// map->y_iso = ((x - y) * SIN30 - (z / map->divider)) * map->scale + map->offset_y;
	// printf("point iso : %f\n", map->y_iso);
	//-----------------------------------------------
	float cos_angle;
    float sin_angle;

    // Calculer les angles cosinus et sinus pour la rotation
    cos_angle = cos(map->rotate);
    sin_angle = sin(map->rotate);

    // Appliquer la rotation autour de l'axe Z
    float x_rot = x * cos_angle - y * sin_angle;
    float y_rot = x * sin_angle + y * cos_angle;


    // Calcul des coordonnées isométriques
    float COS30 = cos(M_PI / 6); // angle de 30 degrés pour isométrique
    float SIN30 = sin(M_PI / map->new_projection); // angle de 30 degrés pour isométrique

    map->x_iso = (x_rot + y_rot) * COS30 * map->scale + map->offset_x;
    map->y_iso = ((x_rot - y_rot) * SIN30 - (z / map->divider)) * map->scale + map->offset_y;

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