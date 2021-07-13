#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
float Convert (float f)
{
    float c=5*(f-32)/9;
    return c;
}
int main()
{
    setlocale(LC_ALL,"portuguese");
    float celsium,fahrenheit;
    printf("Digite um valor em fahrenheit: ");
    scanf("%f",&fahrenheit);
    celsium= Convert (fahrenheit);
    printf("O valor em celsium: %.2f\n",celsium);



    system("pause");
    return 0;
}
