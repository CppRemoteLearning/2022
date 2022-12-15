#include "include/store_manager.h"

int main(){
	std::string path = "/hme/adrian-ilie/Storage/~Courses/Nagarro/projects/course_2_homework/doc/store_products.xml";
	StoreManager myStore(path);
	Product produs(23467,"Super","cat",1000,23.5);
	myStore.Add(produs);
	myStore.ShowInTable();
	myStore.Remove(produs);
	myStore.ShowInTable();

	return 0;
}
