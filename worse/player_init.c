#include "main_header.h"

void display_stats(t_player *player)
{
	system("clear");
	ft_printf("---------------------------------------------------\n");
	ft_printf("Health:\t\t%i\tName:\t\t%s\n", player->health, player->name);
	ft_printf("Strength:\t%i\tMagic:\t\t%i\n", player->strength, player->magic);
	ft_printf("---------------------------------------------------\n");
}


t_orc *orc_init()
{
	t_orc *orc = malloc(sizeof(t_orc));

	if (!orc)
		return (NULL);
	orc->name = "Samuel";
	orc->strength = my_random(3, 8);
	orc->health = my_random(3, 8);
	return(orc);
}

void second_encounter(t_player *player)
{
	t_orc *orc;

	display_stats(player);
	orc = orc_init();
	autobattle(player, orc);
	// text_two();
}

t_player *player_init(void)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	if (!player) {
		ft_printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	player->health = 10;
	player->strength = 2;
	player->magic = 0;
	player->turn = 0;
	wizard_txt_one(player);
	display_stats(player);
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
	free(player->name);
	free(player);
	return 0;
}
