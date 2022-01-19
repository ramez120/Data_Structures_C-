// Dynamic Array code
#include <iostream>
using namespace std;

template <typename T>
class MyVector {
private:
    T* DynamicArray;
    int UserSize;
    int ActualSize;
    
public:
    MyVector() {
        DynamicArray = new T[16];
        this->UserSize = 0;
        this->ActualSize = 16;
    }
    MyVector(int len) {
        try {
            if (len < 0) {
                throw 400;
            }
            else {
                this->UserSize = len;
                this->ActualSize = len;
                DynamicArray = new T[len];

            }
        }

        catch (int MyNum) {
            cout <<"Negative Value Recieved! " << endl;
            
        }
    }
    void print() {
        for (int i = 0; i < UserSize; i++) {
            cout << DynamicArray[i] << endl;
           
        }
        cout << "USER_SIZE : " << UserSize << endl;
        cout << "Actual Size : " << ActualSize << endl;
    }

    int size() {
        return this->UserSize;
    }
    bool IsEmpty() {
        return !this->UserSize;
    }
    // append to end of array
    void append(T elem) {
        if (UserSize < ActualSize) {
            DynamicArray[UserSize++] = elem;
        }
        else {
            if (ActualSize == 0) { ActualSize++; }
            else {
                ActualSize*=2;
            }
            T* TempArray = new T[ActualSize];
            T* temp = DynamicArray;
            DynamicArray = TempArray;
            for (int i = 0; i < UserSize; i++) {
                DynamicArray[i] = temp[i];
            }
            DynamicArray[UserSize++] = elem;
            delete[] temp;
        }
    }

    int GetElem(int index) {
        if (index < 0 || index > UserSize) return -1;
        return DynamicArray[index];
    }

    void SetElem(T elem, int index) {
        if (index<0 || index > UserSize) cout << "Not a valid index";
        DynamicArray[index] = elem;
    }


    void RemoveAt(int index) {
        if (index < 0 || index > UserSize) cout << "Enter a valid index !";
        else {
            T* temp = new T[UserSize];
            for (int i = 0, j = 0; i < UserSize; i++,j++) {
                if (i == index) {
                    j--;
               }
                else {
                    temp[j] = DynamicArray[i];
                }
            }
            
            delete [] DynamicArray;
            DynamicArray = temp;
            UserSize--;
            

        }
    }
    bool remove(T obj) {
        for (int i= 0; i < UserSize; i++) {
            if (DynamicArray[i] == obj) {
                RemoveAt(i);
                return 0;
            }
        }
        return -1;
    }

    int IndexOF(T obj) {
        for (int i = 0; i < UserSize; i++) {
            if (DynamicArray[i] == obj) return i;
        }
        return -1;
    }
    bool contains(T obj) {
        return IndexOF(obj) != -1;
    }


    void clear() {
        for (int i = 0; i < UserSize; i++) {
            DynamicArray[i] = NULL;
        }
        UserSize = 0;
    }

    ~MyVector() {
        delete[] DynamicArray;
    }
};







int main()
{
    MyVector<int> v;
   
    v.append(10);
 
    v.append(6);
 

    v.append(15);
  
    v.append(20);
  
    v.append(20);
    v.print();
    v.contains(15);
    v.print();

  



}

