#include "main_header.h"
#include "player.h"


t_player *player_init(void)
{
    t_player *player;

    player = malloc(sizeof(t_player));
    player->health = 10;
    player->strength = 2;
    (*player).magic = 0;
    player->turn = 0;

    printf("Hello there wanderer, what is your name?\n");
    usleep(1500000);
    printf("Uch!\n");
    usleep(130000);
    printf("fuck me im old.\n");
    usleep(1500000);
    printf("Your name:\n");
    player->name = get_next_line(0);
    while (*(player->name) == '\n')
    {
        printf("you havet given a name little twat!\n");
        free(player->name);
        player->name = get_next_line(0);
    }
    player->name[ft_strlen(player->name) - 1] = '\0';
    printf("hello there %s, i hope your doing well.\n", player->name);
    return (player);
}

// int main(void)
// {
//     t_player *player;
    
//     player = player_init();
//     (void)player;
//     return (0);
// }