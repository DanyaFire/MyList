/*
Вокруг считающего стоит N человек, из которых выделен первый, а остальные занумерованы по часовой стрелке числами от 2 до N. 
Считающий, начиная с кого-то, ведет счет до M. Человек на котором остановился счет, выходит из круга. 
Счет продолжается со следующего человека и так до тех пор, пока не останется один человек.
Определить:
a) номер оставшегося человека, если известно M и то, что счет начинался с первого человека;
b) номер человека c которого начинался счет, если известно M и номер оставшегося человека L.
*/
#include "listcl.h"

using namespace std;
using namespace chrono;

// Функция для определения номера оставшегося человека
int findRemainingPerson(int N, int M) {
    list<int> people;
    for (int i = 1; i <= N; ++i) {
        people.push_back(i);
    }
    for(auto el : people) cout<<el<<" ";
    cout<<endl;
    auto current = people.begin();
    while (people.size() > 1) {
        for (int count = 1; count < M; ++count) {
            ++current;
            if (current == people.end()) {
                current = people.begin();
            }
        }
        current = people.erase(current);
        if (current == people.end()) {
            current = people.begin();
        }
        for(auto el : people) cout<<el<<" ";
        cout<<endl;
    }
    return people.front();
}

// Функция для определения номера человека, с которого начинался счет
int findStartingPerson(int N, int M, int L) {
    list<int> people;
    for (int i = 1; i <= N; ++i) {
        people.push_back(i);
    }
    for(auto el : people) cout<<el<<" ";
        cout<<endl;
    auto current = people.begin();
    while (people.size() > 1) {
        for (int count = 1; count < M; ++count) {
            ++current;
            if (current == people.end()) {
                current = people.begin();
            }
        }
        current = people.erase(current);
        if (current == people.end()) {
            current = people.begin();
        }
    }
    // Находим оставшегося человека
    int remainingPerson = people.front();
    cout<<N<<" "<<M<<" "<<L<<" "<<remainingPerson<<endl;
    // Теперь находим, с какого человека начинался счет
    int startingPerson = (L - M + remainingPerson - 1 + N) % N + 1;
    return startingPerson;
}
    

int main() {
    FILE* m = fopen("inp.txt","r");
    FILE* e = fopen("out.txt","w");
    int B, N, M, L;
    double c;
    Slist<int> A;
    Node<int>* temp;
    cout<<"С какого по счёту человека начнём считать? ";
    cin>>B;
    fscanf(m, "%d %d %d", &N, &M, &L);
    auto start = high_resolution_clock::now();
    if(N < 1) {
        cout<<"Количество N человек < 1";
        return 0;
    }
    // Создание односвязного списка
    for (int i = 1; i <= N; i++) {
        A.Add(i);
    }
    A.Show();
    Node<int>* last = A[B-1];
    // Цикл по обходу списка
    for (int i = 1; i < N; i++) {
        // Цикл для перехода на M-й элемент вперед
        for (int j = 1; j < M; j++) {
            last = last->next;
        }
        // Обновление указателей для удаления текущего элемента
        temp = last;
        last = last->next;
        cout<<"Выбыл "<<temp->x<<"-й человек    ";
        A.remove(temp);
        A.Show();
    }
    cout<<"a)Считалочка остановилась на "<<last->x<<"-м человеке :) \n";
    //printf("a)Считалочка остановилась на %d-м человеке :) \n", last->x);
    int beg = (L - M + last->x - 1 + N) % N + 1; 
    cout<<"b)Считалочка начиналась с "<<beg<<"-ого человека :) \n";
    //printf("b)Считалочка начиналась с %d-ого человека :)\n", begin);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    c = duration.count();
    cout<<"Время выполнения: "<<c<<" наносекунд"<<endl; 
    start = high_resolution_clock::now();
    //STL:
    // a) Номер оставшегося человека
    int remainingPerson = findRemainingPerson(N, M);
    cout<<"a) Номер оставшегося человека: "<<remainingPerson<<endl;

    // b) Номер человека, с которого начинался счет
    int startingPerson = findStartingPerson(N, M, L);
    cout<<"b) Номер человека, с которого начинался счет: "<<startingPerson<<endl;
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    c = duration.count();
    cout<<"Время выполнения: "<<c<<" наносекунд"<<endl; 
    return 0;
}