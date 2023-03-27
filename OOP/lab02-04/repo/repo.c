//
// Created by astan on 3/15/2023.
//
#include "repo.h"
#include <stdlib.h>

/*
 * Receives an entity and adds it to the repo.
 * Returns 0 if everything was successful.
 */
int addEntity(Repo* r, Entity e){
    if (r->dimension < r->capacity){
        r->elements[r->dimension] = e;
        r->dimension++;
    }
    else {
        ensureCapacity(r);
        addEntity(r, e);
    }
    return 0;
}
/*
 * Function that is used to resize the repo when capacity limit is reached
 */
void ensureCapacity(Repo* r){
    Entity* nElems = malloc(sizeof(Entity) * (r->capacity * 2));
    for(int i = 0; i < r->dimension;i++){
        nElems[i] = r->elements[i];
    }
    free(r->elements);
    r->elements = nElems;
    r->capacity = r->capacity * 2;
}
/*
 * function that creates the repo
 */
Repo* createRepo(){
    Repo* r = malloc(sizeof(Repo));
    r->dimension = 0;
    r->capacity = 2;
    r->elements = malloc(sizeof(Entity) * r->capacity);
    return r;
}

void destroyRepo(Repo* r){
    for (int i = 0; i < r->dimension;i++){
        destroyRawMaterial(r->elements[i]);
    }
    free(r->elements);
    free(r);
}


/*
 * Receives the order of the material in the repo and deletes it.
 *
 */
void delete_material(Repo* r, int i){
    destroyRawMaterial(r->elements[i]);
    for (; i < r->dimension - 1; i++){
        r->elements[i] = r->elements[i + 1];
    }
    r->elements[i] = NULL;
    r->dimension--;
}

Repo* getCopyRepo(Repo* r){
    Repo* cr = createRepo();
    cr->dimension = r->dimension;
    cr->capacity = r->capacity;
    free(cr->elements);
    cr->elements = malloc(sizeof(RawMaterial*) * r->capacity);
    for (int i = 0;i < r->dimension;i++){
        cr->elements[i] = copyRawMaterial(r->elements[i]);
    }
    return cr;
}

/*
 * Return a material care se afla pe pozitia i.
 */
Entity get(Repo* r, int i) {
    return r->elements[i];
}

Entity set(Repo* s, int poz, Entity e) {
    Entity rez = s->elements[poz];
    s->elements[poz] = e;
    return rez;

}




