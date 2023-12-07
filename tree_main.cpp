#include "Tree.h"

using namespace std;

// Пример использования реализованного класса AVLTree
int main() {
    AVLTree tree;
    int result = 0, result1 = 0;
    // Заполняем AVL-дерево
    // Заполнение AVL-дерева
    for(int i = 0; i < 100; i++) {
        tree.insert(i + 2*i - i/2, i*i + i);
    }
    cout<<"Глубина дерева: "<<tree.tree_depth()<<endl;
    cout<<"Глубина 0-ого эл-та: "<<tree.depth(0)<<" Глубина 8-ого эл-та: "<< tree.depth(8)<<endl;
    cout<<tree.search(50,result)<<" "<<result<<endl;
    tree.remove(50);
    cout<<tree.search(50,result1)<<" "<<result1<<endl;
    tree.inorderTraversal();
    //cout<<tree.;
    cout << endl;
    tree.printTree();
    return 0;
}