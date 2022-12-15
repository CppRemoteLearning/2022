#include "include/store_manager.h"

int main(){
  StoreManager myStore_v1("/home/adrian-ilie/Storage/~Courses/Nagarro/projects/course_2_homework/doc/store_products.xml");
  myStore_v1.SetName("myStore_v1");
  StoreManager myStore_v2("/home/adrian-ilie/Storage/~Courses/Nagarro/projects/course_2_homework/doc/store_products_merge.xml");
  myStore_v2.SetName("myStore_v2");

  Product produs(23467,"Super","cat",1000,23.5);
  myStore_v1.Add(produs);
  myStore_v1.ShowInTable();
  myStore_v2.ShowInTable();
  myStore_v1.Merge(myStore_v2);
  myStore_v1.Sort();
  myStore_v1.ShowInTable();
  myStore_v1.ExportToXML("/home/adrian-ilie/Storage/~Courses/Nagarro/projects/course_2_homework/doc/","store.xml"); 
  return 0;
}
