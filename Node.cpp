#include <iostream>
#include <iomanip>
using namespace std;

class Node{
public:
  double cuttingLine;
  Node* parent;
  Node* left;
  Node* right;
  Node(double num, Node* parent) {
    this->parent = parent;
    cuttingLine = num;
  }
  void printNode(int level);
};

void Node::printNode(int level) {
  for (int i = 0; i < level; ++i) {
    cout << setfill(' ') << setw(12) << " ";
  }
  cout <<cuttingLine << endl;
}
