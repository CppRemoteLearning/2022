#ifndef _UI_H_
#define _UI_H_


#include "service.h"

class Consola
{
private:
    Service &service;

    void pretty_print(Produs *el);

public:
    Consola(Service &service) noexcept : service{service} {}

    void AfiseazaMeniu();

    void Start();
};

#endif