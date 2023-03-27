//
// Created by astan on 3/16/2023.
//

#ifndef LAB02_04_SERVICE_H
#define LAB02_04_SERVICE_H

#include "../repo/repo.h"
#include "../validator.h"
#include <stdlib.h>
#include <string.h>

typedef struct{
    Repo* repo;
} Service;

Service createService();

typedef int (*CompareFunction)(RawMaterial *,RawMaterial*);

void destroyService(Service*);

int addRawMaterialService(Service*, char*, char*, int);

int deleteMaterialService(Service*, char*);

int modifyMaterialService(Service*, char*, char*, int);

int compareAscendingName(RawMaterial*, RawMaterial*);

int compareDescendingName(RawMaterial*, RawMaterial*);

int compareDescendingQuantity(RawMaterial*, RawMaterial*);

int compareAscendingQuantity(RawMaterial*, RawMaterial*);

Repo* sortService(Service*, CompareFunction);

Repo* filterQuantityService(Service*, int);

Repo* filterLetterService(Service*, char);

#endif //LAB02_04_SERVICE_H
