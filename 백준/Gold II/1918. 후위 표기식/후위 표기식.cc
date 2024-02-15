#include <iostream>
#include <stack>
using namespace std;

// 피연산자는 바로 수식으로 옮긴다
// 연산자라면
	// 스택에서 자신과 우선순위가 같거나 높은 연산자를 모두 꺼내 수식으로 옮긴다
	// 해당 연산자는 스택에 추가한다
	// 여는 괄호 연산자도 스택에 추가한다 (여는 괄호 연산자는 우선순위가 가장 낮다고 간주)
		// 닫는 괄호 연산자를 만나면, 스택에서 여는 괄호 연산자가 나올 때까지 모든 연산자를 빼서 수식으로 옮긴다.

// 인자로 받은 연산자의 우선순위를 숫자로 반환
int getOpPrec(char op)
{
	switch (op)
	{
	case '*': case '/': // 가장 높은 우선순위
		return 3;
	case '+': case '-': // 중간 우선순위
		return 2;
	case '(':
		return 1; // 가장 낮은 우선순위
	}
	return -1; // 등록되지 않은 연산자
}

// 인자로 받은 연산자의 우선순위 비교
// op1이 더 높으면 1, op2가 더 높거나 같으면 2 반환
int whoHasHigherPrec(char op1, char op2)
{
	int op1_prec = getOpPrec(op1);
	int op2_prec = getOpPrec(op2);
	if (getOpPrec(op1) > getOpPrec(op2))
		return 1;
	else
		return 2;
}

int main()
{
	string infix_exp; // 입력으로 받는 중위 표기식
	cin >> infix_exp;

	stack<char> S;
	string post_exp; // 결과로 제출할 후위 표기식
	for(int i = 0; i < infix_exp.length(); i++)
	{
		char token = infix_exp[i];
		if ('A' <= token && token <= 'Z') // 피연산자라면
		{
			post_exp += token; // 바로 수식으로 옮긴다.
		}
		else if (token == '(') // 여는 괄호 연산자라면
		{
			S.push(token); // 스택에 추가
		}
		else if (token == ')') // 닫는 괄호 연산자라면
		{
			while(!S.empty() && S.top() != '(') // 여는 괄호 연산자를 만날 때까지
			{
				post_exp += S.top(); // 모든 연산자를 수식으로 옮기기
				S.pop();
			}
			S.pop();
		}
		else // 일반 연산자라면
		{
			// 스택에서 우선순위가 같거나 높은 연산자를 수식으로 옮기기
			while(!S.empty() && whoHasHigherPrec(token, S.top()) == 2)
			{
				post_exp += S.top();
				S.pop();
			}
			S.push(token);
		}
	}

	while(!S.empty())
	{
		post_exp += S.top();
		S.pop();
	}

	cout << post_exp << '\n';
	return 0;
}
