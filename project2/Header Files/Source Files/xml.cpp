#include "xml.h"
#include <iostream>
#include <fstream>

XMLHandler::XMLHandler(std::string file)
{
    path_to_file_ = file;
}

XMLHandler::XMLHandler(std::string file, std::vector<Produs> file_content)

{
    path_to_file_ = file;
    file_content_ = file_content;
}

void XMLHandler::readFromFile()
{
    
    std::ifstream xmlfile;
    std::string line;
    std::vector<Produs> values;

    xmlfile.open(path_to_file_);
    if (xmlfile.is_open())
    {
        int id = 0;
        std::string nume = "", tip = "";
        double pret = 0;
        while (getline(xmlfile, line))
        {

            if (line.find("<id>") != std::string::npos)
            {
                int begin = line.find("id") + 3;
                int end = line.find("</");
                id = std::stoi(line.substr(begin, end - begin));
            }
            else if (line.find("<name>") != std::string::npos)
            {
                int beg = line.find("name") + 5;
                int end = line.find("</");
                nume = line.substr(beg, end - beg);
            }
            else if (line.find("<type>") != std::string::npos)
            {
                int begin = line.find("type") + 5;
                int end = line.find("</");
                tip = line.substr(begin, end - begin);
            }
            else if (line.find("price") != std::string::npos)
            {
                int begin = line.find("price") + 6;
                int end = line.find("</");
                pret = std::stod(line.substr(begin, end - begin));
                
            }
            Produs prod(id, nume, tip, pret);
            values.push_back(prod);
        }  
        xmlfile.close();
        file_content_ = values;
    }
    else
    {
        std::cout << "Cannot open the file." << std::endl;
    }
}

void XMLHandler::writeToFile()
{
   
    std::ofstream xmlFile;
    xmlFile.open(path_to_file_, std::ofstream::out | std::ofstream::trunc);
    xmlFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<Store>\n";
    for (auto it = file_content_.begin(); it != file_content_.end(); ++it)
    {
        xmlFile << "\t<product>\n\t\t<id>" << (*it).getId() << "</id>\n";
        xmlFile << "\t\t<name>" << (*it).getNume() << "</name>\n";
        xmlFile << "\t\t<type>" << (*it).getTip() << "</type>\n";
        xmlFile << "\t\t<price>" << (*it).getPret() << "</price>\n\t</product>\n";
    }
    xmlFile << "</Store>";
    xmlFile.close();
}