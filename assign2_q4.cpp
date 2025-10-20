#include<bits/stdc++.h>
using namespace std;
void swap_char(char &a,char&b) {
    char temp= a;
    a=b;
    b=temp;
}
string concate(string &a,string &b) {
    string c= a+ b;
    return c;
}
string rev_str(string a) {
    int size= a.size();
    for (int i=0;i<size/2;i++) {
        swap_char(a[i],a[size-i-1]);
    }
    return a;
}
string del_vowel(string a) {
    string b;
    string vowel="aeiouAEIOU";
    for (char ch:a) {
        if (vowel.find(ch) == string::npos) {
            b.push_back(ch);
        }
    }
    return b;
}
void sortStrings(vector<string>& arr) {
    sort(arr.begin(), arr.end());
}

char toLowercase(char c) {
    if (c >= 'A' && c <= 'Z') {
        c = c + 32;
    }
    return c;
}
int main() {
    string a="hello";
    string b="world";
    cout<<concate(a,b)<<endl;
    cout<<rev_str("hello")<<endl;
    cout<<del_vowel("jaspreetsingh");
}