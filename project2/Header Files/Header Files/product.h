#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
#include <iostream>

class DomainException
{
    std::string mesaj;

public:
    DomainException(std::string msg) : mesaj{msg} {};
    std::string getMsg() { return mesaj; }
};

class Produs
{

private:
    int id;
    std::string nume;
    std::string tip;
    double pret;

public:
    std::string getNume();

    std::string getTip();

    int getId();

    double getPret();

    //constructor
    Produs(int id, std::string nume, std::string tip, double pret) : id{id}, nume{nume}, tip{tip}, pret{pret} {}
    //copy constructor
    Produs(const Produs& other) : id{ other.id }, nume{ other.nume }, tip{ other.tip }, pret{ other.pret } {}
    //move constructor
    Produs(const Produs&& other) : id{ other.id }, nume{ other.nume }, tip{ other.tip }, pret{ other.pret } {}
    //copy assigment operator
    Produs& operator=(const Produs& other);
    //move assigment operator
    Produs& operator=(Produs&& other);
    //destructor
    ~Produs() {}

    void validare()
    {
        std::string error = "";
        if (this->getId() < 0)
            error += "Invalid id!\n";
        if (this->getNume() == "")
            error += "Invalid name!\n";
        if (this->getTip() == "")
            error += "Invalid type!\n";
        if (this->getPret() < 1.0)
            error += "Invalid price!\n";
        if (error != "")
            throw DomainException(error);
    }
};

#endif