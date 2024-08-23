#include "../fdf.h"

int	mouse_click(int button, int x, int y, void *param)
{
	(void)param; // On n'utilise pas le paramètre ici, donc on le cast pour éviter les warnings.
	if (button == 1) // Le bouton gauche de la souris est souvent représenté par le numéro 1
	{
		printf("Clic détecté aux coordonnées : x = %d, y = %d\n", x, y);
	}
	return (0);
}


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
		printf("taille ecran %i\n", width);
		printf("taille ecran %i\n", height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		img.height = height;
		img.width = width;
		ft_init_map(argv[1], &img);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_mouse_hook(vars.win, mouse_click, NULL);
		mlx_hook(vars.win, 2, 1L<<0, escape_key, &vars);
		mlx_hook(vars.win, 33, 0L, close_window, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}