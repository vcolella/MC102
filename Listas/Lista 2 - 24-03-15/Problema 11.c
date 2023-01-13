#include <stdio.h>

int main()
{
    int N,intervalo[4]={0,0,0,0},i=0;
    printf("Digite a quantidade de numeros a serem inseridos: ");
    scanf("%d", &N);
    printf("Digite os numeros:");

    float n[N];

    for(i=0;i<N;i++)
    {
        scanf(" %f", &n[i]);
        if(n[i]>=0 && n[i]<=25)
        {
            intervalo[0]++;
        }
        else if(n[i]>=26 && n[i]<=50)
        {
            intervalo[1]++;
        }
        else if(n[i]>=51 && n[i]<=75)
        {
            intervalo[2]++;
        }
        else if(n[i]>=76 && n[i]<=100)
        {
            intervalo[3]++;
        }
    }
    printf("Intervalo [0..25]: %d\nIntervalo [26..50]: %d\nIntervalo [51..76]: %d\nIntervalo [76..100]: %d\n", intervalo[0],intervalo[1],intervalo[2],intervalo[3]);

    return 0;
}
