#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 30

/*-------------------- Estruturas --------------------*/

typedef struct arvore
{
    int info;
    struct arvore *esquerda;
    struct arvore *direita;
    int altura;
} Arvore;

typedef struct base
{
    Arvore *raiz;
} BaseArvore;

/*-------------------- Protótipos das funções utilizadas --------------------*/

Arvore *criarArvore();
int arvoreVazia(Arvore *p);
Arvore *insere(Arvore *Raiz, int valor);
BaseArvore *remover(BaseArvore *RAIZ, int valor);
Arvore *removerAux(Arvore *pai, int valor);
int verificarAltura(Arvore *x);
void mostrarArvoreAux(Arvore *Raiz, int espaco);
void mostrarArvore(Arvore *Raiz);
Arvore *imprime_inOrder(Arvore *Raiz);
void imprimePorNivel(Arvore *Raiz, int nivel);
void imprimeOrdemDoNivel(Arvore *Raiz);

int max(int a, int b); // Prótipos das funções usadas para balanceamento
int determinaAltura(Arvore *N);
Arvore *alocaEspacoBalanceada(int valor);
Arvore *rotacaoDireita(Arvore *y);
Arvore *rotacaoEsquerda(Arvore *x);
int balanceamentoalance(Arvore *N);
Arvore *insereFormaAVL(Arvore *Raiz, int valor);
void preOrder(Arvore *Raiz);

/*-------------------- Função Main --------------------*/
int main()
{
    setlocale(LC_ALL, "Portuguese");
    Arvore *nova = criarArvore();
    nova = insereFormaAVL(nova, 10);
    nova = insereFormaAVL(nova, 20);
    nova = insereFormaAVL(nova, 30);
    nova = insereFormaAVL(nova, 40);
    nova = insereFormaAVL(nova, 50);
    nova = insereFormaAVL(nova, 25);

    preOrder(nova);
    mostrarArvore(nova);
    return 0;
}

/*-------------------- Funções criadas --------------------*/

Arvore *criarArvore()
{
    return NULL;
}

int arvoreVazia(Arvore *p) // Realiza a verificação da arvore para ver se está vazia ou não
{
    return p == NULL;
}

/*-------------------- Funções de inserção e remoção --------------------*/

Arvore *insere(Arvore *Raiz, int valor)
{
    Arvore *aux; //Insercao na arvore, se valor > raiz vai para direita, se valor < raiz vai pra esquerda
    Arvore *Pai;

    aux = (Arvore *)malloc(sizeof(Arvore));
    aux->info = valor;
    aux->direita = NULL;
    aux->esquerda = NULL;

    if (Raiz == NULL)
    {
        return aux;
    }
    else
    {
        Pai = Raiz;
        int flag = 0;

        while (flag != 1)
        {
            if (Pai->info < valor)
            {
                if (Pai->direita == NULL)
                {
                    Pai->direita = aux;
                    flag = 1;
                }
                else
                {
                    Pai = Pai->direita;
                }
            }
            else
            {
                if (Pai->esquerda == NULL)
                {
                    Pai->esquerda = aux;
                    flag = 1;
                }
                else
                {
                    Pai = Pai->esquerda;
                }
            }
        }
    }
    return Raiz;
}

BaseArvore *remover(BaseArvore *RAIZ, int valor) //função remover consiste nela mesmo e na removerAux
{
    Arvore *aux = RAIZ->raiz;
    if (aux->info == valor && aux->direita == NULL && aux->esquerda == NULL) //arvore so tem raiz
    {
        free(aux); //libera o elemento da arvore, ou seja, removeu
        free(RAIZ);
        return NULL;
    }
    RAIZ->raiz = removerAux(RAIZ->raiz, valor);
}

