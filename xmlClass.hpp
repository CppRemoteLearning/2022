#pragma once
#include <iostream>
#include <string>
#include "rapidXML/rapidxml.hpp"
#include <fstream>
using namespace std;

class Reader {
    string filename;
    public:
        //Constructor that takes the filename as an argument
        Reader(const string& filename_) : filename(filename_) {}

        void readData()
        {
            ifstream f(filename);
            if (!f.is_open())
            {
                cout << "Cannot open file\n";
                return;
            }
            else
                cout << "File opened\n";
            //Read the entire file into a string
            string xml((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
            
            //Parse the XML string
            rapidxml::xml_document<> doc;
            doc.parse<0>(&xml[0]);
            
            //Get the root node
            rapidxml::xml_node<>* root = doc.first_node("products");

            //Loop through all the nodes
            /*
            for (rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling())
            {
                cout << "Product name: " << node->name() << '\n';
                cout << "Product value" << node->value() << '\n';
            }
            */
        }

};
