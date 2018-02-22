#include <vector>
#include "Node.cpp"

class KD_Tree {
public:
  vector<vector<double> > data;
  int dimension = 5;
  int size_of_data = 2;
  Node* root;

  KD_Tree() {
    randDataset();
    root = buildTree(0, data.size()-1, 0, NULL);
  }
  ~KD_Tree() {
    vector<vector<double> >().swap(data);
  }

  void swap(int first, int second);
  int partition(int left, int right, int dim_index, double pivot);
  void sort(int start, int end, int dim_index);
  Node* buildTree(int start, int end, int dim_index, Node* parent);
  void printTree();
  void printTreeHelper(Node* node, int level);
  void printMatrix();
  void randDataset();

};


void KD_Tree::printMatrix() {
  for (int j = 0; j < data.size(); ++j) {
    for (int i = 0; i < data[i].size(); ++i) {
      cout << setfill(' ') << left << setw(13) << data[j][i];
    }
    cout << endl;
  }
  cout << endl;
}

void KD_Tree::randDataset() {
  vector<double> row;
  for (int j = 0; j < size_of_data; ++j) {
    row.clear();
    vector<double>().swap(row);
    for (int i = 0; i < dimension; ++i) {
      row.push_back((double)(rand()%200));
    }
    data.push_back(row);
  }
  row.clear();
  vector<double>().swap(row);
  return;
}

void KD_Tree::swap(int first, int second) {
  for (int i = 0; i < data[first].size(); ++i) {
    double tmp = data[first][i];
    data[first][i] = data[second][i];
    data[second][i] = tmp;
  }
}

int KD_Tree::partition(int left, int right, int dim_index, double pivot) {
  int leftP = left-1;
  int rightP = right;
  while (true) {
    while (data[++leftP][dim_index] < pivot);
    while (rightP > 0 && data[--rightP][dim_index] > pivot);
    if (leftP >= rightP) break;
    else {
      swap(leftP, rightP);
    }
  }
  swap(leftP, right);
  return leftP;
}

void KD_Tree::sort(int start, int end, int dim_index) {
  if(start >= end) return;
  dim_index %= dimension;
  double pivot = data[end][dim_index];
  int p = partition(start, end, dim_index, pivot);
  sort(start, p-1, dim_index);
  sort(p+1, end, dim_index);
  return;
}

Node* KD_Tree::buildTree(int start, int end, int dim_index, Node* parent) {
  if (start > end) return NULL;
  if (start == end) return new Node(data[start][dim_index%dimension], parent);
  printMatrix();
  sort(start, end, dim_index);
  dim_index %= dimension;
  int mid = (start+end)/2;
  double line = data[mid][dim_index];
  Node* cur = new Node(line, parent);
  int tail = mid-1;
  int head = mid+1;
  while (tail >= 0 && data[tail][dim_index] == line) --tail;
  while (head < data.size() && data[head][dim_index] == line) ++ head;
  cur->left = buildTree(start, tail, dim_index+1, cur);
  cur->right = buildTree(head, end, dim_index+1, cur);
  return cur;
}

void KD_Tree::printTree() {
  printTreeHelper(root, 0);
}

void KD_Tree::printTreeHelper(Node* node, int level) {
  if (node == NULL) {
    cout << endl;
    return;
  }
  printTreeHelper(node->left, level+1);
  node->printNode(level);
  printTreeHelper(node->right, level+1);
  return;
}



int main(int argc, char const *argv[]) {
  KD_Tree t = KD_Tree();
  t.printTree();
  return 0;
}
