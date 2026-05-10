#include <iostream>

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
    Passport p1("Ivanov Passport", 4567);
    Contract c1("Lease Agreement", 15000);
    
    Document* docs[2];
    docs[0] = &p1;
    docs[1] = &c1;
    
    for (int i = 0; i < 2; ++i) {
        docs[i]->printInfo();
        std::cout << "Is classified: " << docs[i]->isClassified() << "\n";
    }

    Document::printCount();

    return 0;
}