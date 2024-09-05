/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:44:04 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/05 09:44:06 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;

	ft_init_struct(&map);
	if (argc == 2)
	{
		map.size = ft_size_map(argv[1]);
		if (map.size == 0)
			return (0);
		map.mlx = mlx_init();
		mlx_get_screen_size(map.mlx, &map.width, &map.height);
		map.win = mlx_new_window(map.mlx, map.width, map.height, "fdf!!!!");
		map.img = mlx_new_image(map.mlx, map.width, map.height);
		map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel,
				&map.line_length, &map.endian);
		ft_init_map(argv[1], &map);
		mlx_put_image_to_window(map.mlx, map.win, map.img, 0, 0);
		mlx_key_hook(map.win, key_hook, &map);
		mlx_hook(map.win, 4, 4, mouse_scroll, &map);
		mlx_hook(map.win, 2, 1L << 0, escape_key, &map);
		mlx_hook(map.win, 33, 0L, close_window, &map);
		mlx_loop(map.mlx);
		ft_free_3d(map.map);
		ft_free(&map);
	}
	return (0);
}
