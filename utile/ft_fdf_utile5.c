/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utile5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:44:25 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/05 09:44:26 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_init_struct(t_map *map)
{
	ft_init_struct_int(map);
	ft_init_float(map);
	ft_init_pointers(map);
}

void	ft_init_struct_int(t_map *map)
{
	map->size = 0;
	map->line_count = 0;
	map->column_count = 0;
	map->width = 0;
	map->width_screen = 0;
	map->height = 0;
	map->height_screen = 0;
	map->map_int = NULL;
	map->bits_per_pixel = 0;
	map->line_length = 0;
	map->endian = 0;
	map->new_projection = 0;
	map->color = 0;
	map->z_max = 0;
	map->index_color = 0;
}

void	ft_init_float(t_map *map)
{
	map->rotate = 0.00f;
	map->divider = 0.00f;
	map->x_iso = 0.00f;
	map->y_iso = 0.00f;
	map->scale = 0.00f;
	map->offset_x = 0.00f;
	map->offset_y = 0.00f;
	map->x_rot = 0.00f;
	map->y_rot = 0.00f;
	map->cos = 0.00f;
	map->sin = 0.00f;
}

void	ft_init_pointers(t_map *map)
{
	map->img = NULL;
	map->mlx = NULL;
	map->win = NULL;
	map->map = NULL;
	map->addr = NULL;
}
