/* ************************************************************************* */
/*                                                                           */
/*      /$$$$$$  /$$$$$$ /$$      /$$  /$$$$$$  /$$$$$$$  /$$$$$$$           */
/*     /$$__  $$|_  $$_/| $$$    /$$$ /$$__  $$| $$__  $$| $$__  $$          */
/*    | $$  \__/  | $$  | $$$$  /$$$$| $$  \ $$| $$  \ $$| $$  \ $$          */
/*    |  $$$$$$   | $$  | $$ $$/$$ $$| $$$$$$$$| $$$$$$$/| $$  | $$          */
/*     \____  $$  | $$  | $$  $$$| $$| $$__  $$| $$__  $$| $$  | $$          */
/*     /$$  \ $$  | $$  | $$\  $ | $$| $$  | $$| $$  \ $$| $$  | $$          */
/*    |  $$$$$$/ /$$$$$$| $$ \/  | $$| $$  | $$| $$  | $$| $$$$$$$/          */
/*     \______/ |______/|__/     |__/|__/  |__/|__/  |__/|_______/           */
/*                                                                           */
/*    File: day1_header.c                                                    */
/*     Main header for day 1                                                 */
/*                                                                           */
/* Free Palestine, fuck fascists                                             */
/*                               Made with love and coffee by SimardCodeTard */
/* ************************************************************************* */

#ifndef DAY1_HEADER_H
# define DAY1_HEADER_H

# include <stdint.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef enum e_direction
{
	LEFT,
	RIGHT
}	t_direction;

typedef struct s_rotation
{
	t_direction	direction;
	int16_t		value;
}	t_rotation;

/* parse_input.c */
t_rotation		*parse_input(const char * path, uint16_t nlines);

/* solve_day1.c */
uint16_t		solve_day1(t_rotation *rotations, uint16_t nlines);

#endif
