#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    string word;
    cout << "введите искомое слово: ";
    cin >> word;
    
    string text;
    cout << "введите текст: ";
    cin.get(); 
    getline(cin, text);

    for (int i = 0; i < word.length(); i++) {
        word[i] = tolower((unsigned char)word[i]);
    }
    
    string lower_text = text;
    for (int i = 0; i < lower_text.length(); i++) {
        lower_text[i] = tolower((unsigned char)lower_text[i]);
    }

    int count = 0;
    int pos = 0;

    while (lower_text.find(word, pos) != -1) {
        pos = lower_text.find(word, pos);
        
        bool start_ok = false;
        if (pos == 0) {
            start_ok = true;
        } else if (lower_text[pos - 1] == ' ') {
            start_ok = true;
        }
        
        bool end_ok = false;
        int end_pos = pos + word.length();
        
        if (end_pos == lower_text.length()) {
            end_ok = true;
        } else if (lower_text[end_pos] == ' ' || lower_text[end_pos] == '.' || lower_text[end_pos] == ',') {
            end_ok = true; 
        }
        
        if (start_ok == true && end_ok == true) {
            count = count + 1;
        }
        
        pos = pos + word.length(); 
    }

    cout << "слово встречается " << count << " раз." << endl;

    return 0;
}