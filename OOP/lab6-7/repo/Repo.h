//
// Created by astan on 4/3/2023.
//

#ifndef LAB6_7_REPO_H
#define LAB6_7_REPO_H
#include <utility>

#include "../domain/Masina.h"
#include "../domain/VectorDinamic.h"

using namespace std;

typedef Masina Elemtype;
class Repo {
private:
    VectorDinamic<Elemtype> list;
public:
    Repo();
    [[nodiscard]] const VectorDinamic<Elemtype>& getList() const noexcept;
    void addToRepo(const Elemtype& e);
    void deleteFromRepo(int nrInmatriculare);
    Elemtype searchElement(int nrInmatriculare);
    bool exist(const Elemtype& elem);
};

class RepoException: exception {
protected:
    string message;
public:
    explicit RepoException(string msg): message(std::move(msg)){};
    friend ostream& operator<<(ostream& out, const RepoException& ex);
    [[nodiscard]] string getMessage() const {
        return message;
    }
};


ostream& operator<<(ostream& out, const RepoException& ex);
#endif //LAB6_7_REPO_H
