#include "listcl.h"

template<typename T>
struct Node;
template<typename T>
class Slist;

template<typename T>
Node<T>::Node(T value) : x(value), next(nullptr) {};

template<typename T>
bool Node<T>::comparison(const Node<T>& p1, const Node<T>& p2) {
  return (p1.x == p2.x) && (p1.next == p2.next);
}

template<typename T>
Slist<T>::Slist() : Head(NULL), Tail(NULL) {};

template<typename T>
Slist<T>::Slist(const Slist& s) {
  Head = s.Head;
  Tail = s.Tail;
}

template <typename T>
Slist<T>::~Slist() {
  while (Head != NULL) {
    Node<T>* temp = Head;
    Head = Head->next;
    delete temp;
  }
  Tail = NULL;
}

template<typename T>
bool Slist<T>::is_empty() {
  return Head == NULL;
}

template<class T> void Slist<T>::Add(T x) {
  Node<T>* temp = new Node(x);
  if (Head == NULL) {
    Head = Tail = temp;
  } else {
    Tail->next = temp;
    Tail = temp;
  }
}

template<typename T>
void Slist<T>::remove_head() {
  if(is_empty()) return;
  Node<T>* cur = Head;
  Head = cur->next;
  delete cur;
}

template<typename T>
void Slist<T>::remove_tail() {
  if(is_empty()) return;
  if(Head == Tail) {
    remove_head();
    return;
  }
  Node<T>* tmp = Head;
  while(tmp->next != Tail) tmp = tmp->next;
  tmp->next = Head;
  delete Tail;
  Tail = tmp;
}

template<typename T> void Slist<T>::remove(T x) {
  if(is_empty()) return;
  if(Head->x == x) {
    remove_head();
    return;
  } else if(Tail->x == x) {
    remove_tail();
    return;
  } else {
    Node<T>* slow = Head;
    Node<T>* fast = Head->next;
    while((fast != NULL) && (fast->x != x)) {
      fast = fast->next;
      slow = slow->next;
    }
    if(fast == NULL) {
      cout<<"Такого элемента не существует!"<<endl;
      return;
    }
    slow->next = fast->next;
    delete fast;
  }
}

template <typename T>
void Slist<T>::remlolove(iterator& pos) {
  if(pos == end()) {
    remove_tail();
  } else if(pos == begin()) {
    remove_head();
  } else {
    iterator temp = begin();
    while(temp.cur->next != pos.cur) temp.cur = temp.cur->next;
    temp.cur->next = pos.cur->next;
    // while(temp.cur->next != pos.cur) temp++;
    // temp.cur->next = pos.cur->next;
    delete pos.cur;
  }
}

template<typename T>
Node<T>* Slist<T>::find_x(T x) {
  Node<T>* temp = Head;
  while(temp && temp->x != x) temp = temp->next;
  return (temp && temp->x == x)?(temp):(nullptr);
}

template<typename T>
Node<T>* Slist<T>::operator[] (const T i) {
  if(is_empty()) return NULL;
  Node<T>* p = Head;
  for(int j = 0; j < i; j++) {
    p = p->next;
    if(p == NULL) return NULL;
  }
  return p;
}

template<typename T>
Slist<T>& Slist<T>::operator=(const Slist& g) {
  if (this != &g) {
    while(Head != nullptr) {
      Node<T>* temp = Head;
      Head = Head->next;
      delete[] temp;
    }
    Tail = nullptr;
    for (Node<T>* current = g.Head; current != nullptr; current = current->next) {
      Add(current->x);
    }
  }
  return *this;
}

template<typename T>
void Slist<T>::Show() {
  if(Head == NULL) cout<<"Список пуст!";
  Node<T>* temp = Head;
  int tmp = quantity();
  while (tmp != 0) {
    cout<<temp->x<<" ";
    temp = temp->next;
    tmp--;
  }
  cout<<endl;
  delete temp;
}

template<typename T>
int Slist<T>::quantity() {
  if(is_empty()) {
    return 0;
  }
  Node<T>* tmp = Head;
  int size = 1;
  do {
    tmp = tmp->next;
    size++;
  } while(tmp != Tail); 
  return size;
}

template <typename T>
typename Slist<T>::iterator Slist<T>::begin() const {
  return iterator(Head);
}

template <typename T>
typename Slist<T>::iterator Slist<T>::end() const {
  return iterator(nullptr);
}

template class Slist<int>;
template class Slist<double>;
template class Slist<char>;
