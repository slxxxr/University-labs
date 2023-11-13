#include<iostream>
#include<random>

using namespace std;

struct node
{
    int key, count;
    struct node* left, * right;
};

struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->count = 1;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key){

    if (node == NULL) {
        return newNode(key);
    }

    if (key == node->key) {
        node->count++;
    }
    else if (key < node->key){
        node->left = insert(node->left, key);
    }
    else if (key > node->key){
        node->right = insert(node->right, key);
    }

    return node;
}

void print(struct node* root)
{
    if (root != NULL)
    {
        print(root->left);
        for (int i = 0; i < root->count; i++) cout << root->key << " ";
        print(root->right);
    }
}

int main()
{
    struct node* root = NULL;

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;

        if (i == 0) {
            root = insert(root, x);
        }
        else {
            insert(root, x);
        }

        print(root);
        cout << endl;
    }
 

    return 0;
}
