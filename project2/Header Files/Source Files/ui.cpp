#include "service.h"
#include "repo.h"
#include "ui.h"
#include <iostream>

using std::cin;
using std::cout;

void Consola::AfiseazaMeniu() {
	cout << "1. Add product\n";
	cout << "2. Show all products\n";
	cout << "0. Exit\n";
}

void Consola::pretty_print(Produs* el) {
	cout << el->getId() << " | Name: " << el->getNume() << " | Type : " << el->getTip() << " | Price : " << el->getPret() << "\n";
}

void Consola::Start() {
	AfiseazaMeniu();
	const Service* pointer_service = &service;
	std::string path_to_file = "D:\lenovo1\D\Facultate\AN1 SEMESTRU2\OOP\ngarro2\ngarro2\list.xml";

	while (true) {
		int alegere;
		cout << ">>>";
		cin >> alegere;

		if (alegere == 1) {

			int id;
			std::string nume;
			std::string tip;
			double pret;

			cout << "id: ";
			cin >> id;
			cout << "name: ";
			cin >> nume;
			cout << "type:  ";
			cin >> tip;
			cout << "price: ";
			cin >> pret;

			try
			{
				service.add(id, nume, tip, pret, path_to_file);
			}
			catch (RepoException& e)
			{
				cout << e.getMsg();
				break;
			}
			catch (DomainException& d)
			{
				cout << d.getMsg();
				break;
			}
			cout << "Product added!\n";
		}

		else if (alegere == 2) {
			std::vector<Produs> lista = service.getAll(path_to_file);
			if (lista.size() == 0)
				cout << "Empty list!\n";

			for (Produs product : lista) {
				pretty_print(&product);
			}
		}

		else if (alegere == 0) {
			return;
		}

		else {
			cout << "Invalid command!\n";
			break;
		}


	}
}