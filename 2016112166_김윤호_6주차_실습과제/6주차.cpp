//2016112166 김윤호
	
#include<iostream>
using namespace std;

struct node
{
	struct node *left, *right;
	int key;
};//node의 struct

void TreeInt(struct node* &p)
{
	p = new node;
	p->key = NULL;
	p->left = NULL;
	p->right = NULL;
}//초기 root를 만들었습니다.

struct node *TreeSearch(struct node *&root, int xkey)
{
	struct node *p;
	p = root;
	while (p != NULL)
	{
		if (xkey == p->key)
			return p;	//찾는 key값을 찾았을 경우, 그 p node를 return을 해주었습니다.
		if (xkey < p->key)
			p = p->left;
		if (xkey > p->key)
			p = p->right;
		//xkey값과 현재 위치 하고 있는 node의 key값과 비교를 해서 작으면 왼쪽, 크면 오른쪽으로 이동을 했습니다.
	}
	return 0;//찾는 값이 없을 경우, 0을 return을 했습니다.
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
	}/*기존에 있는 값을 넣었을 경우, 아무런 것도 하지 않고 종료를 했습니다.
	 그리고 삽입을 하기위한 적절한  node의 위치를 결정을 했습니다.*/
	
	t = new node;
	t->key = xkey;
	t->left = NULL;
	t->right = NULL;
	if (xkey < p->key)
		p->left = t;
	else
		p->right = t;
	//적절한 위치인 t를 찾았을 경우, node를 생성을 해서 값을 설정을 했습니다.
}

bool TreeDel(struct node *&p, int xkey)
{
	struct node *d;
	
	bool result = false;
	if (p == NULL)
		return false;                               // tree가 비었을 경우 false를 return해주었습니다.
	else if (xkey < p->key)
		result = TreeDel(p->left, xkey);    // //xkey가 node의 key보다 작으면 left값과 비교를 해주는 코드 입니다.
	else if (xkey > p->key)
		result = TreeDel(p->right, xkey);   //xkey가 node의 key보다 크면 right값과 비교를 해주는 코드 입니다.
	else
	{                                            // xKey가 node의 key와 같을 경우 p를 d에 넣어주었습니다,
		d = p;
		struct node *temp = p;
		if (p->right == NULL)
			p = p->left;                    // right값이 없으면 p를 right로 옮겼습니다.
		else if (p->right != NULL && p->right->left == NULL)
		{	
			p = p->right;
			p->left = temp->left;
		}    // right값이 있고, right의 left가 없을 경우, p는 right값을 가지고, left는 기존의 p의 left값을 가지게 됩니다.
		else
		{
			d = p->right;
			while (d->left->left != NULL)
				d = d->left;
			//삭제 하기 위한 node의 right child중에서 가장 왼쪽 노드를 찾아내었습니다.
			p = d->left;
			//찾아낸 node를 p node에 넣었습니다.
			d->left = p->right; 
			p->left = temp->left;
			p->right = temp->right;
			//그리고 원리에 맞춰서 값을 다시 설정을 했습니다.
		}   
		result = true;    //ture를 return을 해주기 위해 넣었습니다.
	}


	return true;
}

void showSub(struct node *&p, int level)
{
	int j;   // Loop counter
	if (p != NULL)
	{
		showSub(p->right, level + 1);         // 재귀를 사용을 해서 오른쪽 tree부분 부터 출력을 했습니다.
		for (j = 0; j < level; j++)    // 가장 오른쪽 부분 부터 출력을 했습니다.
			cout << "\t";
		cout << " " << p->key;  
		if ((p->left != NULL) && (p->right != NULL))//자식이 왼쪽 오른쪽 모두 있을 경우
			cout << "<";
		else if (p->right != NULL)//오른쪽 자식만 있을 경우
			cout << "/";
		else if (p->left != NULL)//왼쪽 자식만 있을 경우,
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);          // 같은 방식으로 왼쪽 tree를 만들었습니다.
	}
}

void showStructure(struct node *&root)
{
	if (root == NULL)
		cout << "Empty tree" << endl;//첫 원소가 NULL인 경우 empty tree를 출력을 했습니다.
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
	int inputKey;                    // key값
	char cmd;                        // command
	
	cout << endl << "Commands:" << endl;
	cout << "  +key : Insert (or update) element" << endl;
	cout << "  ?key : Retrieve element" << endl;
	cout << "  -key : Remove element" << endl;
	cout << "  Q    : Quit the test program" << endl;
	cout << endl;

	do
	{
		showStructure(root->right);                     // tree 출력

		cout << endl << "Command: ";                  // command를 입력 하고 그 값에 따라서 무었을 할 지를 결정을 하는 부분입니다.
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