#include <iostream>
#include <fstream>
#include <string>
#include "StringBinaryTree.h"

using namespace std;

void displayMenu() {
  cout << "1. Add a code" << endl;
  cout << "2. Delete a code" << endl;
  cout << "3. Search for a code" << endl;
  cout << "4. Modify a code" << endl;
  cout << "5. Display the codes in order" << endl;
  cout << "6. Quit" << endl;
}

int main() {
  StringBinaryTree tree;
  ifstream inputFile("codes.txt");
  string code;

  if (!inputFile) {
    cout << "Error opening codes.txt" << endl;
  return 1;
  }

  while (getline(inputFile, code)) {
    tree.inserNode(code);
  }
  inputFile.close();

  int choice;
  string input, newCode;

  
    
