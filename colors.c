#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	hex_to_hex(char first, char second)
{
	static char	*base_hex_max = "0123456789ABCDEF";
	static char	*base_hex_min = "0123456789abcdef";
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (base_hex_max[i] != first && base_hex_min[i] != first)
		i++;
	while (base_hex_max[j] != second && base_hex_min[j] != second)
		j++;
	return (16 * i + j);
}

unsigned int	getting_color(char *str)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	if (ft_strlen(str) == 10)
	{
		t = hex_to_hex(str[2], str[3]);
		r = hex_to_hex(str[4], str[5]);
		g = hex_to_hex(str[6], str[7]);
		b = hex_to_hex(str[8], str[9]);
	}
	else
	{
		r = hex_to_hex(str[2], str[3]);
		g = hex_to_hex(str[4], str[5]);
		b = hex_to_hex(str[6], str[7]);
	}
	return ((unsigned int)create_trgb(t, r, g, b));
}
