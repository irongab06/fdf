#include "../fdf.h"

void	ft_height_2(t_map *m, int x, int y, float s)
{
	float	add_y;

	add_y = 0;
	while (++x < m->line_count)
	{
		y = 0;
		while (++y < m->column_count)
		{
			if (m->map_int[x][y] == m->z_max)
			{
				add_y = ((x - y) * s - (m->map_int[x][y] / m->divider));
				m->y_iso = add_y * m->scale + m->offset_y;
				while (m->y_iso < 0)
				{
					if (m->z_max < 20)
						m->divider = 2;
					else if (m->z_max < 100)
						m->divider = m->z_max / 2;
					else
						m->divider = m->z_max / 12;
					break ;
				}
			}
		}
	}
}
