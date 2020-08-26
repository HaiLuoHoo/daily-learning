using namespace std;
#include<iostream>
#include<stack>
#include<cstring>
#define MAX 20
bool matching(char exp[], int length) {
	stack<char> bra;
	for (int i = 0; i < length; i++) {
		if (exp[i] == ')') {
			if (bra.top() == '(') {
				bra.pop();
				continue;
			}
			return false;
		}
		if (exp[i] == ']') {
			if (bra.top() == '[') {
				bra.pop();
				continue;
			}
			return false;
		}
		if (exp[i] == '}') {
			if (bra.top() == '{') {
				bra.pop();
				continue;
			}
			return false;
		}
		bra.push(exp[i]);
	}
	return bra.empty();
}
int main() {
	int length;
	bool flag;
	char exp[MAX];
	cout << "ÇëÊäÈëÀ¨ºÅ´®£º";
	cin.getline(exp, MAX - 1);
	length = strlen(exp);
	flag = matching(exp, length);
	if (flag) {
		cout << "ÄúÊäÈëµÄÀ¨ºÅ´®Æ¥Åä" << endl;
	}
	else {
		cout << "ÄúÊäÈëµÄÀ¨ºÅ´®²»Æ¥Åä" << endl;
	}
}