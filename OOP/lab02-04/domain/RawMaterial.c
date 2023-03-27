//
// Created by astan on 3/15/2023.
//
#include "RawMaterial.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

RawMaterial* createRawMaterial(char* name, char* manufacturer, int quantity){
    RawMaterial* p = malloc(sizeof(RawMaterial));
    p->quantity = quantity;

    int stringLength = strlen(manufacturer) + 1;
    p->manufacturer = malloc(sizeof(char) * stringLength);
    strncpy(p->manufacturer, manufacturer,stringLength);

    stringLength = strlen(name) + 1;
    p->name = malloc(sizeof(char) * stringLength);
    strncpy(p->name, name, stringLength);

    return p;

}



void destroyRawMaterial(RawMaterial* r){
    free(r->name);
    free(r->manufacturer);
    free(r);
}

int getQuantity(RawMaterial* r){
    return r->quantity;
}

char* getName(RawMaterial* r){
    return r->name;
}

char* getManufacturer(RawMaterial* r){
    return r->manufacturer;
}

RawMaterial* copyRawMaterial(RawMaterial* r){
    RawMaterial* cR = malloc(sizeof(RawMaterial));
    int stringLength = strlen(r->name) + 1;
    cR->name = malloc(sizeof(char) * stringLength);
    strncpy(cR->name, r->name, stringLength);

    stringLength = strlen(r->manufacturer) + 1;
    cR->manufacturer = malloc(sizeof(char) * stringLength);
    strncpy(cR->manufacturer, r->manufacturer, (size_t)stringLength);

    cR->quantity = r->quantity;

    return cR;
}