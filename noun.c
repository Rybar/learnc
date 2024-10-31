#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "object.h"

static bool objectHasTag(OBJECT *obj, const char *noun) {
    return noun != NULL && *noun != '\0' && strcmp(noun, obj->tag) == 0;
}

static OBJECT *getObject(const char *noun) {
    OBJECT *obj, *res = NULL;
    for (obj = objs; obj < endOfObjs; obj++) {
        if (objectHasTag(obj, noun)) {
            res = obj;
        }
    }
    return res;
}

OBJECT *getVisible(const char *intention, const char *noun){
    OBJECT *obj = getObject(noun);
    if (obj == NULL){
        printf("I don't understand %s.\n", intention);
    }
    else if (!(obj == player || // player is always visible
               obj == player->location || // player's current location
               obj->location == player || // objects in player's inventory
               obj->location == player->location || // objects in player's current location
               obj->location == NULL || // any location the player can go to --refined later
               obj->location->location == player || //objects inside another object in player's inventory
               obj->location->location == player->location)) //objects inside another object in player's current location
    {
        printf("I don't see any %s here.\n", noun);
        obj = NULL;
    }
    return obj;
}
