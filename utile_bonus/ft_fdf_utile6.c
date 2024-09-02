#include "../fdf.h"

void	ft_init_algo(t_algo *algo)
{
	algo->dx = 0;
	algo->dy = 0;
	algo->sx = 0;
	algo->sy = 0;
	algo->err = 0;
	algo->e2 = 0;
	algo->x1 = 0;
	algo->x2 = 0;
	algo->y1 = 0;
	algo->y2 = 0;
	algo->temp_column = 0.00f;
	algo->temp_line = 0.00f;
}
