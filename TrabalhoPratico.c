#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Aluno
{
    int numeroMatricula;
    char nome[26];
    char sobrenome[26];
    int anoNascimento;
    char curso[26];
} Aluno;

void preencheVetorAlunos(struct Aluno listaAlunos[]);
Aluno construirNovoAluno();
int adicionarAluno(struct Aluno listaAlunos[], int contadorAlunos);
void editarAluno(struct Aluno listaAlunos[], int contadorAlunos);
int pesquisarAluno(struct Aluno listaAlunos[], int idMatriculaAluno);
int removerAluno(struct Aluno listaAlunos[],int contadorAlunos);
void imprimirListaAlunos(struct Aluno listaAlunos[],int contadorAlunos);
int getNumeroMatriculaAluno();
void getNomeAluno(char * nomeAluno);
void getSobrenomeAluno(char * sobrenomeAluno);
int getAnoNascimentoAluno();
void getCursoAluno(char * cursoAluno);

int main ()
{
    struct Aluno listaAlunos[100];
    int contadorAlunos = 0;
    int opcaoEscolhida = 0;
    int auxQntAlunos;

    preencheVetorAlunos(listaAlunos);

    do
    {
        auxQntAlunos = 0;
        printf("\n\n\n\n -- Ate o momento temos %d alunos cadastrados\n", contadorAlunos);
        printf("\n\n   Insira o numero correspondente a opcao desejada:");
        printf("\n\n\t1 - Adicionar aluno");
        printf("\n\n\t2 - Editar aluno");
        printf("\n\n\t3 - Remover aluno");
        printf("\n\n\t4 - Imprimir alunos");
        printf("\n\n\tOutro valor - Sair do sistema");
        printf("\n\n\tDigite a opcao desejada: ");
        scanf("%d", &opcaoEscolhida);

        switch(opcaoEscolhida)
        {
        case (1):
            auxQntAlunos = adicionarAluno(listaAlunos, contadorAlunos);
            contadorAlunos = (auxQntAlunos==1)? (contadorAlunos+1) : contadorAlunos;
            break;
        case (2):
            editarAluno(listaAlunos, contadorAlunos);
            break;
        case (3):
            auxQntAlunos = removerAluno(listaAlunos, contadorAlunos);
            contadorAlunos = (auxQntAlunos==1)? (contadorAlunos-1) : contadorAlunos;
            break;
        case (4):
            imprimirListaAlunos(listaAlunos, contadorAlunos);
            break;
        default:
            printf("\n\n Sistema fechando...\n\n\n");
            Sleep(4000);
            break;
        }
    }
    while ((opcaoEscolhida >= 1) && (opcaoEscolhida <= 4));

    return 0;
}

void preencheVetorAlunos(struct Aluno listaAlunos[])
{
    for(int i = 0; i < 100; i++)
    {
        Aluno aux;
        aux.numeroMatricula = 0;
        listaAlunos[i] = aux;
    }
}

int adicionarAluno(struct Aluno listaAlunos[], int contadorAlunos)
{
    Aluno aluno;
    if (contadorAlunos>100)
    {
        printf("\n Infelizmente não é possível cadastrar mais nenhum aluno, uma vez que a lista está cheia");
        return 0;
    }
    else
    {
        aluno = construirNovoAluno();

        for(int i = 0; i < 100; i++)
        {
            if(listaAlunos[i].numeroMatricula == 0)
            {
                listaAlunos[i] = aluno;
                printf("\n\n O(a) aluno(a) %s %s, de matricula %d foi inserido(a) com sucesso!!", aluno.nome, aluno.sobrenome, aluno.numeroMatricula);
                return 1;
            }
        }
    }
}

