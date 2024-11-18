#include "MyContainer.h"
#include "MyList.h"
#include "MyVector.h"

MyContainer *MyContainer::Create(ContainerType type){
    if(type == LIST){
        return new MyList();
    }else if(type == VECTOR){
        return new MyVector();
    }
    return nullptr;
}





