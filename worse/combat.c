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
    display_stats(&player->stats);
    display_stats(&enemy->stats);


    // flee stats.
    // display_stats 
    // health - strength
    // exit or return
    while (player->stats.health > 0 && enemy->stats.health > 0)
    {
        message = random_word();
        player_damage = my_random((player->stats.strength / 2), (player->stats.strength / 2) + 2);
        enemy_damage = my_random((enemy->stats.strength / 2), (enemy->stats.strength / 2) + 2);
        enemy->stats.health -= player_damage;
        ft_printf("%s hits %s %s!\n\n%i damage!\n", player->stats.name, enemy->stats.name, message, player_damage);
        sleep(1);
        ft_printf("Enemy health = %i\n", enemy->stats.health);
        sleep(1);
        message = random_word();
        player->stats.health -= enemy_damage;
        ft_printf("%s hits %s %s!\n\n%i damage!\n", enemy->stats.name, player->stats.name, message, enemy_damage);
        sleep(1);
        ft_printf("Player health = %i\n", player->stats.health);
        sleep(1);
    }
    if (player->stats.health > 0)
        ft_printf("\ncongrats!\n");
    else
        ft_printf("\ngame over!\n");
    sleep(5);
    exit(1);
}
