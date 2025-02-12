#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>

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

int	is_str_str(const char *str, const char *strstr)
{
	while (*str && *strstr)
	{
		if (*str != *strstr)
			return (*str - *strstr);
		str++;
		strstr++;
	}
	return (0);
}

int	main(void)
{
	char	*str;
	int	running;

	running = 1;
	system("clear");
	while (running)
	{
		printf("please type \"s\" to shut down.\n");
		str = get_next_line(0);
		system("clear");
		printf("You typed: %s\n", str);
		if ((is_str_str(str, "s") == 0))
		{
			wizard();
			break ;	
		}
		printf("hoi");
		free(str);
	}
	return (0);
}
