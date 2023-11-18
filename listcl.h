#include <iostream>
#include <cmath>
#include <chrono>
#include <forward_list>

using namespace std;

template<typename T>
struct Node {
  T x;
  Node<T> *next;
  Node(T value);
  bool comparison(const Node<T>& p1, const Node<T>& p2);
};

template<typename T>
class Slist {
private:
  Node<T> *Head, *Tail;
  friend class iterator;
public:
  Slist();
  Slist(const Slist& s);
  bool is_empty();
  void Add(T x);
  void remove_head();
  void remove_tail();
  void remove(T x);
  Node<T>* find_x(T x);
  Node<T>* operator[](const T i);
  Slist<T>& operator=(const Slist& g);
  void Show();
  int quantity();
  ~Slist();
  class iterator {
  private:
    friend class Slist<T>;
    Node<T> *cur;
  public:
    iterator (Node<T> *ptr) : cur (ptr) {}
    bool operator==(const iterator& it) const {
      return cur==it.cur;
    }
    T operator*() const {
      if (cur != nullptr) {
        return cur->x;
      } else {
        cout<<"cur is empty!";
        return T();
      }
    }
    bool operator!=(const iterator& it) const {
      return !(cur==it.cur);
    }
    iterator& operator++(int) {
      cur = cur->next; 
      return *this;        
    }
  };
  void remlolove(iterator& pos);
  iterator begin() const;
  iterator end() const;
};