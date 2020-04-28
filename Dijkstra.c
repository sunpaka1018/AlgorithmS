#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h> //system("pause")�� ���� �������
#define INFINITY 9999 //������ ���� ����� ����ġ�� 9999�� ����

int W[101][101]; //������ ���� n�� ������ 1<=n<=100
int F[][2];
int N = 0;

void dijkstra(int N, const int W[][5], int F[][2]) {
	int i, j, vnear; //���� ����
	int min; //9999�� �ʱⰪ�� ������ min ����
	int e = 0; //touch[vnear]�� vnear�� �մ� ����
	int touch[N+1]; //Y�ȿ� �� �������� ���� ��,�ĺ� ������ ������ ������ �� ǥ�ø� ���� touch�迭
	int length[N+1]; //���������κ��� �ĺ����� ������ �Ÿ�

	//�ʱ�ȭ
	for (i = 2; i <= N; i++) {        
		touch[i] = 1;        //touch�� v1���� �ʱ�ȭ
		length[i] = W[0][i - 1]; //v1�κ��� ��� ���������� ����ġ�� �ʱ�ȭ
	}
	for (j = 0; j < N-1 ; j++) { //n-1ȸ �ݺ��ϵ��� ��
		min = INFINITY; //min = 9999
		for (i = 2; i <= N; i++) {        //v2���� vn������ length[] ���� ���������� ���ذ��� �ִ��� ��� ��
			if (length[i] >= 0 && length[i] < min) { //��δ� �� ����� ����
				min = length[i];
				vnear = i; //min�� vnear�� ���� ���� ����
			}
			//e�� F�� ����
			F[e][0] = touch[vnear];
			F[e][1] = vnear;  e++;

			for (i = 2; i <= N; i++)
				if (length[vnear] + W[vnear - 1][i - 1] < length[i]) { //���� �߰��� ��ΰ� ������ length������ ���� �� 
					length[i] = length[vnear] + W[vnear][i]; 
					touch[i] = vnear;    //length���� touch���� ������Ʈ
				}     
			length[vnear] = -1;  //�� �̻� ������� ����(�ĺ����� ����)
		}

		//���
		for (int i = 1; i <= N + 1; i++) {
			printf("shortest paths from v%d = (", i);
			for (int j = 1; j <= N; j++) {
				printf("%d", length[i]);}
			printf(")\n");
		}
	
	}
}


int main()
{
	int N, num_edge, a, b, c;
	freopen("C:\\PR1_data\\graph1.txt", "rt", stdin); //��ο��� ����ġ ���� �׷��� ������ �о��
	scanf("%d %d", &N, &num_edge); //ù��° ���� �����͸� �о�� ����(������ ����, ���� ������ ������ N�� num_edge�� ����)

	for (int i = 1; i < num_edge; i++) { //���⿡���� ����ġ �����͸� ���ʷ� �о��
		scanf("%d %d %d", &a, &b, &c); //�� �����͸� ���� a, b, d�� ����
		W[a][b] = c;				//W[i][j]�� ����
	}

	//���� ��� ���� �� ����ϱ�
	for (int i = 1; i <= N ; i++) {
		for (int j = 1; j <= N; j++) {
			W[i][j] = INFINITY; //������ ��𿡵� ������� ���� ���(���Ѵ��� ����ġ)���� ����
			if (i == j)		    // i=j�� ���(tail(i,j) = head(i,j)�� ���) 0�� ����ġ�� ����
				W[i][j] = 0;
			else                //��ȿ�� ���� ���� ��� W[][]�� �� �Ҵ�
				W[i][j] = c;   
			printf("%d", W[i][j]);//���
		}
		printf("\n");
	}

	for (int i = 1; i <= N; i++) {
		dijkstra(N, W, F); //�Լ� ����
	}

	system("pause");
	return 0; //����
}