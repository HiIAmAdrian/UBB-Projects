//tip de data generic (pentru moment este intreg)
#pragma once

#include <cstdlib>

template <typename T>
 class Iterator;
template <typename T> class VectorDinamic {

private:
    //capacitate
    int cp;
    //dimensiune
    int n;
    //elemente
    T *e;
    //pentru redimensionare
    void redim();

    //pentru modificare element aflat pe poz i
    void modificaElement(int, T);

public:
    //pentru ca Iteratorul sa poata accesa reprezentarea vectorului
    friend class Iterator<T>;

    friend class Repo;
    //constructor
    explicit VectorDinamic(int);

    //destructor
    ~VectorDinamic();

    //dimensiunea vectorului (numar de elemente)
    [[nodiscard]] int dim() const;

    //elementul al i-lea (1 <= i <= numar de elemente)
    T element(int) const;

    //adaugare la sfarsit
    void adaugaSfarsit(T);

    //returneaza un iterator pe vector
    Iterator<T> iterator(int);

    //alte operatii specifice

    //constructor copiere, operator atribuire...

    void stergeElement(Iterator<T> it);
};
template <typename T>
class Iterator {

private:

    //iteratorul contine o referinta catre container
    const VectorDinamic<T>& collection;

    //pozitia curenta in iterator
    int index;


public:

    //constructor
    Iterator(const VectorDinamic<T>&, int);

    //operatii pe iterator
    bool operator!= (Iterator const &) const;

    T const & operator* () const;

    Iterator const & operator++();

    void prim();

    void urmator();

    T element() const;

    [[nodiscard]] bool valid() const;

    int getCurent();
};
