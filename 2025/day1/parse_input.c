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
/*    File: parse_input.c                                                    */
/*     Input parse utils                                                     */
/*                                                                           */
/* Free Palestine, fuck fascists                                             */
/*                               Made with love and coffee by SimardCodeTard */
/* ************************************************************************* */

#include "day1_header.h"

t_rotation	*parse_input(const char	*path, uint16_t nlines)
{
	t_rotation	*rotations;
	char		*line;
	int			fd;
	size_t		i;

	fd = open(path, 0, 0);
	if (fd == -1)
	{
		fprintf(stderr, "Failed to read file %s", path);
		return (NULL);
	}
	rotations = malloc((nlines + 1) * sizeof(t_rotation));
	i = 0;
	line = "";
	while (line && i < nlines)
	{
		line = get_next_line(fd);
		if (line[0] == 'R')
			rotations[i].direction = RIGHT;
		else
			rotations[i].direction = LEFT;
		rotations[i].value = atoi(line + 1);
		i++;
		free(line);
	}
	return (rotations);
}
