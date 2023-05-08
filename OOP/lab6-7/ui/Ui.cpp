//
// Created by astan on 4/3/2023.
//

#include "Ui.h"

using namespace std;

Ui::Ui(const Service& service) : service(service) {}

void Ui::addObject() {
    int nrInmatriculare;
    string producator;
    string model;
    string tip;

    cout<<"Numar inmatriculare: ";
    cin>>nrInmatriculare;
    cout<<"Producator: ";
    cin>>producator;
    cout<<"Model: ";
    cin>>model;
    cout<<"Tip: ";
    cin>>tip;
    service.addToList(nrInmatriculare, producator, model, tip);
    cout<<"Elementul a fost adaugat cu succes!"<<endl<<endl;
}

void Ui::printList(){
    const VectorDinamic<Elemtype>& v = service.getList();

    for (int i = 0; i < v.size(); i++){
        cout<<v.get(i)<<endl;
    }

}

void Ui::deleteObject(){
    int nrInmatriculare;
    cout<<"Introdu numarul de inmatriculare: ";
    cin>>nrInmatriculare;

    service.deleteElement(nrInmatriculare);
    cout<<"Elementul a fost sters cu succes!"<<endl<<endl;
}

/*void Ui::filterProducator() {
    string producator;
    cout<<"Introdu producatorul: ";
    cin>>producator;

    const VectorDinamic<Elemtype>& v = service.filterProducator(producator);
    for (int i = 0; i < v.size(); i++){
        cout<<v.get(i)<<endl;
    }
}

void Ui::filterTip() {
    string tip;
    cout<<"Introdu tipul: ";
    cin>>tip;

    const VectorDinamic<Elemtype>& v = service.filterTip(tip);
    for (int i = 0; i < v.size(); i++){
        cout<<v.get(i)<<endl;
    }
}*/

void Ui::modifyObject(){
    int nrInmatriculare;
    string producator;
    string model;
    string tip;

    cout<<"Numar inmatriculare: ";
    cin>>nrInmatriculare;
    cout<<"Producator nou: ";
    cin>>producator;
    cout<<"Model nou: ";
    cin>>model;
    cout<<"Tip nou: ";
    cin>>tip;

    service.modifyElement(nrInmatriculare, producator, model, tip);
    cout<<"Elementul a fost modificat cu succes!"<<endl<<endl;

}

void Ui::searchObject() {
    int nrInmatriculare;

    cout<<"Numar inmatriculare: ";
    cin>>nrInmatriculare;
    cout<<service.searchElement(nrInmatriculare)<<endl<<endl;
}

void Ui::sortNrInmatriculare() {
    vector<Elemtype> v = service.sortNrInmatriculare();
    for (const auto & i : v){
        cout<<i<<endl;
    }
}

void Ui::sortTip() {
    vector<Elemtype>v = service.sortTip();
    for (const auto & i : v){
        cout<<i<<endl;
    }
}

void Ui::sortProducatorModel() {
    vector<Elemtype> v = service.sortProducatorModel();
    for (const auto & i : v){
        cout<<i<<endl;
    }
}

int Ui::runUi() {
    int input;
    bool runCondition = true;
    while(runCondition){
        cout<<"MENIU:"<<endl<<"1. Printeaza lista de masini"<<endl<<"2. Adauga o masina la lista"<<endl<<"3. Sterge o masina din lista"<<endl<<"4. Modifica o masina"<<endl<<"5. Cauta masina"<<endl<<"6. Filtrare producator"<<endl<<"7. Filtrare Tip"<<endl<<"8. Sortare nrInmatriculare\n"<<"9. Sortare tip\n"<<"10. Sortare producator+model\n"<<"0. Exit"<<endl<<endl;
        cin>>input;
        try {
            switch (input) {
                case 1:
                    printList();
                    break;
                case 2:
                    addObject();
                    break;
                case 3:
                    deleteObject();
                    break;
                case 4:
                    modifyObject();
                    break;
                case 5:
                    searchObject();
                    break;
                /*case 6:
                    filterProducator();
                    break;
                case 7:
                    filterTip();
                    break;*/
                case 8:
                    sortNrInmatriculare();
                    break;
                case 9:
                    sortTip();
                    break;
                case 10:
                    sortProducatorModel();
                    break;
                case 0:
                    runCondition = false;
                    break;
                default:
                    cout << "Comanda inexistenta!" << endl << endl;
                    break;
            }
        }
        catch (ValidationException& ve) {
            cout << ve << '\n';
        }
        catch (RepoException& re){
            cerr<<re<<endl;
        }
    }
    return 0;
}