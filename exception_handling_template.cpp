// Program: Demonstration of template using Exception Handling
// Topic: Exception Handling in C++
#include <iostream>
using namespace std;

template <class T>

class Container {

    T *arr;
    int size;
    int capacity;

public:

    
    Container(int cap = 5) {

        capacity = cap;
        size = 0;

        try {

            arr = new T[capacity];
        }

        catch(bad_alloc&) {

            cout << "Memory allocation failed!";
        }
    }

    
    void addElement(T element) {

        if(size >= capacity)
            throw "Container is full!";

        arr[size] = element;

        size++;

        cout << "Element added\n";
    }

    
    void removeElement(int index) {

        if(size == 0)
            throw "Container is empty!";

        if(index < 0 || index >= size)
            throw "Invalid index!";

        for(int i=index; i<size-1; i++) {

            arr[i] = arr[i+1];
        }

        size--;

        cout << "Element removed\n";
    }

    
    T getElement(int index) {

        if(index < 0 || index >= size)
            throw "Invalid index!";

        return arr[index];
    }

    
    void display() {

        for(int i=0; i<size; i++) {

            cout << arr[i] << " ";
        }

        cout << endl;
    }

   
    ~Container() {

        delete[] arr;
    }
};

int main() {

    try {

        Container<int> c;

        c.addElement(10);
        c.addElement(20);
        c.addElement(30);

        c.display();

        cout << "Element at index 1: "
             << c.getElement(1) << endl;

        c.removeElement(1);

        c.display();

        
        cout << c.getElement(10);
    }

    catch(const char* msg) {

        cout << "Exception: " << msg;
    }

    return 0;
}
