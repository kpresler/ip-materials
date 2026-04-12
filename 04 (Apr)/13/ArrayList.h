#include <stdbool.h>

#pragma once

typedef struct AL {
    int numItems;
    int capacity;
    void** items;

    int (*add)(struct AL* this, void* item);
    int (*addI)(struct AL* this, int idx, void* item);
    void (*destroy)(struct AL* this);
    void (*resize)(struct AL* this);
    int (*size)(struct AL* this);
    void* (*get)(struct AL* this, int idx);
    int (*set)(struct AL* this, int idx, void* item);
    void* (*removeI)(struct AL* this, int idx);
    void* (*remove)(struct AL* this, void* item);
    int (*index)(struct AL* this, void* item);
    bool (*contains)(struct AL* this, void* item);
} ArrayList;

ArrayList* newArrayList();