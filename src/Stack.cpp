//Statikus verem, tesztelés, kivételkezelés

#include "Stack.h"

//Új elemet helyez a verem tetejére, ha a verem tele van kivételt dob
void Stack::push(const int& item) {

    if (isFull()) {
        throw StackOverFlowException;
    }

    items.push_back(item);
    stackPointer++;
}

//Kiveszi a verem tetején lévõ elemet, ha a verem üres kivételt dob
int Stack::pop() {

    if (isEmpty()) {
        throw ItemNotFoundException;
    }

    stackPointer--;
    int item = items.back();
    items.pop_back();

    return item;
}

//Üríti a vermet
void Stack::clear() {

    stackPointer = 0;
    items.clear();
}

//Visszaadja a verem tetején lévõ elemet, de nem veszi ki a verembõl
int Stack::top() const {

    if (stackPointer == 0) { //items.empty()
        throw ItemNotFoundException;
    }

    return items.back();
}

bool Stack::isEmpty() const {

    return items.empty();
}

bool Stack::isFull() const {

    return stackPointer == MAX_SIZE; // items.size() == MAX_SIZE
}
