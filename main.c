#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char		*line = NULL;
	int			fd1;

	(void)argc;
	(void)argv;
	fd1 = open("genese.txt", O_RDONLY);
	while (get_next_line(fd1, &line) == 1)
	{
		printf("Ligne --->%s\n", line);
		free(line);
	}
	close(fd1);
	//while (1);
	return (0);
}
/*
__attribute__((destructor))void destructeur()
{
	printf("destructor\n");
	while(1);
}
*/

/*

Ligne --->Section 5.  General Information About Project Gutenberg-tm electronic
Ligne --->works.
Ligne --->
Ligne --->Professor Michael S. Hart is the originator of the Project Gutenberg-tm
Ligne --->concept of a library of electronic works that could be freely shared
Ligne --->with anyone.  For thirty years, he produced and distributed Project
Ligne --->Gutenberg-tm eBooks with only a loose network of volunteer support.
Ligne --->
Ligne --->
Ligne --->Project Gutenberg-tm eBooks are often created from several printed
Ligne --->editions, all of which are confirmed as Public Domain in the U.S.
Ligne --->unless a copyright notice is included.  Thus, we do not necessarily
Ligne --->keep eBooks in compliance with any particular paper edition.
Ligne --->
Ligne --->
Ligne --->Most people start at our Web site which has the main PG search facility:
Ligne --->
Ligne --->     http://www.gutenberg.org
Ligne --->
Ligne --->This Web site includes information about Project Gutenberg-tm,
Ligne --->including how to make donations to the Project Gutenberg Literary
Ligne --->Archive Foundation, how to help produce our new eBooks, and how to
Ligne --->subscribe to our email newsletter to hear about new eBooks.

*/
