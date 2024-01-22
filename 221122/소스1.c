#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

node* root; //뿌리 노드

node* insertN(node* root, int num) //노드 추가 함수
{
	if (root == NULL) //뿌리가 없으면, 뿌리 노드 입력
	{
		root = (node*)malloc(sizeof(node));
		root->right = root->left = NULL;
		root->data = num;
		return root;
	}
	else //뿌리의 데이터와 값을 비교하여 왼쪽, 오른쪽 선택
	{
		if (num < root->data) 
			root->left = insertN(root->left, num);
		else
			root->right = insertN(root->right, num);
	}
	return root;
}

node* fMin(node* root) 
{ //트리의 최솟값을 구하는 함수
	node* min = root;
	while (min->left != NULL)
		min = min->left;
	return min;
}

node* deleteN(node* root, int num)
{ //노드 삭제 함수
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
{//트리의 높이를 구하는 함수
	if (root == NULL)
		return 0;
	return 1 + max(Nheight(root->left), Nheight(root->right));
}

void print(node* root, int level)
{ //트리 출력 함수
	if (root == NULL)
		return;
	print(root->right, level + 1);
	printf("\n");
	if (level < Nheight(root))
	{//끝 노드에는 가지가 출력되지 않도록 if문사용
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

	printf("실행할 메뉴를 선택하세요: 1. 노드 추가 2. 노드 삭제 3. 트리 출력 ");
	scanf_s("%d", &key);

	while (key != 0)
	{
		switch (key)
		{
		case 1: {
			printf("노드 값을 입력하세요: ");
			int inum = 0;
			scanf_s("%d", &inum);
			root = insertN(root, inum);
			printf("\n입력되었습니다.\n");
			break;
		}

		case 2: {
			printf("삭제할 노드 값을 입력하세요: ");
			int dnum = 0;
			scanf_s("%d", &dnum);
			root = deleteN(root, dnum);
			printf("삭제되었습니다.");
			break;
		}

		case 3: {
			printf("\n입력된 트리: \n");
			print(root, 0);
			break;
		}
		}
		printf("실행할 메뉴를 선택하세요: 1. 노드 추가 2. 노드 삭제 3. 트리 출력 ");
		scanf_s("%d", &key);
	}
}