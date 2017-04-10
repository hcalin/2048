#include "helper.h"


int	***calc_left(int ***map, int size, int *moved)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		map = move_left(map, i, size, moved);
		j = 0;
		while (j < size - 1)
		{
			if (map[0][i][j] == map[0][i][j + 1] && map[0][i][j] != 0)
			{
				map[0][i][j] = map[0][i][j + 1] * 2;
				map[0][i][j + 1] = 0;
				*moved = 1;
			}
			j++;
		}
		map = move_left(map, i, size, moved);
		i++;
	}
	return (map);
}

int	***move_left(int ***map, int i, int size, int *moved)
{
	int	j;
	int	aux;

	aux = 1;
	while (aux)
	{
		aux = 0;
		j = 0;
		while (j < size - 1)
		{
			if (map[0][i][j] == 0 && map[0][i][j + 1] != 0)
			{
				map[0][i][j] = map[0][i][j + 1];
				map[0][i][j + 1] = 0;
				aux = 1;
				*moved = 1;
			}
			j++;
		}
	}
	return (map);
}

int	***calc_right(int ***map, int size, int *moved)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		map = move_right(map, i, size, moved);
		j = 3;
		while (j > 0)
		{
			if (map[0][i][j] == map[0][i][j - 1] && map[0][i][j] != 0)
			{
				map[0][i][j] = map[0][i][j - 1] * 2;
				map[0][i][j - 1] = 0;
				*moved = 1;
			}
			j--;
		}
		map = move_right(map, i, size, moved);
		i++;
	}
	return (map);
}

int	***move_right(int ***map, int i, int size, int *moved)
{
	int	j;
	int	aux;

	aux = 1;
	while (aux)
	{
		aux = 0;
		j = 3;
		while (j > 0)
		{
			if (map[0][i][j] == 0 && map[0][i][j - 1] != 0)
			{
				map[0][i][j] = map[0][i][j - 1];
				map[0][i][j - 1] = 0;
				aux = 1;
				*moved = 1;
			}
			j--;
		}
	}
	return (map);
}

int	***calc_up(int ***map, int size, int *moved)
{
	int		i;
	int		j;


	j = 0;
	while (j < size)
	{
		map = move_up(map, j, size, moved);
		i = 1;
		while (i < size)
		{
			if (map[0][i - 1][j] == map[0][i][j] && map[0][i][j] != 0)
			{
				map[0][i - 1][j] = map[0][i][j] * 2;
				map[0][i][j] = 0;
				*moved = 1;			
			}
			i++;
		}
		map = move_up(map, j, size, moved);
		j++;
	}
	return (map);
}

int	***move_up(int ***map, int j, int size, int *moved)
{
	int		aux_v;
	int		i;

	aux_v = 1;
	while (aux_v)
	{
		i = 1;
		while (i < size)
		{
			aux_v = 0;
			if (map[0][i - 1][j] == 0 && map[0][i][j] != 0)
			{
				map[0][i - 1][j] = map[0][i][j];
				map[0][i][j] = 0;
				aux_v = 1;				
				*moved = 1;
			}
			i++;
		}
	}
	return (map);
}

int	***calc_down(int ***map, int size, int *moved)
{
	int		i;
	int		j;

	j = 0;
	while (j < size)
	{
		map = move_down(map, j, size, moved);
		i = 2;
		while (i >= 0)
		{
			if (map[0][i + 1][j] == map[0][i][j] && map[0][i][j] != 0)
			{
				map[0][i + 1][j] = map[0][i][j] * 2;
				map[0][i][j] = 0;
				*moved = 1;
			}
			i--;
		}
		map = move_down(map, j, size, moved);
		j++;
	}
	return (map);
}

int	***move_down(int ***map, int j, int size, int *moved)
{
	int		aux_v;
	int		i;

	aux_v = 1;
	while (aux_v)
	{
		i = 2;
		while (i >= 0)
		{
			aux_v = 0;
			if (map[0][i + 1][j] == 0 && map[0][i][j] != 0)
			{
				map[0][i + 1][j] = map[0][i][j];
				map[0][i][j] = 0;
				aux_v = 1;
				*moved = 1;
			}
			i--;
		}
	}
	return (map);
}
