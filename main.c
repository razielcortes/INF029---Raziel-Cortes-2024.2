//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "regStudent.h"
#include "regProfessor.h"
#include "regDiscipline.h"

int main(){
  int mainSelect;

  while(1){
    system("cls");
    printf("-= Projeto Escola =-\n\n");

    printf("1- Alunos\n2- Professores\n3- Disciplinas\n0- Sair\n\n");
    scanf("%d", &mainSelect); getchar();

    switch(mainSelect){
      case 1: regStudent();    break;
      case 2: regProfessor();  break;
      case 3: regDiscipline(); break;
      case 0: printf("\n\nSaindo!"); exit(0);

      default: break;
    }
  }
}