#pragma once
template <typename ElementT>
class Iterator;

template <typename ElementT>
class VectorDinamic
{
public:
    /*
    Constructor default
    Alocam loc pentru 5 elemente
    */
    VectorDinamic();

    /*
    Constructor de copiere
    */
    VectorDinamic(const VectorDinamic& ot); //rule of 3

    /*
    Eliberam memoria
    */
    ~VectorDinamic();//rule of 3

    void stergeElement(Iterator<ElementT> it);


        /*
        Operator assgnment
        elibereaza ce era in obiectul curent (this)
        aloca spatiu pentru elemente
        copieaza elementele din ot in this
        */
    VectorDinamic& operator=(const VectorDinamic& ot);//rule of 3


    /*
    Move constructor
    Apelat daca construim un nou vector dintr-un r-value (ex temporary, expresie de la return)
    Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
    */
    VectorDinamic(VectorDinamic&& ot); //rule of 5 

    /*
    Move assignment
    Similar cu move constructor
    Folosit la assignment
    */
    VectorDinamic& operator=(VectorDinamic&& ot) noexcept ; //rule of 5 


    void add(const ElementT& el);

    ElementT& get(int poz) const;

    void set(int poz, const ElementT& el);

    [[nodiscard]] int size() const noexcept;

    friend class Iterator<ElementT>;
    //functii care creaza iteratori
    Iterator<ElementT> begin();
    Iterator<ElementT> end();


private:
    int lg;//numar elemente
    int cap;//capacitate
    ElementT* elems;//elemente

    void ensureCapacity();
};

/*
Constructor default
Alocam loc pentru 5 elemente
*/
template<typename ElementT>
VectorDinamic<ElementT>::VectorDinamic() :elems{ new ElementT[5] }, cap{ 5 }, lg{ 0 } {}

/*
Constructor de copiere
Obiectul current (this) acum se creaza
aloca spatiu pentru elemente
copieaza elementele din ot in this
*/
template<typename ElementT>
VectorDinamic<ElementT>::VectorDinamic(const VectorDinamic<ElementT>& ot) {
    elems = new ElementT[ot.cap];
    //copiez elementele
    for (int i = 0; i < ot.lg; i++) {
        elems[i] = ot.elems[i];  //assignment din Pet
    }
    lg = ot.lg;
    cap = ot.cap;
}

template<typename T>
void VectorDinamic<T>::stergeElement(Iterator<T> it){
    int i = it.getCurrent();
    for (; i < lg - 1;i++){
        this->elems[i] = this->elems[i + 1];
    }
    lg--;
}

/*
Operator assgnment
elibereaza ce era in obiectul curent (this)
aloca spatiu pentru elemente
copieaza elementele din ot in this
*/
template<typename ElementT>
VectorDinamic<ElementT>& VectorDinamic<ElementT>::operator=(const VectorDinamic<ElementT>& ot) {
    if (this == &ot) {
        return *this;//s-a facut l=l;
    }
    delete[] elems;
    elems = new ElementT[ot.cap];
    //copiez elementele
    for (int i = 0; i < ot.lg; i++) {
        elems[i] = ot.elems[i];  //assignment din Pet
    }
    lg = ot.lg;
    cap = ot.cap;
    return *this;
}

/*
Eliberam memoria
*/
template<typename ElementT>
VectorDinamic<ElementT>::~VectorDinamic() {
    delete[] elems;
}


/*
Move constructor
Apelat daca construim un nou vector dintr-un r-value (ex temporary)
Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
*/
template<typename ElementT>
VectorDinamic<ElementT>::VectorDinamic(VectorDinamic&& ot){
    // Copy the data pointer from other
    elems = ot.elems;
    lg = ot.lg;
    cap = ot.cap;

    // Release the data pointer from the source object so that  
    // the destructor does not free the memory multiple times.  
    ot.elems = nullptr;
    ot.lg = 0;
    ot.cap = 0;
}

/*
Move assignment
Similar cu move constructor
Folosit la assignment
Elibereaza ce continea obiectul curent (this)
"fura" interiorul lui ot
pregateste ot pentru distrugere
*/
template<typename ElementT>
VectorDinamic<ElementT>& VectorDinamic<ElementT>::operator=(VectorDinamic<ElementT>&& ot) noexcept {
    if (this == &ot) {
        return *this;
    }
    delete[] elems;
    // Copy the data pointer from other
    elems = ot.elems;
    lg = ot.lg;
    cap = ot.cap;

    // Release the data pointer from the source object so that  
    // the destructor does not free the memory multiple times.  
    ot.elems = nullptr;
    ot.lg = 0;
    ot.cap = 0;
    return *this;
}

template<typename ElementT>
void VectorDinamic<ElementT>::add(const ElementT& el) {
    ensureCapacity();//daca e nevoie mai alocam memorie
    elems[lg++] = el;
}

template<typename ElementT>
ElementT& VectorDinamic<ElementT>::get(int poz) const {
    return elems[poz];
}

template<typename ElementT>
void VectorDinamic<ElementT>::set(int poz, const ElementT& el) {
    elems[poz] = el;
}

template<typename ElementT>
int VectorDinamic<ElementT>::size() const noexcept {
    return lg;
}

template<typename ElementT>
void VectorDinamic<ElementT>::ensureCapacity() {
    if (lg < cap) {
        return; //mai avem loc
    }
    cap *= 2;
    ElementT* aux = new ElementT[cap];
    for (int i = 0; i < lg; i++) {
        aux[i] = elems[i];
    }
    delete[] elems;
    elems = aux;
}

template<typename ElementT>
Iterator<ElementT> VectorDinamic<ElementT>::begin()
{
    return Iterator<ElementT>(*this);
}

template<typename ElementT>
Iterator<ElementT> VectorDinamic<ElementT>::end()
{
    return Iterator<ElementT>(*this, lg);
}

template<typename ElementT>
class Iterator {
private:
    const VectorDinamic<ElementT>& v;
    int poz = 0;
public:
    explicit Iterator(const VectorDinamic<ElementT>& v) noexcept;
    Iterator(const VectorDinamic<ElementT>& v, int poz)noexcept;
    [[nodiscard]] bool valid()const;
    ElementT& element() const;
    void next();
    int getCurrent();
    ElementT& operator*();
    Iterator& operator++();
    bool operator==(const Iterator& ot)noexcept;
    bool operator!=(const Iterator& ot)noexcept;
};

template<typename ElementT>
Iterator<ElementT>::Iterator(const VectorDinamic<ElementT>& v) noexcept:v{ v } {}

template<typename ElementT>
Iterator<ElementT>::Iterator(const VectorDinamic<ElementT>& v, int poz)noexcept : v{ v }, poz{ poz } {}

template<typename ElementT>
bool Iterator<ElementT>::valid()const {
    return poz < v.lg;
}

template<typename ElementT>
int Iterator<ElementT>::getCurrent(){
    return poz;
}

template<typename ElementT>
ElementT& Iterator<ElementT>::element() const {
    return v.elems[poz];
}

template<typename ElementT>
void Iterator<ElementT>::next() {
    poz++;
}

template<typename ElementT>
ElementT& Iterator<ElementT>::operator*() {
    return element();
}

template<typename ElementT>
Iterator<ElementT>& Iterator<ElementT>::operator++() {
    next();
    return *this;
}

template<typename ElementT>
bool Iterator<ElementT>::operator==(const Iterator<ElementT>& ot) noexcept {
    return poz == ot.poz;
}

template<typename ElementT>
bool Iterator<ElementT>::operator!=(const Iterator<ElementT>& ot)noexcept {
    return *this != ot;
}

