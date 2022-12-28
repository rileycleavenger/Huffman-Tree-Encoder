//
// Created by Riley Cleavenger on 12/28/22.
//

#include "HuffmanTreeEncoding.h"

huffmanTree::huffmanTree(){
    // nothing to do
}
huffmanTree::huffmanTree(string s){
    // Store all characters and freqs in map
    for(char i : s){
        charsMap[i]++;
    }
    // creates pq
    createTree();

    // store codes in map
    createCodesMap(pq.top(), "");

    // saves string as codes
    for (char i : s)
        encodedStr += codesMap[i];
}

void huffmanTree::createTree(){

    for(auto iter = charsMap.begin(); iter != charsMap.end(); iter++){
        Node* temp = new Node(iter->first, iter->second);
        pq.push(temp);
    }

    while(pq.size() != 1){
        Node* right = pq.top();
        pq.pop();
        Node* left = pq.top();
        pq.pop();

        // create dummy parent node where freq = sum of left and right freqs, assign '$' as dummy character data
        Node* dummy = new Node('$', left->freq + right->freq);
        dummy->left = left;
        dummy->right = right;
        pq.push(dummy);
    }

}

//used to call print function while using internal class variables
void huffmanTree::printAllCodes(){

    for(auto iter = codesMap.begin(); iter != codesMap.end(); iter++)
        cout << iter->first << ": " << iter->second << endl;

};

string huffmanTree::encodedValue(){
    return encodedStr;
}

//used to decode string
string huffmanTree::decodedValue() {

    string newStr = "";
    Node* temp = pq.top();
    string tempStr = encodedStr;

    // goes through encoded string
    for(int i = 0; i < tempStr.size(); i++) {
        if (tempStr[i] == '0')
            temp = temp->left;
        else
            temp = temp->right;

        if (temp->left == nullptr && temp->right == nullptr) {
            newStr += temp->data;
            temp = pq.top();
        }
    }
    return newStr + '\0';
}

void huffmanTree::createCodesMap(Node* root, string str){
    // ends function if nullptr node is passed
    if(!root)
        return;

    // if it isn't a dummy node add to map
    if(root->data != '$')
        codesMap[root->data] = str;

    //recursively call function
    createCodesMap(root->right, str + '1');
    createCodesMap(root->left, str + '0');
}