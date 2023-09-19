#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;


bool isOperator(char character) {
	switch (character) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return true;
	}

	return false;
}

int priority(char _operator) {
	switch (_operator) {
	case '+':
	case '-':
		return 1;
		break;
	case '*':
	case '/':
		return 2;
		break;
	case '^':
		return 3;
		break;
	}

	return 0;	
}

string postfix(string exp) {
	if (exp.length() <= 0) return "";

	stack<char> s;
	string output = "";

	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == ' ') continue;

		else if (isdigit(exp[i]) || isalpha(exp[i])) {
			output += exp[i];
		}

		else if (exp[i] == '(') {
			s.push(exp[i]);
		}

		else if (exp[i] == ')') {
			while (s.top() != '(') {
				output += s.top();
				s.pop();
			}
			s.pop(); // remove '('
		}

		else if (isOperator(exp[i])) {
			while (!s.empty() && priority(s.top()) >= priority(exp[i])) {
				output += s.top();
				s.pop();
			}
			s.push(exp[i]);
		}

	}

	while (!s.empty()) {
		output += s.top();
		s.pop();
	}

	return output; 
}

int result(char _operator, int left, int right) {
	switch (_operator) {
	case '+':
		return left + right;
		break;
	case '-':
		return left - right;
		break;
	case '*':
		return left * right;
		break;
	case '/':
		return left / right;
		break;
	case '%':
		return (int) (left % right);
		break;
	}
}

int evalutePostfix(string exp) {
	if (exp.length() <= 0) {
		cout << "invalid expression" << endl;
		return 0;
	}

	stack<int> nums;
	int right, left;
	
	for (int i = 0; i < exp.length(); i++) {
		if (isdigit(exp[i])) 
			nums.push(exp[i] - '0'); // nums.push(stoi(exp[i]));
		else {
			right = nums.top();
			nums.pop();

			left = nums.top();
			nums.pop();

			nums.push(result(exp[i], left, right));
		}
	}

	return nums.top();


}

int main()
{
	
	/*string exp = "(3+2)+7/2*((7+3)*2)";
	cout << "to postfix : " << postfix(exp) << endl;*/

	/*string s = "382/+5-";
	cout << "evalute : " << evalutePostfix(s) << endl;*/

	/*string num = "13";
	float n = stoi(num);*/

	//cout << n + 10 << endl;

	cout << isdigit(50) << endl;
	cout << isdigit('4');
	queue<string> q;
 

}

