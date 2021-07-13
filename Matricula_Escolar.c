#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 5
#define TAM 20

struct alunos //Struct alunos contendo variavel de nome e ra do aluno(a)
{
    char nome_a[TAM];
    int ra;
    char disciplinas[TAM][TAM]; //Matriz usada para os vinculos
};
struct disciplinas //Struct disciplinas contendo variavel de nome e c�digo da disciplina
{
    char nome_d[TAM];
    int cod;
    char alunos[TAM][TAM];
    char professores[TAM][TAM];
};

struct professores //Struct professores contendo variavel nome e codigo dos professores
{
    char nome_p[TAM];
    int cod1;
    char disciplinas[TAM][TAM];
};

void menu() //Procedimento de cria��o do menu inicial (com itens para serem selecionados)
{
    printf("\n");
    printf("-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+-----+-----+");
    printf("\n\t\t\t   M E N U   P R I N C I P A L\t\t\t      |");
    printf("\n 1 - Cadastro de alunos\t\t\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 2 - Cadastro de Disciplinas\t\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 3 - Cadastro de Professores\t\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 4 - Fazer matr�cula\t\t\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 5 - Vincular conjunto de professores com conjunto de disciplinas             |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 6 - Impress�es\t\t\t\t\t\t\t              |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 7 - Cancelamentos\t\t\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 8 - Sair do programa\t\t\t\t\t\t\t      |");
    printf("\n");
    printf("-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+-----+-----+");
}

void impressao_menu() //Procedimento de cria��o do menu de impress�o (caso for selecionado para imprimir as informa��es)
{
    system("cls");
    printf("-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+-----+-----+");
    printf("\n\t\t\t\tI M P R E S S � E S\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 1 - Lista de todos os alunos\t\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 2 - Lista de todas as disciplinas\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 3 - Lista de todos os profesores\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 4 - Lista de alunos em uma disciplina\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 5 - Lista de disciplinas de um aluno\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 6 - Lista de todas as disciplinas ministradas por um professor\t              |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 7 - Lista de todos os professores vinculadas a uma disciplina\t              |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n 8 - Voltar para o menu principal\t\t\t\t\t      |\n\t\t\t\t\t\t\t\t\t      |");
    printf("\n");
    printf("-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+-----+-----+");
    printf("\n");
}

void cancelamento_menu() //Procedimento de cria��o do menu de cancelamento
{
    system("cls");
    printf("-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+-----+-----+");
    printf("\n\t\t\t\tC A N C E L A M E N T O S");
    printf("\n 1 - Cancelar Cadastro Aluno: ");
    printf("\n 2 - Cancelar Cadastro Professor: ");
    printf("\n 3 - Cancelar Cadastro Disciplina: ");
    printf("\n 4 - Desvincular um conjunto de professores de um conjunto de disciplinas");
    printf("\n 5 - Cancelar um conjunto de alunos de um conjunto de disciplinas ");
    printf("\n 6 - Voltar para o menu principal");
    printf("\n");
    printf("-----+-----+-----+-----+------+-----+-----+-----+-----+-----+-----+-----+-----+");
    printf("\n");
}

void cadastro_alunos(struct alunos aluno[]) //Procedimento de realizar o cadastro dos alunos
{
    int quant, aux;
    system("cls");
    printf("Quantos alunos deseja cadastrar: ");
    scanf("%d", &quant);
    for (int k = 0; k < quant; k++)
    {

        for (int i = 0; i < TAM; i++)
        {

            if (strcmp(aluno[i].nome_a, "NULL") == 0) //Verificar se a variavel aluno[i].nome_a tem algo ou n�o
            {
                printf("Nome do aluno: "); //Inicia o pedido do/dos nomes
                fflush(stdin);
                gets(aluno[i].nome_a);

                do
                {
                    aux = 0; //variavel usada para verificar o RA
                    printf("RA (4 digitos): ");
                    scanf("%d", &aluno[i].ra);
                    for (int k = 0; k < i; k++)
                    {
                        if (aluno[k].ra == aluno[i].ra && k != i) //Aqui para repeti��o do RA
                        {
                            aux = 1;
                            printf("RA j� cadastrado!\n");
                            system("pause");
                        }
                    }
                    if (aluno[i].ra < 1000 || aluno[i].ra > 9999) //Aqui para o formato do RA
                    {
                        aux = 1;
                        printf("Formato de RA invalido!\n");
                        system("pause");
                    }

                } while (aux != 0); //Condi��o para repetir o pedido do RA
                break;
            }
        }
    }
    system("cls");
}

