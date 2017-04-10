/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:16:24 by chrihorc          #+#    #+#             */
/*   Updated: 2017/03/24 22:26:48 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H
# include <string.h>
# include <stdlib.h>
# include <ncurses.h>
# include <signal.h>
# include <time.h>

//			MENU FUNCTIONS		       //
void		init_first_menu(void);
void		create_first_menu(char **choices);
void		eval_choice(WINDOW *win, int choice);
void		create_menu_window(WINDOW **win);

//			IN-GAME FUNCTIONS	       //	
void		game_start();
void		colors_init();
int		send_color(int value);

//			WORKING WITH MATRIX FUNCTIONS  //
void		print_start(int ***map, int size);
void		print_map(int ***map, int size);
int		***alloc_matrix(int size);
int		ismapclear(int	 ***map, int size);
int		rand_number(void);
int		***init_map(int ***map, int size);
int		***add_rand(int ***map, int size);
void		check_lose(int ***map, int size);
void		check_win(int ***map, int size);

//			CALCULUS FUNCTIONS		//
int		***calc_left(int ***map, int size, int *moved);
int		***move_left(int ***map, int i, int size, int *moved);
int		***calc_right(int ***map, int size, int *moved);
int		***move_right(int ***map, int i, int size, int *moved);
int		***calc_up(int ***map, int size, int *moved);
int		***move_up(int ***map, int j, int size, int *moved);
int		***calc_down(int ***map, int size, int *moved);
int		***move_down(int ***map, int j, int size, int *moved);
#endif
