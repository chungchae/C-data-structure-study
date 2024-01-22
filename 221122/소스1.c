#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

node* root; //�Ѹ� ���

node* insertN(node* root, int num) //��� �߰� �Լ�
{
	if (root == NULL) //�Ѹ��� ������, �Ѹ� ��� �Է�
	{
		root = (node*)malloc(sizeof(node));
		root->right = root->left = NULL;
		root->data = num;
		return root;
	}
	else //�Ѹ��� �����Ϳ� ���� ���Ͽ� ����, ������ ����
	{
		if (num < root->data) 
			root->left = insertN(root->left, num);
		else
			root->right = insertN(root->right, num);
	}
	return root;
}

node* fMin(node* root) 
{ //Ʈ���� �ּڰ��� ���ϴ� �Լ�
	node* min = root;
	while (min->left != NULL)
		min = min->left;
	return min;
}

node* deleteN(node* root, int num)
{ //��� ���� �Լ�
	node* temp = NULL;

	if (root == NULL)
		return NULL;
	if (num < root->data)
		root->left = deleteN(root->left, num);
	else if (num > root->data)
		root->right = deleteN(root->right, num);
	else
	{
		if (root->left != NULL && root->right != NULL)
		{
			temp = fMin(root->right);
			root->data = temp->data;
			root->right = deleteN(root->right, temp->data);
		}
		else
		{
			temp = (root->left == NULL) ? root->right : root->left;
			free(root);
			return temp;
		}
	}
	return root;
}

int Nheight(node* root) 
{//Ʈ���� ���̸� ���ϴ� �Լ�
	if (root == NULL)
		return 0;
	return 1 + max(Nheight(root->left), Nheight(root->right));
}

void print(node* root, int level)
{ //Ʈ�� ��� �Լ�
	if (root == NULL)
		return;
	print(root->right, level + 1);
	printf("\n");
	if (level < Nheight(root))
	{//�� ��忡�� ������ ��µ��� �ʵ��� if�����
		for (int i = 0; i < level; i++) printf("    "); printf("  /\n");
	}
	for (int i = 0; i < level; i++) printf("    ");
	printf("%d\n", root->data);
	if (level < Nheight(root))
	{
		for (int i = 0; i < level; i++) printf("    "); printf("  \\");
	}
	print(root->left, level + 1);
}

int main()
{
	int key = 0;

	printf("������ �޴��� �����ϼ���: 1. ��� �߰� 2. ��� ���� 3. Ʈ�� ��� ");
	scanf_s("%d", &key);

	while (key != 0)
	{
		switch (key)
		{
		case 1: {
			printf("��� ���� �Է��ϼ���: ");
			int inum = 0;
			scanf_s("%d", &inum);
			root = insertN(root, inum);
			printf("\n�ԷµǾ����ϴ�.\n");
			break;
		}

		case 2: {
			printf("������ ��� ���� �Է��ϼ���: ");
			int dnum = 0;
			scanf_s("%d", &dnum);
			root = deleteN(root, dnum);
			printf("�����Ǿ����ϴ�.");
			break;
		}

		case 3: {
			printf("\n�Էµ� Ʈ��: \n");
			print(root, 0);
			break;
		}
		}
		printf("������ �޴��� �����ϼ���: 1. ��� �߰� 2. ��� ���� 3. Ʈ�� ��� ");
		scanf_s("%d", &key);
	}
}