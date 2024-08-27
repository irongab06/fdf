#include "../fdf.h"

void	my_mlx_pixel_put(t_map *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit (0);
	return (0);
}

int	escape_key(int keycode, t_map *map)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit (0);
	}
	return (0);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 0xff51)
		map->offset_x -= 20.00f;
	if (keycode == 0xff52)
		map->offset_y -= 20.00f;
	if (keycode == 0xff54)
		map->offset_y += 20.00f;
	if (keycode == 0xff53)
		map->offset_x += 20.00f;
	if (keycode == 0xff56)
		map->divider += 0.10f;
	if (keycode == 0xff55)
		map->divider -= 0.10f;
	if (keycode == 0x2d)
		map->rotate += 0.20f;
	if (keycode == 0x3d)
		map->rotate -= 0.20f;
	if (keycode == 0x32)
		map->new_projection = 1;
	if (keycode == 0x31)
		map->new_projection = 6;
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

	printf("ca marche ");

	if (scroll == 4)
	{
		printf("scroll\n");
		map->scale += 0.30f;
	}	
	if (scroll == 5)
		map->scale -= 0.30f;
	ft_reset_map(map);
	return (0);
}
