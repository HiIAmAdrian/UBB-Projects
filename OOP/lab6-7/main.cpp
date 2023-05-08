#include "teste/teste.h"
#include "service/Service.h"
#include "ui/Ui.h"

int main() {
    test_all();
    Repo repo = Repo();
    Service service = Service(repo);
    Ui ui = Ui(service);
    ui.runUi();

    return 0;
}
