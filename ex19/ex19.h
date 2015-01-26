#ifndef _ex19_h
#define _ex19_h

#include "object.h"

/* Monster {{{ */

struct Monster {
    Object proto;
    int hit_points;
};

typedef struct Monster Monster;

int Monster_attack(void *self, int damage); // Y
int Monster_init(void *self); // Y

/* }}} Monster */

/* Room {{{ */

struct Room {
    Object proto;

    Monster *bad_guy;

    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
};

typedef struct Room Room;

void *Room_move(void *self, Direction direction); // Y
int Room_attack(void *self, int damage); // Y
int Room_init(void *self);

/* }}} Room */

/* Map {{{ */

struct Map {
    Object proto;
    Room *start;
    Room *location;
};

typedef struct Map Map;

void *Map_move(void *self, Direction direction); // Y
int Map_attack(void *self, int damage); // Y
int Map_init(void *self); // Y

/* }}} Map */

#endif
