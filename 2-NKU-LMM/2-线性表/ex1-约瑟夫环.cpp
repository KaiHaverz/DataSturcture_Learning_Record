#include<iostream>
using namespace std;

struct ChainNode
{
    int data;
    ChainNode* next;
};

void BuildList(ChainNode* L, int n)
{
    ChainNode* p;
    p = L;
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        ChainNode* l = new ChainNode;
        l->data = num++;
        l->next = NULL;
        p->next = l;
        p = l;
    }
    p->next = L->next;
}

void SelectandDelete(int n, int k, ChainNode* L)
{
    int flag = 1;
    ChainNode* q = L->next;
    for (int i = 1; i <= n; i++)
    {

        while (flag != k - 1)
        {
            q = q->next;
            flag++;
        }
        flag = 1;
        cout << q->next->data;

        if (q->next->next != q || q->next != q)
        {
            cout << "->";
            ChainNode* b = q->next;
            q->next = b->next;
            delete b;
            q = q->next;
        }
    }
}


int main()
{
    ChainNode* L = new ChainNode;
    L->next = NULL;
    int n, k;
    cin >> n >> k;
    BuildList(L, n);
    SelectandDelete(n, k, L);

    return 0;
}



