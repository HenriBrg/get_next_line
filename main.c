#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char		*line = NULL;
	int			fd1;

	(void)argc;
	(void)argv;
	fd1 = open("/dev/random", O_RDONLY);
	while (get_next_line(fd1, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd1);
	while (1);
	return (0);
}
