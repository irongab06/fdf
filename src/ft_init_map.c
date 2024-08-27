#include "../fdf.h"

void	ft_init_map(char *file, t_map *map)
{
	int		size;
	char	*str_map;
	char	**line;

	str_map = NULL;
	size = ft_size_map(file);
	str_map = ft_malloc(size);
	if (size != 0)
	{
		
		ft_bzero(str_map, (size_t)size);
		get_line_map(&str_map, file, size);
		line = ft_split(str_map, '\n');
		ft_split_colomn(line, map);
		map->column_count = ft_count_column(map->map);
		ft_malloc_init_map(map);
		draw_map(map, 0);
		free(str_map);
		ft_free_str(line);
	}
	else
		my_mlx_pixel_put(map, 0, 0, 0x00FF0000);
}