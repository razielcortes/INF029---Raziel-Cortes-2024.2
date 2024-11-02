//regProfessor.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "useful.h"

int regProfessor(){
  int mainSelect, cadAgain;
  while(1){
    system("cls");
    printf("-= Professores =-\n\n");

    printf("1- Cadastrar\n2- Editar\n3- Listar\n4- Excluir\n0- Voltar\n\n");
    scanf("%d", &mainSelect); getchar();

    if(mainSelect == 1){
      while(1){
          system("cls");
          printf("-= Cadastrar Professor =-\n\n");

         //Nome Prof
          printf("Digite o nome do professor:\n");
          fgets(profDados[numProf].nome, 100, stdin);
            //clear Buffer
          size_t ln = strlen(profDados[numProf].nome) - 1;
          if(profDados[numProf].nome[ln] == '\n')  profDados[numProf].nome[ln] = '\0';

          //Cpf prof
          do{
              printf("Digite o CPF do professor:\n");
              fgets(profDados[numProf].cpf, 12, stdin);
              // clear Buffer
              size_t ln = strlen(profDados[numProf].cpf) - 1;
              if (profDados[numProf].cpf[ln] == '\n') profDados[numProf].cpf[ln] = '\0';
          } while (!validarCPF(profDados[numProf].cpf));

          //Sexo prof
          do{
            int sexoSel;
            printf("Qual sexo do professor:\n 1 - Masculino\n 2 - Feminino\n");
            scanf("%d", &sexoSel); getchar();

            switch (sexoSel) {
            case 1: profDados[numProf].sexo = 'M'; break;
            case 2: profDados[numProf].sexo = 'F'; break;

            default: printf("Opcao Invalida!\n");
            }
          }while (profDados[numProf].sexo != 'M' && profDados[numProf].sexo != 'F');

        //Data Nascimento 
          do{
            //Dia
            do{
              printf("Digite o dia de nascimento do professor:\n");
              scanf("%d", &profDados[numProf].dataNascProf[numProf].dia); getchar();
              if(profDados[numProf].dataNascProf[numProf].dia < 1 || profDados[numProf].dataNascProf[numProf].dia > 31) printf("Dia inválido!\n");
              else break;
            }while(1);
            //Mes
            do{
              printf("Digite o mês de nascimento do professor:\n");
              scanf("%d", &profDados[numProf].dataNascProf[numProf].mes); getchar();
              if(profDados[numProf].dataNascProf[numProf].mes > 12 || profDados[numProf].dataNascProf[numProf].mes < 1) printf("Valor Inválido!\n");
              else break;
            } while(1);
            //Ano
            do{
              printf("Digite o ano de nascimento do professor:\n");
              scanf("%d", &profDados[numProf].dataNascProf[numProf].ano); getchar();
              if(profDados[numProf].dataNascProf[numProf].ano < 1920) printf("Você é um dinossauro?\n");
              else break;
            } while(1);
            if(!DataValida(profDados[numProf].dataNascProf[numProf].dia, profDados[numProf].dataNascProf[numProf].mes, profDados[numProf].dataNascProf[numProf].ano))
              printf("Data de nascimento inválida!\n");
          }while(!DataValida(profDados[numProf].dataNascProf[numProf].dia, profDados[numProf].dataNascProf[numProf].mes, profDados[numProf].dataNascProf[numProf].ano));



          //Matricula Prof
          do{
            printf("Digite a matricula do professor:\n");
            fgets(profDados[numProf].matricula, maxMatricula, stdin);
              //clear Buffer
            size_t ln = strlen(profDados[numProf].matricula) - 1;
            if (profDados[numProf].matricula[ln] == '\n'){profDados[numProf].matricula[ln] = '\0';}

            if (strlen(profDados[numProf].matricula) != 12) {
              printf("Matrícula inválida.\n");
              continue;
            }
            else {break;}
          }while(1);

          numProf++;

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
        printf("-= Editar Professores =-\n\n");

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
  //-= Listar Professor =-
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