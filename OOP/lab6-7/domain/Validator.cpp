//
// Created by astan on 5/3/2023.
//

#include "Validator.h"

void Validator::validation(const Masina& m) {
    std::vector<std::string> message;
    if (m.getNrInmatriculare() < 0)
        message.emplace_back("Numarul de inmatriculare trebuie sa fie pozitiv!");
    if (m.getProducator().empty())
        message.emplace_back("Producatorul nu poate fi vid!");
    if (m.getModel().empty())
        message.emplace_back("Modelul nu poate fi vid!");
    if (m.getTip().empty())
        message.emplace_back("Tipul nu poate fi vid!");
    if (!message.empty())
        throw ValidationException(message);
}

std::ostream& operator<<(std::ostream& os, const ValidationException& ex) {
    for (const auto& msg : ex.getMessage())
        os << msg << "\n";
    return os;
}

