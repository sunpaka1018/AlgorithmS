#include<stdio.h>

int max, min;
int A[1000]; //임의로 배열의 크기를 지정

//최댓값과 최솟값을 찾는 findMaxMin() 함수
void findMaxMin(int i, int j)
{
	int max_part, min_part; //부분문제로 나눴을 경우 partition 왼쪽의 최댓값과 최솟값
	
	if (i == j)//배열의 원소의 개수가 1인 경우
	{
		max = A[i];
		min = A[i];	//max와 min은 모두 A[i]
	}
	else //배열의 원소의 개수가 2인 경우
	{
		if (j - i == 1)
		{
			if (A[i] < A[j]) //A[i]와 A[j]의 값을 비교하여 큰 쪽이 max, 작은 쪽이 min
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
		else //배열의 원소의 개수가 2보다 많은 경우
		{
			findMaxMin(i, (i + j)/2); //배열 인덱스의 왼쪽에서 max, min을 찾기 위해 재귀 호출
			max_part = max;
			min_part = min;
			findMaxMin((i + j)/2+1, j); //배열 인덱스의 왼쪽에서 max, min을 찾기 위해 재귀 호출
			//각 부분문제의 max, min값 비교
			if (max < max_part)
				max = max_part;
			if (min > min_part)
				min = min_part;
		}
	}
}

//실행
int main()
{
	int num;
	printf("배열의 크기는?\n"); //사용자에게 배열의 크기 입력받기
	scanf_s("%d", &num);
	printf("배열에 들어갈 수를 지정하세요(배열의 크기:%d) \n", num); //사용자에게 배열에 들어갈 수 입력받기
	for (int i = 1; i <= num; i++)
		scanf_s("%d", &A[i]);

	findMaxMin(1, num); //findMaxMin함수 실행
	//최종 출력
	printf("배열의 최솟값 : %d\n", min);
	printf("배열의 최댓값 : %d\n", max);
	system("pause");
	return 0;
}