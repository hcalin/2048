#include "helper.h"

void	create_menu_window(WINDOW **win)
{
	int ystart;
	int xstart;
	int ymax;
	int xmax;

	getmaxyx(stdscr, ymax, xmax);
	// middle positioning 
	xstart = (xmax - 20) / 2; 
	ystart = (ymax - 10) / 2;

	*win = newwin(10, 20, ystart, xstart);
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);
	box(*win, 0, 0);	
	wbkgd(*win, COLOR_PAIR(1));
	keypad(*win, true);

	// refresh window
	refresh();
	wrefresh(*win);

	// game title
	wmove(*win, 1, 7);
	wattron(*win, COLOR_PAIR(2));
	waddstr(*win, " 2048 ");
	wattroff(*win, COLOR_PAIR(2));	
}

void	eval_choice(WINDOW *win, int choice)
{
	if (choice == 0) // -Start Game-
	{
//		exit(1);
		wclear(win);
		clear();
		refresh();
		game_start();
		getch();	
	}
	if (choice == 1) // -Best Scores- 
	{
		wclear(win);
		clear();
		printw("Working on it ...");
		refresh();
		getch();
	}
	if (choice == 2) // -Quit Game-
	{
		wgetch(win);
		wclear(win);
		clear();
		refresh();
	//	printw("Thank you for playing! ...");
	//	getch();
	}
}

void	create_first_menu(char **choices)
{
	int		choice;
	int		highlight;
	int		i;
	WINDOW 	*win;

	highlight = 0;
	while (1)
	{
		i = -1;
		create_menu_window(&win);
		refresh();
		wrefresh(win);
		while (++i < 3)
		{
			if (i == highlight)
				wattron(win, A_REVERSE | A_UNDERLINE);
			mvwprintw(win, 3 + i, 3, choices[i]);
			wattroff(win, A_REVERSE | A_UNDERLINE);
		}
		choice = wgetch(win);
		switch(choice)
		{
		case KEY_UP:
			highlight--;
			if (highlight == -1)
				highlight = 0;
			break ;
		case KEY_DOWN:
			highlight++;
			if (highlight == 3)
				highlight = 2;
			break ;
		case 10:
			break ;
		}
		if (choice == 10)
		{
			eval_choice(win, highlight);
			free(choices);			
			break ;
		}
	}
}

void	init_first_menu()
{
	char 	**choices;
	int 	i;
	/* Choices in the menu */
	i = 0;
	choices = (char**)malloc(sizeof(char*) * 5);
	while (i++ < 4)
		choices[i] = (char*)malloc(sizeof(char) * 30);
	choices[0] = "- Start Game  -";
	choices[1] = "- Best Scores -";
	choices[2] = "- Quit Game   -";

	/* Create the menu window in the center of the terminal */	
	create_first_menu(choices);
}

int	main(void)
{
	initscr();
	start_color();
	noecho();
	cbreak();
	init_first_menu();
//	getch();
	endwin();
	return (0);
}
