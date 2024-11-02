//regDiscipline.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "useful.h"

int regDiscipline(){
  int mainSelect, cadAgain;
  while(1){
    system("cls");
    printf("-= Disciplina =-\n\n");

    printf("1- Cadastrar\n2- Inserir alunos\n3- Listar\n4- Excluir\n0- Voltar\n\n");
    scanf("%d", &mainSelect); getchar();

    if(mainSelect == 1){
      while(1){
          system("cls");
          printf("-= Cadastrar Disciplina =-\n\n");

         //Nome da Disciplina
          printf("Digite o nome da Disciplina:\n");
          fgets(disciplinas[numDisc].nome, 100, stdin);
            //clear Buffer
          size_t ln = strlen(disciplinas[numDisc].nome) - 1;
          if(disciplinas[numDisc].nome[ln] == '\n')  disciplinas[numDisc].nome[ln] = '\0';
        
          //Matricula Prof
          do{
            printf("Informe o codigo da disciplina:\n");
            fgets(disciplinas[numDisc].matricula, maxMatricula, stdin);
              //clear Buffer
            size_t ln = strlen(profDados[numProf].matricula) - 1;
            if (disciplinas[numDisc].matricula[ln] == '\n') disciplinas[numDisc].matricula[ln] = '\0';
              
            break;
          }while(1);

          numDisc++;

          //cadAgain
          printf("Deseja cadastrar novamente?\n1- Sim\n2- Não\n\n");
          scanf("%d", &cadAgain); getchar();
          if(cadAgain == 1) continue;
          else break;
      }
    }
    else if(mainSelect == 2){
      while(1){
        system("cls");
        printf("-= Editar Disciplina =-\n\n");

        if(numDisc == 0){
          printf("Nenhuma Discplina encontrada!\n\nDigite 0 para voltar.\n");
          scanf("%d", &cadAgain); getchar();
          if(cadAgain == 0) break;
        }
        else{
          for(int i = 0; i < numProf; i++){
            printf("Disciplina %d:\n", i + 1);
            printf(" -Nome: %s\n",   disciplinas[i].nome);
            printf(" -Professor: %s\n",    disciplinas[i].professor);
            printf(" -Matricula: %s\n", disciplinas[i].matricula);
            printf(" -= Alunos Matriculados=-\n");

            for(int j=0; j < numAlunoDisc; j++){
              printf(" -Aluno %d: %s\n", j + 1, disciplinas[i].alunos[i]);
            }
          }
          printf("Digite 0 para voltar.\n\n");
          scanf("%d", &cadAgain); getchar();
          if(cadAgain == 0) break;
        }
      }
    }
  //-= Listar Disciplinas =-
    else if(mainSelect == 3){
      while(1){
        system("cls");
        printf("-= Lista de Professor =-\n\n");

        if(numProf == 0){
          printf("Nenhum professor cadastrado!\n\nDigite 0 para voltar.\n");
          scanf("%d", &cadAgain); getchar();
          if(cadAgain == 0) break;
        }
        else{
          for(int i = 0; i < numProf; i++){
            printf("Professor %d:\n", i + 1);
            printf(" -Nome: %s\n",   profDados[i].nome);
            printf(" -Cpf: %s\n",    profDados[i].cpf);
            printf(" -Sexo: ");
            if(profDados[i].sexo == 'M') printf("Masculino\n");
            else if(profDados[i].sexo == 'F') printf("Feminino\n");
            else printf("Outro\n");
            printf(" -Data de Nascimento: %02d/%02d/%d.\n", profDados[i].dataNascProf[i].dia, profDados[i].dataNascProf[i].mes, profDados[i].dataNascProf[i].ano);
            printf(" -Matricula: %s\n\n", profDados[i].matricula);
          }
          printf("Digite 0 para voltar.\n\n");
          scanf("%d", &cadAgain); getchar();
          if(cadAgain == 0) break;
        }
      }
    }
    else if(mainSelect == 0) break;
  }
}