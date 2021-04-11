#include <bits/stdc++.h>
using namespace std;

struct node {
    char val;
    node *left, *right;
    node(char x) : val(x), left(nullptr), right(nullptr) {}
};

void build(const string &inorder, const string &postorder, node *&root, int low, int high) {
    root = new node(postorder[high]);
    int mid = low;
    while (inorder[mid] != postorder[high])
        mid++;
    build(inorder, postorder, root->left, low, mid);
}

int main() {}