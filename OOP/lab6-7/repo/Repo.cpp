//
// Created by astan on 4/3/2023.
//

#include "Repo.h"

Repo::Repo()=default;
const VectorDinamic<Elemtype>& Repo::getList() const noexcept{
    return this->list;
}
void Repo::addToRepo(const Elemtype& e) {
    list.adaugaSfarsit(e);
}

void Repo::deleteFromRepo(int nrInmatriculare) {
    Iterator<Masina> it = this->list.iterator(0);
    it.prim();
    while (it.valid() && it.element().getNrInmatriculare() != nrInmatriculare)
        it.urmator();

    if (!it.valid()){
        throw RepoException("Elementul nu se afla in lista!");
    }
    list.stergeElement(it);
}

Elemtype Repo::searchElement(int nrInmatriculare) {
    Iterator<Masina> it = this->list.iterator(0);
    it.prim();
    if (!it.valid()){
        throw RepoException("Elementul nu se afla in lista!");
    }
    else {
        while (it.valid() && it.element().getNrInmatriculare() != nrInmatriculare)
            it.urmator();

        if (!it.valid()) {
            throw RepoException("Elementul nu se afla in lista!");
        }
        return it.element();
    }
}

bool Repo::exist(Elemtype elem) {
    Iterator<Masina> it = this->list.iterator(0);
    it.prim();
    if (!it.valid()){
        return false;
    }
    else {
        while (it.valid() && it.element().getNrInmatriculare() != elem.getNrInmatriculare())
            it.urmator();

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