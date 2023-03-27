//
// Created by astan on 3/15/2023.
//

#ifndef LAB02_04_RAWMATERIAL_H
#define LAB02_04_RAWMATERIAL_H
typedef struct {
    char* name;
    char* manufacturer;
    int quantity;
} RawMaterial;
#endif //LAB02_04_RAWMATERIAL_H

/*
 * Primeste carateristicile unei materii prime, creeaza
 * entitatea RawMaterial si intoarce un pointer catre ea
 */
RawMaterial* createRawMaterial(char*, char*, int);

/*
 * Primeste o entitate RawMaterial si o elimina din memorie
 */
void destroyRawMaterial(RawMaterial*);

RawMaterial* copyRawMaterial(RawMaterial*);

char* getName(RawMaterial*);
char* getManufacturer(RawMaterial*);
int getQuantity(RawMaterial*);