#include "../fdf.h"

void	ft_movement(int keycode, t_map *map)
{
		if (keycode == 0xff51)
		map->offset_x -= 20.00f;
	if (keycode == 0xff52)
		map->offset_y -= 20.00f;
	if (keycode == 0xff54)
		map->offset_y += 20.00f;
	if (keycode == 0xff53)
		map->offset_x += 20.00f;
}

void	ft_up_down(int keycode, t_map *map)
{
	if (keycode == 0xff56)
		map->divider += 0.10f;	
	if (keycode == 0xff55 && map->divider >= 0.10f)
		map->divider -= 0.10f;
}

void	ft_rotate(int keycode, t_map *map)
{
	if (keycode == 0x2d)
		map->rotate += 0.20f;
	if (keycode == 0x3d)
		map->rotate -= 0.20f;
}

void	ft_projection(int keycode, t_map *map)
{
	if (keycode == 0x32)
		map->new_projection = 1;
	if (keycode == 0x31)
		map->new_projection = 6;
}

void	ft_color(int keycode, t_map *map)
{	
	if (keycode == 0x5b && map->index_color < 5)
		map->index_color++;
	if (keycode == 0x5d && map->index_color > 0)
		map->index_color--;
	if (map->index_color == 0)
 		map->color = 0x00FF0000;
 	if (map->index_color == 1)
 		map->color = 0x0000FF00;
	if (map->index_color == 2)
		map->color = 0x000000FF;
	if (map->index_color == 3)
		map->color = 0x00FFFFFF;
	if (map->index_color == 4)
		map->color = 0x00FFFF00;
	if (map->index_color == 5)
		map->color = 0x00FF69B4;
	
}