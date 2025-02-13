#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "main_header.h"


int	get_length(char *str)
{
	int	length;
	
	length = 0;
	while (*str)
	{
		str++;
		length++;
	}
	return (length);
}
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

// int	main(void)
// {
// 	char	*str;
// 	int	running;

// 	running = 1;
// 	system("clear");
// 	while (running)
// 	{
// 		printf("please type a character you would like to see.\n");
// 		str = get_next_line(0); 
// 		system("clear");
// 		printf("You typed: %s", str);
// 		str[get_length(str) - 1] = '\0';
// 		print_ascii(str);
// 		free(str);
// 	}
// 	return (0);
// }
