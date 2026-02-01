#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
    int data;
    struct tnode * left;
    struct tnode * right;
}tnode;

tnode * talloc(int data){

    tnode* p = malloc(sizeof(*p));

    p->data = data;
    p->left = NULL;
    p->right = NULL;
    
    return p;
}
tnode * addnode(tnode* root, int data){

    if(root == NULL){
        root = talloc(data);
    }else if(data < root->data){
        root->left = addnode(root->left, data);
    }else{
        root->right = addnode(root->right, data);
    }
    return root;
}

void preorder(tnode* root){

    if(root == NULL) return;
    else printf("%d, ", root->data);

    preorder(root->left);
    preorder(root->right);
}
void inorder(tnode* root){
    if (root == NULL) return;

    inorder(root->left);
    printf("%d, ", root->data);
    inorder(root->right);

}

void postorder(tnode* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d, ", root->data);
}

int deltree(tnode* root){
    if(root == NULL) return 0;

    int left_count = deltree(root->left);
    int right_count = deltree(root->right);
    free(root);
    return left_count + right_count+1;
}

int main(){
    tnode *a = talloc(10);
    a = addnode(a, 3);
    a = addnode(a, 12);
    a = addnode(a, 1);
    a = addnode(a, 7);
    a = addnode(a, 13);

    preorder(a);
    inorder(a);
    postorder(a);
    deltree(a);

    return 0;


}
