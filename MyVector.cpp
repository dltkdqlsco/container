#include <iostream>
#include "MyVector.h"

using namespace std;

MyVector::MyVector(){
    canSaveNum = 100;
    pCanSaveNum = new int[100];
    currentNum = 0;
}

MyVector::~MyVector(){
    delete pCanSaveNum;
}

void MyVector::push_back(const int& val){
    if(canSaveNum == currentNum){
        int *new_array = new int[canSaveNum * 2];
        memcpy(new_array, pCanSaveNum, sizeof(int) * canSaveNum);
        delete[] pCanSaveNum;

        pCanSaveNum = new_array;

        canSaveNum *= 2;
    }

    pCanSaveNum[currentNum++] = val;
}

void MyVector::pop_back(){
    if(currentNum == 0){
        cout << "not have num in the any index" << endl;
    }else{
        pCanSaveNum[--currentNum] = 0;
    }
}

int MyVector::size() const{
    return currentNum;
}   

int &MyVector::operator[](const int index){
    return pCanSaveNum[index];
}

const int &MyVector::operator[](const int index) const{
    return pCanSaveNum[index];
} 