//
// Created by astan on 5/3/2023.
//

#ifndef LAB6_7_VALIDATOR_H
#define LAB6_7_VALIDATOR_H
#include "../domain/Masina.h"
#include <utility>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Validator {
public:
    static void validation(const Masina& m);
};

class ValidationException : exception{
private:
    vector<string> message;
public:
    explicit ValidationException(vector<string> message):message{std::move(message)}{}
    friend ostream& operator<<(ostream& os, const ValidationException& ex);
    [[nodiscard]] vector<string> getMessage() const{
        return message;
    };
};

ostream& operator<<(ostream& os, const ValidationException& ex);

#endif //LAB6_7_VALIDATOR_H
