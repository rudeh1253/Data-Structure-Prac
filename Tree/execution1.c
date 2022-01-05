#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "BinaryTree.h"

void removeMethod(BTData data);
bool isSame(BTData, BTData);
int comp(BTData, BTData);
void printNode(BTData);

int main() {
    BTreeNode* root = makeTreeNode();
    tSetData(root, 15);

    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        tAdd(root, rand() % 1000, comp);
    }

    tTraversal(root, printNode);
    printf("\n");

    return 0;
}

bool isSame(BTData d1, BTData d2) { return d1 == d2; }

void removeMethod(BTData data) { }

int comp(BTData d1, BTData d2) {
    if (d1 < d2) {
        
        return -1;
    } else if (d1 == d2) {

        return 0;
    } else {
        
        return 1;
    }
}

void printNode(BTData data) {
    printf("%d  ", data);
}