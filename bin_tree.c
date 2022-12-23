// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *left;
//     struct node *right;
// };
// struct node *root = NULL;
// struct node *create()
// {
//     int num;
//     struct node *newnode;
//     newnode = (struct node *)malloc(sizeof(struct node));
//     printf("Enter num(-1 for no node ) :");
//     scanf("%d", &num);
//     if (num == -1)
//         return NULL;
//     newnode->data = num;
//     printf("Enter left child of %d\n", num);
//     newnode->left = create(); // recursion
//     printf("Enter right child of %d\n", num);
//     newnode->right = create();//recursion
//     return newnode;
// }
// void Preorder(struct node *root)
// {
//     if (root == NULL)
//         return;
//     printf("->%d", root->data);
//     Preorder(root->left);
//     Preorder(root->right);
// }
// int main()
// {
//     root = create();
//     Preorder(root);
//     return 0;
// }

//                                               BINARY TREE

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *left;
//     struct node *right;
// };

// struct node *createNode(int data)
// {
//     struct node *n;
//     n = (struct node *)malloc(sizeof(struct node));
//     n->data = data;
//     n->left = NULL;
//     n->right = NULL;
//     return n;
// }

// void preorder(struct node *root)
// {
//     if (root != NULL)
//     {
//         printf("%d ", root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// void postorder(struct node *root)
// {
//     if (root != NULL)
//     {
//         postorder(root->left);
//         postorder(root->right);
//         printf("%d ", root->data);
//     }
// }

// void inorder(struct node *root)
// {
//     if (root != NULL)
//     {
//         inorder(root->left);
//         printf("%d ", root->data);
//         inorder(root->right);
//     }
// }
// int main()
// {
//     /*
//     // root node
//     struct node *p;
//     p = (struct node *)malloc(sizeof(struct node));
//     p->data=2;
//     p->left = NULL;
//     p->right = NULL;

//     // first node
//     struct node *p1;
//     p1 = (struct node *)malloc(sizeof(struct node));
//     p1->data=2;
//     p1->left = NULL;
//     p1->right = NULL;

//     // second node
//     struct node *p2;
//     p2 = (struct node *)malloc(sizeof(struct node));
//     p2->data=2;
//     p2->left = NULL;
//     p2->right = NULL;

//     p->left=p1;
//     p->right=p2;
//     */

//     struct node *p = createNode(4);
//     struct node *p1 = createNode(1);
//     struct node *p2 = createNode(6);
//     struct node *p3 = createNode(5);
//     struct node *p4 = createNode(2);

//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p1->right = p4;

//     // preorder(p);
//     // postorder(p);
//     inorder(p);
//     return 0;
// }

//                                            BINARY SEARCH TREE

#include <stdio.h>
#include <stdlib.h>
int a[100], i = 0;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
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

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        // a[i] = root->data;
        // i++;
        inorder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1; // means tree is BST
    }
}

struct node* search(struct node *root, int key)
{
    if(root==NULL) return NULL;
    if(root->data==key) return root;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
    /*
    int f = 0;
    if (key == root->data)
    {
        f = 1;
        return f;
    }
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
    return 0;
    */
}
int main()
{
    /*
    // root node
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data=2;
    p->left = NULL;
    p->right = NULL;

    // first node
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data=2;
    p1->left = NULL;
    p1->right = NULL;

    // second node
    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data=2;
    p2->left = NULL;
    p2->right = NULL;


    p->left=p1;
    p->right=p2;
    */
    int j;
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preorder(p);
    // postorder(p);
    inorder(p);
    printf("\n");
    // printf("%d ",isBST(p));
    //  for (j = 0; j < i; j++)
    //  {
    //      printf("%d ", a[j]);
    //  }
    return 0;
}
