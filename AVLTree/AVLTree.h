//
//  AVLTree.h
//  AVLTree
//
//  Self Balancing Tree | Binary Search Tree
//
//  Created by Jose Saldivar on 4/11/19.
//  Copyright © 2019 Jose Javier Saldivar. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

using namespace std;

class AVLTree
{
private:        //private struct
    struct Node
    {
        int value;
        Node *left, *right;
    };
    Node *root;
    
public:     //inline implementations
    
    AVLTree ()
    {   root = nullptr; }
    
    ~AVLTree ()
    {   clear ();  }
    
    void clear ()
    {   clear (root);   }
    
    void append (int v)
    {   append (root, v);   }
    
    void remove (int v)
    {   remove (root, v);   }
    
    bool find (int v)
    {   return find (root, v);  }
    
    void print ()
    {   print (root);   }
    
    bool isEmpty ()
    {   if (root == nullptr)
        return true;
    else
        return false;
    }
    bool isFull ()
    {   Node *d = new Node;
        
        if (d)
        {
            delete d;
            return false;
        }
        delete d;
        return true;
    }
    
private:    //private function definitions, private needs to be redeclared here to make sure functions not public
    void clear (Node *&r);   //reference to the root pointer
    int height (Node *r);
    
    void rotateRight (Node *&r);
    void rotateLeft (Node *&r);
    void rotateRightLeft (Node *&r);
    void rotateLeftRight (Node *&r);
    
    int difference (Node *r);
    void balance (Node *&r);
    void append (Node *&r, int v);  //use balance
    void remove (Node *&r, int v);  //use balance
    
    bool find (Node *&r, int v);
    void print (Node *r);
};

//PRIVATE DEFINITIONS
void AVLTree :: clear (Node *&r)
{
    if (r != nullptr)
    {
        clear (r -> right);
        clear (r -> left);
        delete r;
        r = nullptr;
    }
}

int AVLTree :: height (Node *r)
{
    if (r == nullptr)
        return 0;
    else
    {
        int L = height (r -> left);
        int R = height (r -> right);
        // ^runs recursion, going shortest path down the tree counting the levels (LEFT & RIGHT)
        if (L > R)
            return L + 1;
        else
            return R + 1;
        // ^if left is bigger then right or vice versa it counts +1 because only one possible
        // level can be bigger then the other side do to running (RL, RR, RRL, RLR)
    }
}
void AVLTree :: rotateRight (Node *&r)
{
    Node *p = r -> left;
    r -> left = p -> right;
    p -> right = r;         // p will be ROOT so saying OLD ROOT is now p's right
    r = p;                  // updating so that the root is now *p's left
}

void AVLTree :: rotateLeft (Node *&r)
{
    Node *p = r -> right;
    r -> right = p -> left;
    p -> left = r;
    r = p;
}

void AVLTree :: rotateRightLeft (Node *&r)
{
    rotateRight (r -> right);
    rotateLeft (r);
}

void AVLTree :: rotateLeftRight (Node *&r)
{
    rotateLeft (r -> left);
    rotateRight (r);
}

int AVLTree :: difference (Node *r)
{
    int bf = height (r -> right) - height (r -> left);
    return bf;
    // (HL - HR) should always be in range of {-1, 0, 1}
    // if not then thats when the ROTATING happens
}

void AVLTree :: balance (Node *&r)
{
    if (difference (r) == -2)
    {
        if (difference (r -> left) == -1)
            rotateRight (r);
        else
            rotateLeftRight (r);
    }
    else if (difference (r) == 2)
    {
        if (difference (r -> right) == 1)
            rotateLeft (r);
        else
            rotateRightLeft (r);
    }
}

void AVLTree :: append (Node *&r, int v)
{
    if (isFull () )
        throw ("Error, full AVL Tree, can no longer append.\n");
    
    if (r == nullptr)
    {
        r = new Node;
        r -> value = v;
        r -> right = r -> left = nullptr;
    }
    else if (v < r -> value)
    {
        append (r -> left, v);
        balance (r);    //balances each subtree / overall tree as needed when traveling recursively though the tree
    }
    else
    {
        append (r -> right, v);
        balance (r);    //balances each subtree / overall tree as needed when traveling recursively though the tree, balances every append while traversing tree
    }
}

void AVLTree :: remove (Node *&r, int v)
{
    if (isEmpty () )
        throw ("Error, empty AVL Tree, nothing to remove.\n");
  
    if (r == nullptr)
    {
        cout << "Value not found to be removed.\n";
        return;
    }
    else if (v < r -> value)
        remove (r -> left, v);
    else if (v > r -> value)
        remove (r -> right, v);
    else
    {
        if (r -> left == nullptr && r -> right == nullptr)  //no children at remove node
        {
            delete r;
            r = nullptr;
        }
        else if (r -> left != nullptr && r -> right == nullptr) //left child at remove node
        {
            Node *p = r;
            r = r -> left;
            delete p;
        }
        else if (r -> left == nullptr && r -> right != nullptr) //right child at remove node
        {
            Node *p = r;
            r = r -> right;
            delete p;
        }
        else                //two children at remove node
        {
            Node *p = r -> right;
            while (p -> left != nullptr)
                p = p -> left;
            
            p -> left = r -> left;
            p = r;
            r = r -> right;
            delete p;
        }
    }
    
    if (isEmpty () )    //no need to balance an empty tree
        return;
    
    balance (root);     //balance entire tree after removing a node, shouldn't need too much arranging as tree is already balanced on every append
}

bool AVLTree :: find (Node *&r, int v)
{
    if (isEmpty () )
        cout << "Error, empty AVL Tree, nothing to find.\n";
        //throw ("Error, empty AVL Tree, nothing to find.\n");
    
    if (r == nullptr)
        return false;
    else if (r -> value == v)
        return true;
    else
        return find (r -> left, v) + find (r -> right, v); //search both sides of the tree with recursive formula
    
    return false;
}

void AVLTree :: print (Node *r)   //inorder traversal
{
    if (isEmpty () )
        throw ("Error, empty AVL Tree, nothing to print.\n");
    if (r)
    {
        print (r -> left);
        cout << r -> value << "\t";
        print (r -> right);
    }
}


#endif /* AVLTree_h */
