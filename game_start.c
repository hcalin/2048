#include "helper.h"

void	game_start()
{
	int	moved;
	int	key;
	int 	size = 4;
	int	indices = 1;
	int	***map;

	colors_init();
	clear();
	map = alloc_matrix(size);
	map = init_map(map, size); 
	print_start(map, size);
	while (1)
	{
		moved = 0;
		key = getch();
		if (key == 119)
		{
			map = calc_up(map, size, &moved);
			if (ismapclear(map, size) && moved)
				map = add_rand(map, size);	
		}
		if (key == 27)
		{
			free(map);
			clear();
			printw("Thank you for playing! Press any key to exit...");
			break;
		}
		if (key == 115)
		{	
			map = calc_down(map, size, &moved);
			if (ismapclear(map, size) && moved)
				add_rand(map, size);
		}
	  	if (key == 97)
		{
			map = calc_left(map, size, &moved);
			if (ismapclear(map, size) && moved)
				map = add_rand(map, size);
		}
		if (key == 100)
		{
			map = calc_right(map, size, &moved);
			if (ismapclear(map, size) && moved)
				map = add_rand(map, size);
		}
	//	clear_board(map, size);
		clear();	
		print_map(map, size);
		check_win(map, size);
		if (!ismapclear(map, size))
			check_lose(map, size);
	}
}

void	colors_init()
{
	start_color();
	init_pair(50, COLOR_WHITE, COLOR_RED);
	init_pair(12, COLOR_BLUE, COLOR_YELLOW);
	init_pair(11, COLOR_WHITE, COLOR_YELLOW);
	init_pair(10, COLOR_YELLOW, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_YELLOW);
	init_pair(8, COLOR_BLUE, COLOR_YELLOW);
	init_pair(7, COLOR_WHITE, COLOR_RED);
	init_pair(6, COLOR_RED, COLOR_BLUE);
	init_pair(5, COLOR_YELLOW, COLOR_BLUE);
	init_pair(4, COLOR_GREEN, COLOR_WHITE);
	init_pair(3, COLOR_BLUE, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
}

void	print_start(int ***map, int size)
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
				if (value)
					attron(COLOR_PAIR(value));
				else
					attron(COLOR_PAIR(1));				
				if (i == ystart + (row) * 4 + 2 
				&&  j == xstart + (col) * 8 + 4)
				{
					if (value == 0)
						mvprintw(i, j, " ");
					else
						mvprintw(i, j, "%d", value);	
					//j = j + 1;
				}
				else
					mvprintw(i,j," ");
				if (value)				
					attroff(COLOR_PAIR(value));
				else
					attroff(COLOR_PAIR(1));
				}
		}
	}
	refresh();
}

int 	***alloc_matrix(int size)
{
	int		***map;
	int		i;
	int		j;

	i = -1;
	map = (int***)malloc(sizeof(int**) * 6);
	while (++i < size)
	{
		map[i] = (int**)malloc(sizeof(int*) * size + 1); 
		j = -1;
		while (++j < size)
			map[i][j] = (int*)malloc(sizeof(int*) * size + 2);
	}
	return (map);
}

int		***init_map(int ***map, int size)
{
	int i;
	int	j;

	srand (time(NULL));
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			do
			{
				map[0][i][j] = rand() % 4;
			}while (map[0][i][j] % 2 != 0);
		}
	}
	return (map);
}

