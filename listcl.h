#include <iostream>
#include <cmath>
#include <chrono>
#include <list>

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
  Node<T> *Head;
  friend class iterator;
public:
  Slist();
  Slist(const Slist& s);
  bool is_empty();
  void Add(const T& x);
  void remove_head();
  void remove(const T& x);
  void remove(const Node<T>* bye);
  //Node<T>* find_x(const T& x);
  void Show();
  int quantity();
  ~Slist();
  Node<T>* operator[] (const int i);
  Slist<T>& operator=(const Slist& g);
  // void remove_tail();
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