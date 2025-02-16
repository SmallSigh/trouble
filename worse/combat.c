#include "main_header.h"

int my_random(int min, int max)
{
    int random_num;

    srand(time(NULL));
    random_num = min + rand() % (max - min + 1);
    return(random_num);    
}


void attack_turn(t_basic_stats *attacker, t_basic_stats *defender)
{
    const char *message;
    int damage;

    message = random_word();
    damage = my_random((attacker->strength / 2), (attacker->strength / 2) + 2);
    defender->health -= damage;
    ft_printf("%s hits %s %s!\n%i damage!\n", attacker->name, defender->name, message, damage);
    sleep(1);
    if (defender->health > 0)
        ft_printf("\n%s's health dropped by %i\n\n", defender->name, defender->health);
    else
    {
        ft_printf("%s health dropped below zero.\n", defender->name);
        ft_printf("%s has been black holed!\n", defender->name);
    }
    sleep(1);
}

void autobattle(t_player *player, t_orc *enemy)
{
    display_stats(&player->stats);
    display_stats(&enemy->stats);

    while (player->stats.health > 0 && enemy->stats.health > 0)
    {
        attack_turn(&player->stats, &enemy->stats);
        if (enemy->stats.health <= 0)
            break;

        attack_turn(&enemy->stats, &player->stats);
    }
    if (player->stats.health > 0)
        ft_printf("\nCongratulations, you won!\n");
    else
        ft_printf("\nGame over!\n");

    sleep(5);
    exit(1);
}
