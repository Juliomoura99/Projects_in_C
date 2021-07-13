
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define max 20

/*-------------------- Structs --------------------*/
typedef struct No{
    char nome[max];
    int prioridade;
    int idade;
    int tempo;
    struct no *prox;
} no;

typedef struct Fila{
    int quant_atendidos;
    int quant;
    int tempo_total;
    no *ini;
    no *fim;
} fila;

/*-------------------- Funcao de criar as filas --------------------*/
fila *criar_fila()
{
    fila *f;
    f = (fila *)malloc(sizeof(fila));
    f->quant = 0;
    f->quant_atendidos = 0;
    f->tempo_total = 0;
    f->ini = f->fim = NULL;
    return f;
}

/*-------------------- Funcao de impressao do menu --------------------*/
void menu()
{
    printf("\tBEM VINDO AO BANCO");
    printf("\n ");
    printf("__________________________________________");
    printf("\t\n 1 > Inserir um cliente ");
    printf("\t\n 2 > Imprimir relatorio das filas");
    printf("\t\n 3 > Imprimir todas as filas");
    printf("\t\n 4 > Rodar programa");
    printf("\t\n 0 > Encerrar o programa \n");
    printf("__________________________________________");
}

/*-------------------- Funcao de insercao na fila --------------------*/
no* geraNo()
{
    no *p = (no *)malloc(sizeof(no)); //Aloca espaco para um no
    printf("\t    > CADASTRO DE CLIENTE <\n"); //Faz as perguntas para colher as informacoes dos clientes
    printf("\n > Nome do cliente: ");
    fflush(stdin);
    gets(p->nome);
    printf(" > Idade do cliente: ");
    fflush(stdin);
    scanf("%d", &p->idade);
    printf("-------------------------------------------");
    printf("\n > O cliente atende a um destes quadros?");
    printf("\n - Mais de 60 anos");
    printf("\n - Gestante");
    printf("\n - Crianca de colo");
    printf("\n\n > 1 - SIM  |  0 - NAO. \n   ");
    scanf("%d", &p->prioridade);
    p->tempo = (rand()% 10) + 1; //Passa um numero randomico para a pessoa = tempo de espera na fila da mesma
    p->prox = NULL; //proximo do no eh null

    return p;
}

/*-------------------- Funcao que insere na fila --------------------*/

void *ins_fila(fila *f, no *no)
{
    f->tempo_total+= no->tempo; //Acresce tempo da pessoas inserida no tempo total daquela fila
    no->tempo = f->tempo_total; //Passa tempo total da fila para o tempo do ultimo da fila(pessoa que acbou de inserida)

    if (f->fim != NULL) //Caso a fila esteja vazia
    {
        f->fim->prox = no;
        f->fim = no;
    }else //Caso seja o primeiro da fila
    {
        f->fim = no;
        f->ini = no;
    }
    f->quant++;
}

/*-------------------- Funcao de insercao no comeco da fila --------------------*/
void *troca_preferencial(fila *fila1,fila *fila2) //fila1 = preferencial e fila2 = normal
{
    if(vazia(fila1))
        return;

    no *aux = fila1->ini;  //inicio fila preferencial = no auxiliar

    fila1->ini = fila1->ini->prox; //1º fila preferencial recebe 2º preferencial

    aux->prox = fila2->ini; //aux->prox recebe o inicio da fila normal

    fila2->ini = aux; //inicio da fila normal passa a ser aux (inicio da fila do preferencial)

    fila1->quant--; //diminui quantidade pessoas na preferencial
    fila2->quant++; //Aumenta quantidade pessoas na normal

    no *aux2;

    fila1->tempo_total-=aux->tempo; // É subtraido o tempo da pessoa retirada da preferencial do tempo total

    for(aux2 = fila1->ini; aux2!=NULL; aux2 = aux2->prox) //aux2 percorre toda preferencial
    {
        aux2->tempo-=aux->tempo; //Subtrai tempo da pessoa retirada de todas as pessoas da preferencial
    }

    fila2->tempo_total+=aux->tempo; //tempo total da fila normal recebe tempo da pessoa inserida
    for(aux2 = fila1->ini->prox; aux2!=NULL; aux2 = aux2->prox)//percorre toda fila2
    {
        aux2->tempo+=aux->tempo; //Acresce tempo da pessoa inserida em todas as pessoas da normal
    }
}

/*-------------------- Funcao de retirar o cliente da fila --------------------*/
void retira_cliente(fila *f)
{
    if (vazia(f) == 1){
        printf("Fila vazia.\n");
        return;
    }

    no *aux = f->ini; //aux recebe inicio da fila(cliente que será retirado)

    f->ini = f->ini->prox; // 2º da fila passa a ser o 1º da fila

    f->quant_atendidos++; //Acresce uma pessoa atendida já que seu tempo chegou a zero

    f->quant--; //Diminui uma pessoa da fila ja que a mesma vai ser retirada

    if(f->ini == NULL) f->fim == NULL;
    free(aux); //libera no do codigo
}

