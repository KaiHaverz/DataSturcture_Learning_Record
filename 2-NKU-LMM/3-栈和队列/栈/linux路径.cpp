#include <iostream>
#include <string>
#include <stack>

using namespace std;

string simplifyPath(string path)
{
    stack<string> temp;

    int i = 0;
    while (i < path.size())
    {
        // 跳过连续的斜杠
        while (i < path.size() && path[i] == '/') {
            ++i;
        }

        // 读取一个完整的目录名称
        int j = i;
        while (j < path.size() && path[j] != '/') {
            ++j;
        }

        // 如果没有读取到目录名称，跳出循环
        if (i == j) {
            break;
        }

        string s = path.substr(i, j - i);

        if (s == ".")
        {
            // 忽略当前目录
        }
        else if (s == ".." && !temp.empty())
        {
            // 返回上一级目录
            temp.pop();
        }
        else if (s != "..")
        {
            // 添加目录到栈中
            temp.push("/" + s);
        }

        i = j; // 更新索引
    }

    if (temp.empty()) return "/";

    string res;
    while (!temp.empty())
    {
        res = temp.top() + res;
        temp.pop();
    }

    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << simplifyPath(s) << endl;

    return 0;
}