//
// Created by astan on 3/16/2023.
//
#include "service.h"
#include <string.h>

/*
 * Creates the service object and returns it.
 */
Service createService(){
    Service service;
    service.repo = createRepo();
    return service;
}
/*
 * Frees the memory from service
 */
void destroyService(Service* service){
    destroyRepo(service->repo);
}
/*
 * Receives raw material name, manufacturer, and quantity, creates and adds the material into repo
 * and returns 0 if everything was successful. Returns 1 if material is invalid.
 */
int addRawMaterialService(Service* service, char* name, char* manufacturer, int quantity){
    Entity e = createRawMaterial(name, manufacturer, quantity);
    if (validate_material(e)){
        destroyRawMaterial(e);
        return 1;
    }
    addEntity(service->repo, e);

    return 0;
}

/*
 * Deletes the material with the name provided. Returns 0 if material exists,
 * 1 if otherwise.
 */
int deleteMaterialService(Service* service, char* name){
    if (service->repo->dimension == 0){
        return 1;
    }
    for(int i = 0;i < service->repo->dimension;i++){
        if (strcmp(getName(service->repo->elements[i]), name) == 0){
            delete_material(service->repo, i);
            return 0;
        }
    }
    return 1;
}
/*
 * Modifies a material from repo.
 * Returns 1 if not successful. 0 if successful.
 */
int modifyMaterialService(Service* service, char* name, char* manufacturer, int quantity){
    RawMaterial* r = createRawMaterial(name, manufacturer, quantity);
    if (validate_material(r)){
        destroyRawMaterial(r);
        return 1;
    }
    if (deleteMaterialService(service, name)){
        destroyRawMaterial(r);
        return 1;
    }
    destroyRawMaterial(r);
    return addRawMaterialService(service, name, manufacturer, quantity);
}

/*
 * primeste 2 raw materials si intoarce diferenta dintre numele celor 2
 */
int compareAscendingName(RawMaterial* r1, RawMaterial* r2){
    return strcmp(r1->name, r2->name);
}
/*
 * primeste 2 raw materials si intoarce diferenta cu minus intre numele celor 2
 */
int compareDescendingName(RawMaterial* r1, RawMaterial* r2){
    return -strcmp(r1->name, r2->name);
}
/*
 * primeste 2 raw materials si intoarce diferenta dintre cantitatile celor 2
 */
int compareAscendingQuantity(RawMaterial* r1, RawMaterial* r2){
    return r1->quantity - r2->quantity;
}
/*
 * primeste 2 raw materials si intoarce diferenta dintre cantitatile celor 2
 */
int compareDescendingQuantity(RawMaterial* r1, RawMaterial* r2){
    return r2->quantity - r1->quantity;
}
/*
 * Primeste un repo si o functie de compare ,
 * si aplica functia de comparare pe repo.
 */
void sort(Repo* r, CompareFunction cmpf){
    int i, j;
    for (i = 0; i < r->dimension - 1;i++){
        for(j = i + 1; j < r->dimension;j++){
            RawMaterial* p1 = get(r, i);
            RawMaterial* p2 = get(r, j);
            if (cmpf(p1, p2) > 0){
                set(r, i, p2);
                set(r, j, p1);
            }
        }
    }
}

/*
 * Primeste service si o functie de compare si in functie de functia de comparare,
 *  intoarce un nou repo sortat.
 */
Repo* sortService(Service* service, CompareFunction compare){
    Repo* copyRepo = getCopyRepo(service->repo);
    sort(copyRepo, compare);
    return copyRepo;
}

/*
 * primeste rawmaterial si un caracter l si intoarce 1 daca prima litera a numelui materialului e
 * caracterul l, 0 otherwise.
 */
int filterLetter(RawMaterial* r, char l){
    return r->name[0] == l;
}
/*
 * Primeste un raw material si o cantitate si intoarce 1 daca cantitatea materialului e mai mica
 * decat cantitatea data.
 * 0, otherwise
 */
int filterQuantity(RawMaterial* r, int quantity){
    return r->quantity < quantity;
}

/*
 * Filters the repo and returns the items whose name begin with letter l
 *
 */
Repo* filterLetterService(Service* service, char l){
    Repo* cr = createRepo();
    int dim = 0;
    cr->capacity = service->repo->capacity;
    free(cr->elements);
    cr->elements = malloc(sizeof(RawMaterial*) * service->repo->capacity);
    for (int i = 0;i < service->repo->dimension;i++){
        if (filterLetter(service->repo->elements[i], l)) {
            cr->elements[dim] = copyRawMaterial(service->repo->elements[i]);
            dim++;
        }
    }
    cr->dimension = dim;
    return cr;
}
/*
 * primeste service si quantity si intoarce un nou repo cu raw materials cu cantitatea mai mica decat
 * quantity.
 */
Repo* filterQuantityService(Service* service, int quantity){
    Repo* cr = createRepo();
    int dim = 0;
    cr->capacity = service->repo->capacity;
    free(cr->elements);
    cr->elements = malloc(sizeof(RawMaterial*) * service->repo->capacity);
    for (int i = 0;i < service->repo->dimension;i++){
        if (filterQuantity(service->repo->elements[i], quantity)) {
            cr->elements[dim] = copyRawMaterial(service->repo->elements[i]);
            dim++;
        }
    }
    cr->dimension = dim;
    return cr;
}