/*-------------------- Funcao de analisar as filas para poder realizar a insercao do cliente --------------------*/

void verificaPreferencial(fila *Fila1, fila *Fila2, fila *Fila3, fila *Fila4, fila *FilaPreferencial)
{
    if(FilaPreferencial->quant>5 && (FilaPreferencial->tempo_total / ((float) FilaPreferencial->quant))>5) //condicoes para verificar se vai tirar da preferencial e colocar na normal
    {
        int qtdPessoas[4], aux; // declara vetor referente a quantidade de pessoas em cada fila
        int filaPessoas[4] = {1,2,3,4}; //declaracao de vetor referente as filas normais
        qtdPessoas[0] = Fila1->quant; //cada posiçao do vetor "quantidade de pessoas", recebe a "quantidade de pessoas" em cada fila normal
        qtdPessoas[1] = Fila2->quant;
        qtdPessoas[2] = Fila3->quant;
        qtdPessoas[3] = Fila4->quant;

        for(int i = 0; i<4; i++){ //Ordenacao do vetor (Lógica Bubble sort)
            for(int j = 0; j<3; j++){
                if(qtdPessoas[j]>qtdPessoas[j+1]){ //Se a quantidade de pessoas na primeira fila for maior que na segunda fila entra no if
                    aux = qtdPessoas[j]; //auxiliar recebe quantidade de pessoas na primeira fila
                    qtdPessoas[j] = qtdPessoas[j+1];//quantidade de pessoas na fila um recebe quantidade de pessoas na fila dois
                    qtdPessoas[j+1] = aux;//quantidade de pessoas da fila dois recebe auxiliar

                    aux = filaPessoas[j]; //auxiliar recebe fila1
                    filaPessoas[j] = filaPessoas[j+1];//fila 1 recebe fila 2
                    filaPessoas[j+1] = aux; //fila 2 recebe aux
                }
            }
        }

        switch(filaPessoas[0]){ //Fila preferencial 
            case 1:
                troca_preferencial(FilaPreferencial,Fila1); //Faz as trocas da preferencial para as normais
                break;
            case 2:
                troca_preferencial(FilaPreferencial,Fila2);
                break;
            case 3:
                troca_preferencial(FilaPreferencial,Fila3);
                break;
            case 4:
                troca_preferencial(FilaPreferencial,Fila4);
                break;
        }
    }
}

/*-------------------- Funcao de insercao de clientes --------------------*/


void insere_cliente(fila *Fila1, fila *Fila2, fila *Fila3, fila *Fila4, no *no)
{
    int qtdPessoas[4], aux;
    int filaPessoas[4] = {1,2,3,4}; //Mesma logica bubble sort para inserir na melhor fila normal quando a pessoa é inserida sem ser da preferencial
    qtdPessoas[0] = Fila1->quant;
    qtdPessoas[1] = Fila2->quant;
    qtdPessoas[2] = Fila3->quant;
    qtdPessoas[3] = Fila4->quant;

    for(int i = 0; i<4; i++){
        for(int j = 0; j<3; j++){
            if(qtdPessoas[j]>qtdPessoas[j+1]){
                aux = qtdPessoas[j];
                qtdPessoas[j] = qtdPessoas[j+1];
                qtdPessoas[j+1] = aux;

                aux = filaPessoas[j];
                filaPessoas[j] = filaPessoas[j+1];
                filaPessoas[j+1] = aux;
            }
        }
    }

    switch(filaPessoas[0]){
        case 1:
            ins_fila(Fila1, no);
            break;
        case 2:
            ins_fila(Fila2, no);
            break;
        case 3:
            ins_fila(Fila3, no);
            break;
        case 4:
            ins_fila(Fila4, no);
            break;
    }
}

/*-------------------- Funcao de verificar se a fila esta vazia --------------------*/
int vazia(fila *f)
{
    if (f->ini == NULL) return 1;
    else return 0;
}

/*-------------------- Funcao de impressco dos clientes por fila --------------------*/
void imprime(fila *f)
{
    for (no *p = f->ini; p != NULL; p = p->prox){
        printf("Nome:%s\t", p->nome);
        printf("Idade:%d\t", p->idade);
        printf("Prioridade:->%d<-\t", p->prioridade);
        printf("Quando tempo demorara na fila:%d\t", p->tempo);

        printf("\n");
    }
    printf("\n");
    printf("Contagem:%d\n", f->quant);

    for(int i=0; i<100; i++)
        printf("-");

    printf("\n");
}

