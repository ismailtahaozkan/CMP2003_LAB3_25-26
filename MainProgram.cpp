#include <iostream>
#include <cassert>
#include <stdexcept>
using namespace std;

template <class elemType>
class arrayListType {
public:
    // FILL IN BASED ON UML DIAGRAM

protected:
    // FILL IN BASED ON UML DIAGRAM
};

// ==========================================================
// Function Implementations
// ==========================================================
template <class elemType>
bool arrayListType<elemType>::isEmpty() const { return (length == 0); }

template <class elemType>
bool arrayListType<elemType>::isFull() const { return (length == maxSize); }

template <class elemType>
int arrayListType<elemType>::listSize() const { return length; }

template <class elemType>
int arrayListType<elemType>::maxListSize() const { return maxSize; }

template <class elemType>
void arrayListType<elemType>::print() const {
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const {
    return (list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem) {
    if (location < 0 || location >= maxSize)
        cerr << "Position out of range\n";
    else if (length >= maxSize)
        cerr << "Cannot insert in a full list\n";
    else {
        for (int i = length; i > location; i--)
            list[i] = list[i - 1];
        list[location] = insertItem;
        length++;
    }
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem) {
    if (length < maxSize)
        list[length++] = insertItem;
}

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const {
    if (location >= 0 && location < length)
        retItem = list[location];
}

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem) {
    if (location >= 0 && location < length)
        list[location] = repItem;
}

template <class elemType>
void arrayListType<elemType>::clearList() { length = 0; }

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const {
    for (int i = 0; i < length; i++)
        if (list[i] == item)
            return i;
    return -1;
}

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem) {
    if (!isFull())
        list[length++] = insertItem;
}


template<class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem){
    int loc;

    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
                 << endl;
    }
}


// ==========================================================
// Constructors / Destructors
// ==========================================================
template <class elemType>
arrayListType<elemType>::arrayListType(int size) {
    maxSize = (size > 0) ? size : 100;
    list = new elemType[maxSize];
    length = 0;
}

template <class elemType>
arrayListType<elemType>::~arrayListType() { delete[] list; }

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList) {
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize];
    for (int i = 0; i < length; i++)
        list[i] = otherList.list[i];
}

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList) {
    if (this != &otherList) {
        delete[] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new elemType[maxSize];
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}


// ==========================================================
// SAFE FALLBACKS — These guarantee compilation never fails
// ==========================================================
template <class elemType>
void arrayListType<elemType>::removeAt(int location) {
    throw runtime_error("removeAt() not implemented");
}

template <class elemType>
void arrayListType<elemType>::removeAll(const elemType& item) {
    throw runtime_error("removeAll() not implemented");
}


template <class elemType>
elemType arrayListType<elemType>::min() const {
    throw runtime_error("min() not implemented");
}

template <class elemType>
elemType arrayListType<elemType>::max() const {
    throw runtime_error("max() not implemented");
}



// ==========================================================
// MAIN
// ==========================================================
#ifndef CATCH_TESTING
int main() {
    arrayListType<int> list(20);
    list.insertEnd(5);
    list.insertEnd(7);
    list.insertEnd(3);
    list.insertEnd(7);
    list.insertEnd(9);
    list.insertEnd(7);

    cout << "\n=== INITIAL LIST ===\n";
    list.print();

    // Task 2
    cout << "\n[TEST] removeAt (index 1)" << endl;
    try {
        list.removeAt(1);
        list.print();
    } catch (...) {
        cout << "❌ removeAt test failed" << endl;
    }

    // Task 3
    cout << "\n[TEST] removeAll(7)" << endl;
    try {
        list.removeAll(7);
        list.print();
    } catch (...) {
        cout << "❌ removeAll test failed" << endl;
    }

    // Task 4
    cout << "\n[TEST] min()" << endl;
    try {
        cout << "Min element = " << list.min() << endl;
    } catch (...) {
        cout << "❌ min() test failed" << endl;
    }

    // Task 5
    cout << "\n[TEST] max()" << endl;
    try {
        cout << "Max element = " << list.max() << endl;
    } catch (...) {
        cout << "❌ max() test failed" << endl;
    }

    cout << "\n=== ALL TESTS COMPLETED ===\n";
    return 0;
}
#endif
