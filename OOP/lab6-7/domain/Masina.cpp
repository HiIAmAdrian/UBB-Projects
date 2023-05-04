//
// Created by astan on 4/3/2023.
//

#include "Masina.h"

using namespace std;

Masina::Masina()=default;
Masina::Masina(int nrInmatriculare, std::string producator, std::string model, std::string tip){
    this->nrInmatriculare = nrInmatriculare;
    this->producator = std::move(producator);
    this->model = std::move(model);
    this->tip = std::move(tip);

}
Masina::Masina(const Masina& a):nrInmatriculare(a.nrInmatriculare),producator(a.producator),model(a.model),tip(a.tip){}
std::ostream& operator <<(std::ostream& os, const Masina& m){
    os<<m.nrInmatriculare<<" "<<m.producator<<" "<<m.model<<" "<<m.tip<<"\n";
    return os;
}

std::istream& operator >>(std::istream& is, Masina& m){
    is>>m.nrInmatriculare>>m.producator>>m.model>>m.tip;
    return is;
}
int Masina::getNrInmatriculare() const{
    return nrInmatriculare;
}
std::string Masina::getProducator() const{
    return producator;
}
std::string Masina::getModel() const{
    return model;
}
std::string Masina::getTip() const{
    return tip;
}
void Masina::setNrInmatriculare(int nrNou){
    nrInmatriculare = nrNou;
}
void Masina::setProducator(std::string producatorNou){
    producator = std::move(producatorNou);
}
void Masina::setModel(std::string modelNou){
    model = std::move(modelNou);
}
void Masina::setTip(std::string tipNou){
    tip = std::move(tipNou);
}
