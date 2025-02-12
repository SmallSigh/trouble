//#include "small_game.h"

void	print_ascii(char *printable)
{
	int	fd;
	char *str;
	
	fd = open(printable, 0);
	
	if (fd == -1)
	{
		printf("No file found: %s.\n", printable);
		return ;
	}
	str = get_next_line(fd);
	while(str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
