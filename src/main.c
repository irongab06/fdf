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
		//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
		// ft_besenham(&img, 1140, 700, 2280, 700, 0x00FF0000);
		// ft_besenham(&img, 1140, 770, 2280, 770, 0x00FF0000);
		// ft_besenham(&img, 1140, 840, 2280, 840, 0x00FF0000);
		// ft_besenham(&img, 1140, 910, 2280, 910, 0x00FF0000);
		// ft_besenham(&img, 1140, 980, 2280, 980, 0x00FF0000);
		// ft_besenham(&img, 1140, 1050, 2280, 1050, 0x00FF0000);
		// ft_besenham(&img, 1140, 1120, 2280, 1120, 0x00FF0000);
		// ft_besenham(&img, 1140, 1190, 2280, 1190, 0x00FF0000);
		// ft_besenham(&img, 1140, 1260, 2280, 1260, 0x00FF0000);
		// ft_besenham(&img, 1140, 1330, 2280, 1330, 0x00FF0000);

		// ft_besenham(&img, 1140, 700, 1140, 1330, 0x00FF0000);
		// ft_besenham(&img, 1235, 700, 1235, 1330, 0x00FF0000);
		// ft_besenham(&img, 1330, 700, 1330, 1330, 0x00FF0000);
		// ft_besenham(&img, 1425, 700, 1425, 1330, 0x00FF0000);
		// ft_besenham(&img, 1520, 700, 1520, 1330, 0x00FF0000);
		// ft_besenham(&img, 1615, 700, 1615, 1330, 0x00FF0000);
		// ft_besenham(&img, 1710, 700, 1710, 1330, 0x00FF0000);
		// ft_besenham(&img, 1805, 700, 1805, 1330, 0x00FF0000);
		// ft_besenham(&img, 1900, 700, 1900, 1330, 0x00FF0000);
		// ft_besenham(&img, 1995, 700, 1995, 1330, 0x00FF0000);
		// ft_besenham(&img, 2090, 700, 2090, 1330, 0x00FF0000);
		// ft_besenham(&img, 2185, 700, 2185, 1330, 0x00FF0000);
		// ft_besenham(&img, 2280, 700, 2280, 1330, 0x00FF0000);
		// ft_besenham(&img, 2280, 700, 0, 0, 0x00FF0000);
		ft_besenham(&img, 1140, 700, 1230, 750, 0x00FF0000); // (0, 0, 0) à (1, 0, 0)
		 ft_besenham(&img, 1230, 750, 1320, 800, 0x00FF0000); // (1, 0, 0) à (2, 0, 0)
		// ft_besenham(&img, 1050, 750, 1140, 800, 0x00FF0000); // (0, 1, 0) à (1, 1, 0)
		// ft_besenham(&img, 1140, 800, 1230, 850, 0x00FF0000); // (1, 1, 0) à (2, 1, 0)
		// ft_besenham(&img, 960, 800, 1050, 850, 0x00FF0000);  // (0, 2, 0) à (1, 2, 0)
		// ft_besenham(&img, 1050, 850, 1140, 900, 0x00FF0000); // (1, 2, 0) à (2, 2, 0)

		// // Lignes verticales (après projection isométrique)
		// ft_besenham(&img, 1140, 700, 1050, 750, 0x00FF0000); // (0, 0, 0) à (0, 1, 0)
		// ft_besenham(&img, 1050, 750, 960, 800, 0x00FF0000);  // (0, 1, 0) à (0, 2, 0)
		// ft_besenham(&img, 1230, 750, 1140, 800, 0x00FF0000); // (1, 0, 0) à (1, 1, 0)
		// ft_besenham(&img, 1140, 800, 1050, 850, 0x00FF0000); // (1, 1, 0) à (1, 2, 0)
		// ft_besenham(&img, 1320, 800, 1230, 850, 0x00FF0000); // (2, 0, 0) à (2, 1, 0)
		// ft_besenham(&img, 1230, 850, 1140, 900, 0x00FF0000); // (2, 1, 0) à (2, 2, 0)
		ft_init_map(argv[1]);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, 2, 1L<<0, escape_key, &vars);
		mlx_hook(vars.win, 33, 0L, close_window, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}