void cadastro_disciplinas(struct disciplinas disciplina[]) //Procedimento de realizar o cadastro das disciplinas
{
    int quant, aux;
    system("cls");
    printf("Quantas disciplinas deseja cadastrar: ");
    scanf("%d", &quant);
    for (int k = 0; k < quant; k++)
    {

        for (int i = 0; i < TAM; i++)
        {

            if (strcmp(disciplina[i].nome_d, "NULL") == 0)
            {
                printf("Nome da disciplina: ");
                fflush(stdin);
                gets(disciplina[i].nome_d);

                do
                {
                    aux = 0;
                    printf("C�digo (3 digitos): ");
                    scanf("%d", &disciplina[i].cod);
                    for (int k = 0; k < i; k++)
                    {
                        if (disciplina[k].cod == disciplina[i].cod && k != i)
                        {
                            aux = 1;
                            printf("Codigo j� cadastrado!\n");
                            system("pause");
                        }
                    }
                    if (disciplina[i].cod < 100 || disciplina[i].cod > 999)
                    {
                        aux = 1;
                        printf("Formato de C�digo invalido!\n");
                        system("pause");
                    }

                } while (aux != 0);
                break;
            }
        }
    }
    system("cls");
}

void cadastro_professores(struct professores professor[]) //Procedimento de realizar o cadastro de professores
{
    int quant, aux;
    system("cls");
    printf("Quantos professores deseja cadastrar: ");
    scanf("%d", &quant);
    for (int k = 0; k < quant; k++)
    {

        for (int i = 0; i < TAM; i++)
        {

            if (strcmp(professor[i].nome_p, "NULL") == 0)
            {
                printf("Nome do professor: ");
                fflush(stdin);
                gets(professor[i].nome_p);

                do
                {
                    aux = 0;
                    printf("C�digo (2 digitos): ");
                    scanf("%d", &professor[i].cod1);
                    for (int k = 0; k < i; k++)
                    {
                        if (professor[k].cod1 == professor[i].cod1 && k != i)
                        {
                            aux = 1;
                            printf("C�digo j� cadastrado!\n");
                            system("pause");
                        }
                    }
                    if (professor[i].cod1 < 10 || professor[i].cod1 > 99)
                    {
                        aux = 1;
                        printf("Formato de C�digo invalido!\n");
                        system("pause");
                    }

                } while (aux != 0);
                break;
            }
        }
    }
    system("cls");
}

void imprime_alunos(struct alunos aluno[]) //Procedimento de impress�o da lista de alunos caso desejado
{
    system("cls");
    printf("Lista de alunos:\n");
    printf("\t      RA       -      Nome \n");

    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(aluno[i].nome_a, "NULL") != 0) //Se vari�vel aluno[i].nome_a ter algo diferente de NULL significa que tem um nome
                                                  //Logo, ele printa na tela o nome
        {
            printf("\n\t      %d     -     %s      \n", aluno[i].ra, aluno[i].nome_a);
        }
    }
}

void imprime_disciplinas(struct disciplinas disciplina[]) //Procedimento de impress�o da lista de disciplina caso desejado
{
    system("cls");
    printf("Lista de disciplinas:\n");
    printf("\t      C�digo       -      Nome \n");
    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(disciplina[i].nome_d, "NULL") != 0)
        {
            printf("\n\t       %d        -     %s      \n", disciplina[i].cod, disciplina[i].nome_d);
        }
    }
}