Arvore *removerAux(Arvore *pai, int valor)
{
    if (pai == NULL)
    {
        printf("Elemento nao encontrado! "); //elemento nao foi encontrado na arvore binaria
    }
    else
    {
        if (valor > pai->info)
        {
            pai->direita = removerAux(pai->direita, valor);
        }
        else
        {
            if (valor < pai->info)
            {
                pai->esquerda = removerAux(pai->esquerda, valor);
            }
            else //achou o elemento (no) a ser removido
            {
                if (pai->direita == NULL && pai->esquerda == NULL) //caso 1: folhas, no sem filhos
                {
                    free(pai);
                    pai = NULL;
                }
                else
                {
                    if (pai->esquerda == NULL) //caso 2: so tem filho da direita
                    {
                        Arvore *aux = pai;
                        pai = pai->direita;
                        free(aux);
                    }
                    else
                    {
                        if (pai->direita == NULL) //caso 2: so tem filho da esquerda
                        {
                            Arvore *aux = pai;
                            pai = pai->esquerda;
                            free(aux);
                        }
                        else //casp 3: tem dois filhos
                        {
                            Arvore *aux;
                            aux = pai->esquerda;
                            while (aux->direita != NULL)
                            {
                                aux = aux->direita;
                            }
                            pai->info = aux->info;
                            aux->info = valor;
                            pai->esquerda = removerAux(pai->esquerda, valor);
                        }
                    }
                }
                //Achou o no a ser removido
            }
        }
    }
    return pai;
}

/*-------------------- Funções de busca --------------------*/

int busca(Arvore *Raiz, int target)
{
    int flag = -1;

    while (flag != 1 && flag != 0)
    {
        if (Raiz->info == target)
            flag = 1;
        else
        {
            if (Raiz->info < target)
            {
                if (Raiz->direita == NULL)
                {
                    flag = 0;
                }
                else
                {
                    Raiz = Raiz->direita;
                }
            }
            else
            {
                if (Raiz->esquerda == NULL)
                {
                    flag = 0;
                }
                else
                {
                    Raiz = Raiz->esquerda;
                }
            }
        }
    }
    return flag;
}

/*-------------------- Funções de verificar altura e printa arvore graficamente --------------------*/

int verificarAltura(Arvore *x)
{
    int alturaEsquerda, alturaDireita;
    if (arvoreVazia(x))
    {
        return 0; // Se arvore estiver vazia, retorna
    }
    else
    {
        alturaEsquerda = 1 + verificarAltura(x->esquerda); // passa nivel a nivel da arvore para ver ate onde vai
        alturaDireita = 1 + verificarAltura(x->direita);
        if (alturaEsquerda > alturaDireita)
        {
            return alturaEsquerda; // se alturaEsquerda > direita , retorna alturaEsquerda -> nivel maior
        }
        else
        {
            return alturaDireita; // se alturaDireita > esquerda , retorna alturaDireita -> nivel maior
        }
    }
}

void mostrarArvoreAux(Arvore *Raiz, int espaco)
{
    if (Raiz == NULL) // Se raiz for nula retorna
        return;

    espaco += 10; // Aumenta o espaçamento entres os niveis da arvore

    mostrarArvoreAux(Raiz->direita, espaco); // Printa o primeiro filho da direita

    printf("\n");
    for (int i = 10; i < espaco; i++) // Printa o no em que esta apos o espaco
        printf(" ");
    printf("%d\n", Raiz->info);

    mostrarArvoreAux(Raiz->esquerda, espaco); // Printa o primeiro filho da esquerda
}

void mostrarArvore(Arvore *Raiz)
{
    mostrarArvoreAux(Raiz, 0); // mostra arvore a partir da raiz, com espaco inicial = 0
}

Arvore *imprime_inOrder(Arvore *Raiz)
{
    Arvore *f;
    f = Raiz;
    if (f->esquerda != NULL) //Impressão in order da arvore, crescente
    {
        imprime_inOrder(f->esquerda);
    }
    printf(" | %d", f->info);
    if (f->direita != NULL)
    {
        imprime_inOrder(f->direita);
    }
}

void imprimePorNivel(Arvore *Raiz, int nivel)
{
    if (arvoreVazia(Raiz))
    {
        return; //Verifica se esta vazia
    }
    if (nivel == 1)
    {
        printf("%c ", Raiz->info); //Printa raiz
    }
    else if (nivel > 1)
    {
        imprimePorNivel(Raiz->esquerda, nivel - 1); //passa para os proximos niveis
        imprimePorNivel(Raiz->direita, nivel - 1);
    }
}

