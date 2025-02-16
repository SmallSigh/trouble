#ifndef PLAYER_H
# define PLAYER_H


typedef struct s_player
{
    char *name;
    int strength;
    int magic;
    int turn;
    int health;
}       t_player;

typedef struct s_orc
{
    char *name;
    int strength;
    // int magic;
    int health;
}       t_orc;

t_player    *player_init(void);
t_orc       *orc_init(void);
void        wizard_txt_one(t_player *player);
void        first_encounter_txt();
void        first_encounter(t_player *player);
void        second_encounter(t_player *player);
void        display_stats(t_player *player);
void        autobattle(t_player *player, t_orc *enemy);
int         my_random(int min, int max);
const char  *random_word();

#endif

// typedef struct s_wizard
// {
//     char *name;
//     int strength;
//     int magic;
//     int health;
// }       t_wizard;
