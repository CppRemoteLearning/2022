#include "service.h"
void Service::add(int id, std::string a, std::string b, double pret, std::string path_to_file)
{
    Produs test{id, a, b, pret};
    test.validare();
    r.store(test);
}
