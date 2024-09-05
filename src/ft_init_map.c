/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:42:59 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/05 09:43:05 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_init_map(char *file, t_map *map)
{
	char	*str_map;
	char	**line;

	str_map = NULL;
	str_map = ft_malloc(map->size);
	ft_bzero(str_map, (size_t)map->size);
	get_line_map(&str_map, file, map->size);
	line = ft_split(str_map, '\n');
	ft_split_colomn(line, map);
	map->column_count = ft_count_column(map->map);
	ft_malloc_init_map(map);
	draw_map(map, 0);
	free(str_map);
	ft_free_str(line);
}