void editarAluno(struct Aluno listaAlunos[], int contadorAlunos)
{
    system("cls");
    printf("\n Voce esta editando um(a) aluno(a)!!\n\n\n");

    int numeroMatriculaAux = getNumeroMatriculaAluno();

    int posicaoAluno = pesquisarAluno(listaAlunos,numeroMatriculaAux); //se diferente de -1, esta cadastrado

    if (posicaoAluno != -1)
    {

        system ("cls");
        Aluno alunoSendoAlterado = listaAlunos[posicaoAluno];
        printf("\n\n Estamos alterando os valores de %s %s de ID: %d", alunoSendoAlterado.nome, alunoSendoAlterado.sobrenome, alunoSendoAlterado.numeroMatricula);

        int opcaoEscolhida;

        do
        {
            printf("\n\n   Insira o numero correspondente a alteracao desejada:");
            printf("\n\n\t1 - Alterar numero de matricula do aluno");
            printf("\n\n\t2 - Alterar nome do aluno");
            printf("\n\n\t3 - Alterar sobrenome do aluno");
            printf("\n\n\t4 - Alterar ano de nascimento do aluno");
            printf("\n\n\t5 - Alterar curso que aluno esta matriculado");
            printf("\n\n\tOutro valor - Sair da edicao");
            printf("\n\n\tDigite a opcao desejada: ");
            scanf("%d", &opcaoEscolhida);

            switch(opcaoEscolhida)
            {

            case (1):
                alunoSendoAlterado.numeroMatricula = getNumeroMatriculaAluno();
                listaAlunos[posicaoAluno] = alunoSendoAlterado;
                printf("\n\n O numero de matricula foi alterado!\n");
                Sleep(2000);
                system("cls");
                break;

            case (2):
                getNomeAluno(alunoSendoAlterado.nome);
                listaAlunos[posicaoAluno] = alunoSendoAlterado;
                printf("\n\n O nome foi alterado!\n");
                Sleep(2000);
                system("cls");
                break;

            case (3):
                getSobrenomeAluno(alunoSendoAlterado.sobrenome);
                listaAlunos[posicaoAluno] = alunoSendoAlterado;
                printf("\n\n O sobrenome foi alterado!\n");
                Sleep(2000);
                system("cls");
                break;

            case (4):
                alunoSendoAlterado.anoNascimento = getAnoNascimentoAluno();
                listaAlunos[posicaoAluno] = alunoSendoAlterado;
                printf("\n\n O ano de nascimento foi alterado!\n");
                Sleep(2000);
                system("cls");
                break;

            case (5):
                getCursoAluno(alunoSendoAlterado.curso);
                listaAlunos[posicaoAluno] = alunoSendoAlterado;
                printf("\n\n O curso foi alterado!\n");
                Sleep(2000);
                system("cls");
                break;

            default:
                printf("\n\n Edicao finalizada...\n\n\n");
                Sleep(2000);
                system("cls");
                printf("\n\n Aluno alterado com sucesso!!");
                break;
            }
        }
        while ((opcaoEscolhida >= 1) && (opcaoEscolhida <= 5));

    }
    else
    {
        system ("cls");
        printf("\n\n Nao existe nenhum aluno com o numero de matrícula %d informado, nao houveram edicoes!!", numeroMatriculaAux);
    }

}

int removerAluno(struct Aluno listaAlunos[],int contadorAlunos)
{
    system ("cls");

    int numeroMatriculaAux = 0;

    printf(" Voce esta removendo um(a) aluno(a)!!");

    do
    {
        printf("\n\n Digite o numero de matricula do aluno(a): ");
        scanf("%d", &numeroMatriculaAux);
    }
    while (numeroMatriculaAux < 100000 || numeroMatriculaAux > 999999);

    int posicaoAluno = pesquisarAluno(listaAlunos,numeroMatriculaAux); //variavel que tem a posicao do aluno que será removido no array, se nao tiver o aluno, possui -1

    if (posicaoAluno != -1)
    {
        Aluno aux = listaAlunos[posicaoAluno];
        printf("\n\n O aluno %s %s de numero de matricula: %d foi removido!!", aux.nome, aux.sobrenome, aux.numeroMatricula);
        aux.numeroMatricula = 0;
        strcpy(aux.nome, "");
        strcpy(aux.sobrenome, "");
        strcpy(aux.curso, "");
        aux.anoNascimento = 0;
        listaAlunos[posicaoAluno] = aux;
        return 1;
    }

    printf("\n\n Nao existe nenhum aluno com o numero de matricula %d informado, nao houveram remocoes!!", numeroMatriculaAux);

}