int verifica_repeticao_nome_aluno(struct disciplinas disciplina[], char estudante[TAM][TAM], char materia[TAM][TAM])
{
    int cont, aux = 1;  //Funcao que verifica se o nome do aluno ja foi vinculado aquela materia ou nao, repetindo a pergunta
    int aux2 = 0, aux3 = 0;

    for (int i = 0; i < TAM; i++)
    {
        for (int l = i; l < TAM; l++)
        {
            if (strcmp(disciplina[i].nome_d, materia[l]) == 0 && strcmp(disciplina[i].nome_d, "NULL") != 0)
            {

                for (int j = 0; j < TAM; j++)
                {
                    for (int k = j; k < TAM; k++)
                    {
                        if (strcmp(disciplina[i].alunos[j], estudante[k]) == 0 && strcmp(disciplina[i].alunos[j], "NULL") != 0)
                        {
                            aux3++; //contador auxiliar para entrar no if
                            if (aux3 >= 1) //se n�o for igual a zero entra
                            {
                                do
                                {
                                    printf("O aluno %s ja existe na disciplina %s", estudante[k], disciplina[i].nome_d);
                                    printf("\n\nDeseja cadastrar alunos com mesmo nome? [1] SIM  [2] N�O");
                                    scanf("%d", &aux);
                                } while (aux <= 1 && aux >= 2); //repetir a pergunta caso for = 1
                                break;
                            }
                        }
                    }

                    break;
                }
                aux2++; //variavel auxuliar para futuras matriculas
                break;
            }
            break;
        }
    }

    return aux;
}

int verifica_repeticao_nome_professor(struct disciplinas disciplina[], char prof[TAM][TAM], char materia[TAM][TAM])
{
    int cont, aux = 1;
    int aux2 = 0, aux3 = 0;

    for (int i = 0; i < TAM; i++)
    {
        for (int l = i; l < TAM; l++)
        {
            if (strcmp(disciplina[i].nome_d, materia[l]) == 0 && strcmp(disciplina[i].nome_d, "NULL") != 0)
            {

                for (int j = 0; j < TAM; j++)
                {
                    for (int k = j; k < TAM; k++)
                    {
                        if (strcmp(disciplina[i].professores[j], prof[k]) == 0 && strcmp(disciplina[i].professores[j], "NULL") != 0)
                        {
                            aux3++;
                            if (aux3 >= 1)
                            {

                                do
                                {
                                    printf("O professor %s ja existe na disciplina %s", prof[k], disciplina[i].nome_d);
                                    printf("\n\nDeseja cadastrar professores com mesmo nome? [1] SIM  [2] N�O");
                                    scanf("%d", &aux);

                                } while (aux <= 1 && aux >= 2);
                                break;
                            }
                        }
                    }

                    break;
                }
                aux2++;
                break;
            }
            break;
        }
    }

    return aux;
}

void imprime_professores(struct professores professor[]) //Procedimento de impress�o da lista de professores caso desejado
{
    system("cls");
    printf("Lista de professores:\n");
    printf("\t      C�digo       -      Nome \n");
    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(professor[i].nome_p, "NULL") != 0)
        {
            printf("\n\t        %d       -       %s      \n", professor[i].cod1, professor[i].nome_p);
        }
    }
}