void imprimeOrdemDoNivel(Arvore *Raiz)
{
    int h = verificarAltura(Raiz);
    for (int i = 1; i <= h; i++) //printa todos os niveis da arvore separadamente ate o ultimo
    {
        printf("Nível %d: ", i - 1);
        imprimePorNivel(Raiz, i);
        printf("\n");
    }
}

/*-------------------- Funções de inserção ena arvore AVL (de modo balanceado) e auxialiares --------------------*/

int determinaAltura(Arvore *N) // Utilzada dentro das rotações
{
    if (N == NULL)
        return 0;
    return N->altura;
}

int max(int a, int b) //Pega o maximo entre dois numeros inteiros
{
    return (a > b) ? a : b;
}

Arvore *alocaEspacoBalanceada(int valor)
{
    Arvore *no = (Arvore *)malloc(sizeof(Arvore));
    no->info = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1;
    return (no);
}

Arvore *rotacaoDireita(Arvore *y)
{
    Arvore *x = y->esquerda;
    Arvore *T2 = x->direita;

    x->direita = y; // Realiza as rotações
    y->esquerda = T2;

    y->altura = max(determinaAltura(y->esquerda), determinaAltura(y->direita)) + 1; //atualiza a função da altura
    x->altura = max(determinaAltura(x->esquerda), determinaAltura(x->direita)) + 1;

    return x; //retorna a nova raiz
}

Arvore *rotacaoEsquerda(Arvore *x)
{
    Arvore *y = x->direita;
    Arvore *T2 = y->esquerda;

    y->esquerda = x; //Realiza as rotações
    x->direita = T2;

    x->altura = max(determinaAltura(x->esquerda), determinaAltura(x->direita)) + 1; //atualiza altura
    y->altura = max(determinaAltura(y->esquerda), determinaAltura(y->direita)) + 1;

    return y; //retorna raiz nova
}

int balanceamento(Arvore *N)
{
    if (N == NULL)
        return 0;
    return determinaAltura(N->esquerda) - determinaAltura(N->direita);
}

Arvore *insereFormaAVL(Arvore *Raiz, int valor)
{
    if (Raiz == NULL)
        return (alocaEspacoBalanceada(valor));

    if (valor < Raiz->info)
        Raiz->esquerda = insereFormaAVL(Raiz->esquerda, valor);
    else if (valor > Raiz->info)
        Raiz->direita = insereFormaAVL(Raiz->direita, valor);
    else
        return Raiz;

    Raiz->altura = 1 + max(determinaAltura(Raiz->esquerda), determinaAltura(Raiz->direita)); //Atualiza a determinaAltura dos nos

    int balance = balanceamentoalance(Raiz); //verifica se o fator de balancear daquele elemento esta desbalanceado
                                             //se estiver desbalanceado, serao os casos abaixo

    if (balance > 1 && valor < Raiz->esquerda->info) //caso esquerda esquerda
        return rotacaoDireita(Raiz);

    if (balance < -1 && valor > Raiz->direita->info) //caso direita direita
        return rotacaoEsquerda(Raiz);

    if (balance > 1 && valor > Raiz->esquerda->info) //caso esquerda direita
    {
        Raiz->esquerda = rotacaoEsquerda(Raiz->esquerda);
        return rotacaoDireita(Raiz);
    }

    if (balance < -1 && valor < Raiz->direita->info) //caso direita esquerda
    {
        Raiz->direita = rotacaoDireita(Raiz->direita);
        return rotacaoEsquerda(Raiz);
    }

    return Raiz; //retorna a raiz original
}

void preOrder(Arvore *Raiz) //Imprime de forma a arvore preOrder
{
    if (Raiz != NULL)
    {
        printf("%d ", Raiz->info);
        preOrder(Raiz->esquerda);
        preOrder(Raiz->direita);
    }
}
