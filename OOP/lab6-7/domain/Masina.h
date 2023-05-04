//
// Created by astan on 4/3/2023.
//

#ifndef LAB6_7_MASINA_H
#define LAB6_7_MASINA_H
#include <string>
#include <iostream>
#include <utility>

class Masina {
private:
    int nrInmatriculare{};
    std::string producator;
    std::string model;
    std::string tip;
public:
    Masina();
    Masina(int nrInmatriculare, std::string producator, std::string model, std::string tip);
    Masina(const Masina& a);
    friend std::ostream& operator <<(std::ostream& os, const Masina& m);

    friend std::istream& operator >>(std::istream& is, Masina& m);
    [[nodiscard]] int getNrInmatriculare() const;
    [[nodiscard]] std::string getProducator() const;
    [[nodiscard]] std::string getModel() const;
    [[nodiscard]] std::string getTip() const;
    void setNrInmatriculare(int nrNou);
    void setProducator(std::string producatorNou);
    void setModel(std::string modelNou);
    void setTip(std::string tipNou);

};


#endif //LAB6_7_MASINA_H
