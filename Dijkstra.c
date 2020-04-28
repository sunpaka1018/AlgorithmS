#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h> //system("pause")를 위한 헤더파일
#define INFINITY 9999 //에지가 없는 경우의 가중치를 9999로 정함

int W[101][101]; //정점의 개수 n의 범위는 1<=n<=100
int F[][2];
int N = 0;

void dijkstra(int N, const int W[][5], int F[][2]) {
	int i, j, vnear; //변수 선언
	int min; //9999의 초기값을 가지는 min 선언
	int e = 0; //touch[vnear]와 vnear를 잇는 에지
	int touch[N+1]; //Y안에 들어간 정점들의 집합 중,후보 정점과 인접한 정점의 값 표시를 위한 touch배열
	int length[N+1]; //시작점으로부터 후보정점 까지의 거리

	for (i = 2; i <= N; i++) {        
		touch[i] = 1;        //touch를 v1으로 초기화
		length[i] = W[0][i - 1]; //v1로부터 모든 정점까지의 가중치로 초기화
	}
	for (j = 0; j < N-1 ; j++) { //n-1회 반복하도록 함
		min = INFINITY; //min = 9999
		
		for (i = 2; i <= N; i++) {        //v2부터 vn까지의 length[] 값을 순차적으로 비교해가며 최단의 경로 비교
			if (length[i] >= 0 && length[i] < min) { //경로는 늘 양수를 보장
				min = length[i];
				vnear = i; //min과 vnear의 값을 새로 저장
			}
			
			//e를 F에 저장
			F[e][0] = touch[vnear];
			F[e][1] = vnear;  e++;

			for (i = 2; i <= N; i++)
				if (length[vnear] + W[vnear - 1][i - 1] < length[i]) { //새로 발견한 경로가 기존의 length값보다 적을 때 
					length[i] = length[vnear] + W[vnear][i]; 
					touch[i] = vnear;    //length값과 touch값을 업데이트
				}     
			length[vnear] = -1;  
			//후보에서 제외
		}

		//출력
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
	freopen("C:\\PR1_data\\graph1.txt", "rt", stdin); //경로에서 가중치 방향 그래프 파일을 읽어옴
	scanf("%d %d", &N, &num_edge); //첫번째 줄의 데이터를 읽어와 저장(정점의 개수, 방향 에지의 개수를 N과 num_edge에 저장)

	for (int i = 1; i < num_edge; i++) { //방향에지와 가중치 데이터를 차례로 읽어옴
		scanf("%d %d %d", &a, &b, &c); //각 데이터를 변수 a, b, d에 저장
		W[a][b] = c;				//W[i][j]값 지정
	}

	//인접 행렬 생성 및 출력하기
	for (int i = 1; i <= N ; i++) {
		for (int j = 1; j <= N; j++) {
			W[i][j] = INFINITY; //에지가 어디에도 연결되지 않은 경우(무한대의 가중치)부터 시작
			if (i == j)		    // i=j인 경우(tail(i,j) = head(i,j)인 경우) 0의 가중치를 가짐
				W[i][j] = 0;
			else                //유효한 값을 가진 경우 W[][]에 값 할당
				W[i][j] = c;   
			printf("%d", W[i][j]);//출력
		}
		printf("\n");
	}

	for (int i = 1; i <= N; i++) {
		dijkstra(N, W, F); //함수 실행
	}

	system("pause");
	return 0; //종료
}
