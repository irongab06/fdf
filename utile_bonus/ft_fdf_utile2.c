/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utile2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:44:41 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/05 09:44:42 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	proj_iso(int x, int y, t_map *map, int z)
{
	float	add_y;
	float	add_x;
	float	cos_angle;
	float	sin_angle;

	add_y = 0;
	cos_angle = cos(map->rotate);
	sin_angle = sin(map->rotate);
	map->x_rot = x * cos_angle - y * sin_angle;
	map->y_rot = x * sin_angle + y * cos_angle;
	map->cos = cos(PI / 6);
	map->sin = sin(PI / map->new_projection);
	add_x = (map->x_rot + map->y_rot) * map->cos;
	map->x_iso = add_x * map->scale + map->offset_x;
	add_y = (map->x_rot - map->y_rot) * map->sin;
	map->y_iso = (add_y - (z / map->divider)) * map->scale + map->offset_y;
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
			break ;
		if ((map->line_count * map->scale) > map->width)
			break ;
		map->scale += 0.01f;
	}
}
