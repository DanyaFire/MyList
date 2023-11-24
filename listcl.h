#include <iostream>
#include <cmath>
#include <chrono>
#include <list>
#include <string>

using namespace std;

template<typename T>
struct Node {
  T x;
  Node<T> *next;
  Node(T value);
  Node(T* value);
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
  bool is_empty() const;
  void Add(const T& x);
  void Add(const T* x);
  void remove_head();
  void remove(const T& x);
  void remove(const Node<T>* bye);
  void clear();
  //Node<T>* find_x(const T& x);
  void Show();
  int quantity() const;
  ~Slist();
  Node<T>* operator[] (const int i);
  bool operator==(const Slist<T>& obj);
  bool operator!=(const Slist<T>& obj);
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
  Node<T> * golova() const
  {
    return Head;
  }
}; 

class Exception {
private:
  string message;
public: 
  Exception(string message): message(message) {}
  string getMessage() const {
    return message;
  }
};

class Helped { 
private:
  Slist<int> lst;
public: 
  Helped() { 
    for (int i = 1; i <= 10; ++i) { 
      lst.Add(i); 
    } 
    cout<<"aboba";
    Print();
  } 
  bool operator==(const Helped V) {
    return lst == V.lst;
  }
  bool operator!=(const Helped V) {
    return !(lst == V.lst);
  }
  void Print() {
    lst.Show();
  }
  friend std::ostream & operator<<( std::ostream &O, Helped &L);
  friend class Slist<int>;
}; 
