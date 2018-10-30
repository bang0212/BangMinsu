#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void make_num(int *num); //숫자 생성 함수 
int compare(int* input, int* num); //숫자 비교 함수 
void result(int* num, int strike, int cnt); //결과 출력 함수 
int restart();
int main() {
 
 int num[3]={0}; //정답 
 int input[3]={0}; //사용자의 입력 
 int i=0, j=0;
 int cnt=1; // 횟수 
 int strike=0; //스트라이크 
 int re_chk=0; 
 
  while(1) 
  {

  printf("          숫자야구 게임\n");
  printf("숫자 3개를 맞추면 되는 게임입니다\n");
  printf("숫자,위치가 맞는경우 스트라이크\n숫자는 맞는데 위치가 틀린경우 볼입니다\n");
  printf("9회의 기회가 있습니다!\n");
  printf("숫자입력 예시) 1 2 3o 123x \n숫자 사이에 띄어쓰기를 적용해 주세요\n"); 
  printf("----------------------------------------\n");
  
  
  cnt=1;
  
  make_num(num); // 난수 생성 
 
  
  
  while(cnt < 10) 
  {
   
   printf("입력 : ");
   
   // 숫자가 아닐경우 출력 
   if(scanf("%d%d%d", &input[1], &input[2], &input[3]) != 3) 
   {
    printf("잘못입력하였습니다. 다시 입력하세요.\n");
    fflush(stdin);
    continue;
   }

   // 동일한 수 입력/1~9 이외의 수 입력시  
   if( (input[1] == input[2] || input[1] == input[3] || input[2] == input[3]) ||
    (input[1] < 1 || input[2] < 1 || input[3] < 1 || input[1] > 10 ||  input[2] > 10 ||  input[3] > 10) )
	{
    printf("잘못입력하였습니다. 다시 입력하세요.\n");
    continue;
    } 


   strike = compare(input, num); // 세가지 숫자를 비교

   result(num, strike, cnt); // 결과 출력

   if(strike == 3)
    break;

   cnt++;   
  }
  
  // 재시작확인 
  char re = restart();
  if( (strike == 3 || cnt == 10) && (re == 1) ) 
  {
   system("cls");
   continue;
  }
  
  else
   break;
    
 } 
 
 return 0;
}

// 난수3개를 생성하는 함수 
void make_num(int *num)
{
 int i=0;
 int j=0;
 
 // 3개의 수를 랜덤하게 생성
 srand(time(NULL));
 for(i=3; i>=1; i--) 
 {
  num[i] = rand() % 9 + 1;
  
  while(num[i] == num[i+1] || num[i] == num[i+2])
   num[i] = rand() % 9 + 1;
 }
 
}

// 정답과 사용자가 입력한 답을 비교하는 함수 
int compare(int* input, int* num)
{
 int i, j;
 int strike=0, ball=0;

 // input과 num 값을 비교해 strike, ball을 구함
 for(i=1, j=1; i<4; i++)
  {
  for(j=1; j<4; j++)
   {
   if(input[i] == num[i]) 
   {
    strike++;
    break;
   }
   else if(input[i] == num[j])
    ball++;
  }
 }
 
 printf("%d S, %d B\n", strike, ball); // strike, ball 갯수를 출력

 
 return strike; // strike 갯수를 반환
 
}


// 결과를 출력하는 함수
void result(int* num, int strike, int cnt)
{ 
 // 숫자 세개를 다 맞췄을 경우메시지출력 
 if(strike == 3) {

   printf("정답!\n");
 }
 
 // 숫자 세개를 다 맞추지 못했을 경우 남은 횟수를 출력
 else
  printf("%d번 시도했습니다.\n", cnt);
  
 
 //9번 모두 맞추지 못했을 경우 패배하였다는 메시지 출력
 if(cnt == 10)
  printf("\n실패! ");

 // 모두 맞췄거나 9회를 초과한 경우 정답 출력
 if(strike == 3 || cnt == 10)
   printf("정답은 %d %d %d입니다.\n\n", num[1], num[2], num[3]);
 
}


// 재시작 여부 확인 함수
int restart()
{

 char select='n';
 int rlt=0;
 
 printf("다시 시작할까요?(YES : 'Y', NO : 'N') : ");
 fflush(stdin);
 scanf("%c", &select);
 
 if(select == 'y')
  rlt=1;
 else if(select == 'n')
  rlt=0;
 else
  rlt=0;

 return rlt;
 
}
