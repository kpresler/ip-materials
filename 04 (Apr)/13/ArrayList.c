#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "ArrayList.h"

int al_add(ArrayList* this, void* item) {
    if (this->numItems == this->capacity) {
        this->resize(this);
    }

    this->items[this->numItems] = item;

    this->numItems++;

    return 0;

}

void* al_removeI(ArrayList* this, int idx){

    if (idx < 0 || idx >= this->size(this)) {
        return NULL;
    }

    void* oldItem = this->items[idx];

    for (int i = idx; i < this->size(this); i++) {
        this->items[i] = this->items[i + 1];
    }

    this->items[this->numItems] = NULL;
    this->numItems--;

    return oldItem;
}

void* al_remove(ArrayList* this, void* item) {
    return this->removeI(this, this->index(this, item));
}

int al_addI(ArrayList* this, int idx, void* item) {

    if (idx < 0 || idx > this->size(this)) {
        return -1;
    }

    if (this->numItems == this->capacity) {
        this->resize(this);
    }

    for (int i = this->size(this); i > idx; i--) {
        this->set(this, i, this->get(this, i - 1));
    }
    this->set(this, idx, item);
    this->numItems++;

    return 0;

}


int al_set(ArrayList* this, int idx, void* item) {
    if (idx < 0 || idx > this->size(this)) {
        return -1;
    }
    this->items[idx] = item;
    return 0;
}


int al_size(ArrayList* this) {
    return this->numItems;
}

void* al_get(ArrayList* this, int idx) {
    void* item = this->items[idx];
    return item;
}

void al_destroy(ArrayList* this) {
    free(this->items);
    free(this);
}

void al_resize(ArrayList* this) {

    this -> capacity *= 2;

    void * ptr = realloc(this->items, this->capacity * sizeof(void*));
		
    assert(ptr);
	
	this->items = ptr;

}

int al_index(ArrayList* this, void* item) {

    for (int i = 0; i < this->numItems; i++) {
        if (this->items[i] == item) {
            return i;
        }
    }
    return -1;

}

bool al_contains(ArrayList* this, void* item) {
    return this->index(this, item) >= 0;
}

ArrayList* newArrayList() {

    ArrayList* list = malloc(sizeof(ArrayList));


    list->capacity = 10;
    list->numItems = 0;
    list->items = malloc(10 * sizeof(void *));
    
    
    list->add = al_add;
    list->destroy = al_destroy;
    list->resize = al_resize;
    list->size = al_size;
    list->get = al_get;
    list->set = al_set;
    list->addI = al_addI;
    list->contains = al_contains;
    list->removeI = al_removeI;
    list->remove = al_remove;
    list->index = al_index;


    return list;

}