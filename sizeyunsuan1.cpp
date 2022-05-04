
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<random>
using namespace std;
 int num;//��Ҫ��Ŀ������
 int symbol_type[4] = { 0,0,0,0 };//��Ҫ�������ͱ�־��
 int maxnum;//ϣ����Ŀ�г��ֵ����ֵ��
 int brackets;//��Ŀ���Ƿ���Ҫ���ŵı�־��
 int decimal;//��Ŀ����������С���ı�־��
 int style;//�����ʽ��־��
 int line_number;//ÿ����Ŀ��
 int now_number;//��ǰ����Ŀ��
int number_int[3];//��Ŀ�г��ֵ�������
float number_float[3];//��Ŀ�г��ֵ�С����
char symbol[2];//��Ŀ�г��ֵ��������
FILE *fp;//��Ҫ������ļ���

/*�û����ú���*/
void start() {
	cout << "��������Ҫ���ٵ���Ŀ��\n";
	cin >> num;
	cout << "��Ҫ+������1������2\n";
	cin >> symbol_type[0];
	cout << "��Ҫ-������1������2\n";
	cin >> symbol_type[1];
	cout << "��Ҫ*������1������2\n";
	cin >> symbol_type[2];
	cout << "��Ҫ/������1������2\n";
	cin >> symbol_type[3];
	cout << "ϣ����ʽ�г��ֵ������ֵ\n";
	cin >> maxnum;
	cout << "��Ҫ����������1������2\n";
	cin >> brackets;
	cout << "��Ҫ����������1��С������2\n";
	cin >>decimal;
	cout << "ÿ����Ŀ������1-5��\n";
	cin >>line_number;
	cout << "��Ҫ������ļ�������1����ӡ����2\n";
	cin >> style;
}

/*ȡ���������С������*/
void randnumber() {
	if ( decimal == 1) {
		for (int i = 0; i < 3; i++) {
			number_int[i] = rand() % (maxnum)+1;
		}
	}
	if (decimal == 2) {
		for (int i = 0; i < 3; i++) {
			number_float[i] = rand() / (double)(RAND_MAX / maxnum);
		}
	}
}
/*ȡ������������*/
void randsymbol() {
	int j = 0;
	while(j<3) {
		int flge = rand() % 4;
		switch (flge) {
		case 0:
			if (symbol_type[0] == 1) {
				symbol[j] = '+';
				j++;
			}
			break;
		case 1:
			if (symbol_type[1] == 1) {
				symbol[j] = '-';
				j++;
			}
			break;
		case 2:
			if (symbol_type[2] == 1) {
				symbol[j] = '*';
				j++;
			}
			break;
		case 3:
			if (symbol_type[3] == 1) {
				symbol[j] = '/';
				j++;
			}
			break;
		}
	}
}

/*�������ŵ���Ŀ���ɺ���*/
void create_expression1(int i) {
	if (decimal == 1) {
		printf("%d. ", i);
		printf("%d %c %d %c %d= ", number_int[0], symbol[0], number_int[1],symbol[1], number_int[2]);
	}
	if (decimal == 2) {
		printf("%d. ", i);
		printf("%.2f %c %.2f %c %.2f=        ", number_float[0], symbol[1], number_float[1], symbol[1], number_float[1]);
	}
}

/*�����ŵ���Ŀ���ɺ���*/
void create_expression2( int i) {
	int brackets_place = rand() % 2;
	if (brackets_place == 0) {
		if (decimal == 1) {
			printf("%d. ", i);
			printf("( %d %c %d ) %c %d =         ", number_int[0], symbol[0], number_int[1], symbol[1], number_int[2]);
		}
		if (decimal == 2) {
			printf("%d. ", i);
			printf("( %.2f %c %.2f ) %c %.2f =       ", number_float[0], symbol[1], number_float[1], symbol[1], number_float[1]);
		}
	}
	if (brackets_place == 1) {
		if (decimal == 1) {
			printf("%d. ", i);
			printf("%d %c ( %d %c %d ) =         ", number_int[0], symbol[0], number_int[1], symbol[1], number_int[2]);
		}
		if (decimal == 2) {
			printf("%d. ", i);
			printf("%.2f %c ( %.2f %c %.2f ) =          ", number_float[0], symbol[1], number_float[1], symbol[1], number_float[1]);
		}
	}
}



/*�ļ���������Ŀ����*/
void create_expression3(int i) {
	fprintf(fp,"%d. ", i);
	if (brackets == 1) {
		int brackets_place = rand() % 2;
		if (brackets_place == 0) {
			if (decimal == 1) {
				fprintf(fp,"( %d %c %d ) %c %d =     ", number_int[0], symbol[0], number_int[1], symbol[1], number_int[2]);
			}
			if (decimal == 2) {
				fprintf(fp,"( %.2f %c %.2f ) %c %.2f =     ", number_float[0], symbol[1], number_float[1], symbol[1], number_float[1]);
			}
		}
		if (brackets_place == 1) {
			if (decimal == 1) {
				fprintf(fp,"%d %c ( %d %c %d ) =     ", number_int[0], symbol[0], number_int[1], symbol[1], number_int[2]);
			}
			if (decimal == 2) {
				fprintf(fp,"%.2f %c ( %.2f %c %.2f ) =    ", number_float[0], symbol[1], number_float[1], symbol[1], number_float[1]);
			}
		}
	}
	else {
		if (decimal == 1) {
			fprintf(fp,"%d %c %d %c %d=     ", number_int[0], symbol[0], number_int[1], symbol[1], number_int[2]);
		}
		if (decimal == 2) {
			fprintf(fp,"%.2f %c %.2f %c %.2f=     ", number_float[0], symbol[1], number_float[1], symbol[1], number_float[1]);
		}
	}
	fprintf(fp, "\n");
}

/*������*/
int main() {
	start();
	if ((fp = fopen("D:\\zuoye.txt", "w")) == NULL)
	{
		printf("���ܴ��ļ���\n");
		exit(0);
	}
	for (int j = 1; j <= num; j++) {
		randnumber();
		randsymbol();
		if (brackets == 1&&style==2) {
			create_expression1(j);
			now_number++;
			if(now_number>=line_number){
				printf("\n");
				now_number=0;
			}
		}
		if (brackets == 2&&style==2) {
			create_expression2(j);
			now_number++;
			if(now_number>=line_number){
				printf("\n");
				now_number=0;
			}
		}
		if (style == 1) {
			create_expression3(j);
		}
	}
	fclose(fp);
	system("pause");
	return 0;
}