void matricula(struct alunos aluno[], struct disciplinas disciplina[])
{
    char estudante[TAM][TAM];
    char materia[TAM][TAM];
    int aux = 0, aux2 = 0, escolha, cont = 0, cont2 = 0;
    for (int i = 0; i < TAM; i++)
    {
        strcpy(estudante[i], "NULL"); //Inicia variavel estudante e materia com NULL para n�o ter lixo e prejudicar a logica futuramente
        strcpy(materia[i], "NULL");
    }

    do //Do-> controla se o usuario quer matricular mais alunos ou n�o
    {
        system("cls");
        imprime_alunos(aluno);
        printf("Digite o nome do aluno que deseja matricular: "); //Pergunta o nome do aluno
        fflush(stdin);
        gets(estudante[cont]); //Usuario digita o nome
        for (int i = 0; i < TAM; i++)
        {
            if (strcmp(estudante[cont], aluno[i].nome_a) == 0) //Nesse if, elecompara com o vetor aluno para verificar se existe o aluno
            {
                escolha = 0; //Variavel de controle para verifica��o de existencia dos alunos
                break;
            }
            else
            {
                escolha = 1;
            }
        }
        if (escolha == 1)
        {
            printf("Aluno inexistente! Tente outro. \n"); //Mensagem caso aluno n�o tenha sido cadastrado
            system("pause");
        }
        else
        {
            cont += 1;

            printf("Deseja incluir mais aluno? [1-SIM ou 2-N�O]");
            scanf("%d", &escolha);
        }
    } while (escolha != 2 && cont < TAM);

    do
    {
        system("cls");
        imprime_disciplinas(disciplina); //chama funcao para aparecer a tabela de disciplinas
        printf("Digite o nome da disciplina em que os alunos serao incluidos: ");
        fflush(stdin);
        gets(materia[cont2]);
        escolha = 3;
        if (verifica_repeticao_nome_aluno(disciplina, estudante, materia) == 1) //if funcao for falsa
        {

            for (int i = 0; i < TAM; i++)
            {
                if (strcmp(materia[cont2], disciplina[i].nome_d) == 0)
                {
                    escolha = 0;
                    break;
                }
                else
                {
                    escolha = 1; //escolha fica igual a 1 para entrar no if
                }
            }

            if (escolha == 1) //If mostra que materia != materias dentro do vetor disciplina
            {
                printf("Disciplina inexistente! Tente outra. \n");
                system("pause");
            }
            else
            {
                cont2 += 1;
                printf("Deseja incluir mais disciplina? [1-SIM ou 2-N�O]");
                scanf("%d", &escolha);
            }
        }
    } while (escolha != 2 && cont2 < TAM); //variavel auxiliar que repete todo o processo

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(materia[i], disciplina[j].nome_d) == 0)
            {
                for (int k = 0; k < TAM; k++)
                {

                    if (strcmp(disciplina[j].alunos[k], "NULL") == 0) //Se n�o for igual a NULL entra
                    {
                        strcpy(disciplina[j].alunos[k], estudante[aux]); //copia estudante no vetor disciplina[j].alunos[k]
                        aux++;
                    }

                    else if (aux == cont)
                        break;
                }
            }
            aux = 0;
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(estudante[i], aluno[j].nome_a) == 0)
            {
                for (int k = 0; k < TAM; k++)
                {
                    if (strcmp(aluno[j].disciplinas[k], "NULL") == 0)
                    {

                        strcpy(aluno[j].disciplinas[k], materia[aux2]);
                        aux2++;
                    }
                    else if (aux2 == cont2)
                        break;
                }
            }
            aux2 = 0;
        }
    }
}

void vinculo1(struct disciplinas disciplina[], struct professores professor[])
{
    char prof[TAM][TAM];
    char materia[TAM][TAM];
    int aux = 0, aux2 = 0, escolha, cont = 0, cont2 = 0;
    for (int i = 0; i < TAM; i++)
    {
        strcpy(prof[i], "NULL");
        strcpy(materia[i], "NULL");
    }
    do
    {
        system("cls");
        imprime_professores(professor);
        printf("Digite o nome do professor que deseja vincular: ");
        fflush(stdin);
        gets(prof[cont]);
        for (int i = 0; i < TAM; i++)
        {
            if (strcmp(prof[cont], professor[i].nome_p) == 0)
            {
                escolha = 0;
                break;
            }
            else
            {
                escolha = 1;
            }
        }

        if (escolha == 1)
        {
            printf("Professor inexistente! Tente outro nome. \n");
            system("pause");
        }
        else
        {
            cont += 1;

            printf("Deseja incluir mais professores? [1-SIM ou 2-N�O]");
            scanf("%d", &escolha);
        }
    } while (escolha != 2 && cont < TAM);

    do
    {
        system("cls");
        imprime_disciplinas(disciplina);
        printf("Digite o nome da disciplina em que os professores serao vinculados: ");
        fflush(stdin);
        gets(materia[cont2]);
        escolha = 3;
        if (verifica_repeticao_nome_professor(disciplina, prof, materia) == 1)
        {

            for (int i = 0; i < TAM; i++)
            {
                if (strcmp(materia[cont2], disciplina[i].nome_d) == 0)
                {
                    escolha = 0;
                    break;
                }
                else
                {
                    escolha = 1;
                }
            }

            if (escolha == 1)
            {
                printf("Disciplina inexistente! Tente outra \n");
                system("pause");
            }
            else
            {
                cont2 += 1;
                printf("Deseja incluir mais disciplina? [1-SIM ou 2-N�O]");
                scanf("%d", &escolha);
            }
        }
    } while (escolha != 2 && cont2 < TAM);

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(materia[i], disciplina[j].nome_d) == 0)
            {
                for (int k = 0; k < TAM; k++)
                {
                    if (strcmp(disciplina[j].professores[k], "NULL") == 0)
                    {
                        strcpy(disciplina[j].professores[k], prof[aux]);
                        aux++;
                    }
                    else if (aux == cont)
                        break;
                }
            }
            aux = 0;
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(prof[i], professor[j].nome_p) == 0)
            {
                for (int k = 0; k < TAM; k++)
                {

                    if (strcmp(professor[j].disciplinas[k], "NULL") == 0)
                    {
                        strcpy(professor[j].disciplinas[k], materia[aux2]);
                        aux2++;
                    }
                    else if (aux2 == cont2)
                        break;
                }
            }
            aux2 = 0;
        }
    }
}

