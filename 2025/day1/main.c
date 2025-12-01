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
/*    File: main.c                                                           */
/*     Program entry point                                                   */
/*                                                                           */
/* Free Palestine, fuck fascists                                             */
/*                               Made with love and coffee by SimardCodeTard */
/* ************************************************************************* */

#include "day1_header.h"

int	main(int ac, char **av)
{
	t_rotation *rotations;
	uint16_t		result;
	uint16_t	nlines;

	if (ac < 3)
	{
		fprintf(stderr, "Usage : [program] [input file] [lines count]\n");
		return (EXIT_FAILURE);
	}
	nlines = atoi(av[2]);
	rotations = parse_input(av[1], nlines);
	if (!rotations)
		return (EXIT_FAILURE);
	result = solve_day1(rotations, nlines);
	free(rotations);
	printf("Result : %d\n", result);
	return (EXIT_SUCCESS);
}
