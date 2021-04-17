//2016112166 ����ȣ

#include <iostream>

using namespace std;

enum Color { RED, BLACK };

struct Node
{
	int data;
	bool color;
	Node *left, *right, *parent;

	// Constructor 
	Node(int data)
	{
		this->data = data;
		left = right = parent = NULL;
		this->color = RED;
	}
};//Node�� struct

// Red-Black Tree�� Class
class RBTree
{
private:
	Node *root;
protected:
	void rotateLeft(Node *&, Node *&);
	void rotateRight(Node *&, Node *&);
	void fixup(Node *&, Node *&);
	void showSub(Node *&, int lev);
public:
	// Constructor 
	RBTree() { root = NULL; }
	void insert(const int &n);
	void showStructure();

};

Node* BSTInsert(Node* root, Node *pt)
{
	
	if (root == NULL)
		return pt;
	//��� �ִ�  tree�� ��, ���� �ִ� node�� root������ ������ �߽��ϴ�.
	
	if (pt->data < root->data)
	{
		root->left = BSTInsert(root->left, pt);
		root->left->parent = root;
	}
	else if (pt->data > root->data)
	{
		root->right = BSTInsert(root->right, pt);
		root->right->parent = root;
	}
	/*tree�� ������� ���� ���, ���� �ִ� ���� ��� �������� �� node�� ����
	�񱳸� �ؼ� �ڸ��� ã�� ������ �ڸ��� ���� �־����ϴ�.*/

	return root;
}

void RBTree::rotateLeft(Node *&root, Node *&pt)
{
	Node *pt_right = pt->right;

	pt->right = pt_right->left;

	if (pt->right != NULL)
		pt->right->parent = pt;

	pt_right->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_right;

	else if (pt == pt->parent->left)
		pt->parent->left = pt_right;

	else
		pt->parent->right = pt_right;

	pt_right->left = pt;
	pt->parent = pt_right;
}

void RBTree::rotateRight(Node *&root, Node *&pt)
{
	Node *pt_left = pt->left;

	pt->left = pt_left->right;

	if (pt->left != NULL)
		pt->left->parent = pt;

	pt_left->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_left;

	else if (pt == pt->parent->left)
		pt->parent->left = pt_left;

	else
		pt->parent->right = pt_left;

	pt_left->right = pt;
	pt->parent = pt_left;
}

