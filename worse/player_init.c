#include "main_header.h"

void	display_stats(t_basic_stats *stats)
{
	if (!stats)
		exit (EXIT_FAILURE);
	
	// system("clear");
	ft_printf("---------------------------------------------------\n");
	ft_printf("Health:\t\t%i\tName:\t\t%s\n", stats->health, stats->name);
	ft_printf("Strength:\t%i\tMagic:\t\t%i\n", stats->strength, stats->magic);
	ft_printf("---------------------------------------------------\n");
}


t_orc *orc_init()
{
	t_orc *orc = malloc(sizeof(t_orc));

	if (!orc)
		return (NULL);
	orc->stats.name = ft_strdup("Samuel the orc");
	orc->stats.strength = my_random(3, 8);
	orc->stats.health = my_random(3, 8);
	orc->stats.magic = my_random(1, 2);
	return(orc);
}

void second_encounter(t_player *player)
{
	t_orc *orc;

	orc = orc_init();
	autobattle(player, orc);
	// text_two();
}

t_player *player_init(void)
{
	t_player *player;
	t_basic_stats *stats;

	stats = malloc(sizeof(t_basic_stats));
	if (!stats)
		exit(EXIT_FAILURE);
	player = malloc(sizeof(t_player));
	if (!player)
	{
		free(stats);
		ft_printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	// player->stats = stats;
	player->stats.health = 10;
	player->stats.strength = 2;
	player->stats.magic = 0;
	wizard_txt_one(player);
	display_stats(&player->stats);
	// ft_printf("I’ve set you up with some basic stats.\nHealth: %d\n Strength: %d\n Magic: %d\n",
	//     player->health, player->strength, player->magic);
	return player;
}

int main(void)
{
	t_player *player;

	main_screen();
	system("clear");
	player = player_init();
	first_encounter(player);
	second_encounter(player);
	free(player->stats.name);
	free(player);
	return 0;
}
