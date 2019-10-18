#include "get_next_line.h"
#include <stdio.h>

/*
int				main(void)
{
	char		*line = NULL;
	int			fd = open("gnl10.txt", O_RDONLY);

	get_next_line(fd, &line);
	free(line);
	close(fd);
	//sleep(15);
	return (0);
}

*/
int		main(int argc, char **argv)
{
	char		*line;
	//int			fd1;

	(void)argc;
	(void)argv;
	//fd1 = open("/dev/random", O_RDONLY);
	while (get_next_line(0, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	//close(fd1);
	return (0);
}