void imprimirListaAlunos(struct Aluno listaAlunos[], int contadorAlunos)
{
    system("cls");
    int auxContadorVerificaQntNaoCadastrados = 0;

    printf("\n Alunos(as) registrados(as) ate o momento:\n\n\n");
    for(int i = 0; i < 100; i++)
    {
        if(listaAlunos[i].numeroMatricula != 0)
        {
            Aluno aux = listaAlunos[i];
            printf(" %s %s, de numero de matricula: %d, nascido(a) em %d, matriculado(a) no curso de %s. Posicao: %d\n\n", aux.nome, aux.sobrenome, aux.numeroMatricula, aux.anoNascimento, aux.curso, i);
        }
        else
        {
            auxContadorVerificaQntNaoCadastrados++;
        }
    }

    if(auxContadorVerificaQntNaoCadastrados == 100)
    {
        printf("  Nao existem alunos cadastrados ate o momento!!");
    }

}

Aluno construirNovoAluno()
{
    system("cls");
    printf("\n Voce esta cadastrando um(a) aluno(a), por favor insira os dados solicitados:\n\n");

    Aluno alunoAux;
    alunoAux.numeroMatricula = getNumeroMatriculaAluno();

    getNomeAluno(alunoAux.nome);
    getSobrenomeAluno(alunoAux.sobrenome);

    alunoAux.anoNascimento = getAnoNascimentoAluno();

    getCursoAluno(alunoAux.curso);

    system("cls");
    return alunoAux;

}

int pesquisarAluno(struct Aluno listaAlunos[], int idMatriculaAluno)
{

    for(int i = 0; i < 100; i++)
    {
        if (listaAlunos[i].numeroMatricula==idMatriculaAluno)
        {
            return i;
        }
    }

    return -1;
}



int getNumeroMatriculaAluno()
{
    int numeroMatriculaAux = 0;
    while (numeroMatriculaAux < 100000 || numeroMatriculaAux > 999999)
    {
        printf("\n Digite o numero de matricula:(entre 100000 e 999999): ");
        scanf("%d", &numeroMatriculaAux);
    }

    return numeroMatriculaAux;
}

void getNomeAluno(char * nomeAluno)
{
    fflush(stdin);
    char nomeAux[100] = "";
    while ((strlen(nomeAux) == 0) || (strlen(nomeAux) > 26))
    {
        printf("\n Digite o nome (Deve possuir entre 1 e 26 caracteres): ");
        fgets(nomeAux, sizeof(nomeAux), stdin);
    }

    strtok(nomeAux, "\n");
    strcpy(nomeAluno, nomeAux);

}

void getSobrenomeAluno(char * sobrenomeAluno)
{
    fflush(stdin);
    char sobrenomeAux[100] = "";
    while ((strlen(sobrenomeAux) == 0) || (strlen(sobrenomeAux) > 26))
    {
        printf("\n Digite o sobrenome (Deve possuir entre 1 e 26 caracteres): ");
        fgets(sobrenomeAux, sizeof(sobrenomeAux), stdin);
    }

    strtok(sobrenomeAux, "\n");
    strcpy(sobrenomeAluno, sobrenomeAux);
}


int getAnoNascimentoAluno()
{
    int anoNascimentoAux = 0;
    while (anoNascimentoAux < 1900 || anoNascimentoAux > 2019)
    {
        printf("\n Digite a data de nascimento (entre 1900 e 2019:): ");
        scanf("%d", &anoNascimentoAux);
    }

    return anoNascimentoAux;
}

void getCursoAluno(char * cursoAluno)
{
    fflush(stdin);
    char cursoAux[100] = "";
    while ((strlen(cursoAux) == 0) || (strlen(cursoAux) > 26))
    {
        printf("\n Digite o curso (Deve possuir entre 1 e 26 caracteres): ");
        fgets(cursoAux, sizeof(cursoAux), stdin);
    }

    strtok(cursoAux, "\n");
    strcpy(cursoAluno, cursoAux);
}
