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

int main() {
    cout<<"aboba";
     int N = 10;
    printf(" aboba\n");
    Slist<int> A;
    for (int i = 1; i <= N; i++) {
        A.Add(i);
    }
    A.Show();
    Slist<int>::iterator i = A.begin();
    A.remlolove(i);
    A.Show();
    i = A.begin();
    A.Show();
    i++;
    A.remlolove(i);
    A.Show();
    // FILE* m = fopen("inp.txt","r");
    // FILE* e = fopen("out.txt","w");
    // Slist<int> A;
    // int N, M, L;
    // fscanf(m, "%d %d %d", &N, &M, &L);
    // // Создание односвязного списка
    // for (int i = 1; i <= N; i++) {
    //     A.Add(i);
    //     if (A[0] == NULL) {
    //         cout<<"Please, enter N > 0";
    //         return -1;
    //     }
    // }
    // A.Show();
    // for(Slist<int>::iterator i = A.begin(); i != A.end(); i++) {
    //     while(*i != M) i++;
    //     A.remlolove(i);
    // }
    //int last = 0;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j < M; j++) {
    //         current = A[j-1]->next;
    //         last = current->x;
    //         cout<<last;
    //         break;
    //     }
    //     Node<int>* temp = current->next;
    //     current->next = temp->next;
    //     last = temp->x;
    //     free(temp);
    // }

    // printf("a) %d ", last);
    
    // Находим начало
    // int begin = L - last + 1;
    // if (begin <= 0) {
    //     begin = begin + N;
    // }
    // printf("b) %d", begin);

    // // Освобождение памяти
    // Node* temp = head;
    // while (temp != NULL) {
    //     Node* nextNode = temp->next;
    //     free(temp);
    //     temp = nextNode;
    // }
    return 0;
}