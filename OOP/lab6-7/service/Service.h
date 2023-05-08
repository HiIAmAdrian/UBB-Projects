//
// Created by astan on 4/3/2023.
//

#ifndef LAB6_7_SERVICE_H
#define LAB6_7_SERVICE_H
#include "../repo/Repo.h"
#include "../domain/Validator.h"

using namespace std;

class Service {
private:
    Repo& repo;
public:
    explicit Service(Repo &repo1);
    [[nodiscard]] VectorDinamic<Elemtype> getList() const;

    [[nodiscard]] VectorDinamic<Elemtype> filterProducator(const string&) const;
    [[nodiscard]] VectorDinamic<Elemtype> filterTip(const string&) const;
    [[nodiscard]] vector<Elemtype> sortNrInmatriculare() const;
    [[nodiscard]] vector<Elemtype> sortTip() const;
    [[nodiscard]] vector<Elemtype> sortProducatorModel() const;
    void addToList(int nrInmatriculare, string producator, string model, string tip);
    void deleteElement(int nrInmatriculare);
    void modifyElement(int nrInmatriculare, string producator, string model, string tip);
    Elemtype searchElement(int nrInmatriculare);

};


#endif //LAB6_7_SERVICE_H
