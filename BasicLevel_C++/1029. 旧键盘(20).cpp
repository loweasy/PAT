#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
            ans += toupper(s1[i]);
    cout << ans;
    return 0;
}

//how to solve?
//遍历except input，对于所有的字符，hash记录 它出现与否
//遍历actual input，将对应的置位false，然后gg；
//如果不用hash 函数转换，直接使用map 会非常麻烦，这里决定直接用数组就行，不用unorder_map；
#include<iostream>
#include<string>
                                                                                //一般不超过80行宽；
using namespace std;

char map[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int hashfunc(char a) { //今天看的代码风格，大括号不换行，前面放一个空格比较ok；
    if (a >= 'a' && a <= 'z') return a - 'a';
    else if (a >= 'A' && a <= 'Z') return a-'A';
    else if (a >= 0 && a <= '9') return a-'0' + 26;
    else return 36;
}

// 我可真是sb  写了个按自定义的字典序 输出的程，csb！
int main(){
    bool hashtable[37] = {false};
    for (int i =0; i < 37; ++i)
    cout << hashtable[i];
    cout << endl;
    string except;
    string actual;
    cin >> except;
    cin >> actual;
    for (int i = 0, size = except.size(); i < size ; i++) { 
        int h = hashfunc(except[i]);
        hashtable[h] = true;
    }
        for (int i =0; i < 37; ++i)
    cout << hashtable[i];
    cout <<endl;
    for (int i = 0, size = actual.size(); i < size; i++) {
        int h = hashfunc(actual[i]);
        hashtable[h] = false;
    }
    for (int i =0; i < 37; ++i)
    cout << hashtable[i];
    for (int i = 0; i < 37; ++i) {
        if (hashtable[i] == true) {
            if (i < 26) cout << map[i];
            else if (i == 36) cout << '_';
            else cout << i-26;
        }
    }
    return 0;
}
