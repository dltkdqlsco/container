#ifndef MYVECTOR_H
#define MYVECTOR_H

#include "MyContainer.h"

class MyVector : public MyContainer{
    public:
        MyVector();
        ~MyVector();
        void push_back(const int& val) override; // 마지막 원소 뒤에 새 원소를 추가하는 함수, 원소 개수 갱신, 더 이상 저장할 공간이 없는 경우 2배 동적 할당
        void pop_back() override; //마지막 원소를 삭제한다. 삭제 작업은 그냥 현재 저장한 원소 개수를 1 줄이는 것으로 충분하다. 
        int size() const override;   // 현재 저장된 원소 개수를 반환한다.
        int &operator[](const int index);   // 주어진 인덱스의 원소를 반환한다. 원소를 수정할 수 있다.
        const int &operator[](const int index) const;   // 주어진 인덱스의 원소를 반환하다. 원소를 수정할 수 없다.
        
    private:
        int canSaveNum;
        int *pCanSaveNum;
        int currentNum;
};
#endif