#include <bits/stdc++.h>
using namespace std;
//void solve() {}
struct node
{
    int data;
    struct node *left, *right;
};
struct node *root = NULL;
void insert(int data)
{
    struct node *tempNode = (node *)malloc(sizeof(node));
    struct node *current;
    struct node *parent;
    tempNode->data = data;
    tempNode->left = NULL;
    tempNode->right = NULL;
    if (root == NULL)
        root = tempNode;
    else
    {
        current = root;
        parent = NULL;
        while (1)
        {
            parent = current;
            if (data < parent->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = tempNode;
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = tempNode;
                    return;
                }
            }
        }
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    //solve();
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }
    preorder(root);
    return 0;
}