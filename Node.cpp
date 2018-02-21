
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
};
