#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tnode {
    int key;
    struct tnode* left;
    struct tnode* right;
};

int random()
{
    int p;
    p = rand() % 10000;
    return p;
}

void freemem(tnode* tree) {
    if (tree != NULL) {
        freemem(tree->left);
        freemem(tree->right);
        tree->left = NULL;
        tree->right = NULL;
    }
}

struct tnode* addtree(struct tnode* p, int w) {
    int cond = 1;
    int nl;
    int nr;
    nl = w / 2;
    nr = w - nl - 1;

    if (p == NULL) {
        p = (struct tnode*)malloc(sizeof(struct tnode));
        int y = random();
        p->key = y;
        p->left = p->right = NULL;
    }
    else
    {
        p->left = addtree(p->left, nl);
        p->right = addtree(p->right, nr);
    }

    return p;
}

void treeprint(struct tnode* root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                treeprint(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                treeprint(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}
//Z-2===========================================
int poisk(tnode* root, int value)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->key == value)
        return true;
    tnode* cur = root;
    while (cur->key != value)
    {
        if (value < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
        if (cur == NULL)
            return false;
    }
}

int main()
{
    //Z-1=======================================
    struct tnode* root;
    root = NULL;
    for (int i = 0; i < 50; i++)
    {
        freemem(root);
        for (int x = 0; x < 3; x++)
        {
            root = addtree(root, 10000);
        }
        treeprint(root);
        printf("\n");

    }
    //Z-2================================================
    printf("%s \n", poisk(root, 142) ? "true" : "false");
    printf("%s \n", poisk(root, 41) ? "true" : "false");
    return 0;
}
