#include <stdlib.h>
#include <stdbool.h>
#include "BinaryTree.h"

void removeNode(BTreeNode* node, void (*removeMethod)(BTData data));
void removeTraversal(BTreeNode* bt, void (*task)(BTData node));

BTreeNode* makeTreeNode() {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BTData tGetData(BTreeNode* bt) { return bt->data; }

void tSetData(BTreeNode* node, BTData data) { node->data = data; }

void tAdd(BTreeNode* bt, BTData data, int (*comp)(BTData d1, BTData d2)) {
    if (comp(bt->data, data) >= 0) {
        if (getLeftSubTree(bt) == NULL) {
            BTreeNode* newNode = makeTreeNode();
            newNode->data = data;
            makeLeftSubTree(bt, newNode);
        } else {
            tAdd(getLeftSubTree(bt), data, comp);
        }
    } else {
        if (getRightSubTree(bt) == NULL) {
            BTreeNode* newNode = makeTreeNode();
            newNode->data = data;
            makeRightSubTree(bt, newNode);
        } else {
            tAdd(getRightSubTree(bt), data, comp);
        }
    }
}

BTreeNode* getLeftSubTree(BTreeNode* bt) { return bt->left; }

BTreeNode* getRightSubTree(BTreeNode* bt) { return bt->right; }

void makeLeftSubTree(BTreeNode* main, BTreeNode* sub) { main->left = sub; }

void makeRightSubTree(BTreeNode* main, BTreeNode* sub) { main->right = sub; }

void tTraversal(BTreeNode* node, void (*task)(BTData data)) {
    // 레벨 순회
    if (getRightSubTree(node) != NULL) {
        tTraversal(getRightSubTree(node), task);
    }
    task(tGetData(node));
    if (getLeftSubTree(node) != NULL) {
        tTraversal(getLeftSubTree(node), task);
    }
}

void tRemoveData(BTreeNode* bt, BTData data, void (*removeMethod)(BTData data), bool (*isSame)(BTData d1, BTData d2)) {
    if (isSame(tGetData(bt), data)) {
        removeTraversal(bt, removeMethod);
    } else {
        if (getLeftSubTree(bt) != NULL) {
            tRemoveData(getLeftSubTree(bt), data, removeMethod, isSame);
        }
        if (getRightSubTree(bt) != NULL) {
            tRemoveData(getRightSubTree(bt), data, removeMethod, isSame);
        }
    }
}

void tRemoveTree(BTreeNode* bt, void (*removeMethod)(BTData data)) {
    removeTraversal(bt, removeMethod);
}

void removeTraversal(BTreeNode* bt, void (*task)(BTData node)) {
    if (getLeftSubTree(bt) != NULL) {
        removeTraversal(getLeftSubTree(bt), task);
    }
    removeNode(bt, task);
    if (getRightSubTree(bt) != NULL) {
        removeTraversal(getRightSubTree(bt), task);
    }
}

void removeNode(BTreeNode* node, void (*removeMethod)(BTData data)) {
    removeMethod(tGetData(node));
    free(node);
}