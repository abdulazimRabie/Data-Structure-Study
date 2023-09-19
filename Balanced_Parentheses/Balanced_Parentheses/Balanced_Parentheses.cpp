
#include <iostream>
#include <stack>
using namespace std;

// method to find out pairing od parentheses
bool arePaired(char openChar , char closeChar) {
	if (openChar == '(' && closeChar == ')') return true;
	else if (openChar == '{' && closeChar == '}') return true;
	else if (openChar == '[' && closeChar == ']') return true;
	else return false;
}

bool isBalanced(string exp) {
	if (exp.length() == 0) return false;

	stack<char> barentheses;
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') 
			barentheses.push(exp[i]);

		else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
			if ( barentheses.empty() || !arePaired(barentheses.top(), exp[i]) ) 
				return false;
			barentheses.pop();
		}
	}
	return barentheses.empty();
}

int main()
{
	for (;;) {
		string exp;
		cout << "an expression : ";
		cin >> exp;
		if (isBalanced(exp) == 1) cout << "is balanced \n";
		else cout << "not balanced \n";
	}
}
