#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
    int numeroMatricula; //100000 e 999999
    char nome[26]; //max 25 letras
    char sobrenome[26]; //max 25 letras
    int anoNascimento; //deve ser entre 1900 e 2019
    char curso[26]; // max 25 letras
} Aluno;

//incrementa contador
//para adicionar, procura o primeiro espaço vazio e aloca


void preencheVetorAlunos(struct Aluno listaAlunos[])
{
    for(int i = 0; i < 100; i++)
    {
        Aluno aux;
        aux.numeroMatricula = 0;
        listaAlunos[i] = aux;
    }
}







Aluno construirNovoAluno()
{

    system("cls");

    int numeroMatriculaAux = 0;
    char nomeAux[100] = "";
    char sobrenomeAux[100] = "";
    int anoNascimentoAux = 0;
    char cursoAux[100] = "";

    printf("\nVoce esta cadastrando um(a) aluno(a), por favor insira os dados solicitados:\n\n");

    while (numeroMatriculaAux < 100000 || numeroMatriculaAux > 999999)
    {
        printf("\nDigite o numero de matricula:(entre 100000 e 999999): ");
        scanf("%d", &numeroMatriculaAux);
    }

    fflush(stdin); //para dar flush no console, retirar o /n do buffer

    while ((strlen(nomeAux) == 0) || (strlen(nomeAux) > 26))
    {
        printf("\nDigite o nome (Deve possuir entre 1 e 26 caracteres): ");
        fgets(nomeAux, sizeof(nomeAux), stdin);
    }

    fflush(stdin);

    while ((strlen(sobrenomeAux) == 0) || (strlen(sobrenomeAux) > 26))
    {
        printf("\nDigite o sobrenome (Deve possuir entre 1 e 26 caracteres): ");
        fgets(sobrenomeAux, sizeof(sobrenomeAux), stdin);
    }


    //strtok eh uma funcao achada em https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    fflush(stdin);

    while (anoNascimentoAux < 1900 || anoNascimentoAux > 2019)
    {
        printf("\nDigite a data de nascimento (entre 1900 e 2019:): ");
        scanf("%d", &anoNascimentoAux);
    }

    fflush(stdin);

    while ((strlen(cursoAux) == 0) || (strlen(cursoAux) > 26))
    {
        printf("\nDigite o curso (Deve possuir entre 1 e 26 caracteres): ");
        fgets(cursoAux, sizeof(cursoAux), stdin);
    }

    Aluno alunoAux;

    //consertando os \n existentes no sobrenome

    alunoAux.numeroMatricula = numeroMatriculaAux;
    strcpy(alunoAux.nome, strtok(nomeAux, "\n"));
    strcpy(alunoAux.sobrenome, strtok(sobrenomeAux, "\n"));
    alunoAux.anoNascimento = anoNascimentoAux;
    strcpy(alunoAux.curso, strtok(cursoAux, "\n"));


    system("cls");
    return alunoAux;

}


int adicionarAluno(struct Aluno listaAlunos[], int contadorAlunos)
{
    Aluno aluno;
    if (contadorAlunos>100)
    {
        printf("\nInfelizmente não é possível cadastrar mais nenhum aluno, uma vez que a lista está cheia");
        return 0;
    }
    else
    {
        aluno = construirNovoAluno();

        for(int i = 0; i < sizeof(listaAlunos); i++)
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

    printf(" Voce esta editando um(a) aluno(a)!!");

    int numeroMatriculaAux;


    printf("\n\n Digite o ID de matricula do aluno que voce deseja editar: ");
    do
    {
        printf("\n\n Digite o numero de matricula do aluno(a): ");
        scanf("%d", &numeroMatriculaAux);
    } while (numeroMatriculaAux < 100000 || numeroMatriculaAux > 999999);

    int posicaoAluno = pesquisarAluno(numeroMatriculaAux); //se diferente de -1, esta cadastrado

    if (posicaoAluno != -1){






    } else {
        printf("\n\n Nao existe nenhum aluno com o ID %d informado, nao houveram remocoes!!", numeroMatriculaAux);
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
        printf("\n\n O aluno %s %s de ID: %d foi removido!!", aux.nome, aux.sobrenome, aux.numeroMatricula);
        aux.numeroMatricula = 0;
        strcpy(aux.nome, "");
        strcpy(aux.sobrenome, "");
        strcpy(aux.curso, "");
        aux.anoNascimento = 0;
        listaAlunos[posicaoAluno] = aux;
        return 1;
    }

    printf("\n\n Nao existe nenhum aluno com o ID %d informado, nao houveram remocoes!!", numeroMatriculaAux);

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

void imprimirListaAlunos(struct Aluno listaAlunos[], int contadorAlunos)
{
    system("cls");
    int auxContadorVerificaQntNaoCadastrados = 0;

    printf("\n Alunos(as) registrados(as) ate o momento:\n\n");
    for(int i = 0; i < 100; i++)
    {
        if(listaAlunos[i].numeroMatricula != 0)
        {
            Aluno aux = listaAlunos[i];
            printf("\n %s %s, de ID: %d, nascido(a) em %d, matriculado(a) no curso de %s. Posicao: %d", aux.nome, aux.sobrenome, aux.numeroMatricula, aux.anoNascimento, aux.curso, i);
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



int main ()
{
    struct Aluno listaAlunos[100];
    int contadorAlunos = 0;
    int opcaoEscolhida = 0;

    /*
    a variavel auxQntAlunos serve para auxiliar na contagem de alunos cadastrados, ela recebe o retorno
    das funcoes, caso o retorno for 1, a operação foi sucedida, entao a variavem contadorAlunos
    deve ser alterada!
    */

    int auxQntAlunos;

    //preechendo vetor de alunos com valores vazios para auxiliar na manipulação futura
    preencheVetorAlunos(listaAlunos);

    printf("\n   Bem vindo ao sistema de gestao de alunos feito por Joao!:");


    do
    {
        auxQntAlunos = 0;
        printf("\n\n\n\n Ate o momento temos %d alunos cadastrados\n", contadorAlunos);
        printf("\n\n   Insira o numero correspondente a opcao desejada:");
        printf("\n\n\t1 - Adicionar aluno");
        printf("\n\n\t2 - Editar aluno");
        printf("\n\n\t3 - Remover aluno");
        printf("\n\n\t4 - Imprimir alunos");
        printf("\n\n\t5 - Sair do sistema");
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
            printf("\n\nSistema fechando...\n\n\n");

        }
    }
    while ((opcaoEscolhida >= 1) && (opcaoEscolhida <= 4));

    system("PAUSE");

    return 13;
}


//printf("%s", aluno1.nome);
//Aluno aluno1;
//strcpy(aluno1.nome, "Mateus");




