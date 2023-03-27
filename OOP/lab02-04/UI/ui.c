//
// Created by astan on 3/16/2023.
//
#include "../service/service.h"
#include <stdio.h>

void add_material(Service* service){
    int quantity;
    char name[20];
    char manufacturer[20];
    setbuf(stdout, 0);
    printf("Introdu numele:\n");
    scanf("%s", name);
    setbuf(stdout, 0);
    printf("Introdu producatorul:\n");
    scanf("%s", manufacturer);
    setbuf(stdout, 0);
    printf("Introdu cantitatea:\n");
    scanf("%d", &quantity);
    if (addRawMaterialService(service,name, manufacturer, quantity)){
        setbuf(stdout, 0);
        printf("Material invalid!\n");
    }
    else{
        setbuf(stdout, 0);
        printf("Material adaugat cu sucees!\n");
    }
}

void print_list(Service* service){
    for (int i = 0; i < service->repo->dimension;i++){
        RawMaterial* r = get(service->repo, i);
        setbuf(stdout, 0);
        printf("Nume: %s\nProducator:%s\nCantitate:%d\n\n", r->name, r->manufacturer, r->quantity);
    }
}

void deleteMaterial(Service* service){
    char name[20];

    setbuf(stdout, 0);
    printf("Introdu numele materialului: ");
    scanf("%s", name);
    if (deleteMaterialService(service, name)){
        setbuf(stdout, 0);
        printf("Materialul nu exista!\n");
    }
    else{
        setbuf(stdout, 0);
        printf("Material sters cu succes!\n");
    }
}

void modifyMaterial(Service* service){
    int quantity;
    char name[20];
    char manufacturer[20];
    setbuf(stdout, 0);
    printf("Introdu numele materialului:\n");
    scanf("%s", name);
    setbuf(stdout, 0);
    printf("Introdu noul producator:\n");
    scanf("%s", manufacturer);
    setbuf(stdout, 0);
    printf("Introdu noua cantitate:\n");
    scanf("%d", &quantity);
    if (modifyMaterialService(service, name, manufacturer, quantity)){
        setbuf(stdout, 0);
        printf("Operatiune invalida!\n");
    }
    else{
        setbuf(stdout, 0);
        printf("Material modificat cu succes!\n");
    }
}

void sortMaterials(Service* service){
    int option = 0;
    Repo* r = NULL;
    setbuf(stdout, 0);
    printf("OPTIUNI SORTARI:\n1.Sorteaza crescator dupa cantitate.\n2.Sorteaza descrescator dupa cantitate.\n3.Sorteaza crescator dupa nume.\n4.Sorteaza descrescator dupa nume.\n");
    scanf("%d", &option);
    if (option == 1){
        r = sortService(service, (CompareFunction) compareAscendingQuantity);
    } else if (option == 2) {
        r = sortService(service, (CompareFunction) compareDescendingQuantity);
    } else if (option == 3) {
        r = sortService(service, (CompareFunction) compareAscendingName);
    } else if (option == 4){
        r = sortService(service, (CompareFunction) compareDescendingName);
    }
    for (int i = 0; i < r->dimension;i++){
        RawMaterial* m = get(r, i);
        setbuf(stdout, 0);
        printf("Nume: %s\nProducator:%s\nCantitate:%d\n\n", m->name, m->manufacturer, m->quantity);
    }

    destroyRepo(r);
}

void filterMaterials(Service* service){
    int option = 0;
    setbuf(stdout, 0);
    printf("FILTRARI:\n1. Filtreaza nume dupa litera.\n 2. Filtreaza dupa cantitate.\n");
    scanf("%d",&option);
    getchar();
    Repo* r = NULL;
    if (option == 1){
        char l;
        setbuf(stdout, 0);
        printf("Introdu litera: ");
        scanf("%c", &l);
        r = filterLetterService(service, l);
    }
    else if (option == 2){
        int quantity;
        setbuf(stdout, 0);
        printf("Introdu cantitatea: ");
        scanf("%d", &quantity);
        r = filterQuantityService(service, quantity);
    } else {
        setbuf(stdout, 0);
        printf("Optiune invalida!\n");
    }
    for (int i = 0; i < r->dimension;i++){
        RawMaterial* m = get(r, i);

        setbuf(stdout, 0);
        printf("Nume: %s\nProducator:%s\nCantitate:%d\n\n", m->name, m->manufacturer, m->quantity);
    }
    destroyRepo(r);
}

void free_memory(Service* service){
    destroyService(service);
}

void run(){
    Service service = createService();
    setbuf(stdout, 0);
    printf("Bine ati venit!\n");
    while(1){
        int cmd = 0;
        setbuf(stdout, 0);
        printf("1. Adauga materie prima\n2. Afiseaza lista de materii prime\n3. Sterge un material.\n4. Modifica un material\n5. Sorteaza lista de materiale.\n6. Filtreaza\n7. Exit\n");
        scanf("%d", &cmd);
        if (cmd == 1) {
            add_material(&service);
        }
        else if (cmd == 2){
            print_list(&service);
        }
        else if (cmd == 3){
            deleteMaterial(&service);
        }
        else if (cmd == 4) {
            modifyMaterial(&service);
        }
        else if (cmd == 5){
            sortMaterials(&service);
        }
        else if (cmd == 6){
            filterMaterials(&service);
        }
        else if (cmd == 7){
            break;
        }
        else{
            setbuf(stdout, 0);
            printf("Comanda invalida!\n");
        }
    }
    free_memory(&service);
}