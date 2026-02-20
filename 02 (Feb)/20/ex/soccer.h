#ifndef SOCCER_H
#define SOCCER_H

#include <stdbool.h>

//TODO 1: DEFINE DATE, STAT AND PLAYER STRUCTS HERE

// Stat struct
typedef struct Stat_ {
  int num_of_goals;
  int num_of_assists;
  float pass_accuracy;
  int min_played;
  int num_of_shots;
  float shot_accuracy;
} Stat;

// Date struct
typedef struct Date_ {
  int day;
  int month;
  int year;
} Date;

// Player struct
typedef struct Player_ {
  int age;
  int jersey_num;
  bool goalkeeper;
  Date *date;
  Stat *stat;
} Player;

void create_player (Player *p, bool goalie);
void create_team (Player team[], int size);
void print_team (Player team[], int size);

#endif
