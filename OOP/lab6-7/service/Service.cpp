//
// Created by astan on 4/3/2023.
//

#include "Service.h"

#include <utility>
#include <iostream>
Service::Service(Repo &repo1) : repo(repo1) {}

void Service::addToList(int nrInmatriculare, std::string producator, std::string model, std::string tip) {
    Elemtype e = Masina(nrInmatriculare, std::move(producator), std::move(model), std::move(tip));
    Validator::validation(e);
    if (repo.exist(e)){
        throw RepoException("Elementul deja exista!");
    }
    else{
        repo.addToRepo(e);
    }
}

const VectorDinamic<Elemtype>& Service::getList() const{
    return repo.getList();
}

void Service::deleteElement(int nrInmatriculare) {
    repo.deleteFromRepo(nrInmatriculare);
}

void Service::modifyElement(int nrInmatriculare, std::string producator, std::string model, std::string tip) {
    repo.deleteFromRepo(nrInmatriculare);
    addToList(nrInmatriculare,std::move(producator),std::move(model),std::move(tip));
}

Elemtype Service::searchElement(int nrInmatriculare) {
    return repo.searchElement(nrInmatriculare);
}