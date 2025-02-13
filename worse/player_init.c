#include "main_header.h"

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
    ft_printf("I’ve set you up with some basic stats.\nHealth: %d\n Strength: %d\n Magic: %d\n",
        player->health, player->strength, player->magic);
    return player;
}

int main(void)
{
    t_player *player;

    player = player_init();
    first_encounter(player);
    // player = second_encounter();
    free(player->name);
    free(player);
    return 0;
}