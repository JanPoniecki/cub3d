#include "cub3d.h"

int	interpolation(int height, int txt_height, int point)
{
	float	sum;

	sum = txt_height * (float)((float)point / (float)height);
	sum -= 0.01;
	sum = floor(sum) + 1;
	if (sum > txt_height)
		sum --;
	return (sum);
}
