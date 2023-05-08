//
// Created by astan on 4/3/2023.
//

#ifndef LAB6_7_UI_H
#define LAB6_7_UI_H
#include "../service/Service.h"
#include <iostream>

class Ui {
private:
    Service service;
    void addObject();
    void printList();
    void deleteObject();
    void modifyObject();
    void searchObject();
    void filterProducator();
    void filterTip();
    void sortNrInmatriculare();
    void sortTip();
    void sortProducatorModel();
public:
    explicit Ui(const Service &service);
    int runUi();
};


#endif //LAB6_7_UI_H
