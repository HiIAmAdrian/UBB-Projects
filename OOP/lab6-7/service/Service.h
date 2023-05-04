//
// Created by astan on 4/3/2023.
//

#ifndef LAB6_7_SERVICE_H
#define LAB6_7_SERVICE_H
#include "../repo/Repo.h"
#include "../domain/Validator.h"

class Service {
private:
    Repo& repo;
public:
    explicit Service(Repo &repo1);
    [[nodiscard]] const VectorDinamic<Elemtype>& getList() const;
    void addToList(int nrInmatriculare, std::string producator, std::string model, std::string tip);
    void deleteElement(int nrInmatriculare);
    void modifyElement(int nrInmatriculare, std::string producator, std::string model, std::string tip);
    Elemtype searchElement(int nrInmatriculare);

};


#endif //LAB6_7_SERVICE_H