void imprime_matriculas(struct alunos aluno[], struct disciplinas disciplina[])
{
    int i, j;
    system("cls");
    printf("Lista de Disciplinas de 1 aluno\n");
    printf("______________________\n");
    for (i = 0; i < TAM; i++)
    {
        if (strcmp(aluno[i].nome_a, "NULL") != 0)
        {
            printf("\n%s :", aluno[i].nome_a);
            printf("\t");
            for (j = 0; j < TAM; j++)
            {
                if (strcmp(aluno[i].disciplinas[j], "NULL") != 0)
                {
                    printf(" %s  \n\t", aluno[i].disciplinas[j]);
                }
            }
            printf("\n_____________________");
        }
    }
    system("pause");
    system("cls");
}

void imprime_lista_alunos_disciplina(struct alunos aluno[], struct disciplinas disciplina[])
{
    int i, j;
    system("cls");
    printf("Lista de Alunos em 1 disciplina\n");
    printf("______________________\n");
    for (j = 0; j < TAM; j++)
    {
        if (strcmp(disciplina[j].nome_d, "NULL") != 0)
        {
            printf("\n%s:", disciplina[j].nome_d);
            printf("\t");
            for (i = 0; i < TAM; i++)
            {
                if (strcmp(disciplina[j].alunos[i], "NULL") != 0)
                {
                    printf(" %s    \n\t", disciplina[j].alunos[i]);
                }
            }
            printf("\n_____________________");
            printf("\n\n");
        }
    }
    system("pause");
    system("cls");
}

void imprime_pd(struct professores professor[], struct disciplinas disciplina[])
{
    system("cls");
    printf("Lista de Disciplinas de 1 professor\n");
    printf("______________________\n");
    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(professor[i].nome_p, "NULL") != 0)
        {
            printf("\n%s :", professor[i].nome_p);
            printf("\t");
            for (int j = 0; j < TAM; j++)
            {
                if (strcmp(professor[i].disciplinas[j], "NULL") != 0)
                {
                    printf(" %s \n\t", professor[i].disciplinas[j]);
                }
            }
            printf("\n_____________________");
        }
    }
    system("pause");
    system("cls");
}

void imprime_dp(struct disciplinas disciplina[], struct professores professor[])
{
    system("cls");
    printf("Lista de Professores em 1 disciplina\n");
    printf("______________________\n");
    for (int j = 0; j < TAM; j++)
    {
        if (strcmp(disciplina[j].nome_d, "NULL") != 0)
        {
            printf("\n%s:", disciplina[j].nome_d);
            printf("\t");
            for (int i = 0; i < TAM; i++)
            {
                if (strcmp(disciplina[j].professores[i], "NULL") != 0)
                {
                    printf(" %s    \n\t", disciplina[j].professores[i]);
                }
            }
            printf("\n_____________________");
            printf("\n\n");
        }
    }
    system("pause");
    system("cls");
}

void cancelamento_matricula_aluno(struct alunos aluno[], struct disciplinas disciplina[])
{
    char estudante[TAM];
    int aux = 0;
    char aux2[TAM];
    int aux3;
    system("cls");
    imprime_alunos(aluno); //chama funcao impressao alunos para facilitar escolha dos mesmos para cancelamento
    printf("Digite o nome do aluno que deseja cancelar a matricula: ");  //printa na tela
    fflush(stdin);
    gets(estudante); //usuario digita nome do aluno que deseja cancelar

    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(estudante, aluno[i].nome_a) == 0) //se for verdade
        {

            aux = 1; //variavel passa a valer 1
            aux3 = i; //aux 3 passa a valer posicao i
            strcpy(aux2, aluno[i].nome_a); //copia nome do aluno na variavel auxiliar 2
            strcpy(aluno[i].nome_a, "NULL");
            aluno[i].ra = 0; //ra do aluno passa a valer 0
        }
    }
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(aluno[aux3].disciplinas[i], disciplina[j].nome_d) == 0)//se for verdade entra
            {
                for (int k = 0; k < TAM; k++)
                {
                    if (strcmp(disciplina[j].alunos[k], aux2) == 0) //se for iguais entra,obs: aux2 = aluno[i].nome_a
                    {
                        strcpy(disciplina[j].alunos[k], "NULL"); //NULL � copiado em disciplina[j].alunos[k]
                    }
                }
            }
        }
    }
    printf("Cancelamento Feito com sucesso !! \n");
    system("pause"); //sistema espera usuario digitar uma tecla para continuar
    if (aux == 0)
    {
        printf("Nao foi encontrado nenhum aluno com esse nome");
    }
}

