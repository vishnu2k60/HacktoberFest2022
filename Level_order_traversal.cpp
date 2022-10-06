#include <bits/stdc++.h>

using namespace std;

struct Tree
{
    int data;
    struct Tree *left, *right;

    Tree(int k)
    {
        data = k;
        left = NULL;
        right = NULL;
    }
};

Tree *createTree()
{
    Tree *root;
    int a;
    printf("Enter the Value:\t");
    scanf("%d", &a);
    if (a == -1)
        return NULL;

    root = new Tree(a);
    printf("Enter left node of %d\n", a);
    root->left = createTree();

    printf("Enter right node of %d\n", a);
    root->right = createTree();
    return root;
}

void print(struct Tree *root)
{
    std::queue<Tree *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Tree *cur = q.front();
        if (cur == NULL)
        {
            q.pop();
            if (q.empty())
                return;
            q.push(NULL);
            cout << endl;
            cur = q.front();
        }
        printf("%d ", cur->data);
        q.pop();

        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
}

int main()
{
    Tree *root;
    root = createTree();
    print(root);
    return 0;
}