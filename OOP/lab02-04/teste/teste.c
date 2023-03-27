//
// Created by astan on 3/16/2023.
//
#import "../service/service.h"
#import <assert.h>

void test_add_service(){
    Service service = createService();
    assert(addRawMaterialService(&service, "Material1", "Johnson", 32) == 0);
    assert(addRawMaterialService(&service, "Material2", "Johnson", 32) == 0);
    assert(addRawMaterialService(&service, "Material3", "Johnson", 32) == 0);
    assert(addRawMaterialService(&service, "", "", -2) == 1);
    assert(addRawMaterialService(&service, "", "fd", -2) == 1);
    assert(addRawMaterialService(&service, "ff", "ff", -2) == 1);
    destroyService(&service);
}
void test_modify_service(){
    Service service = createService();
    addRawMaterialService(&service, "Material1", "Johnson", 32);
    addRawMaterialService(&service, "Material2", "Johnson", 32);
    addRawMaterialService(&service, "Material3", "Johnson", 32);
    assert(modifyMaterialService(&service, "Material1", "JJ", 23) == 0);
    assert(modifyMaterialService(&service, "ss", "ss", -2) == 1);
    assert(modifyMaterialService(&service, "Mat", "4", 43) == 1);
    destroyService(&service);
}
void test_delete_service(){
    Service service = createService();
    addRawMaterialService(&service, "Material1", "Johnson", 32);
    addRawMaterialService(&service, "Material2", "Johnson", 32);
    addRawMaterialService(&service, "Material3", "Johnson", 32);
    assert(deleteMaterialService(&service, "Material2") == 0);
    assert(deleteMaterialService(&service, "hehe") == 1);
    assert(deleteMaterialService(&service, "Material1") == 0);
    assert(deleteMaterialService(&service, "Material3") == 0);
    assert(deleteMaterialService(&service, "mat") == 1);
    destroyService(&service);
}

void test_sorts(){
    Service service = createService();
    addRawMaterialService(&service, "B", "Johnson", 2);
    addRawMaterialService(&service, "C", "Johnson", 1);
    addRawMaterialService(&service, "A", "Johnson", 3);
    Repo* r = sortService(&service, compareAscendingQuantity);
    RawMaterial* mat = get(r,0);
    assert(mat->quantity == 1);
    destroyRepo(r);
    r = sortService(&service, (CompareFunction) compareDescendingQuantity);
    mat = get(r,0);
    assert(mat->quantity == 3);
    destroyRepo(r);
    r = sortService(&service, (CompareFunction) compareAscendingName);
    mat = get(r,0);
    assert(strcmp(mat->name, "A") == 0);
    destroyRepo(r);
    r = sortService(&service, (CompareFunction) compareDescendingName);
    mat = get(r,0);
    assert(strcmp(mat->name, "C") == 0);
    destroyRepo(r);
    destroyService(&service);
}

void test_filters_service(){
    Service service = createService();
    addRawMaterialService(&service, "B", "Johnson", 2);
    addRawMaterialService(&service, "C", "Johnson", 1);
    addRawMaterialService(&service, "A", "Johnson", 35);
    addRawMaterialService(&service, "ARF LLL", "Johnson", 244);
    addRawMaterialService(&service, "ABC", "Johnson", 19);
    addRawMaterialService(&service, "F", "Johnson", 3);
    Repo *r = filterLetterService(&service, 'A');
    assert(r->dimension == 3);
    destroyRepo(r);
    r = filterQuantityService(&service, 30);
    assert(r->dimension == 4);
    destroyRepo(r);
    destroyService(&service);
}

void run_teste(){
    test_add_service();
    test_modify_service();
    test_delete_service();
    test_filters_service();
    test_sorts();
}