void cancelamento_matricula_professor(struct professores professor[], struct disciplinas disciplina[])
{
    char prof[TAM];
    int aux = 0;
    char aux2[TAM];
    int aux3;
    system("cls");
    imprime_professores(professor);
    printf("Digite o nome do professor que deseja cancelar o cadastro: ");
    fflush(stdin);
    gets(prof);

    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(prof, professor[i].nome_p) == 0)
        {

            aux = 1;
            aux3 = i;
            strcpy(aux2, professor[i].nome_p);
            strcpy(professor[i].nome_p, "NULL");
            professor[i].cod1 = 0;
        }
    }
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(professor[aux3].disciplinas[i], disciplina[j].nome_d) == 0)
            {
                for (int k = 0; k < TAM; k++)
                {
                    if (strcmp(disciplina[j].professores[k], aux2) == 0)
                    {
                        strcpy(disciplina[j].professores[k], "NULL");
                    }
                }
            }
        }
    }
    printf("Cancelamento Feito com sucesso !! \n");
    system("pause");
    if (aux == 0)
    {
        printf("Nao foi encontrado nenhum professor com esse nome");
    }
}

void cancelamento_matricula_disciplina(struct disciplinas disciplina[], struct alunos aluno[], struct professores professor[])
{
    char materia[TAM];
    int aux = 0;
    char aux2[TAM];
    int aux3;
    system("cls");
    imprime_disciplinas(disciplina);
    printf("Digite o nome da disciplina que deseja cancelar o cadastro: ");
    fflush(stdin);
    gets(materia);

    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(materia, disciplina[i].nome_d) == 0)
        {

            aux = 1;
            aux3 = i;
            strcpy(aux2, disciplina[i].nome_d);
            strcpy(disciplina[i].nome_d, "NULL");
            disciplina[i].cod = 0;
        }
    }
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(disciplina[aux3].alunos[i], aluno[j].nome_a) == 0)
            {
                for (int k = 0; k < TAM; k++)
                {
                    if (strcmp(aluno[j].disciplinas[k], aux2) == 0)
                    {
                        strcpy(aluno[j].disciplinas[k], "NULL");
                    }
                }
            }
        }
    }
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(disciplina[aux3].professores[i], professor[j].nome_p) == 0)
            {
                for (int k = 0; k < TAM; k++)
                {
                    if (strcmp(professor[j].disciplinas[k], aux2) == 0)
                    {
                        strcpy(professor[j].disciplinas[k], "NULL");
                    }
                }
            }
        }
    }
    printf("Cancelamento Feito com sucesso !! \n");
    system("pause");
    if (aux == 0)
    {
        printf("Nao foi encontrado nenhum professor com esse nome");
    }
}

