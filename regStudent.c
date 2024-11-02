//regStudent.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "useful.h"

int regStudent(){
  int mainSelect;
  while(1){
    int cadAgain;
    
    system("cls");
    printf("-= Alunos =-\n\n");

    printf("1- Cadastrar\n2- Editar\n3- Listar\n4- Excluir\n0- Voltar\n\n");
    scanf("%d", &mainSelect); getchar();

    if(mainSelect == 1){
      while(1){
        system("cls");
        printf("-= Cadastrar Alunos =-\n\n");

       //Nome Aluno
        printf("Digite o nome do aluno:\n");
        fgets(alunoDados[numAluno].nome, 100, stdin);
          //clear Buffer
        size_t ln = strlen(alunoDados[numAluno].nome) - 1;
        if(alunoDados[numAluno].nome[ln] == '\n')  alunoDados[numAluno].nome[ln] = '\0';

        //Cpf Aluno
        do{
            printf("Digite o CPF do aluno:\n");
            fgets(alunoDados[numAluno].cpf, 12, stdin);
            // clear Buffer
            size_t ln = strlen(alunoDados[numAluno].cpf) - 1;
            if (alunoDados[numAluno].cpf[ln] == '\n') alunoDados[numAluno].cpf[ln] = '\0';
        } while (!validarCPF(alunoDados[numAluno].cpf));

        //Sexo ALuno
        do{
          int sexoSel;
          printf("Qual sexo do aluno:\n 1 - Masculino\n 2 - Feminino\n");
          scanf("%d", &sexoSel); getchar();

          switch (sexoSel) {
          case 1: alunoDados[numAluno].sexo = 'M'; break;
          case 2: alunoDados[numAluno].sexo = 'F'; break;

          default: printf("Opcao Invalida!\n");
          }
        }while (alunoDados[numAluno].sexo != 'M' && alunoDados[numAluno].sexo != 'F');
        
      //Data Nascimento 
        do{
          //Dia
          do{
            printf("Digite o dia de nascimento do aluno:\n");
            scanf("%d", &alunoDados[numAluno].dataNascAlun[numAluno].dia); getchar();
            if(alunoDados[numAluno].dataNascAlun[numAluno].dia < 1 || alunoDados[numAluno].dataNascAlun[numAluno].dia > 31) printf("Dia inválido!\n");
            else break;
          }while(1);
          //Mes
          do{
            printf("Digite o mês de nascimento do aluno:\n");
            scanf("%d", &alunoDados[numAluno].dataNascAlun[numAluno].mes); getchar();
            if(alunoDados[numAluno].dataNascAlun[numAluno].mes > 12 || alunoDados[numAluno].dataNascAlun[numAluno].mes < 1) printf("Valor Inválido!\n");
            else break;
          } while(1);
          //Ano
          do{
            printf("Digite o ano de nascimento do aluno:\n");
            scanf("%d", &alunoDados[numAluno].dataNascAlun[numAluno].ano); getchar();
            if(alunoDados[numAluno].dataNascAlun[numAluno].ano < 1920) printf("Você é um dinossauro?\n");
            else break;
          } while(1);
          if(!DataValida(alunoDados[numAluno].dataNascAlun[numAluno].dia, alunoDados[numAluno].dataNascAlun[numAluno].mes, alunoDados[numAluno].dataNascAlun[numAluno].ano))
            printf("Data de nascimento inválida!\n");
        }while(!DataValida(alunoDados[numAluno].dataNascAlun[numAluno].dia, alunoDados[numAluno].dataNascAlun[numAluno].mes, alunoDados[numAluno].dataNascAlun[numAluno].ano));
        
        

        //Matricula Aluno
        do{
          printf("Digite a matricula do aluno:\n");
          fgets(alunoDados[numAluno].matricula, maxMatricula, stdin);
            //clear Buffer
          size_t ln = strlen(alunoDados[numAluno].matricula) - 1;
          if (alunoDados[numAluno].matricula[ln] == '\n'){alunoDados[numAluno].matricula[ln] = '\0';}

          if (strlen(alunoDados[numAluno].matricula) != 12) {
            printf("Matrícula inválida.\n");
            continue;
          }
          else {break;}
        }while(1);

        numAluno++;

        //cadAgain
        printf("Deseja cadastrar novamente?\n1- Sim\n2- Não\n\n");
        scanf("%d", &cadAgain); getchar();
        if(cadAgain == 1) continue;
        else break;
      }
    }
  
  //-= Editar Aluno =-
    else if(mainSelect == 2){
      int alunSelect, editSelect;
      while(1){
        system("cls");
        printf("-= Editar Alunos =-\n\n");
        if(numAluno == 0){
          printf("Nenhum aluno cadastrado!\n\nDigite 0 para voltar.\n\n");
          scanf("%d", &cadAgain); getchar();
          if(cadAgain == 0) break;
        }
        else{
          for(int i = 0; i < numAluno; i++){
            printf("Aluno %d:\n", i + 1);
            printf(" -Nome: %s\n",   alunoDados[i].nome);
            printf(" -Cpf: %s\n",    alunoDados[i].cpf);
            printf(" -Sexo: ");
            if(alunoDados[i].sexo == 'M') printf("Masculino\n");
            else if(alunoDados[i].sexo == 'F') printf("Feminino\n");
            else printf("Outro\n");
            printf(" -Data de Nascimento: %02d/%02d/%d.\n", alunoDados[i].dataNascAlun[i].dia, alunoDados[i].dataNascAlun[i].mes, alunoDados[i].dataNascAlun[i].ano);
            printf(" -Matricula: %s\n\n", alunoDados[i].matricula);
          }
          printf("Digite o numero do aluno para editar, ou digite 0 para sair:\n");
          scanf("%d", &alunSelect); getchar();
          if(alunSelect == 0) break;
          else{
            while(1){
              printf("Escolha o que editar:\n");
              printf("1- Nome\n2- CPF\n3- Sexo\n4- Data de Nascimento\n5- Matricula\n0- Sair\n\n");
              scanf("%d", &editSelect); getchar();
              //EditNome Aluno
              if(editSelect == 1){
                printf("Digite o novo nome do Aluno:\n");
                fgets(alunoDados[alunSelect - 1].nome, 100, stdin);
                  //clear Buffer
                size_t ln = strlen(alunoDados[alunSelect - 1].nome) - 1;
                if(alunoDados[alunSelect - 1].nome[ln] == '\n')  alunoDados[alunSelect - 1].nome[ln] = '\0';
                break;
              }
              else if(editSelect == 2){
              //EditCpf Aluno
                do{
                    printf("Digite o novo CPF do aluno:\n");
                    fgets(alunoDados[alunSelect - 1].cpf, 12, stdin);
                    // clear Buffer
                    size_t ln = strlen(alunoDados[alunSelect - 1].cpf) - 1;
                    if (alunoDados[alunSelect - 1].cpf[ln] == '\n') alunoDados[alunSelect - 1].cpf[ln] = '\0';
                } while (!validarCPF(alunoDados[alunSelect - 1].cpf));
                break;
              }
              else if(editSelect == 3){
                //EditSexo ALuno
                do{
                  int sexoSel;
                  printf("Qual o novo sexo do aluno:\n 1 - Masculino\n 2 - Feminino\n");
                  scanf("%d", &sexoSel); getchar();

                  switch (sexoSel) {
                  case 1: alunoDados[alunSelect - 1].sexo = 'M'; break;
                  case 2: alunoDados[alunSelect - 1].sexo = 'F'; break;

                  default: printf("Opcao Invalida!\n");
                  }
                }while (alunoDados[alunSelect - 1].sexo != 'M' && alunoDados[alunSelect - 1].sexo != 'F');
                break;
              }
              else if(editSelect == 4){
                do{
                  //Dia
                  do{
                    printf("Digite o dia de nascimento do aluno:\n");
                    scanf("%d", &alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].dia); getchar();
                    if(alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].dia < 1 || alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].dia > 31) printf("Dia inválido!\n");
                    else break;
                  }while(1);
                  //Mes
                  do{
                    printf("Digite o mês de nascimento do aluno:\n");
                    scanf("%d", &alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].mes); getchar();
                    if(alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].mes > 12 || alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].mes < 1) printf("Valor Inválido!\n");
                    else break;
                  } while(1);
                  //Ano
                  do{
                    printf("Digite o ano de nascimento do aluno:\n");
                    scanf("%d", &alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].ano); getchar();
                    if(alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].ano < 1920) printf("Você é um dinossauro?\n");
                    else break;
                  } while(1);
                  if(!DataValida(alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].dia, alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].mes, alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].ano))
                    printf("Data de nascimento inválida!\n");
                }while(!DataValida(alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].dia, alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].mes, alunoDados[alunSelect - 1].dataNascAlun[alunSelect - 1].ano));
                break;
              }
                //EditMatricula Aluno
              else if(editSelect == 5){
                
                do{
                  printf("Digite a matricula do aluno:\n");
                  fgets(alunoDados[alunSelect - 1].matricula, maxMatricula, stdin);
                    //clear Buffer
                  size_t ln = strlen(alunoDados[alunSelect - 1].matricula) - 1;
                  if (alunoDados[alunSelect - 1].matricula[ln] == '\n'){alunoDados[alunSelect - 1].matricula[ln] = '\0';}

                  if (strlen(alunoDados[alunSelect - 1].matricula) != 12) {
                    printf("Matrícula inválida.\n");
                    continue;
                  }
                  else {break;}
                }while(1);
                break;
              }
              else break;
            }
            
          }
        }
      }
    }
  //-= Listar Aluno =-
    else if(mainSelect == 3){
      while(1){
        system("cls");
        printf("-= Lista de Alunos =-\n\n");
        
        if(numAluno == 0){
          printf("Nenhum aluno cadastrado!\n\nDigite 0 para voltar.\n");
          scanf("%d", &cadAgain); getchar();
          if(cadAgain == 0) break;
        }
        else{
          for(int i = 0; i < numAluno; i++){
            printf("Aluno %d:\n", i + 1);
            printf(" -Nome: %s\n",   alunoDados[i].nome);
            printf(" -Cpf: %s\n",    alunoDados[i].cpf);
            printf(" -Sexo: ");
            if(alunoDados[i].sexo == 'M') printf("Masculino\n");
            else if(alunoDados[i].sexo == 'F') printf("Feminino\n");
            else printf("Outro\n");
            printf(" -Data de Nascimento: %02d/%02d/%d.\n", alunoDados[i].dataNascAlun[i].dia, alunoDados[i].dataNascAlun[i].mes, alunoDados[i].dataNascAlun[i].ano);
            printf(" -Matricula: %s\n\n", alunoDados[i].matricula);
          }

          printf("Digite 0 para voltar.\n\n");
          scanf("%d", &cadAgain); getchar();
          if(cadAgain == 0) break;
        }
      }
    }
    else if(mainSelect == 4){
      int alunSelect;
      while(1){
        system("cls");
        printf("-= Excluir ALuno =-\n\n");

        if(numAluno == 0){
          printf("Nenhum aluno cadastrado!\n\nDigite 0 para voltar.\n");
          scanf("%d", &cadAgain); getchar();
          if(cadAgain == 0) break;
        }
        else{
          for(int i = 0; i < numAluno; i++){
            printf("Aluno %d:\n", i + 1);
            printf(" -Nome: %s\n",   alunoDados[i].nome);
            printf(" -Cpf: %s\n",    alunoDados[i].cpf);
            printf(" -Sexo: ");
            if(alunoDados[i].sexo == 'M') printf("Masculino\n");
            else if(alunoDados[i].sexo == 'F') printf("Feminino\n");
            else printf("Outro\n");
            printf(" -Data de Nascimento: %02d/%02d/%d.\n", alunoDados[i].dataNascAlun[i].dia, alunoDados[i].dataNascAlun[i].mes, alunoDados[i].dataNascAlun[i].ano);
            printf(" -Matricula: %s\n\n", alunoDados[i].matricula);
          }
          printf("Digite o numero do aluno para EXCLUIR, ou digite 0 para sair:\n");
          scanf("%d", &alunSelect); getchar();
          if(alunSelect == 0) break;
          else{
            if(alunSelect - 1 >= 0 && alunSelect - 1 < numAluno){
              for(int i = alunSelect - 1; i < numAluno - 1; i++){
                alunoDados[i] = alunoDados[i + 1];
              }
              numAluno--;
              break;
            }
          }
        }
      }
    }
  //-= Sair =- 
    else if(mainSelect == 0) break;
  }
}