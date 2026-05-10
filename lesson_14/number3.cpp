#include <iostream>

template <typename T>
class TSet {
private:
    T* data;
    int count;
    int capacity;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < count; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    TSet() : data(nullptr), count(0), capacity(0) {}

    TSet(const TSet& other) : count(other.count), capacity(other.capacity) {
        data = new T[capacity];
        for (int i = 0; i < count; ++i) {
            data[i] = other.data[i];
        }
    }

    ~TSet() {
        delete[] data;
    }

    TSet& operator=(const TSet& other) {
        if (this != &other) {
            delete[] data;
            count = other.count;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < count; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    TSet operator+(const T& item) const {
        TSet res(*this);
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

    TSet operator+(const TSet& other) const {
        TSet res(*this);
        for (int i = 0; i < other.count; ++i) {
            res = res + other.data[i];
        }
        return res;
    }

    bool operator<=(const TSet& other) const {
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

    TSet& operator()(const T* arr, int n) {
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

class Document {
private:
    char* title;
    static int totalDocuments;

    void copyTitle(const char* str) {
        if (!str) {
            title = nullptr;
            return;
        }
        int len = 0;
        while (str[len] != '\0') len++;
        title = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            title[i] = str[i];
        }
    }

public:
    Document(const char* t = "Untitled") {
        copyTitle(t);
        totalDocuments++;
    }

    Document(const Document& other) {
        copyTitle(other.title);
        totalDocuments++;
    }

    virtual ~Document() {
        delete[] title;
        totalDocuments--;
    }

    const char* getTitle() const {
        return title ? title : "Unknown";
    }

    static void printCount() {
        std::cout << "Total documents: " << totalDocuments << "\n";
    }

    virtual void printInfo() const = 0;
    virtual bool isClassified() const = 0;
};

int Document::totalDocuments = 0;

class Passport : public Document {
private:
    int idNumber;

public:
    Passport(const char* name, int id) : Document(name), idNumber(id) {}
    
    void printInfo() const override {
        std::cout << "Passport: " << getTitle() << ", ID: " << idNumber << "\n";
    }

    bool isClassified() const override {
        return true;
    }
};

class Contract : public Document {
private:
    int sum;

public:
    Contract(const char* name, int amount) : Document(name), sum(amount) {}

    void printInfo() const override {
        std::cout << "Contract: " << getTitle() << ", Sum: " << sum << "\n";
    }

    bool isClassified() const override {
        return false;
    }
};

int main() {
    unsigned int arr1[] = {1, 2, 3};
    unsigned int arr2[] = {3, 4, 5};
    
    TSet<unsigned int> set1;
    set1(arr1, 3);
    
    TSet<unsigned int> set2;
    set2(arr2, 3);
    
    TSet<unsigned int> set3 = set1 + set2;
    
    std::cout << "Set 1 <= Set 3: " << (set1 <= set3) << "\n";
    
    Passport p1("Ivanov Passport", 4567);
    Contract c1("Lease Agreement", 15000);
    
    TSet<Document*> docs;
    docs = docs + &p1;
    docs = docs + &c1;
    
    Document::printCount();

    return 0;
}