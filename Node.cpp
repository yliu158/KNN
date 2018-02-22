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
  void printNode(int level, int hight);
};

void Node::printNode(int level, int hight) {
  for (int i = 0; i < hight-level; ++i) {
    cout << setfill(' ') << setw(12) << " ";
  }
  cout <<cuttingLine << endl;
}
