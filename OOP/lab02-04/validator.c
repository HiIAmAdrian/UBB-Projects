//
// Created by astan on 3/17/2023.
//

#include "domain/RawMaterial.h"
#include <string.h>
#include "validator.h"

int validate_material(RawMaterial* r){
    if (strlen(getManufacturer(r)) < 1) return 1;
    if (strlen(getName(r)) < 1) return 1;
    if (getQuantity(r) < 0) return 1;
    return 0;
}