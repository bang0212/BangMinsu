#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void make_num(int *num); //���� ���� �Լ� 
int compare(int* input, int* num); //���� �� �Լ� 
void result(int* num, int strike, int cnt); //��� ��� �Լ� 
int restart();
int main() {
 
 int num[3]={0}; //���� 
 int input[3]={0}; //������� �Է� 
 int i=0, j=0;
 int cnt=1; // Ƚ�� 
 int strike=0; //��Ʈ����ũ 
 int re_chk=0; 
 
  while(1) 
  {

  printf("          ���ھ߱� ����\n");
  printf("���� 3���� ���߸� �Ǵ� �����Դϴ�\n");
  printf("����,��ġ�� �´°�� ��Ʈ����ũ\n���ڴ� �´µ� ��ġ�� Ʋ����� ���Դϴ�\n");
  printf("9ȸ�� ��ȸ�� �ֽ��ϴ�!\n");
  printf("�����Է� ����) 1 2 3o 123x \n���� ���̿� ���⸦ ������ �ּ���\n"); 
  printf("----------------------------------------\n");
  
  
  cnt=1;
  
  make_num(num); // ���� ���� 
 
  
  
  while(cnt < 10) 
  {
   
   printf("�Է� : ");
   
   // ���ڰ� �ƴҰ�� ��� 
   if(scanf("%d%d%d", &input[1], &input[2], &input[3]) != 3) 
   {
    printf("�߸��Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���.\n");
    fflush(stdin);
    continue;
   }

   // ������ �� �Է�/1~9 �̿��� �� �Է½�  
   if( (input[1] == input[2] || input[1] == input[3] || input[2] == input[3]) ||
    (input[1] < 1 || input[2] < 1 || input[3] < 1 || input[1] > 10 ||  input[2] > 10 ||  input[3] > 10) )
	{
    printf("�߸��Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���.\n");
    continue;
    } 


   strike = compare(input, num); // ������ ���ڸ� ��

   result(num, strike, cnt); // ��� ���

   if(strike == 3)
    break;

   cnt++;   
  }
  
  // �����Ȯ�� 
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

// ����3���� �����ϴ� �Լ� 
void make_num(int *num)
{
 int i=0;
 int j=0;
 
 // 3���� ���� �����ϰ� ����
 srand(time(NULL));
 for(i=3; i>=1; i--) 
 {
  num[i] = rand() % 9 + 1;
  
  while(num[i] == num[i+1] || num[i] == num[i+2])
   num[i] = rand() % 9 + 1;
 }
 
}

// ����� ����ڰ� �Է��� ���� ���ϴ� �Լ� 
int compare(int* input, int* num)
{
 int i, j;
 int strike=0, ball=0;

 // input�� num ���� ���� strike, ball�� ����
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
 
 printf("%d S, %d B\n", strike, ball); // strike, ball ������ ���

 
 return strike; // strike ������ ��ȯ
 
}


// ����� ����ϴ� �Լ�
void result(int* num, int strike, int cnt)
{ 
 // ���� ������ �� ������ ���޽������ 
 if(strike == 3) {

   printf("����!\n");
 }
 
 // ���� ������ �� ������ ������ ��� ���� Ƚ���� ���
 else
  printf("%d�� �õ��߽��ϴ�.\n", cnt);
  
 
 //9�� ��� ������ ������ ��� �й��Ͽ��ٴ� �޽��� ���
 if(cnt == 10)
  printf("\n����! ");

 // ��� ����ų� 9ȸ�� �ʰ��� ��� ���� ���
 if(strike == 3 || cnt == 10)
   printf("������ %d %d %d�Դϴ�.\n\n", num[1], num[2], num[3]);
 
}


// ����� ���� Ȯ�� �Լ�
int restart()
{

 char select='n';
 int rlt=0;
 
 printf("�ٽ� �����ұ��?(YES : 'Y', NO : 'N') : ");
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
