//infix to postfix conversion] 
//develope by me
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int precedence(char c) //to check the precedence of operator
{
if(c=='+' || c=='-')
{
return 1;
}else if(c=='*' || c=='/')
{
return 2;
}else if(c=='^')
{
return 3;
}else
{
return 0;
}
}
bool isOperator(char d)
{
return (d=='+' || d=='-' || d=='*' || d=='/' || d=='^');
}
string infixToPostfix(string ex)
{
int i;
string postfix="";
stack<char> s;
for(i=0;i<ex.length();i++)
{
char m=ex[i];
if(isalnum(m))
{
postfix+=m;
}else if(isOperator(m))
{
while(!s.empty() && precedence(s.top())>=precedence(m))
{
postfix+=s.top();
s.pop();
}
s.push(m);
}else if(m=='(')
{
s.push(m);
}else if(m==')')
{
while(!s.empty() && s.top()!='(')
{
postfix+=s.top();
s.pop();
}
s.pop();
}
}
while(!s.empty())
{
postfix+=s.top();
s.pop();
}
return postfix;
}
int main()
{
string infix,post;
cout<<"Enter infix expression:";
cin>>infix;
post=infixToPostfix(infix);
cout<<"postfix="<<post<<endl;
return 0;
}
