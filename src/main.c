#include "../fdf.h"

int	main(int argc, char **argv)
{	
	t_vars	vars;
	t_data	img;
	int		width;
	int		height;

	if (argc == 2)
	{
		vars.mlx = mlx_init();
		mlx_get_screen_size(vars.mlx, &width, &height);
		vars.win = mlx_new_window(vars.mlx, width, height, "fdf!!!!");
		img.img = mlx_new_image(vars.mlx, width, height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		ft_init_map(argv[1], &img);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, 2, 1L<<0, escape_key, &vars);
		mlx_hook(vars.win, 33, 0L, close_window, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}