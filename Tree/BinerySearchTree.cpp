class Node {

public:
    int data;
    Node* left, * right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {

public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* Insert(Node* pnode, int item) {
        if (pnode == NULL) {
            Node* newnode = new Node(item);
            pnode = newnode;
        }
        else if (pnode->data > item) {
            pnode->left =  Insert(pnode->left, item); // the recursive will make the pnode convert to the next element
        }
        else if (pnode->data < item) {
            pnode->right = Insert(pnode->right, item);
        }
        else {
            pnode->right = Insert(pnode->right, item);
        }

        return pnode;
    }

    void Insert(int item) {
        root = Insert(root, item);
    }

    void Preorder(Node* r) { //root left right
        if (r == NULL) { // if tree empty
            return;
        }
        cout << r->data<<" ";
        Preorder(r->left);
        Preorder(r->right);
    }

    void Inorder(Node* r) { //left->root->right
        if (r == NULL) {
            return;
        }
        Inorder(r->left);
        cout << r->data << " ";
        Inorder(r->right);
    }

    void Postorder(Node* r) { // left right root
        if (r == NULL) {
            return;
        }
        Postorder(r->left);
        Postorder(r->right);
        cout << r->data << " ";
    }

    Node* Search(Node* r, int key) {
        if (r == NULL) {
            return NULL;
        }
        else if (r->data == key) {
            return r;
        }
        else if (key <= r->data) {
            return Search(r->left, key);
        }
        else if (key > r->data) {
            return Search(r->right ,key);
        }

    }

    bool Search(int key) {
        Node* result = Search(root, key);

        if (result == NULL) {
            return false;
        }
        else {
            return true;
        }
    }


    Node* find_minimum(Node* r) {
        if (r == NULL) {
            return NULL;
        }
        else if (r->left == NULL) {
            return r;
        }
        else {
            return find_minimum(r->left);
        }
    }

    Node* find_maximum(Node* r) {
        if (r == NULL) {
            return NULL;
        }
        else if (r->right == NULL) {
            return r;
        }
        else {
            return find_maximum(r->right);
        }
    }
};
