// useful.h
#ifndef USEFUL_H
#define USEFUL_H

#define MAX 50
#define maxMatricula 15
#define maxCPF 11
#define maxNome 100

extern int numAlunoDisc;
extern int numAluno;
extern int numProf;
extern int numDisc;

//Data de Nascimento
typedef struct{
    int dia, mes, ano;
} datanasc;
//Aluno Dados
typedef struct{
    char nome[100], cpf[15], sexo, matricula[maxMatricula];
    datanasc dataNascAlun[MAX];
} alunodados; extern alunodados alunoDados[MAX];
//Professor Dados
typedef struct{
  char nome[100], cpf[15], sexo, matricula[maxMatricula];
datanasc dataNascProf[MAX];
} profdados; extern profdados profDados[MAX];
//
typedef struct{
  char nome[100], matricula[maxMatricula];
  alunodados alunos[MAX];
  profdados professor;
} discdados; extern discdados disciplinas[MAX]; 

//Validar Cpf
int validarCPF(char *cpf);

//Validar Matricula
int ValidarMatricula(const char *matricula);

//Validar Data
int ObterAnoAtual();
int ObterMesAtual();
int ObterDiaAtual();
int AnoBissexto(int year);
int DataValida(int day, int month, int year);


#endif
