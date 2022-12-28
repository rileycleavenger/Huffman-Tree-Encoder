#include <iostream>
#include <fstream>
#include "HuffmanTreeEncoding.h"

string txtFileToString(string filePath);

using namespace std;

int main() {

    // create test tree with string from txt file
    //huffmanTree testTree(txtFileToString("testFile.txt"));

    //create test tree with string
    huffmanTree testTree("mississippi");

    //prints codes
    testTree.printAllCodes();

    //encoded and decoded value
    cout << "Encoded Value: " << testTree.encodedValue() << endl;
    cout << "Decoded Value: " << testTree.decodedValue() << endl;
    return 0;
}

string txtFileToString(string filePath){
    string str;
    string returnStr = "";
    ifstream inFile;

    // opens file and reads into string
    inFile.open(filePath);
    while(!inFile.eof()) {
        getline(inFile, str);
        returnStr += str + "\n";

    }
    inFile.close();

    return returnStr;
}