void desvincular_professor_disciplina(struct professores professor[], struct disciplinas disciplina[])
{
    char prof[TAM][TAM];
    char materia[TAM][TAM];
    int aux = 0, aux2 = 0, escolha, cont = 0;
    for (int i = 0; i < TAM; i++)
    {
        strcpy(prof[i], "NULL"); //inicia funcao copiando NULL em prof[i] para nao iniciar com lixo e prejudicar a logica futuramente
    }
    do
    {
        system("cls");
        //imprime_professores(professor);
        printf("Digite o nome do professor que deseja remover da disciplina: ");
        fflush(stdin);
        gets(prof[cont]); //usuario digita nome do professor que � guardado no vetor prof
        cont += 1; //contador auxiliar incrementado em 1

        printf("Deseja remover mais professor? [1-SIM ou 2-N�O]");
        scanf("%d", &escolha);

    } while (escolha != 2 && cont < TAM); //Caso escolha for igual a 2 para repetir a pergunta e adicionar no vetor

    cont = 0;
    do
    {
        system("cls");
        imprime_disciplinas(disciplina);
        printf("Digite o nome da disciplina a ser removida: ");
        fflush(stdin);
        gets(materia[cont]);
        cont += 1;

        printf("Deseja remover mais disciplina? [1-SIM ou 2-N�O]");
        scanf("%d", &escolha);
    } while (escolha != 2 && cont < TAM);

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(disciplina[j].nome_d, materia[i]) == 0) // Se for iguais entra
            {
                for (int k = 0; k < TAM; k++)
                {
                    for (int l = 0; l < TAM; l++)
                    {
                        if (strcmp(disciplina[j].professores[l], prof[k]) == 0)
                        {
                            strcpy(disciplina[j].professores[l], "NULL");
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(professor[j].nome_p, prof[i]) == 0) //se for igual entra
            {
                for (int k = 0; k < TAM; k++)
                {
                    for (int l = 0; l < TAM; l++)
                    {
                        if (strcmp(professor[j].disciplinas[l], materia[k]) == 0) //E se for igual entra
                        {
                            strcpy(professor[j].disciplinas[l], "NULL"); //Copia NULL na posicao
                        }
                    }
                }
            }
        }
    }
}

