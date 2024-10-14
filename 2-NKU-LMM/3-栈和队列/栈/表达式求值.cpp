#include <iostream>
#include<cmath>
#include<iomanip>

using namespace std;

template<class T>
class stack
{
public:
    T s[50];
    int top;
public:
    T nexttop();
    T gettop();
    void pop();
    void push(T ch);
    stack();
    bool empty();
};
template<class T>
T stack<T>::nexttop()
{
    return s[top - 2];
}
template<class T>
T stack<T>::gettop()
{
    return s[top - 1];
}
template<class T>
void stack<T>::push(T ch)
{
    s[top++] = ch;
}
template<class T>
void stack<T>::pop()
{
    s[--top] = NULL;
}
template<class T>
stack<T>::stack()
{
    top = 0;
}
template<class T>
bool stack<T>::empty()
{
    return top == 0;
}
int charge(char ch)
{
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/' || ch == '%') return 2;
    else if (ch == '+' || ch == '-')return 1;
    else if (ch == '(') return 0;
    else return -1;
}
template<class T>
void change(stack<T>& s2, stack<T>& t, string& s1, int n, bool& flag)
{
    for (int i = 0; i < n; i++)
    {
        if (s1[i] >= '0'&&s1[i] <= '9')
        {
            while ((s1[i] >= '0'&&s1[i] <= '9') || s1[i] == '.')
            {
                s2.push(s1[i++]);
            }
            i--;
            s2.push(' ');
        }
        else if (s1[i] == '(')
            t.push(s1[i]);
        else if (s1[i] == ')')
        {
            while (t.gettop() != '(' && !t.empty())
            {
                s2.push(t.gettop());
                t.pop();
            }
            if (t.empty())
            {
                flag = 1;
                return;
            }
            else
                t.pop();
        }
        else if (charge(s1[i]) > 0)
        {
            if (charge(s1[i]) > charge(t.gettop()) || t.empty()|| charge(s1[i])==3)
            {
                t.push(s1[i]);
            }
            else
            {
                while (charge(s1[i]) <= charge(t.gettop()) || t.gettop() == '(')
                {
                    s2.push(t.gettop());
                    t.pop();
                }
                t.push(s1[i]);
            }
        }
        else if (charge(s1[i]) < 0)
        {
            flag = 1;
            return;
        }
    }
    while (!t.empty())
    {
        s2.push(t.gettop());
        t.pop();
    }
    for (int i = 0; i < s2.top; i++)
    {
        // cout << s2.s[i];
        if (s2.s[i] == '(')
        {
            flag = 1;
            return;
        }
    }
    //cout << endl;
}
template<class T>
void count(stack<T>& s2,bool& flag)
{
    if (flag)
        return;
    stack<double> num;
    for (int i = 0; i < s2.top; i++)
    {
        if (s2.s[i] >= '0' && s2.s[i] <= '9')
        {
            double sum = s2.s[i] - '0';
            int n = 0;
            while (1)
            {
                if (s2.s[i + 1] >= '0' && s2.s[i + 1] <= '9')
                    sum = sum * 10 + s2.s[++i]-'0';
                else if (s2.s[i + 1] == '.')
                {
                    i++;
                    while (1)
                        if (s2.s[i + 1] >= '0' && s2.s[i + 1] <= '9')
                        {
                            n++;
                            i++;
                            double m = s2.s[i] - '0';
                            for (int j = 0; j < n; j++)
                                m *= 0.1;
                            sum += m;
                        }
                        else if (s2.s[i + 1] == ' ')
                            break;
                    break;
                }
                else if (s2.s[i + 1] == ' ')
                    break;
            }
            num.push(sum);
        }
        else if (s2.s[i] == ' ')
            continue;
        else if (charge(s2.s[i] > 0) && num.top == 1)
        {
            flag = 1;
            return;
        }
        else if (s2.s[i] == '+')
        {
            double n = num.gettop() + num.nexttop();
            num.pop();
            num.pop();
            num.push(n);
        }
        else if (s2.s[i] == '*')
        {
            double n = num.gettop() * num.nexttop();
            num.pop();
            num.pop();
            num.push(n);
        }
        else if (s2.s[i] == '-')
        {
            double n = num.nexttop() - num.gettop();
            num.pop();
            num.pop();
            num.push(n);
        }
        else if (s2.s[i] == '/')
        {
            double n = num.nexttop() / num.gettop();
            num.pop();
            num.pop();
            num.push(n);
        }
        else if (s2.s[i] == '%')
        {
            int n =((int)num.nexttop())%((int) num.gettop());
            num.pop();
            num.pop();
            num.push((double)n);
        }
        else if (s2.s[i] == '^')
        {
            double n = pow(num.nexttop(), num.gettop());
            num.pop();
            num.pop();
            num.push(n);
        }
    }
    if (num.top == 1)
        cout << num.gettop();
    else
        flag = 1;
}
void m(string s)
{
    cout << fixed << setprecision(2);
    bool falg = 0;
    string s1=s;
    int n = -1;
    while (s1[++n] != NULL);
    stack<char> s2;
    stack<char> t;
    change(s2, t, s1, n, falg);
    count(s2, falg);
    if (falg)
    {
        cout << "ERROR IN INFIX NOTATION" << endl;
        return;
    }
}


int main() {
    string s1;
    while (cin >> s1)
        m(s1);
    return 0;
}