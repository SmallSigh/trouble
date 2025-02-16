#include "main_header.h"

int my_random(int min, int max)
{
    int random_num;

    srand(time(NULL));
    random_num = min + rand() % (max - min + 1);
    return(random_num);    
}

void  autobattle(t_player *player, t_orc *enemy)
{
    int player_damage;
    int enemy_damage;
    const char *message;

    enemy_damage = 0;
    player_damage = 0;
    display_stats(player);


    // flee
    // display_stats 
    // health - strength
    // exit or return
    while (player->health > 0 && enemy->health > 0)
    {
        message = random_word();
        player_damage = my_random((player->strength / 2), (player->strength / 2) + 2);
        enemy_damage = my_random((enemy->strength / 2), (enemy->strength / 2) + 2);
        enemy->health -= player_damage;
        ft_printf("%s hits %s %s!\n\n%i damage!\n", player->name, enemy->name, message, player_damage);
        sleep(1);
        message = random_word();
        player->health -= enemy_damage;
        ft_printf("%s hits %s %s!\n\n%i damage!\n", enemy->name, player->name, message, enemy_damage);
        sleep(1);
    }
    if (player->health > 0)
        ft_printf("congrats!");
    else
        ft_printf("game over!");
    while (1)
        pause();
}
