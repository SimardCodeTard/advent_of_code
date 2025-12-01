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
/*    File: solve_day1.c                                                     */
/*     Day 1 problem solve                                                   */
/*                                                                           */
/* Free Palestine, fuck fascists                                             */
/*                               Made with love and coffee by SimardCodeTard */
/* ************************************************************************* */

#include "day1_header.h"

uint16_t	solve_day1(t_rotation *rotations, uint16_t nlines)
{
	int32_t		dial_value;
	uint16_t	result;
	size_t		i;

	result = 0;
	dial_value = 50;
	i = 0;
	while (i < nlines)
	{
		if (rotations[i].direction == RIGHT)
			dial_value += rotations[i].value;
		else
			dial_value -= rotations[i].value;
		dial_value %= 100;
		if (dial_value == 0)
			result++;
		i++;
	}
	return (result);
}
