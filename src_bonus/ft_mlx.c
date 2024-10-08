/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:44:00 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/05 09:44:02 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_map *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_image(map->mlx, map->img);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	ft_free_3d(map->map);
	ft_free(map);
	exit (0);
	return (0);
}

int	escape_key(int keycode, t_map *map)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(map->mlx, map->win);
		mlx_destroy_image(map->mlx, map->img);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		ft_free_3d(map->map);
		ft_free(map);
		exit (0);
	}
	return (0);
}

int	key_hook(int keycode, t_map *map)
{
	ft_movement(keycode, map);
	ft_up_down(keycode, map);
	ft_rotate(keycode, map);
	ft_projection(keycode, map);
	ft_color(keycode, map);
	if (keycode == 0xff0d)
		draw_map(map, 0);
	ft_reset_map(map);
	return (0);
}

int	mouse_scroll(int scroll, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	(void)map;
	if (scroll == 4)
		map->scale += 0.50f;
	if (scroll == 5 && map->scale >= 2.00f)
		map->scale -= 0.50f;
	ft_reset_map(map);
	return (0);
}
