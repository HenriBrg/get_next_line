#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char		*line;
	int			fd1;

	(void)argc;
	printf("%d\n", BUFFER_SIZE);
	fd1 = open(argv[1], O_RDONLY);
	while (get_next_line(fd1, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd1);
	return (0);
}
