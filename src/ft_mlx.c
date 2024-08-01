#include "../fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int	escape_key(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}
