#include <iostream>
#include <cstdlib>
#include <new>

using namespace std;


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

Container::~Container() { }


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

public:
    SimpleTree()
    {
        root = NULL;
    }
    void insert(int value)
    {
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

    void insert(struct tree_elem* next, int value)
    {
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

    void print()
    {
        print(root);
        cout << endl;
    }

    void print(struct tree_elem* next)
    {
        cout << next->value << " ";
        if(next->left != NULL)
            print(next->left);
        if(next->right != NULL)
            print(next->right);
    }

    struct tree_elem* find(int value) { return find(value, root); }

    struct tree_elem* find(int value, struct tree_elem* next)
    {
        if(value == next->value)
            return next;
        if(value < next->value)
        {
            if(next->left != NULL)
                return find(value, next->left);
        }
        else
        {
            if(next->right != NULL)
                return find(value, next->right);
        }
        return NULL;
    }

    bool exists(int value)
    {
        if(find(value) == NULL)
            return false;
        return true;
    }

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

    void remove(int value)
    {
        struct tree_elem* elemToRemove = find(value);

        //for NULL POINTER
        if(elemToRemove == NULL) {
            cout << "not found" << endl;
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

            else{
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
            else{
                if(elemToRemove->left == NULL) {
                    //висячая вершина
                    if(elemToRemove->right == NULL) {
                        elemToRemove->parent->right = NULL;
                        delete elemToRemove;
                        return;
                    }

                    else {
                        elemToRemove->right->parent = elemToRemove->parent;
                        elemToRemove->parent->right = elemToRemove->right;
                    }
                }
                else {
                    elemToRemove->parent->right = elemToRemove->left;
                    elemToRemove->left->parent = elemToRemove->parent;
                    if(elemToRemove->right != NULL)
                        elemToRemove->right->parent = find_right_NULL(elemToRemove->left);
                    find_right_NULL(elemToRemove->left)->right = elemToRemove->right;
                }
            }
        }
        //check the use of memory
        delete elemToRemove;
    }
    void remove(struct tree_elem* next)
    {
        if(next->left != NULL)
            remove(next->left);
        if(next->right != NULL)
            remove(next->right);
        delete next;
    }
    ~SimpleTree()
    {
        if(root == NULL)
            return;
        remove(root);
    }
};


int main()
{
    Container* c = new SimpleTree();
    for(int i = 1; i < 10; i++)
        c->insert(i*i);
    printf("List after creation:\n");
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(25);
    cout << "List after deletion of the element:" << endl;
    c->print();
    delete c;
    return 0;
}
