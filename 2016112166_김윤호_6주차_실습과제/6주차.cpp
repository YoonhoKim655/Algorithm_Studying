//2016112166 ����ȣ
	
#include<iostream>
using namespace std;

struct node
{
	struct node *left, *right;
	int key;
};//node�� struct

void TreeInt(struct node* &p)
{
	p = new node;
	p->key = NULL;
	p->left = NULL;
	p->right = NULL;
}//�ʱ� root�� ��������ϴ�.

struct node *TreeSearch(struct node *&root, int xkey)
{
	struct node *p;
	p = root;
	while (p != NULL)
	{
		if (xkey == p->key)
			return p;	//ã�� key���� ã���� ���, �� p node�� return�� ���־����ϴ�.
		if (xkey < p->key)
			p = p->left;
		if (xkey > p->key)
			p = p->right;
		//xkey���� ���� ��ġ �ϰ� �ִ� node�� key���� �񱳸� �ؼ� ������ ����, ũ�� ���������� �̵��� �߽��ϴ�.
	}
	return 0;//ã�� ���� ���� ���, 0�� return�� �߽��ϴ�.
}

void TreeInsert(struct node *&root, int xkey)
{
	struct node *p, *t;
	p = root;	t = p->right;
	while (t != NULL)
	{
		p = t;
		if (xkey == t->key)
			return;
		else if (xkey < t->key)
			t = t->left;
		else
			t = t->right;
	}/*������ �ִ� ���� �־��� ���, �ƹ��� �͵� ���� �ʰ� ���Ḧ �߽��ϴ�.
	 �׸��� ������ �ϱ����� ������  node�� ��ġ�� ������ �߽��ϴ�.*/
	
	t = new node;
	t->key = xkey;
	t->left = NULL;
	t->right = NULL;
	if (xkey < p->key)
		p->left = t;
	else
		p->right = t;
	//������ ��ġ�� t�� ã���� ���, node�� ������ �ؼ� ���� ������ �߽��ϴ�.
}

bool TreeDel(struct node *&p, int xkey)
{
	struct node *d;
	
	bool result = false;
	if (p == NULL)
		return false;                               // tree�� ����� ��� false�� return���־����ϴ�.
	else if (xkey < p->key)
		result = TreeDel(p->left, xkey);    // //xkey�� node�� key���� ������ left���� �񱳸� ���ִ� �ڵ� �Դϴ�.
	else if (xkey > p->key)
		result = TreeDel(p->right, xkey);   //xkey�� node�� key���� ũ�� right���� �񱳸� ���ִ� �ڵ� �Դϴ�.
	else
	{                                            // xKey�� node�� key�� ���� ��� p�� d�� �־��־����ϴ�,
		d = p;
		struct node *temp = p;
		if (p->right == NULL)
			p = p->left;                    // right���� ������ p�� right�� �Ű���ϴ�.
		else if (p->right != NULL && p->right->left == NULL)
		{	
			p = p->right;
			p->left = temp->left;
		}    // right���� �ְ�, right�� left�� ���� ���, p�� right���� ������, left�� ������ p�� left���� ������ �˴ϴ�.
		else
		{
			d = p->right;
			while (d->left->left != NULL)
				d = d->left;
			//���� �ϱ� ���� node�� right child�߿��� ���� ���� ��带 ã�Ƴ������ϴ�.
			p = d->left;
			//ã�Ƴ� node�� p node�� �־����ϴ�.
			d->left = p->right; 
			p->left = temp->left;
			p->right = temp->right;
			//�׸��� ������ ���缭 ���� �ٽ� ������ �߽��ϴ�.
		}   
		result = true;    //ture�� return�� ���ֱ� ���� �־����ϴ�.
	}


	return true;
}

void showSub(struct node *&p, int level)
{
	int j;   // Loop counter
	if (p != NULL)
	{
		showSub(p->right, level + 1);         // ��͸� ����� �ؼ� ������ tree�κ� ���� ����� �߽��ϴ�.
		for (j = 0; j < level; j++)    // ���� ������ �κ� ���� ����� �߽��ϴ�.
			cout << "\t";
		cout << " " << p->key;  
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

void showStructure(struct node *&root)
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
	struct node *root = new node;   // root
	TreeInt(root);
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
		showStructure(root->right);                     // tree ���

		cout << endl << "Command: ";                  // command�� �Է� �ϰ� �� ���� ���� ������ �� ���� ������ �ϴ� �κ��Դϴ�.
		cin >> cmd;
		if (cmd == '+' || cmd == '?' ||
			cmd == '-' || cmd == '<')
			cin >> inputKey;

		switch (cmd)
		{
		case '+':                                  // insert
			cout << "Insert : key = " << inputKey;
			TreeInsert(root, inputKey);
			break;

		case '?':                                  // search
			if (TreeSearch(root, inputKey))
			{
				cout << "Retrieved : key = " << inputKey << endl;
				if (TreeSearch(root, inputKey)->left != NULL)
					cout << "Left child is " << TreeSearch(root, inputKey)->left->key << endl;
				else
					cout << "Left child is none" << endl;
				if (TreeSearch(root, inputKey)->right != NULL)
					cout << "Right child is " << TreeSearch(root, inputKey)->right->key << endl;
				else
					cout << "right child is none" << endl;
			}
			else
				cout << "Not found" << endl;
			break;

		case '-':                                  // delete
			if (TreeDel(root, inputKey))
				cout << "Removed element" << endl;
			else
				cout << "Not found" << endl;
			break;

		case 'Q': case 'q':                   // Quit
			break;

		default:                               // Invalid command
			cout << "Inactive or invalid command" << endl;
		}
	} while ((cmd != 'Q') && (cmd != 'q'));

}