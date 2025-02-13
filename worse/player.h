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

t_player *player_init(void);
void wizard_txt_one(t_player *player);
void first_encounter_txt();
void first_encounter(t_player *player);

#endif

// typedef struct s_wizard
// {
//     char *name;
//     int strength;
//     int magic;
//     int health;
// }       t_wizard;

// typedef struct s_orc
// {
//     char *name;
//     int strength;
//     int magic;
//     int health;
// }       t_orc;