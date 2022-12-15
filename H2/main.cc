#include "include/XMLHandler.h"
#include "include/Product.h"
#include <string>
#include <vector>
#include <utility>
#include <iostream>


int main()
{
  XMLHandler Handler = XMLHandler("store.xml");
  Handler.readFromFile();
  std::vector<std::pair<std::string, double>> values = Handler.getValues();
  //Handler.writeToFile();

  for (auto it = values.begin(); it != values.end(); ++it)
  {
    std::cout << (*it).first << " " << (*it).second << std::endl;
  }
  
  Product mouse = Product("Mouse", 150.0);
  Product keyboard = Product("Keyboard", 175.76);
  Product monitor = Product("Monitor", 330.23);


  values.push_back(std::make_pair(mouse.getName(), mouse.getPrice()));
  values.push_back(std::make_pair(keyboard.getName(), keyboard.getPrice()));
  values.push_back(std::make_pair(monitor.getName(), monitor.getPrice()));

  for (auto it = values.begin(); it != values.end(); ++it)
  {
    std::cout << (*it).first << " " << (*it).second << std::endl;
  }
  
  XMLHandler XMLHandler2 = XMLHandler("store.xml", values);

  XMLHandler2.writeToFile();

}  
