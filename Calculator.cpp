#include<iostream>
#include<conio.h>
#include<vector>
#include<stack>
using namespace std;
      int prec(char);
      void infixToPostfix(string);
     void posfixEval(string);
int main(){
    int choice;
    int b=(int)'2'-48;

cout<<"CALCULATOR\n";
cout<<"Press 1 for Addition\nPress 2 for subtraction\nPress 3 for multiplication\nPress 4 for division\nPress 5 for square\npress 6 for cube\npress 7 for factoial\npress 8 for power\nPress 9 for Arithmatic expression\npress 0 to exit\n";
cin>>choice;
switch (choice)
{
case 1:{
    cout<<"ENTER THE NUMBERS THAT YOU WANT TO ADD\N PRESS X FOR GETTING THE ANSWER\n";
    vector<int> v;
    char k;
    int sum=0;
    while(true)

    {
         cin>>k;
         if(k=='x')
            break;
        int ik=(int)k-48;

    v.push_back(ik);
    }
    for(auto &elem : v)
    {
        sum=sum+elem;
    }
    cout<<sum;
    }
case 2: {
     cout<<"ENTER THE NUMBERS THAT YOU WANT TO Subtract\N PRESS X FOR GETTING THE ANSWER";
    vector<int> v;
    char k;
    int ans;
    while(true)

    {
         cin>>k;
         if(k=='x')
            break;
        int ik=(int)k-48;

    v.push_back(ik);
    }
    ans=2*v.at(0);
    for(auto &elem : v)
    {
        ans=ans-elem;
    }
    cout<<ans;


}
case 3:{
     cout<<"ENTER THE NUMBERS THAT YOU WANT TO MULTIPLY\N PRESS X FOR GETTING THE ANSWER";
    vector<int> v;
    char k;
    int ans=1;;
    while(true)

    {
         cin>>k;
         if(k=='x')
            break;
        int ik=(int)k-48;

    v.push_back(ik);
    }

    for(auto &elem : v)
    {
        ans=ans*elem;
    }
    cout<<ans;
}
    break;
case 4:{
    int a,b;
    cout<<"Enter the dividend\n";
    cin>>a;
    cout<<"Enter the divisor\n";
    cin>>b;
    cout<<a/b;
    break;
}
case 5:
 {

    int a;
    cout<<"enter the number for getting its square";
    cin>>a;
    cout<<a*a;
    break;
}
case 6:
    int a;
    cout<<"enter the number for getting its cube";
    cin>>a;
    cout<<a*a*a;
    break;
case 7:
    {
        int a,k=1;
    cout<<"enter the number for getting its factorial";
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        k=k*i;
    }
    cout<<k;
    break;
    }

case 8:
    {
        int a,n;
    cout<<"enter the number";
    cin>>a;
    cout<<"enter the power";
    cin>>n;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*a;
    }
    cout<<ans;
    break;
    }


case 9:
    {

        string s;
        cout<<"ENTER THE EXPRESSION";
        cin>>s;
        infixToPostfix(s);
       // Function to return precedence of operators

    }
}
return 1;
}
//below two functions for infix to postfix
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// to postfix expression
void infixToPostfix(string s)
{

    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];


        // for operands
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;


        // for (
        else if (c == '(')
            st.push('(');

        //for )
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        //for operator
        else {
            while (!st.empty()&& prec(s[i]) <= prec(st.top())) {

                    result += st.top();
                    st.pop();


            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
    posfixEval(result);
}


///postfix evaluation

void posfixEval(std::string s){
    stack<int> astack;
    for(int i=0;i<=s.length()-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            astack.push(s[i]-48);
        }
        else{
            int op2=astack.top();
            astack.pop();
            int op1=astack.top();
            astack.pop();
            switch(s[i]){
            case '+':
            astack.push(op1+op2);
            break;
            case '-':
                astack.push(op1-op2);
            break;
                case '*':
                    astack.push(op1*op2);
            break;

                case '/':
                astack.push(op1/op2);
            break;
            }
        }

    }

cout<<astack.top();
}








