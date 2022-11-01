
#include <iostream>
#include <queue>
using namespace std;

template <typename T>

struct tree {
    struct treeNode {
        T* data;
        struct treeNode* left;
        struct treeNode* right;

        treeNode(T* d, treeNode* l, treeNode* r) : data(d), left(l), right(r) {};

    };

    treeNode* head;
    int nNodes = 0;

	//Specifications: 
	//Requires: A pointer to a treeNode
	//Effects: Adds the node to the tree.
	//Test cases:
    // 1- If the left child is null, we add it to the left.
	// 2- If the right child is null and the left child is not, we add it to the right.
    void addNode(T* d) {
        treeNode* n(d, NULL, NULL);
        queue<treeNode*> q1;
        q1.push(head);
        while (true) {
            if (q1.front()->left == NULL) {
                q1.front()->left = n;
                break;
            }
            else if (q1.front()->right == NULL) {
                q1.front()->right = n;
                break;
            }
            else {
                q1.push(q1.front()->left);
                q1.push(q1.front()->right);
                q1.pop();
            }
            nNodes++;
        }
    }

	//Specifications:
	//Requires: A pointer to a treeNode
	//Effects: Deletes a node from the tree
	//Test cases:
	//1-  If the node is the head, we delete it and replace it with null 
	//2- If the node is a leaf, we delete it.
	//3- If the node is a parent, we print "CANNOT DELETE NODE"
    bool deleteNode(T* d) {
        if (head->data == d) {
            if (head->left == NULL && head->right == NULL) {
                head = NULL;
                nNodes = 0;
                return true;
            }
            else {
                cout << "CANNOT DELETE NODE" << endl;
                return false;
            }
        }
        else {
            return deleteNode(d, head);
        }
    }

    bool deleteNode(T* d, treeNode* c) {
        if (c->left->data == d) {
            if (c->left->left == NULL && c->left->right == NULL) {
                c->left = NULL;
                nNodes--;
                return true;
            }
            else {
                cout << "CANNOT DELETE NODE" << endl;
                return false;
            }
        }
        else if (c->right->data == d) {
            if (c->right->left == NULL && c->right->right == NULL) {
                c->right = NULL;
                size--;
                return true;
            }
            else {
                cout << "CANNOT DELETE NODE" << endl;
                return false;
            }
        }
        else {
            return deleteNode(d, c->left) || deleteNode(d, c->right);
        }
    }
    //Specifications:
	//Requires: None
	//Returns: The number of nodes in the tree
    int treeSize() {
        return nNodes;
    }
    //Specifications:
	//Requires: A pointer to a treeNode (root of that subtree)
    // Effects: The number of nodes in that subtree.
	//Test cases:
    //1- If the node is the head, we return the treeSize()
	
    int subTreeSize(T* d) {
        if (head->data == d) {
            return nNodes;
        }
        else {
            return subTreeSize(find(d, head));
        }
    }

    int subTreeSize(treeNode* m) {
        if (m == NULL) {
            return 0;
        }
        else {
            return 1 + subTreeSize(m->left) + subTreeSize(m->right);
        }
    }
	//Specifications: 
    // Requires:
	// Effects: Prints the content of each node in a PostOrder traversal
    //Test cases:
	//1- If the head is null, we don't print anything. Else we recurse on the left and right subtree then print data
    void postOrderPrint() {
        postOrderPrint(head);
    }
    void postOrderPrint(treeNode* current) {
        if (current == NULL) {
            return;
        }
        else {
            postOrderPrint(current->left);
            postOrderPrint(current->right);
            cout << current->data;
        }
    }
    //Specifications: 
    // Requires:
    // Effects: Prints the content of each node in a PreOrder traversal
    //Test cases:
    //1- If the head is null, we don't print anything. Else we print data then recurse on the left and right subtree
    void preOrderPrint() {
        preOrderPrint(head);
    }
    void preOrderPrint(treeNode* current) {
        if (current == NULL) {
            return;
        }
        else {
            cout << current->data;
            postOrderPrint(current->left);
            postOrderPrint(current->right);
            
        }
    }
    //Specifications: 
    // Requires:
    // Effects: Prints the content of each node in a PostOrder traversal
    //Test cases:
    //1- If the head is null, we don't print anything. Else we recurse on the left subtree, print data and then recurse on right subtree
    void inOrderPrint() {
        inOrderPrint(head);
    }
    void inOrderPrint(treeNode* current) {
        if (current == NULL) {
            return;
        }
        else {
            postOrderPrint(current->left);
            cout << current->data;
            postOrderPrint(current->right);
        }
    }
};
int main() {
	{
		tree<int> t;
        t.addNode(1);
		t.addNode(2);
		t.addNode(3);
		t.addNode(4);
        t.inOrderPrint();
        t.deleteNode(4);
        t.preOrderPrint();
        cout << "Tree size = " << t.treeSize();
		cout << "Subtree size = " << t.subTreeSize(2);
        t.postOrderPrint;
        return 0;
}
