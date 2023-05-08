//
// Created by astan on 4/3/2023.
//
#include "teste.h"
#include "../service/Service.h"
#include <cstring>

void test_add(){
    Repo repo = Repo();
    Service service = Service(repo);

    service.addToList(1, "Toyota", "lolo", "th");
    service.addToList(2, "Mercedes", "lodlo", "tdh");
    service.addToList(3, "Toyota", "lolo", "th");

    try {
        service.addToList(2, "Mercedes", "lodlo", "tdh");
        assert(false);
    }catch(RepoException& ex){
        assert(true);
    }
    assert(service.getList().get(0).getNrInmatriculare() == 1);
    assert(service.getList().get(1).getModel() == "lodlo");
    assert(service.getList().get(1).getProducator() == "Mercedes");
    assert(service.getList().get(1).getTip() == "tdh");
    assert(service.getList().size() == 3);
}

void test_validation(){
    Repo repo = Repo();
    Service service = Service(repo);

    try{
        service.searchElement(0);
        assert(false);
    } catch(RepoException& ex){
        assert(true);
    }

    try{
        service.addToList(-2, "Toyota", "lolo", "th");
        assert(false);
    }catch(ValidationException& ex){
        assert(true);
    }
    try{
        service.addToList(1, "", "lolo", "th");
        assert(false);
    }catch(ValidationException& ex){
        assert(true);
    }
    try{
        service.addToList(1, "Toyota", "", "th");
        assert(false);
    }catch(ValidationException& ex){
        assert(true);
    }
    try{
        service.addToList(1, "Toyota", "lolo", "");
        assert(false);
    }catch(ValidationException& ex){
        assert(true);
    }
    assert(service.getList().size() == 0);
}

void test_filter(){
    Repo repo = Repo();
    Service service = Service(repo);

    service.addToList(1, "Toyota", "lolo", "th");
    service.addToList(2, "Mercedes", "lodlo", "tdh");
    service.addToList(3, "Toyota", "lolo", "th");

    VectorDinamic<Masina> v = service.filterProducator("Toyota");
    assert(v.size() == 2);
    assert(v.get(0).getProducator() == "Toyota");
    assert(v.get(1).getProducator() == "Toyota");

    VectorDinamic<Masina> v2 = service.filterTip("tdh");
    assert(v2.size() == 1);
    assert(v2.get(0).getTip() == "tdh");

    VectorDinamic<Masina> v3 = service.filterTip("abc");
    assert(v3.size() == 0);
}

void test_delete(){
    Repo repo = Repo();
    Service service = Service(repo);
    service.addToList(1, "Toyota", "lolo", "th");
    service.addToList(2, "Mercedes", "lodlo", "tdh");
    service.deleteElement(2);
    try{
        service.deleteElement(2);
        assert(false);
    }
    catch(RepoException& ex){
        assert(true);
    }

    assert(service.getList().size() == 1);

}

void test_domain(){
    Masina m;
    Masina masina = Masina(1, "Toyota", "lolo", "th");
    masina.setNrInmatriculare(2);
    masina.setModel("abc");
    masina.setProducator("abc");
    masina.setTip("abc");
    assert(masina.getTip() == "abc");
    assert(masina.getProducator() == "abc");
    assert(masina.getNrInmatriculare() == 2);
    assert(masina.getModel() == "abc");

    Masina masina2 = masina;
    assert(masina2.getTip() == "abc");
    assert(masina2.getProducator() == "abc");
    assert(masina2.getNrInmatriculare() == 2);
    assert(masina2.getModel() == "abc");
}

void test_modify(){
    Repo repo = Repo();
    Service service = Service(repo);
    service.addToList(1, "Toyota", "lolo", "th");
    service.addToList(2, "Mercedes", "lodlo", "tdh");

    service.modifyElement(2, "abc", "abc", "abc");
    assert(service.getList().get(1).getProducator() == "abc");
    try{
        service.modifyElement(3, "a", "a", "a");
        assert(false);
    }
    catch(RepoException& ex){
        assert(true);
    }
}

void test_search(){
    Repo repo = Repo();
    Service service = Service(repo);
    service.addToList(1, "Toyota", "lolo", "th");
    service.addToList(2, "Mercedes", "lodlo", "tdh");
    Masina m = service.searchElement(2);
    try{
        service.searchElement(5);
        assert(false);
    }
    catch(RepoException& ex){
        assert(true);
    }
    assert(m.getTip() == "tdh");
}

void test_sort(){
    Repo repo = Repo();
    Service service = Service(repo);
    service.addToList(2, "Mercedes", "lodlo", "tdh");
    service.addToList(1, "Toyota", "lolo", "th");
    service.addToList(3, "Audi", "lodlo", "tdh");
    service.addToList(4, "Toyota", "aodlo", "z");

    vector<Elemtype> v = service.sortNrInmatriculare();
    assert(v[0].getNrInmatriculare() == 1);
    assert(v[1].getNrInmatriculare() == 2);
    assert(v[2].getNrInmatriculare() == 3);

    vector<Elemtype> g = service.sortProducatorModel();
    assert(g[0].getProducator() == "Audi");
    assert(g[1].getProducator() == "Mercedes");
    assert(g[2].getProducator() == "Toyota");
    assert(g[2].getModel() == "aodlo");


    vector<Elemtype> h = service.sortTip();
    assert(h[0].getTip() == "tdh");
    assert(h[1].getTip() == "tdh");
    assert(h[2].getTip() == "th");
}

void test_all(){
    test_domain();
    test_add();
    test_validation();
    test_modify();
    test_filter();
    test_sort();
    test_delete();
    test_search();
}