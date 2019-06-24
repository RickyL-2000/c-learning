//考虑把两个n位二进制整数相加并存储在一个(n+1)位数组C中
#include <stdio.h>
void readArray(int array[], int length);
void sumArray(int array1[], int array2[], int sum[], int length);
void showArray(int array[], int length);

int main()
{
    printf("Please enter the length of binary numbers you want: ");
    int length;
    scanf("%d", &length);
    int number1[length], number2[length];
    int sum[length+1];
    puts("Enter the first binary number:");
    readArray(number1, length);
    puts("Enter the second binary number:");
    readArray(number2, length);


    sumArray(number1, number2, sum, length);
    puts("Now the sum of these two binary numbers is:");
    showArray(sum, length+1);     //这里的length+1容易搞错！

    return 0;
}

void readArray(int array[], int length)
{
    for (int i = 0; i < length; i++) {
        scanf("%1d", &array[i]);
    }
}

void sumArray(int array1[], int array2[], int sum[], int length)
{
    int carry = 0;  //进位
    for (int i = length - 1; i >= 0; i--) {
        printf("Now the carry is %d.\n", carry);          //debug
        sum[i+1] = ( array1[i] ^ array2[i] ) ^ carry;
        printf("Now the number at %d of sum is %d.\n", i+1, sum[i+1]);   //debug
        if (array1[i] + array2[i] + carry >= 2) {
            carry = 1;
            puts("This time carry = 1.");     //debug
        }
        else {
            carry = 0;
            puts("This time carry = 0.");     //debug
        }
    }
    printf("At last carry = %d\n", carry);
    sum[0] = carry;
}

void showArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d", array[i]);
    puts("");    //print the '\n'
}