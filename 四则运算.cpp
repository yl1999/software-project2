#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
/*��������*/
int subject_sum; //��Ŀ��
int subject_operation; //��������or��������
int subject_line_number; //����Ŀ��
int subject_nowline_number; //��ǰ����Ŀ��
int subject_ifdecimal; //�Ƿ���С��
int subject_ifbrackets; //�Ƿ�������
int number_smallest; //��С��
int number_largest; //�����
char subject_operators[4][4] = { "+","-","*","/" }; //�������

/*���ܺ���*/
void Menu(); //����ѡ��˵�
void Subeject_Output_Screen(); //��Ļ�������
void Subject_Generate_Screen(); //��Ļ���ɺ���

void Menu() //����ѡ��˵�
{
    printf("���������ɵ���Ŀ����1-10000����\n");
    scanf_s("%d", &subject_sum);
    if (subject_sum < 1 || subject_sum > 10000)
    {
        printf("�������\n");
        return;
    }
    printf("�������Ƿ��г˳�����������1��������0\n");
    scanf_s("%d", &subject_operation);
    if (subject_operation < 0 || subject_operation > 1)
    {
        printf("�������\n");
        return;
    }
    if (subject_operation == 1)
        subject_operation = 4;
    else
        subject_operation = 2;
    printf("���������ķ�Χa,b��0-30000����a,b�Կո��������֤a<b\n");
    scanf_s("%d%d", &number_smallest, &number_largest);
    if (number_smallest < 0 || number_largest > 30000 || number_smallest >= number_largest)
    {
        printf("�������\n");
        return;
    }
    printf("�������Ƿ���С����������1��������0\n");
    scanf_s("%d", &subject_ifdecimal);
    if (subject_ifdecimal < 0 || subject_ifdecimal > 1)
    {
        printf("�������\n");
        return;
    }
    printf("�������Ƿ������ţ�������1��������0\n");
    scanf_s("%d", &subject_ifbrackets);
    if (subject_ifbrackets < 0 || subject_ifbrackets > 1)
    {
        printf("�������\n");
        return;
    }
    printf("������ÿ�е���Ŀ����1-5����\n");
    scanf_s("%d", &subject_line_number);
    if (subject_line_number < 1 || subject_line_number > 5)
    {
        printf("�������\n");
        return;
    } 
        Subeject_Output_Screen();  
}

void Subeject_Output_Screen() //��Ļ�������
{
    printf("��Ŀ���ɣ�\n");
    while (subject_sum--)
    {
        subject_nowline_number++;
        Subject_Generate_Screen();
        printf("=");
        if (subject_nowline_number == subject_line_number)
        {
            printf("\n");
            subject_nowline_number = 0;
        }
        else
            printf("     ");
    }
}

void Subject_Generate_Screen() //��Ļ���ɺ���
{
    /*�����������*/
    int number_first = (rand() % (number_largest - number_smallest)) + number_smallest;
    int number_second = (rand() % (number_largest - number_smallest)) + number_smallest;
    int number_last = (rand() % (number_largest - number_smallest)) + number_smallest;
    /*������������*/
    int number_operator_first = rand() % subject_operation;
    int number_operator_second = rand() % subject_operation;
    /*�Ƿ�������*/
    int number_brackets = 0;
    if (subject_ifbrackets == 1)
        number_brackets = rand() % 2;

    if (!subject_ifdecimal)
    {
        printf("%3d %s ", number_first, subject_operators[number_operator_first]);
        if (number_brackets)
            printf("(");
        else
            printf(" ");
        printf("%3d %s %3d", number_second, subject_operators[number_operator_second], number_last);
        if (number_brackets)
            printf(")");
        else
            printf(" ");
    }
    else
    {
        printf("%5g %s ", number_first + (rand() % 100) / 100.0, subject_operators[number_operator_first]); //��������ת���ɸ�����
        if (number_brackets)
            printf("(");
        else
            printf(" ");
        printf("%5g %s %5g ", number_second + (rand() % 100) / 100.0, subject_operators[number_operator_second], number_last + (rand() % 100) / 100.0);
        if (number_brackets)
            printf(")");
        else
            printf(" ");
    }
}
int main()
{
    Menu();
    system("pause");
    return(0);
}
