#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_

#include <stdbool.h>

typedef int BTData;

typedef struct _binary_tree_node {
    BTData data;
    struct _binary_tree_node* left;
    struct _binary_tree_node* right;
} BTreeNode;

BTreeNode* makeTreeNode();
BTData tGetData(BTreeNode* bt);
void tSetData(BTreeNode*, BTData);
void tAdd(BTreeNode* bt, BTData data, int (*comp)(BTData d1, BTData d2));

BTreeNode* getLeftSubTree(BTreeNode* bt);
BTreeNode* getRightSubTree(BTreeNode* bt);

void makeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void makeRightSubTree(BTreeNode* main, BTreeNode* sub);

void tTraversal(BTreeNode* node, void (*task)(BTData data));
void tRemoveData(BTreeNode* bt, BTData data, void (*removeMethod)(BTData data), bool (*isSame)(BTData d1, BTData d2));
void tRemoveTree(BTreeNode* bt, void (*removeMethod)(BTData data));

#endif