//
// Created by astan on 4/3/2023.
//

#include "Service.h"
#include <algorithm>
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

VectorDinamic<Elemtype> Service::getList() const{
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

bool cmpF(const Elemtype& a, const Elemtype& b){
    return a.getNrInmatriculare() < b.getNrInmatriculare();
}

bool cmpFT(const Elemtype& a, const Elemtype& b){
    return a.getTip() < b.getTip();
}

bool cmpFPM(const Elemtype& a, const Elemtype& b){
    if (a.getProducator() > b.getProducator()) {
       return false;
    }
    else if (a.getProducator() == b.getProducator()){
        if (a.getModel() > b.getModel()){
            return false;
        }
    }
    return true;
}

vector<Elemtype> Service::sortNrInmatriculare() const {
    VectorDinamic<Elemtype> v = getList();
    vector<Elemtype> v1;
    for (int i = 0; i < v.size(); i++)
        v1.push_back(v.get(i));
    sort(v1.begin(), v1.end(), cmpF);
    return v1;
}



vector<Elemtype> Service::sortTip() const {
    VectorDinamic<Elemtype> v = getList();
    vector<Elemtype> v1;
    for (int i = 0; i < v.size(); i++)
        v1.push_back(v.get(i));
    sort(v1.begin(), v1.end(), cmpFT);
    return v1;
}

VectorDinamic<Elemtype> Service::filterProducator(const string &producator) const {
    VectorDinamic<Elemtype> v = getList();
    VectorDinamic<Elemtype> v1;
    for (int i = 0; i < v.size(); i++)
        if (v.get(i).getProducator() == producator)
            v1.add(v.get(i));
    return v1;
}

VectorDinamic<Elemtype> Service::filterTip(const string &tip) const {
    VectorDinamic<Elemtype> v = getList();
    VectorDinamic<Elemtype> v1;
    for (int i = 0; i < v.size(); i++)
        if (v.get(i).getTip() == tip)
            v1.add(v.get(i));
    return v1;
}



vector<Elemtype> Service::sortProducatorModel() const {
    VectorDinamic<Elemtype> v = getList();
    vector<Elemtype> v1;
    for (int i = 0; i < v.size(); i++)
        v1.push_back(v.get(i));
    sort(v1.begin(), v1.end(), cmpFPM);
    return v1;
}

