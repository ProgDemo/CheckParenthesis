//Egész számokat tároló, vektorral ábrázolt statikus verem

/*
Include guard, segítségével a header hivatkozás helyén elkerülhetõ a duplikáció.
Továbbiak: https://en.wikipedia.org/wiki/Include_guard
*/
#ifndef STACK_H
#define STACK_H

#include <vector>

//Kivételtípus
enum StackException {StackOverFlowException, ItemNotFoundException};

class Stack
{
    private:
        const int MAX_SIZE = 100;
        int stackPointer; //a verem tetejére mutat, az aktuális elemszámot is mutatja
        std::vector<int> items;

    public:
        Stack(): stackPointer(0) {}
        void push(const int& item);
        int pop();
        void clear();
        int top() const;
        bool isEmpty() const;
        bool isFull() const;
};

#endif // STACK_H
