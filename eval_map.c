#include "helper.h"

void		check_lose(int ***map, int size)
{
	int i;
	int j;
	int ok;

	i = -1;
	j = -1;
	ok = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (j < size - 1)
				if (map[0][i][j] == map[0][i][j + 1])
					ok = 1;
			if (i < size - 1)
				if (map[0][i][j] == map[0][i + 1][j])	
					ok = 1;
		}
	}
	if (!ok)
	{
		int row,col,x,y;
		attron(COLOR_PAIR(50));
		getmaxyx(stdscr, row,col);
		y = (row - 4 * (size)) / 2 + 17;
		x = (col - 6 * (size + 1)) / 2 + 10;
		mvprintw(y, x, " YOU LOSE !");
		attroff(COLOR_PAIR(50));
		mvprintw(y + 2, x - 4, "Press Esc key to exit");
	}
}

void		check_win(int ***map, int size)
{
	int i;
	int j;
	int ok;

	i = -1;
	j = -1;
	ok = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (map[0][i][j] >= 2048)	
			{	
				ok = 1;
				break;
			}
		}
	}
	if (ok)
	{
		int row,col,x,y;
		attron(COLOR_PAIR(8));
		getmaxyx(stdscr, row,col);
		y = (row - 4 * (size)) / 2 + 17;
		x = (col - 6 * (size + 1)) / 2 + 10;
		mvprintw(y, x, " YOU WIN !");
		attroff(COLOR_PAIR(50));
		mvprintw(y + 2, x - 4, "Press Esc key to exit");
	}
}

int		***add_rand(int ***map, int size)
{
	int	i;
	int	j;

	srand(time(NULL));
	i = rand() % (size);
	j = rand() % (size);
	while (map[0][i][j] != 0)
	{
		i = rand() % (size);
		j = rand() % (size);
	}
	map[0][i][j] = rand_number();
	return (map);
}

int		rand_number(void)
{
	int	num;

	srand(time(NULL));
	num = rand();
	if (num % 3 == 0 || num % 3 == 1)
		return (2);
	else
		return (4);
}

int		ismapclear(int	 ***map, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (map[0][i][j] == 0)
				return (1);
	}
	return (0);
}

int		digit_n(int x)
{
	int y = x;
	int n = 0;

	while (y)
	{
		y /= 10;
		n ++;
	}
	return (n);
}

int	send_color(int	x)
{
	if (x == 0)
		return (1);
	if (x == 2)
		return (2);
	if (x == 4)
		return (3);
	if (x == 8)
		return (4);
	if (x == 16)
		return (5);
	if (x == 32)
		return (6);
	if (x == 64)
		return (7);
	if (x == 128)
		return (8);
	if (x == 256)
		return (9);
	if (x == 512)
		return (10);
	if (x == 1024)
		return (11);
	if (x == 2048)
		return (12);
	else
		return (13);
}

void		print_map(int ***map, int size)
{
	int 	row,col;
	int 	xstart,ystart;
	int	value;

	getmaxyx(stdscr, row, col);
	ystart = (row - 4 * (size)) / 2; // Pozitionare pe mijlocul axei y
	xstart = (col - 6 * (size + 1)) / 2; // Pozitionare pe mijlocul axei x
	int tiles = -1, i = ystart, j = xstart;
	while (++tiles < (size * size ))
	{
		row =  (tiles / size);
		i = ystart + row * 4;
		while (++i < ystart + row * 4 + 4)
		{
			col = (tiles % size);
			j = xstart + col * 8; 
			while (++j < xstart + (col * 8) + 7)
			{
				value = map[0][row][col];
				attron(COLOR_PAIR(send_color(value)));			
				if (i == ystart + (row) * 4 + 2 
				&&  j == xstart + (col) * 8 + 4)
				{
					if (value == 0)
					{
						mvprintw(i, j, " ");
					}					
					else
					{
						if (digit_n(value) < 3)
						{
							mvprintw(i, j - digit_n(value) + 1, "%d", value);
						}					
						else if (digit_n(value) == 3)
						{
							mvprintw(i, j - 1, "%d", value);
							j ++;
						}
						else if (digit_n(value) == 4)
						{
							mvprintw(i, j - 2, "%d", value);
							j ++;
						}
						else if (digit_n(value) == 5)
						{
							mvprintw(i, j - 2, "%d", value);
							j += 3;
						}
						else if (digit_n(value) == 6)
						{
							mvprintw(i, j - 3, "%d", value);
							j += 4;
						}
					}
				}
				else
					mvprintw(i,j," ");			
				attroff(COLOR_PAIR(send_color(value)));
				}
		}
	}
	refresh();
}
