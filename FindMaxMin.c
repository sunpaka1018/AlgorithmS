#include<stdio.h>

int max, min;
int A[1000]; //���Ƿ� �迭�� ũ�⸦ ����

//�ִ񰪰� �ּڰ��� ã�� findMaxMin() �Լ�
void findMaxMin(int i, int j)
{
	int max_part, min_part; //�κй����� ������ ��� partition ������ �ִ񰪰� �ּڰ�
	
	if (i == j)//�迭�� ������ ������ 1�� ���
	{
		max = A[i];
		min = A[i];	//max�� min�� ��� A[i]
	}
	else //�迭�� ������ ������ 2�� ���
	{
		if (j - i == 1)
		{
			if (A[i] < A[j]) //A[i]�� A[j]�� ���� ���Ͽ� ū ���� max, ���� ���� min
			{
				max = A[j];
				min = A[i];
			}
			else
			{
				max = A[i];
				min = A[j]; 
			}
		}
		else //�迭�� ������ ������ 2���� ���� ���
		{
			findMaxMin(i, (i + j)/2); //�迭 �ε����� ���ʿ��� max, min�� ã�� ���� ��� ȣ��
			max_part = max;
			min_part = min;
			findMaxMin((i + j)/2+1, j); //�迭 �ε����� ���ʿ��� max, min�� ã�� ���� ��� ȣ��
			//�� �κй����� max, min�� ��
			if (max < max_part)
				max = max_part;
			if (min > min_part)
				min = min_part;
		}
	}
}

//����
int main()
{
	int num;
	printf("�迭�� ũ���?\n"); //����ڿ��� �迭�� ũ�� �Է¹ޱ�
	scanf_s("%d", &num);
	printf("�迭�� �� ���� �����ϼ���(�迭�� ũ��:%d) \n", num); //����ڿ��� �迭�� �� �� �Է¹ޱ�
	for (int i = 1; i <= num; i++)
		scanf_s("%d", &A[i]);

	findMaxMin(1, num); //findMaxMin�Լ� ����
	//���� ���
	printf("�迭�� �ּڰ� : %d\n", min);
	printf("�迭�� �ִ� : %d\n", max);
	system("pause");
	return 0;
}