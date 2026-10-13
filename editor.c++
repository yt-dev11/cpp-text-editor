#include <iostream>
struct Node{
    std::string text;
    Node* next;
    Node* prev;
};
struct list{
    Node* tail = nullptr;
    Node* head = nullptr;
    int size;
};
list listmaker(){
   list a;
   a.head = nullptr;
   a.tail = nullptr;
   a.size = 1;
   return a;
};
Node* Nodemaker(){
    Node* a = new Node;
    a->next = nullptr;
    a->prev = nullptr;
    return a;
};
void push(list& a , Node* n){
    if (a.head == nullptr ){
    a.head = n;
    a.tail = n;
    a.size++;
    return ;
    }
    n->prev = a.tail;
    a.tail->next = n;
    a.tail = n;
    a.size = a.size + 1;
}

using namespace std;
int main (){
std::string T;
list a = listmaker();
for(int i=1;i<40;i++){ 
 cout << "line" << a.size << ">";
 getline(cin,T);
 if( T == "exit" ){
    i=40;
 }else{
 Node* n = Nodemaker();
 n->text = T;
 push(a , n);
 };
};
 return 0;
}

