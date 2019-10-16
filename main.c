#include "get_next_line.h"
#include <stdio.h>

void	ft_putendl_fd(char *s, int fd)
{
	int i;

	i = -1;
	while (s[++i])
		write(fd, s + i, 1);
	write(fd, "\n", 1);
}

int		main(int argc, char **argv)
{
	char		*line;
	int			fd1;

	(void)argc;
	fd1 = open(argv[1], O_RDONLY);
	while (get_next_line(fd1, &line) == 1)
	{
		ft_putendl_fd(line, 1);
		free(line);
	}
	close(fd1);
	return (0);
}
