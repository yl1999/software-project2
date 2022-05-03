#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
/*变量数据*/
int subject_sum; //题目数
int subject_operation; //四则运算or二则运算
int subject_line_number; //行题目数
int subject_nowline_number; //当前行题目数
int subject_ifdecimal; //是否有小数
int subject_ifbrackets; //是否有扩号
int number_smallest; //最小数
int number_largest; //最大数
char subject_operators[4][4] = { "+","-","*","/" }; //运算符号

/*功能函数*/
void Menu(); //功能选择菜单
void Subeject_Output_Screen(); //屏幕输出函数
void Subject_Generate_Screen(); //屏幕生成函数

void Menu() //功能选择菜单
{
    printf("请输入生成的题目数（1-10000）：\n");
    scanf_s("%d", &subject_sum);
    if (subject_sum < 1 || subject_sum > 10000)
    {
        printf("输入错误！\n");
        return;
    }
    printf("请输入是否有乘除法：是输入1，否输入0\n");
    scanf_s("%d", &subject_operation);
    if (subject_operation < 0 || subject_operation > 1)
    {
        printf("输入错误！\n");
        return;
    }
    if (subject_operation == 1)
        subject_operation = 4;
    else
        subject_operation = 2;
    printf("请输入数的范围a,b（0-30000）：a,b以空格隔开，保证a<b\n");
    scanf_s("%d%d", &number_smallest, &number_largest);
    if (number_smallest < 0 || number_largest > 30000 || number_smallest >= number_largest)
    {
        printf("输入错误！\n");
        return;
    }
    printf("请输入是否有小数：是输入1，否输入0\n");
    scanf_s("%d", &subject_ifdecimal);
    if (subject_ifdecimal < 0 || subject_ifdecimal > 1)
    {
        printf("输入错误！\n");
        return;
    }
    printf("请输入是否有括号：是输入1，否输入0\n");
    scanf_s("%d", &subject_ifbrackets);
    if (subject_ifbrackets < 0 || subject_ifbrackets > 1)
    {
        printf("输入错误！\n");
        return;
    }
    printf("请输入每行的题目数（1-5）：\n");
    scanf_s("%d", &subject_line_number);
    if (subject_line_number < 1 || subject_line_number > 5)
    {
        printf("输入错误！\n");
        return;
    } 
        Subeject_Output_Screen();  
}

void Subeject_Output_Screen() //屏幕输出函数
{
    printf("题目生成：\n");
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

void Subject_Generate_Screen() //屏幕生成函数
{
    /*随机生成数字*/
    int number_first = (rand() % (number_largest - number_smallest)) + number_smallest;
    int number_second = (rand() % (number_largest - number_smallest)) + number_smallest;
    int number_last = (rand() % (number_largest - number_smallest)) + number_smallest;
    /*随机生成运算符*/
    int number_operator_first = rand() % subject_operation;
    int number_operator_second = rand() % subject_operation;
    /*是否有括号*/
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
        printf("%5g %s ", number_first + (rand() % 100) / 100.0, subject_operators[number_operator_first]); //将整数型转换成浮点型
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
