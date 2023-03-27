//
// Created by astan on 3/10/2023.
//

#ifndef LAB02_04_REPO_H
#define LAB02_04_REPO_H
#include "../domain/RawMaterial.h"
typedef void* Entity;

/*
 * functie pentru dealocarea unui element
 */
typedef void(*DestroyF)(Entity);

typedef Entity(*CopyF)(Entity);
typedef struct {
    Entity* elements;
    int dimension;
    int capacity;
    DestroyF dstf;
    CopyF cpyf;
} Repo;

/*
 * adauga o entitate in repo
 */
int addEntity(Repo*, Entity);

void ensureCapacity(Repo*);

Repo* createRepo();

void destroyRepo(Repo*);

Entity get(Repo*, int);

void delete_material(Repo*, int);

Repo* getCopyRepo(Repo*);

Entity set(Repo*, int, Entity);

#endif //LAB02_04_REPO_H
