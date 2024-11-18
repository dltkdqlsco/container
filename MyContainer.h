#pragma once

class MyContainer{
    public:
        virtual void push_back(const int &val) = 0;
        virtual void pop_back() = 0;
        virtual int size() const = 0;
        virtual ~MyContainer() = default;

        enum ContainerType{LIST, VECTOR};
        static MyContainer *Create(ContainerType type);
};