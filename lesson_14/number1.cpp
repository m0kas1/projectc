#include <iostream>

class Set {
private:
    int* data;
    int count;
    int capacity;

    void resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        for (int i = 0; i < count; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Set() : data(nullptr), count(0), capacity(0) {}

    Set(const int* arr, int n) : data(nullptr), count(0), capacity(0) {
        for (int i = 0; i < n; ++i) {
            *this = *this + arr[i];
        }
    }

    Set(const Set& other) : count(other.count), capacity(other.capacity) {
        data = new int[capacity];
        for (int i = 0; i < count; ++i) {
            data[i] = other.data[i];
        }
    }

    ~Set() {
        delete[] data;
    }

    Set& operator=(const Set& other) {
        if (this != &other) {
            delete[] data;
            count = other.count;
            capacity = other.capacity;
            data = new int[capacity];
            for (int i = 0; i < count; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Set operator+(int item) const {
        Set res(*this);
        bool exists = false;
        for (int i = 0; i < res.count; ++i) {
            if (res.data[i] == item) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            if (res.count == res.capacity) {
                res.resize(res.capacity == 0 ? 1 : res.capacity * 2);
            }
            res.data[res.count++] = item;
        }
        return res;
    }

    Set operator+(const Set& other) const {
        Set res(*this);
        for (int i = 0; i < other.count; ++i) {
            res = res + other.data[i];
        }
        return res;
    }

    bool operator<=(const Set& other) const {
        for (int i = 0; i < count; ++i) {
            bool found = false;
            for (int j = 0; j < other.count; ++j) {
                if (data[i] == other.data[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }

    Set& operator()(const int* arr, int n) {
        delete[] data;
        data = nullptr;
        count = 0;
        capacity = 0;
        for (int i = 0; i < n; ++i) {
            *this = *this + arr[i];
        }
        return *this;
    }

    void print() const {
        std::cout << "{ ";
        for (int i = 0; i < count; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "}\n";
    }
};

int main() {
    Set s1;
    s1 = s1 + 1 + 2 + 3;
    s1.print();

    int arr[] = {3, 4, 5};
    Set s2(arr, 3);
    s2.print();

    Set s3 = s1 + s2;
    s3.print();

    std::cout << "s1 <= s3: " << (s1 <= s3) << "\n";
    std::cout << "s2 <= s3: " << (s2 <= s3) << "\n";

    return 0;
}