#include "main_header.h"

void wizard_txt_one(t_player *player)
{
    char *name;

    ft_printf("You can stay one the couch for this one.\n");
    usleep(1500000);
    ft_printf("Uch!\n");
    usleep(130000);
    ft_printf("Fuck me, I'm old.\n");
    usleep(1500000);
    ft_printf("So were gonna go a trip now, what were you called again?\n");
    usleep(1500000);
    ft_printf("Your name:\n");
    name = get_next_line(0);
    while (name && name[0] == '\n')
    {
        ft_printf("You haven't given a name, little twat!\n");
        free(name);
        name = get_next_line(0);
    }
    name[ft_strlen(name) - 1] = '\0';
    system("clear");
    ft_printf("Hello there %s, I hope you're doing well.\n", name);
    player->stats.name = name;
}

void first_encounter_txt()
{
    ft_printf("Before you lie three altars.\n\bOne with a book that glows feintly...\n");
    usleep(130000);
    ft_printf("One with a spike covered in caked up old blood...\n");
    usleep(130000);
    ft_printf("And one with a crystal ball, with an image of the wizard in yellow swimming trunks...\n");
    usleep(130000);
    ft_printf("\nWhich one do you interact with?\n\n[1] for book\n[2] for spike\n[3] for wizard!\n");
}

void first_encounter(t_player *player)
{
    char *answer_one;
    
    answer_one = NULL;
    first_encounter_txt();
    answer_one = get_next_line(0);
    if (answer_one && answer_one[0] == '1')
    {
        ft_printf("As you touch the book, it stops glowing...\nBut you start glowing a bit!\n");
        ft_printf("\nYou gain 2 magic!\n");
        player->stats.magic += 2;
    }
    else if (answer_one && answer_one[0] == '2')
    {
        ft_printf("You slam you hand on the spike!\nIt pierces through!\n");
        ft_printf("\n-2 health... Dumbass...\n");
        player->stats.health -= 2;
    }
    else if (answer_one && answer_one[0] == '3')
    {
        ft_printf("\nYou rub your hand over the crystal ball... the wizard smiles at you, he is on holiday...\n");
    }
    sleep(3);
    system("clear");
    free(answer_one);
}