void cancelar_matricula_conjunto_alunos_disciplinas(struct alunos aluno[], struct disciplinas disciplina[])
{
    char estudante[TAM][TAM];
    char materia[TAM][TAM];
    int aux = 0, aux2 = 0, escolha, cont = 0;
    for (int i = 0; i < TAM; i++)
    {
        strcpy(estudante[i], "NULL");
        strcpy(materia[i], "NULL");
    }
    do
    {
        system("cls");
        imprime_alunos(aluno);
        printf("Digite o nome do aluno que deseja remover da disciplina: ");
        fflush(stdin);
        gets(estudante[cont]);
        cont += 1;

        printf("Deseja remover mais aluno? [1-SIM ou 2-N�O]");
        scanf("%d", &escolha);

    } while (escolha != 2 && cont < TAM);

    cont = 0;
    do
    {
        system("cls");
        imprime_disciplinas(disciplina);
        printf("Digite o nome da disciplina a ser removida: ");
        fflush(stdin);
        gets(materia[cont]);
        cont += 1;

        printf("Deseja remover mais disciplina? [1-SIM ou 2-N�O]");
        scanf("%d", &escolha);
    } while (escolha != 2 && cont < TAM);

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(disciplina[j].nome_d, materia[i]) == 0)
            {
                for (int k = 0; k < TAM; k++)
                {
                    for (int l = 0; l < TAM; l++)
                    {
                        if (strcmp(disciplina[j].alunos[l], estudante[k]) == 0)
                        {
                            strcpy(disciplina[j].alunos[l], "NULL");
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (strcmp(aluno[j].nome_a, estudante[i]) == 0)
            {
                for (int k = 0; k < TAM; k++)
                {
                    for (int l = 0; l < TAM; l++)
                    {
                        if (strcmp(aluno[j].disciplinas[l], materia[k]) == 0)
                        {
                            strcpy(aluno[j].disciplinas[l], "NULL");
                        }
                    }
                }
            }
        }
    }
}

void inicializa(struct alunos aluno[], struct disciplinas disciplina[], struct professores professor[])
{
    for (int i = 0; i < TAM; i++)  //� colocado NULL em todas as posicoes para n�o gerar conflitos na matricula em rela�ao as variaveis retornarem lixo e causar problemas no programa
    {
        strcpy(aluno[i].nome_a, "NULL");
        strcpy(disciplina[i].nome_d, "NULL");
        strcpy(professor[i].nome_p, "NULL");

        for (int j = 0; j < TAM; j++)
        {
            strcpy(aluno[i].disciplinas[j], "NULL");
            strcpy(professor[i].disciplinas[j], "NULL");
            strcpy(disciplina[i].alunos[j], "NULL");
            strcpy(disciplina[i].professores[j], "NULL");
        }
    }
}

int main() //Fun��o principal:
{

    setlocale(LC_ALL, "portuguese"); //-> Faz a chamada das structs criadas ao longo do programa
    struct alunos ALUNO[TAM];
    struct disciplinas DISCIPLINA[TAM];
    struct professores PROFESSOR[TAM];
    inicializa(ALUNO, DISCIPLINA, PROFESSOR);
    int A = 0, B = 0, C = 0, D, E, N, M, escolha, escolha1, escolha2;

    do
    {
        system("cls"); //sistema apaga tudo o que veio antes a sua chamada
        menu(); //chamada da funcao
        printf("\n Qual op��o desejada: ");
        scanf("%d", &escolha);
        if (escolha == 1)
        {

            cadastro_alunos(ALUNO); //chamada da funcao
            system("cls"); //sistema apaga tudo o que veio antes a sua chamada
        }
        if (escolha == 2)
        {
            cadastro_disciplinas(DISCIPLINA);
            system("cls"); //sistema apaga tudo o que veio antes a sua chamada
        }
        if (escolha == 3)
        {
            cadastro_professores(PROFESSOR);
            system("cls"); //sistema apaga tudo o que veio antes a sua chamada
        }
        if (escolha == 4)
        {
            matricula(ALUNO, DISCIPLINA);
            system("cls"); //sistema apaga tudo o que veio antes a sua chamada
        }
        if (escolha == 5)
        {
            vinculo1(DISCIPLINA, PROFESSOR);
            system("cls"); //sistema apaga tudo o que veio antes a sua chamada
        }
        if (escolha == 6)
        {
            impressao_menu();
            printf("Qual op��o desejada: ");
            scanf("%d", &escolha1);
            if (escolha1 == 1)
            {
                imprime_alunos(ALUNO);
                system("pause"); //sistema espera usuario digitar uma tecla para continuar
                system("cls"); //sistema apaga tudo o que veio antes a sua chamada
            }
            if (escolha1 == 2)
            {
                imprime_disciplinas(DISCIPLINA);
                system("pause"); //sistema espera usuario digitar uma tecla para continuar
                system("cls"); //sistema apaga tudo o que veio antes a sua chamada
            }
            if (escolha1 == 3)
            {
                imprime_professores(PROFESSOR);
                system("pause"); //sistema espera usuario digitar uma tecla para continuar
                system("cls"); //sistema apaga tudo o que veio antes a sua chamada
            }
            if (escolha1 == 4)
            {
                imprime_lista_alunos_disciplina(ALUNO, DISCIPLINA);
            }
            if (escolha1 == 5)
            {
                imprime_matriculas(ALUNO, DISCIPLINA);
            }
            if (escolha1 == 6)
            {
                imprime_pd(PROFESSOR, DISCIPLINA);
            }
            if (escolha1 == 7)
            {
                imprime_dp(DISCIPLINA, PROFESSOR);
            }
            if (escolha1 == 8)
            {
                system("cls"); //sistema apaga tudo o que veio antes a sua chamada
            }
        }

        if (escolha == 7)
        {
            cancelamento_menu();
            printf("Escolha uma op��o: ");
            scanf("%d", &escolha2);
            if (escolha2 == 1)
            {
                cancelamento_matricula_aluno(ALUNO, DISCIPLINA);
                system("cls"); //sistema apaga tudo o que veio antes a sua chamada
            }

            if (escolha2 == 2)
            {
                cancelamento_matricula_professor(PROFESSOR, DISCIPLINA);
                system("cls"); //sistema apaga tudo o que veio antes a sua chamada
            }

            if (escolha2 == 3)
            {
                cancelamento_matricula_disciplina(DISCIPLINA, ALUNO, PROFESSOR);
                system("cls"); //sistema apaga tudo o que veio antes a sua chamada
            }

            if (escolha2 == 4)
            {
                desvincular_professor_disciplina(PROFESSOR, DISCIPLINA);
                system("cls"); //sistema apaga tudo o que veio antes a sua chamada
            }

            if (escolha2 == 5)
            {
                cancelar_matricula_conjunto_alunos_disciplinas(ALUNO, DISCIPLINA);
                system("cls"); //sistema apaga tudo o que veio antes a sua chamada
            }

            if (escolha2 == 6)
            {
                system("cls"); //sistema apaga tudo o que veio antes a sua chamada
            }
        }

        if (escolha == 8)
        {
            system("cls");
            printf("\n Muito Obrigado !!\n");
            return 0;
        }
    } while ((escolha > 1) || (escolha < 8)); //Caso usuario digite algo fora, voltar para a chamada do menu no inicio

    return 0;
}
