/* ************************************************************************** */
/*                                                                            */
#include "../tools/tools.h"
 
 void	print_ascii(char *pathname)
 {
 	int	fd;
 	char *str;

 	fd = open(pathname, 0);

 	if (fd == -1)
 	{
 		printf("No file found: %s.\n", pathname);
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

// // int	main_screen(void)
// // {
// // 	system("clear");
// // 	printf("Ahum!\n");
// // 	sleep(1);
// // 	printf("Please, yes! Here");
// // 	usleep(750);
// // 	printf(" the image of the couch please.\n");
// // 	sleep(2);
// // 	system("clear");
// // 	print_ascii("../ascii/couch");
// // 	sleep(2);
// // 	printf("\t\tThe meaning of life. A question to ask.");
// // 	sleep(1);
// // 	printf(" Indeed!\n");
// // 	usleep(750);
// // 	printf("\tYou are asking it as you sit on this coudh.\n");
// // 	sleep(2);
// // 	printf("\tYou are asking it as you sit on this couch having done two tabs of acid...\n");
// // 	sleep(3);
// // 	printf("\tYou are asking it as you sit on this couch having done two tabs of acid and you still don't feel anything so you decided to smoke a joint\n");
// // 	sleep(2);

// // 	printf("\n\n\tcause what's the point anyway?\n");
// // 	int pid = fork();

// // 	if (pid == 0)
// // 	{
// // 		sleep(2);
// // 		printf("\n\t\t\tpress enter to question life\n");
// // 		get_next_line(0);
// // 		exit(0);
// // 	}
// // 	waitpid(pid, NULL, 0);
// // 	system("clear");
// // 	print_ascii("../ascii/AND_THEN_THE_ACID_HIT");

// // 	return (0);
// // }
