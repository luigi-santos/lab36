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

  do {
    displayMenu();
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1:
      cout << "Enter a code to add: ";
      getline(cin, input);
      tree.insertNode(input);
      break;
    case 2:
      cout << "Enter a code to delete: ";
      getline(cin, input);
      tree.iremove(input);
      break;
    case 3:
      cout << "Enter a code to search for: ";
      getline(cin, input);
      if (tree.isearchNode(input))
        cout << "Code found." << endl;
      else
        cout << "Code not found" << endl;
      break;
    case 4:
      cout << "Enter a code to modify: ";
      getline(cin, input);
      cout << "Enter new code: ";
      getline(cin, newCode);
      tree.modifyNode(input, newCode);
      break;
    case 5:
      cout << "Displaying codes in order: " << endl;;
      tree.displayInOrder();
      break;
    case 6:
      cout << "Exiting.";
      break;
    default:
      cout << "Invalid. Try again." << endl;
    }
  } while (choice != 6);

  return 0;
}
