//
// Created by lenzer on 21.05.2019.
//

#ifndef TREEC___SIMPLETREE_H
#define TREEC___SIMPLETREE_H

class Container {
public:
    // Виртуальные методы, будут реализованы далее
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;
    // Это потом заменим на перегруженный оператор <<
    virtual void print() = 0;

    // Виртуальный деструктор
    virtual ~Container();
};



class SimpleTree: public Container {
private:

    struct tree_elem {
        int depth;
        int value;
        struct tree_elem* parent;
        struct tree_elem* left;
        struct tree_elem* right;
    };

    tree_elem* root;

    void remove(struct tree_elem* next);

    struct tree_elem* find(int value) { return find(value, root); }

    void print(struct tree_elem* next);

    struct tree_elem* find_left_NULL(struct tree_elem* next) {
        if(next->left == NULL)
            return next;
        find_left_NULL(next->left);
    }

    struct tree_elem* find_right_NULL(struct tree_elem* next) {
        if(next->right == NULL)
            return next;
        find_right_NULL(next->right);
    }

    struct tree_elem* find(int value, struct tree_elem* next) {
        if(value == next->value)
            return next;
        if(value < next->value) {
            if(next->left != NULL)
                return find(value, next->left);
        }
        else {
            if(next->right != NULL)
                return find(value, next->right);
        }
        return NULL;
    }
public:
    SimpleTree();

    void insert(int value);

    void insert(struct tree_elem* next, int value);

    void print();

    bool exists(int value);

    void remove(int value);

    ~SimpleTree();
};
#endif //TREEC___SIMPLETREE_H
