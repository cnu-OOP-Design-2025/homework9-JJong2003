#include <iostream>
#include <string>
#include <list>
using namespace std;

template<typename T>
class MyVector {
/* TODO */
private:
    T* data;             // 동적 배열을 가리키는 포인터
    size_t capacity;     // 현재 할당된 배열 크기
    size_t length;       // 실제 저장된 요소 개수

    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;

        T *tmp = new T[capacity * 2];
        for (int i=0; i<length; i++) {
            tmp[i] = data[i];
        }
        delete [] data;    // 기존 배열 해제
        data = tmp;        // 새 배열 할당
        capacity *= 2;
    }

public:

    MyVector() : capacity(2), length(0) {
        data = new T[capacity];
    }

    ~MyVector() {
        delete [] data;
    }

    void push_back(const T& value) {
        if (length == capacity)
            resize();
        data[length] = value;
        length++;
    }

    T pop_back() {
        if (length == 0)
            throw out_of_range("Vector is empty");
        return data[--length];
    }

    T& operator[](const int index){
        return data[index];
    }

    size_t size() const {
        return length;
    }
};



template<typename T>
void testVector(const string& name, std::list<T> values) {

    cout << "------------------" << endl;
    MyVector<T> vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";

    cout << endl;
    while(vec.size())
        cout << "Pop: " << vec.pop_back() << "\n";
}

int main() {
    testVector<int>("IntVec", {1, 2, 3, 4, 5, 6});
    testVector<double>("DoubleVec", {1.1, 2.2, 3.3, 4.4, 5.5});
    testVector<char>("CharVec", {'A', 'B', 'C', 'D', 'E', 'F'});
    testVector<string>("StringVec", {"Hello", "World", "C++", "Template", "Vector"});
    return 0;
}
