//userful.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "useful.h"
alunodados alunoDados[MAX];
profdados profDados[MAX];
discdados disciplinas[MAX]; 

int numAluno = 0;
int numProf = 0;
int numDisc = 0;
int numAlunoDisc = 0;
int diaAtual, mesAtual, anoAtual;

//Validar Cpf
int validarCPF(char *cpf) {
    int i, j;
    int sum1 = 0, sum2 = 0;

    // Verifica se todos os dígitos do CPF são iguais, o que não é um CPF válido
    for (i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            break;
        }
    }
    if (i == 11) return 0;
    // Primeiro dígito verificador
    for (i = 0, j = 10; i < 9; i++, j--) {
        sum1 += (cpf[i] - '0') * j;
    }
    int digit1 = (sum1 * 10) % 11;
    if (digit1 == 10) {
        digit1 = 0;
    }
    // Segundo dígito verificador
    for (i = 0, j = 11; i < 10; i++, j--) {
        sum2 += (cpf[i] - '0') * j;
    }
    int digit2 = (sum2 * 10) % 11;
    if (digit2 == 10) {
        digit2 = 0;
    }
    // Verifica se os dígitos verificadores são iguais aos do CPF
    if ((digit1 == cpf[9] - '0') && (digit2 == cpf[10] - '0')) {
        return 1;
    } else {
        printf("Valor Inválido!\n");
        return 0;
    }
}
//Validar Matricula
int ValidarMatricula(const char *matricula) {
  if (strlen(matricula) != 12) {
    printf("A matrícula deve conter 12 dígitos.\n");
    return 0;
  }
  else return 1; // Matrícula válida
}

//-= Validar data =-
// Obter ano atual
int ObterAnoAtual() {
  time_t t = time(NULL);
  struct tm *info = localtime(&t);
  return info->tm_year + 1900;
}

// Obter mês atual
int ObterMesAtual() {
  time_t t = time(NULL);
  struct tm *info = localtime(&t);
  return info->tm_mon + 1;
}

// Obter dia atual
int ObterDiaAtual() {
  time_t t = time(NULL);
  struct tm *info = localtime(&t);
  return info->tm_mday;
}

// Função para verificar se um ano é bissexto
int AnoBissexto(int year) {
  return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Função para validar uma data
int DataValida(int day, int month, int year) {
  int anoAtual = ObterAnoAtual();

  if (year < 1 || year > anoAtual || month < 1 || month > 12)
    return 0;

  int maxDay;

  switch (month) {
  case 2:
    maxDay = AnoBissexto(year) ? 29 : 28;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    maxDay = 30;
    break;
  default:
    maxDay = 31;
  }

  if (day < 1 || day > maxDay)
    return 0;

  // Verificar se a data está no futuro
  if (year > anoAtual || (year == anoAtual && month > ObterMesAtual()) ||
      (year == anoAtual && month == ObterMesAtual() && day > ObterDiaAtual())) {
    printf("Data no futuro.\n");
    return 0;
  }

  return 1;
}