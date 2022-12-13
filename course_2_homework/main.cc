#include "include/manage_store.h"

int main(){
	ManageStore myStore("../course_2_homework/doc/store_products.xml"); // path to xml file

	// the folowing structure is used to test add/remove function
	std::tuple<unsigned int, std::string, std::string, std::string, float> temp {342456,"Produs","categorie","origine",23.45};
	Product produs(temp);

	myStore.add(temp);
	myStore.display();
	myStore.remove(temp);
	myStore.display();

	return 0;
}
