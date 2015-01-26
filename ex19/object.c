/* Headers {{{1 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>

/* 1}}} */

/* Object destroy {{{ */

void Object_destroy(void *self)
{
    assert(self != NULL);

    Object *obj = self;

    if (obj) {
        if (obj->description) free(obj->description);
        free(obj);
    }
}

/* }}} Object destroy */

/* Object describe {{{ */

void Object_describe(void *self)
{
    assert(self != NULL);

    Object *obj = self;
    assert(printf("%s.\n", obj->description) >= 0);
}

/* }}} Object describe */

/* Object init {{{ */

int Object_init(void *self)
{
    assert(self != NULL);

    // do nothing really
    // just placeholder
    // NOT IMPLEMENTED.
    return 1;
}

/* }}} Object init */

/* Object move {{{ */

void *Object_move(void *self, Direction direction)
{
    assert(self != NULL);

    // DEFAULT MOVE
    assert(printf("You can't go that direction.\n") >= 0);
    return NULL;
}

/* }}} Object move */

/* Object attack {{{ */

int Object_attack(void *self, int damage)
{
    assert(self != NULL);

    // DEFAULT ATTACK
    assert(printf("You can't attack that.\n") >= 0);
    return 0;
}

/* }}} Object attack */

/* Object new {{{ */

void *Object_new(size_t size, Object proto, char *description)
{
    assert(description != NULL);

    // setup the default functions in case they aren't set
    if (!proto.init) proto.init = Object_init;
    if (!proto.describe) proto.describe = Object_describe;
    if (!proto.destroy) proto.destroy = Object_destroy;
    if (!proto.attack) proto.attack = Object_attack;
    if (!proto.move) proto.move = Object_move;

    // this seems weird, but we can make a struct of one size,
    // then point a different pointer at it to "cast" it
    Object *el = calloc(1, size);
    *el = proto;

    // copy the description over
    el->description = strdup(description);

    // initialize it with whatever init we were given
    if (!el->init(el)) {
        // looks like it didn't initialize properly
        el->destroy(el);
        return NULL;
    } else {
        // all done, we made an object of any type
        return el;
    }
}

/* }}} Object new */
