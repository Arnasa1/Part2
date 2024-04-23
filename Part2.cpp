#include <bits/stdc++.h>
using namespace std;

bool isValid(string s, int y, string path) {
    stack<pair<char, int>> st; 
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push({ch, i + 1});
        } else {
            if (!st.empty()) {
                char top = st.top().first;
                int pos = st.top().second;
                st.pop();
                if ((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    continue;
                } else {
                    cout << "Invalid bracket " << ch << " found at " << path << ":" << y << ":" << i + 1 << endl;
                    return false; 
                }
            } else {   
                cout << "Invalid bracket " << ch << " found at " << path << ":" << y << ":" << i + 1 << endl;
                return false;
            }   
        }
    }

    if (!st.empty()) {
        char extra = st.top().first;
        int pos = st.top().second;
        cout << "Invalid bracket " << extra << " found at " << path << ":" << y << ":" << pos << endl;
        return false;
    }
    
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <file_path>" << endl;
        return 1;
    }

    string path = argv[1];
    ifstream MyFile;
    MyFile.open(path);
    if (!MyFile) {
        cerr << "Unable to open file: " << path << endl;
        return 1;
    }

    string s;
    int y = 0;
    while(getline(MyFile, s)) {
        y++;
        isValid(s, y, path);
    }
    MyFile.close();
    return 0;
}  
