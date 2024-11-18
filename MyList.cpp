#include "MyList.h"
#include "MyContainer.h"
#include <iostream>

using namespace std;

// MyList::Nested::Nested() : data{0}, pnode{nullptr}{}
// MyList::Nested::Nested(int data, Nested *pnode) : data{data}, pnode{pnode}{}
// MyList::MyList() : head{nullptr}{}

// 위에 코드처럼 {}를 사용했는데 계속 오류가 떠서 밑에 코드처럼 ()로 바꿨습니다.
MyList::Node::Node() : data(0), pnode(nullptr){}

MyList::Node::Node(int data, Node *pnode) : data(data), pnode(pnode){}

MyList::MyList() : head(nullptr){}

MyList::~MyList(){
    // 리스트 삭제
    Node *temp = head;

    while(temp){
        Node *next = temp->pnode;
        delete temp;
        temp = next;
    }
    
    head = nullptr;
}

// 마지막 원소를 삭제한다.
void MyList::pop_back(){  
    if(!head){
        throw out_of_range("list is empty");
        // cout << "not have data" << endl;
        // return;
    }

    if(!head->pnode){
        delete head;
        head = nullptr; 
        return;
    }

    Node *temp = head;
    Node *pretemp = head;   
    while(temp->pnode != nullptr){
        pretemp = temp;
        temp = temp->pnode;
    }

    delete temp;
    pretemp->pnode = nullptr; 
}

// 마지막 원소 뒤에 새 원소를 추가한다.
void MyList::push_back(const int &val){     
    if(!head){
        head = new Node(val, nullptr);
        return;
    }

    Node *temp = head;
    Node *newNode = new Node(val, nullptr);
    while(temp->pnode != nullptr){
        temp = temp->pnode;
    }

    temp->pnode = newNode;
}

// 현재 저장된 원소 개수를 반환한다.
int MyList::size() const{
    Node *temp = head;
    int count = 0;

    while(temp){    // temp 자체가 nullptr인지 확인
        temp = temp->pnode;
        ++count;
    }

    return count;
}

// 맨 마지막 원소의 데이터를 반환한다. 
int &MyList::back(){
    if(!head){
        throw out_of_range("list is empty");
    }

    Node *temp = head;
    while(temp->pnode != nullptr){
        temp = temp->pnode;
    }
    return temp->data;
}

// 맨 마지막 원소의 데이터를 반환한다. 단 변경할 수 없다.
const int &MyList::back() const{
    if(!head){
        throw out_of_range("list is empty");
    }
    Node *temp = head;
    while(temp->pnode != nullptr){
        temp = temp->pnode;
    }
    return temp->data;
}
