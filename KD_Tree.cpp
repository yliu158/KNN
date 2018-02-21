#include "Node.cpp"
#include <vector>
using namespace std;

class KD_Tree{
public:
  Node* root;
  vector<vector<double> > data;
  KD_Tree(vector<vector<double> >& input) {
    data = vector<vector<double> > (input);
  }
  Node* constructorHelper(vector<vector<double> >& input, int dim_index, Node* parent);
  void sort(vector<vector<double> >& input, int start, int end, int dim_index);
  void swap(vector<double>& first, vector<double>& second, int dimension);
};

Node* KD_Tree::constructorHelper(vector<vector<double> >& input, int dim_index, Node* parent) {

  return new Node(0, parent);
}

void KD_Tree::sort(vector<vector<double> >& input, int start, int end, int dim_index) {
  if (start >= end) return;
  if (start < 0 || end >= input.size()) return;
  if (dim_index < 0) return;
  dim_index %= input[start].size();
  double pivot = input[end][dim_index];
  int write = start-1;
  for (int i = start; i < end; ++i) {
    if (input[i][dim_index] <= pivot) {
      ++ write;
      swap(input[write], input[i], dim_index);
    }
  }
  return;
}

void KD_Tree::swap(vector<double>& first, vector<double>& second, int dimension){
  for (int i = 0 ; i < dimension; ++i) {
    double tmp = first[dimension];
    first[dimension] = second[dimension];
    second[dimension] = tmp;
  }
  return;
}



int main(int argc, char const *argv[]) {
  vector<vector<double> > testcase;
  KD_Tree t = KD_Tree(testcase);
  for (int i = 0; i < 100; ++i) {

  }
  vector<vector<double> >().swap(testcase);
  return 0;
}