// This function fixes violations caused by BST insertion 
void RBTree::fixup(Node *&root, Node *&pt)
{
	Node *parent_pt = NULL;
	Node *grand_parent_pt = NULL;

	while ((pt != root) && (pt->color != BLACK) &&
		(pt->parent->color == RED))
	{
		parent_pt = pt->parent;
		grand_parent_pt = pt->parent->parent;

		/*  Case : A
			Parent of pt is left child of Grand-parent of pt */
		if (parent_pt == grand_parent_pt->left)
		{
			Node *uncle_pt = grand_parent_pt->right;

			/* Case : 1
			   The uncle of pt is also red
			   Only Recoloring required */
			if (uncle_pt != NULL && uncle_pt->color == RED)
			{
				grand_parent_pt->color = RED;
				parent_pt->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grand_parent_pt;
			}

			else
			{
				/* Case : 2
				   pt is right child of its parent
				   Left-rotation required */
				if (pt == parent_pt->right)
				{
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				/* Case : 3
				   pt is left child of its parent
				   Right-rotation required */
				rotateRight(root, grand_parent_pt);
				swap(parent_pt->color, grand_parent_pt->color);
				pt = parent_pt;
			}
		}

		/* Case : B
		   Parent of pt is right child of Grand-parent of pt */
		else
		{
			Node *uncle_pt = grand_parent_pt->left;

			/*  Case : 1
				The uncle of pt is also red
				Only Recoloring required */
			if ((uncle_pt != NULL) && (uncle_pt->color == RED))
			{
				grand_parent_pt->color = RED;
				parent_pt->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grand_parent_pt;
			}
			else
			{
				/* Case : 2
				   pt is left child of its parent
				   Right-rotation required */
				if (pt == parent_pt->left)
				{
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				/* Case : 3
				   pt is right child of its parent
				   Left-rotation required */
				rotateLeft(root, grand_parent_pt);
				swap(parent_pt->color, grand_parent_pt->color);
				pt = parent_pt;
			}
		}
	}

	root->color = BLACK;
}

// Function to insert a new node with given data 
void RBTree::insert(const int &data)
{
	Node *pt = new Node(data);

	// Do a normal BST insert 
	root = BSTInsert(root, pt);

	// fix Red Black Tree violations 
	fixup(root, pt);
}

void RBTree::showSub(struct Node *&p, int level)
{
	int j;   // Loop counter
	if (p != NULL)
	{
		showSub(p->right, level + 1);         // ��͸� ����� �ؼ� ������ tree�κ� ���� ����� �߽��ϴ�.
		for (j = 0; j < level; j++)    // ���� ������ �κ� ���� ����� �߽��ϴ�.
			cout << "\t";
		if(p->color == 0)
			cout << " " << p->data<<"[R]";
		else
			cout << " " << p->data << "[B]";
		//color�� ���� ���� �÷��� ����� �߽��ϴ�.
		if ((p->left != NULL) && (p->right != NULL))//�ڽ��� ���� ������ ��� ���� ���
			cout << "<";
		else if (p->right != NULL)//������ �ڽĸ� ���� ���
			cout << "/";
		else if (p->left != NULL)//���� �ڽĸ� ���� ���,
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);          // ���� ������� ���� tree�� ��������ϴ�.
	}
}

void RBTree::showStructure()
{
	if (root == NULL)
		cout << "Empty tree" << endl;//ù ���Ұ� NULL�� ��� empty tree�� ����� �߽��ϴ�.
	else
	{
		cout << endl;
		showSub(root, 1);
		cout << endl;
	}
}


void main()
{
	RBTree tree;   // RBTree�� ��������ϴ�.
	;
	int inputKey;                    // key��
	char cmd;                        // command

	cout << endl << "Commands:" << endl;
	cout << "  +key : Insert (or update) element" << endl;
	cout << "  ?key : Retrieve element" << endl;
	cout << "  -key : Remove element" << endl;
	cout << "  Q    : Quit the test program" << endl;
	cout << endl;

	do
	{
		tree.showStructure();                     // tree ���

		cout << endl << "Command: ";                  // command�� �Է� �ϰ� �� ���� ���� ������ �� ���� ������ �ϴ� �κ��Դϴ�.
		cin >> cmd;
		if (cmd == '+' || cmd == '?' ||
			cmd == '-' || cmd == '<')
			cin >> inputKey;

		switch (cmd)
		{
		case '+':                                  // insert
			cout << "Insert : key = " << inputKey;
			tree.insert(inputKey);//TreeInsert(root, inputKey);
			break;

		case 'Q': case 'q':                   // Quit
			break;

		default:                               // Invalid command
			cout << "Inactive or invalid command" << endl;
		}
	} while ((cmd != 'Q') && (cmd != 'q'));

}



/*RB - Insert - Fixup(T, z)
{
	while (z.parent != nil) and (z.parent.color = red) do
	{
		if z.parent = z.parent.parent.left then
		{
		y < -z.parent.parent.right
		if y.color = red then
		{
		z.parent.color < -black // CASE 1
		y.color < -black
		z.parent.parent.color < -red
		z < -z.parent.parent
		}
		else
		{
		if z = z.parent.right then
		{
		z < -z.parent // CASE 2
		Left_Rotate(T, z)
		}
		z.parent.color < -black // CASE 3
		z.parent.parent.color < -red
		Right_Rotate(T, z.parent.parent)
		}
		}
		else // if z.parent = z.parent.parent.right
			y < -z.parent.parent.left
			if y.color = red then
			{
			z.parent.color < -black // CASE 4
			y.color < -black
			z.parent.parent.color < -red
			z < -z.parent.parent
			}
			else
			{
				if z = z.parent.left then
				{
				z < -z.parent // CASE 5
				Right_Rotate(T, z)
				}
					z.parent.color < -black // CASE 6
					z.parent.parent.color < -red
					Left_Rotate(T, z.parent.parent)
			}
	}
}
root.color < -black
}*/