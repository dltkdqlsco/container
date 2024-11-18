#pragma once
#include "MyContainer.h"

class MyList : public MyContainer{
    public:
        class Node{   // nest 클래스
          public:
            Node();  // nest클래스 기본 생성자
            Node(int data, Node *pnode);   // nest 클래스 생성자

            public:
                int data;   // 저장하고 있는 정수 데이터 값
                Node*pnode; // 다음 node에 대한 포인터
        };

        MyList();   // MyList 클래스 기본 생성자
        ~MyList();  // 기본 소멸자
        void push_back(const int &val) override; // 마지막 원소 뒤에 새 원소를 추가한다.
        void pop_back() override;    // 마지막 원소를 삭제한다.
        int size() const override;   // 현재 저장된 원소 개수를 반환한다.
        int &back();    // 맨 마지막 원소의 데이터를 반환한다. 
        const int &back() const;    // 맨 마지막 원소의 데이터를 반환한다. 단 변경할 수 없다.
    public:
        Node *head;  // 처음 node에 대한 포인터
};