#include <stdio.h>
#include <ncurses.h>
#include <string.h>

int main()
{
	initscr();
	start_color();
	noecho();
	cbreak();
	init_pair(1, COLOR_BLACK, COLOR_YELLOW);
	init_pair(2, COLOR_BLACK, COLOR_BLUE);
	int row,col;
	getmaxyx(stdscr, row, col);
	int xstart,ystart;
	int size = 4;
	ystart = (row - 4 * (size)) / 2; // Pozitionare pe mijlocul axei y
	xstart = (col - 6 * (size + 1)) / 2; // Pozitionare pe mijlocul axei x
	int tiles = -1,i = ystart,j = xstart;
	int number2 = 64;
	int l = 0,p;
	while (++tiles < (size * size ))
	{
		i = ystart + (tiles / size) * 4;
		while (++i < ystart + (tiles / size) * 4 + 4)
		{
			j = xstart + (tiles % size) * 8; 
			while (++j < xstart + (tiles % size * 8) + 7 )
			{
				attron(COLOR_PAIR(1));
				if (i == ystart + (tiles / size) * 4 + 2 
				&&  j == xstart + (tiles % size) * 8 + 3)
				{
					mvprintw(i, j, "%d", number2);	
					j = j + 1;
				}
				else
				mvprintw(i,j," ");
				attroff(COLOR_PAIR(1));
				}
		}
	}
	getch();	
	endwin();
	return (0);
}
