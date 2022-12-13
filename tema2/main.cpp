#include "headers/XmlParser.h"

using namespace std;
int main(){
    XmlParser parser = XmlParser("file.xml");
    map<string, pair<string, string>> out;
    parser.readProductInfo(out);
    cout<<out["Product1"].first;
}