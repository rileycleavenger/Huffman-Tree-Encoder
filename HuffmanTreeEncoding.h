//
// Created by Riley Cleavenger on 12/28/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
#include <unordered_map>

using namespace std;

#pragma once

class huffmanTree{
private:
    struct Node{
        int freq;
        char data;
        Node* left;
        Node* right;
        Node(char d, int f){
            data = d;
            freq = f;
        }
    };
    struct compare{
        bool operator()(Node* c1, Node* c2){
            return c1->data < c2->data;
        }
    };
    unordered_map<char, int> charsMap;
    priority_queue<Node*, vector<Node*>, compare> pq;
    unordered_map<char, string> codesMap;
    string encodedStr;
public:
    huffmanTree();
    huffmanTree(string s);
    void createTree();
    void printAllCodes();
    string encodedValue();
    string decodedValue();
    void createCodesMap(Node* root, string str);
};