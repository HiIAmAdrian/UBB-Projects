#include "VectorDinamic.h"
#include <iostream>
using namespace std;
template<typename T> void VectorDinamic<T>::redim() {

    //alocam un spatiu de capacitate dubla
    T *eNou = new T[2 * cp];

    //copiem vechile valori in noua zona
    for (int i = 0; i < n; i++)
        eNou[i] = e[i];

    //dublam capacitatea
    cp = 2 * cp;

    //eliberam vechea zona
    delete[] e;

    //vectorul indica spre noua zona
    e = eNou;
}

template<typename T> void VectorDinamic<T>::modificaElement(int i, T newVal) {
    e[i] = newVal;
}

template<typename T> VectorDinamic<T>::VectorDinamic(int cp) {
    //setam capacitatea
    this->cp = cp;

    //alocam spatiu de memorare pentru vector
    e = new T[cp];

    //setam numarul de elemente
    this->n = 0;
}

template<typename T> VectorDinamic<T>::~VectorDinamic() {
    //eliberam zona de memorare alocata vectorului
    delete[] e;
}

template<typename T> int VectorDinamic<T>::dim() const{
    return n;
}

template<typename T> T VectorDinamic<T>::element(int i) const{
    return e[i];
}

template<typename T> void VectorDinamic<T>::adaugaSfarsit(T elem) {
    //daca s-a atins capacitatea maxima, redimensionam
    if (n == cp)
        redim();

    //adaugam la sfarsit
    this->e[n++] = elem;
}

template<typename T> void VectorDinamic<T>::stergeElement(Iterator<T> it){
    int i = it.getCurent();
    for (; i < n - 1;i++){
        this->e[i] = this->e[i + 1];
    }
    n--;
}

template<typename T>
Iterator<T> VectorDinamic<T>::iterator(int index) {
    //returnam un iterator pe vector
    return Iterator<T>(*this, index);
}

template <typename T>
Iterator<T>::Iterator(const VectorDinamic<T>& collection, int index) : index(index), collection(collection) {}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T> & other) const {
    return index != other.index;
}

template <typename T>
T const & Iterator<T>::operator*() const{

    return collection.element(index);
}

template <typename T>
Iterator<T> const & Iterator<T>::operator++(){
    ++index;
    return *this;
}

template <typename T>
inline Iterator<T> begin(VectorDinamic<T> const & collection){
    return Iterator<T>(collection, 0);
}

template <typename T>
inline Iterator<T> end(VectorDinamic<T> const & collection){
    return Iterator<T>(collection, collection.dim());
}

template <typename T>
void Iterator<T>::prim() {
    //seteaza iteratorul pe prima pozitie din vector
    index = 0;
}

template <typename T>
int Iterator<T>::getCurent() {
    return index;
}

template <typename T>
bool Iterator<T>::valid() const{
    //verifica daca iteratorul indica spre un element al vectorului
    return index < collection.dim();
}

template <typename T>
T Iterator<T>::element() const{
    //elementul curent
    return collection.e[index];
}


template <typename T>
void Iterator<T>::urmator() {
    //pentru ambele variante
    index++;
}