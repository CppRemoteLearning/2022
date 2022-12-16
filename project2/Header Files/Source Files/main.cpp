#include "repo.h"
#include "ui.h"
#include "service.h"
#include "xml.h"

int main(int argc, char *argv[])
{

    

    repo r{"list.txt"};
    Service serv{r};
    Consola ui{serv};
    ui.Start();
}