/*-------------------- Funcao de reducao do tempo das filas --------------------*/
void *relatorio_filas(fila *f)
{
    no *p;
    printf("\n > Quantidade de pessoas: %d\t", f->quant);
    printf("Quantidade de pessoas atendidas: %d\t", f->quant_atendidos);

    if(vazia(f)){
        printf("\n > Tempo medio da fila : 0 (Ninguem na fila)");
        printf("\n");
    }

    else{
        printf("\n > Tempo medio da fila: %.2f", (f->tempo_total / (float)f->quant));
        printf("\n");
    }
     printf("\n> Ordem da fila:\n");
    for (p = f->ini; p != NULL; p = p->prox)
        printf("Nome:%s\t\tTempo:%d\n", p->nome, p->tempo);

    printf("___________________________________________________________________________________________");
    printf("\n");
}

/*-------------------- Funcao de rodar "tempo" do programa --------------------*/
void *roda_programa(fila *f)
{
    if(vazia(f))
    {
        return;
    }
    no *aux;

    f->tempo_total--; //Diminui tempo total da fila correspondente para simular um ciclo de tempo
    for (aux = f->ini; aux != NULL; aux = aux->prox)
        aux->tempo--; //Diminui tempo de todos os clientes da fila

    if(f->ini->tempo == 0) retira_cliente(f); //condicao que se o tempo do cliente for zero quer dizer que o mesmo foi atendido logo eh retirado da fila
}

/*-------------------- Funcao que libera as filas--------------------*/


void libera_tudo (fila *fila1,fila *fila2,fila *fila3, fila *fila4, fila *FilaPreferencial)
{
    free(fila1);
    free(fila2);
    free(fila3);
    free(fila4);
    free(FilaPreferencial);
}

/*-------------------- Programa main --------------------*/
int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL)); //Seta diferentes combinacoes de numeros randomicos tendo em vista que o programa sera rodado varias vezes
    fila *Fila1, *Fila2, *Fila3, *Fila4, *FilaPreferencial; //cria todas as filas
    Fila1 = criar_fila();
    Fila2 = criar_fila();
    Fila3 = criar_fila();
    Fila4 = criar_fila();
    FilaPreferencial = criar_fila();

    int option, continuar, op;
    do{
        system("cls");
        menu(); //Chama funcao de menu e a imprime na tela
        printf("\n\n Selecione uma opcao: ");
        scanf("%d", &option); //pede um inteiro para vereficar qual acao sera feita
        system("cls");
        switch (option)
        {
            case 1:
                do{
                    no* aux = geraNo(); //por ser do tipo no eh igualado a um no, enquanto eh chamada a funcao
                    if(aux->prioridade != 1) //Se prioridade eh diferente de 1, ou seja, nao eh preferencial
                        insere_cliente(Fila1, Fila2, Fila3, Fila4, aux); 
                    else{ //Se for preferencial
                        ins_fila(FilaPreferencial, aux); //Insere na preferencial
                        verificaPreferencial(Fila1, Fila2, Fila3, Fila4, FilaPreferencial); //Se a preferencial estiver cheia, faz o rodizio entre as normais e coloca em uma delas
                    }
                    printf("\n Deseja cadastrar mais?  1[SIM] ou 0[NAO] ");
                    scanf("%d", &op);
                    system("cls");

                }while(op == 1); //repete processo enquanto o usuario desejar inserir mais clientes de uma vez
                break;

            case 2:
                system("cls");
                printf("Relatorio da fila Preferencial:\n");
                relatorio_filas(FilaPreferencial);
                printf("Relatorio da fila 1:\n");
                relatorio_filas(Fila1);
                printf("Relatorio da fila 2:\n");
                relatorio_filas(Fila2);
                printf("Relatorio da fila 3:\n");
                relatorio_filas(Fila3);
                printf("Relatorio da fila 4:\n");
                relatorio_filas(Fila4);
                system("pause");
                break;

            case 3:
                printf("\nFila Preferencial\n\n");
                imprime(FilaPreferencial);
                printf("\nFila 1\n");
                imprime(Fila1);
                printf("\nFila 2\n");
                imprime(Fila2);
                printf("\nFila 3\n");
                imprime(Fila3);
                printf("\nFila 4\n");
                imprime(Fila4);
                system("pause");
                break;
            case 4:
                roda_programa(FilaPreferencial);
                roda_programa(Fila1);
                roda_programa(Fila2);
                roda_programa(Fila3);
                roda_programa(Fila4);
                break;

            default:
                printf("Finalizou o programa"); 
            }
    }while (option != 0);

    libera_tudo(Fila1, Fila2, Fila3, Fila4, FilaPreferencial); //da um free em todas as filas e desaloca tudo
    return 0; //Finaliza programa
}

