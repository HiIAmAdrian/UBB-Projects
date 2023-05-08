//
// Created by astan on 4/3/2023.
//

#include "Repo.h"

Repo::Repo()=default;
const VectorDinamic<Elemtype>& Repo::getList() const noexcept{
    return this->list;
}

void Repo::addToRepo(const Elemtype& e) {
    list.add(e);
}

void Repo::deleteFromRepo(int nrInmatriculare) {
    Iterator<Masina> it = this->list.begin();
    while (it.valid() && it.element().getNrInmatriculare() != nrInmatriculare)
        it.next();

    if (!it.valid()){
        throw RepoException("Elementul nu se afla in lista!");
    }
    list.stergeElement(it);
}

Elemtype Repo::searchElement(int nrInmatriculare) {
    Iterator<Masina> it = this->list.begin();
    if (!it.valid()){
        throw RepoException("Elementul nu se afla in lista!");
    }
    else {
        while (it.valid() && it.element().getNrInmatriculare() != nrInmatriculare)
            it.next();

        if (!it.valid()) {
            throw RepoException("Elementul nu se afla in lista!");
        }
        return it.element();
    }
}

bool Repo::exist(const Elemtype& elem) {
    Iterator<Masina> it = this->list.begin();
    if (!it.valid()){
        return false;
    }
    else {
        while (it.valid() && it.element().getNrInmatriculare() != elem.getNrInmatriculare())
            it.next();

        if (!it.valid()) {
            return false;
        }
        return true;
    }
}

ostream & operator<<(ostream & out, const RepoException& ex){
    for (const auto& m : ex.getMessage())
        out << m;
    return out;
}