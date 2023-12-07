#include <iostream>

using namespace std;

class AVLTree {
private:
    struct Node {
        int key;
        int value;
        Node* left;
        Node* right;
        int depth;
        Node() : key(0), value(0), left(nullptr), right(nullptr), depth(0) {}
        Node(const int& k, const int& v, Node* l, Node* r, int& d) : key(k), value(v), left(l), right(r), depth(d) {}
    };

    Node* root;

    // Функция для получения высоты узла дерева
    int depth(Node* node) const;

    int getNodeDepth(Node* node, const int& key);

    // Функция для создания нового узла
    Node* newNode(const int& key, const int& value);

    // Функция для правого вращения поддерева с корнем y
    Node* rightRotate(Node* y);

    // Функция для левого вращения поддерева с корнем x
    Node* leftRotate(Node* x);

    // Функция для получения баланса узла N
    int getBalance(Node* N);

    // Функция для вставки по ключу в AVL-дерево
    Node* insert(Node* node, const int& key, const int& value);

    // Функция для удаления по ключу из AVL-дерева
    Node* remove(Node* root, const int& key);

    // Функция поиска минимального элемента в AVL-дереве
    Node* minValueNode(Node* node);

    // Функция для обхода в порядке "inorder"
    void inorder(Node* root);

    // Функция для вывода дерева на экран
    void printTree(Node* root, std::string prefix = "", bool isLeft = true);

    // Удаление некоторой части дерева
    void destroyTree(Node* node);
public:
    AVLTree() {
        root = nullptr;
    }

    // Функция для вставки ключа в AVL-дерево
    void insert(const int& key, const int& value) {
        root = insert(root, key, value);
    }
    
    // Функция поиска по ключу в AVL-дереве
    bool search(const int& key, int& result) const;

    // Функция для удаления ключа в AVL-дерево
    void remove(const int& key) {
        root = remove(root, key);
    }

    // Функция для вывода данных обходом в порядке "inorder"
    void inorderTraversal() {
        cout << "Узлы AVL-дерева в порядке обхода \"inorder\": ";
        inorder(root);
        cout << endl;
    }

    // Вывод дерева на экран
    void printTree() {
        cout << "Дерево AVL:" << endl;
        printTree(root,"",true);
    }

    int depth(const int& key) {
        return getNodeDepth(root, key);
    }

    int tree_depth() const {
        return depth(root);
    }

    ~AVLTree() {
        destroyTree(root);
    }
};