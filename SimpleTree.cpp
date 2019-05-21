//
// Created by lenzer on 21.05.2019.
//
#include <iostream>
#include <cstdlib>
#include <new>
#include "SimpleTree.h"

Container::~Container() { }

void SimpleTree::print(struct tree_elem* next) {
    std::cout << next->value << " ";
    if(next->left != NULL)
        print(next->left);

    if(next->right != NULL)
        print(next->right);
}

void SimpleTree::remove(struct tree_elem* next) {
    if(next->left != NULL)
        remove(next->left);
    if(next->right != NULL)
        remove(next->right);
    delete next;
}

SimpleTree::SimpleTree() { root = NULL; }

void SimpleTree::insert(int value) {
    if(root == NULL) {
        root = new struct tree_elem;
        root->parent = NULL;
        root->right = NULL;
        root->left = NULL;
        root->value = value;
        return;
    }

    tree_elem* contemporary = new struct tree_elem;
    contemporary->value = value;
    contemporary->left = NULL;
    contemporary->right = NULL;
    insert(root, value);
    delete contemporary;
}

void SimpleTree::insert(struct tree_elem* next, int value) {
    if(value < next->value) {
        if(next->left == NULL) {
            struct tree_elem* last = new struct tree_elem;
            next->left = last;
            last->value = value;
            last->parent = next;
            last->left = NULL;
            last->right = NULL;
        }
        else
            insert(next->left, value);
    }
    else {
        if(next->right == NULL) {
            struct tree_elem* last = new struct tree_elem;
            next->right = last;
            last->value = value;
            last->parent = next;
            last->left = NULL;
            last->right = NULL;
        }
        else
            insert(next->right, value);
    }
}

void SimpleTree::print() {
    print(root);
    std::cout << std::endl;
}

bool SimpleTree::exists(int value) {
    if(find(value) == NULL)
        return false;
    return true;
}

void SimpleTree::remove(int value) {
    struct tree_elem* elemToRemove = find(value);

    //for NULL POINTER
    if(elemToRemove == NULL) {
        std::cout << "not found" << std::endl;
        return;
    }

    //for root:
    if(elemToRemove->parent == NULL) {
        if(elemToRemove->right == NULL) {
            //only root
            if(elemToRemove->left == NULL) {
                delete elemToRemove;
                root = NULL;
                return;
            }

            else {
                root = elemToRemove->left;
                elemToRemove->left->parent = NULL;
            }
        }

        else {
            root = elemToRemove->right;
            root->parent = NULL;
            if(elemToRemove->left != NULL)
                elemToRemove->left->parent = find_left_NULL(root);
            find_left_NULL(root)->left = elemToRemove->left;
        }
    }

    else {
        //for left element
        if(elemToRemove->value < elemToRemove->parent->value) {

            if(elemToRemove->right == NULL) {
                //висячая вершина
                if(elemToRemove->left == NULL) {
                    elemToRemove->parent->left = NULL;
                    delete elemToRemove;
                    return;
                }

                else {
                    elemToRemove->left->parent = elemToRemove->parent;
                    elemToRemove->parent->left = elemToRemove->left;
                }

            }
            else {
                elemToRemove->parent->left = elemToRemove->right;
                elemToRemove->right->parent = elemToRemove->parent;
                if(elemToRemove->left != NULL)
                    elemToRemove->left->parent = find_left_NULL(elemToRemove->right);
                find_left_NULL(elemToRemove->right)->left = elemToRemove->left;
            }
        }


            //for right element
        else {
            if(elemToRemove->left == NULL) {
                //висячая вершина
                if(elemToRemove->right == NULL) {
                    elemToRemove->parent->right = NULL;
                    delete elemToRemove;
                    return;
                } else {
                    elemToRemove->right->parent = elemToRemove->parent;
                    elemToRemove->parent->right = elemToRemove->right;
                }
            } else {
                elemToRemove->parent->right = elemToRemove->left;
                elemToRemove->left->parent = elemToRemove->parent;
                if(elemToRemove->right != NULL)
                    elemToRemove->right->parent = find_right_NULL(elemToRemove->left);
                find_right_NULL(elemToRemove->left)->right = elemToRemove->right;
            }
        }
    }
    delete elemToRemove;
}

SimpleTree::~SimpleTree() {
    if(root == NULL)
        return;
    remove(root);
}