#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define COL (2)
#define LIN (37)
int main(){
    //=====================VARI�VEL====================================

    int x, y;
    int i = 0;
    char texto[1000];
    char textoUpper[1000];
    char cripto[1000];
    char descripto[1000];
    int escolha;


    //=====================//====================================


    for(i=0; i<1000; i++){
        descripto[i]=0;
    }
     //=====================CIFRA====================================
    char morse[LIN][COL] = {
        {' ', ' '}, {'0', '9'}, {'1', '8'}, {'2', '7'}, {'3', '6'}, {'4', '5'}, 
        {'5', '4'}, {'6', '3'}, {'7', '2'}, {'8', '1'}, {'9', '0'}, {'A', '!'}, 
        {'B', '@'}, {'C', '#'}, {'D', '$'}, {'E', '%'}, {'F', ';'}, {'G', '&'}, 
        {'H', '*'}, {'I', '('}, {'J', ')'}, {'K', '_'}, {'L', '-'}, {'M', '='}, 
        {'N', '>'}, {'O', '<'}, {'P', '"'}, {'Q', ':'}, {'R', '+'}, {'S', '.'}, 
        {'T', '{'}, {'U', '~'}, {'V', '}'}, {'W', '^'}, {'X', 'x'}, {'Y', '/'}, 
        {'Z', '|'} 
    };
    //=====================VARIAVEIS CONVERSÃO PARA ASCII====================================


    int conversaoT[1000];
    int conversaoM[1000];
    int conversaoC[1000];
    int conversaoX[1000];

    printf("\n\t[0] Criptografar\n\t[1] Descriptografar\n\t");
    scanf("%d", &escolha);

    //=====================//====================================
  
    switch (escolha)
    {
    case 0:
    
  
    printf("Digite o texto que você quer criptografar: \n");
    getchar();
    fgets(texto, sizeof(texto), stdin);
    int tam = strlen(texto);

    //=====================COLOCANDO TODAS AS  LETRAS EM MAIÚSCULO====================================
    while(y < tam){
        textoUpper[y] = toupper(texto[y]);
        y++;
    }
    //=====================//====================================

    
   
    //=====================CONVERTENDO PARA ASCII====================================
    
    if(texto[i] < 65)
     for(i = 0; i < tam; i++){
        conversaoT[i] = textoUpper[i];
    }
    for(i = 0; i < LIN; i++){
        conversaoM[i] = morse[i][0];
    }
    //=====================//====================================
    //=====================CRIPTOGRAFANDO====================================

    
    for(i = 0; i < tam; i++){
        for(x = 0; x < LIN; x++){
            if(conversaoT[i] == conversaoM[x]){
                cripto[i] = morse[x][1];
            }
        }
    }
    printf("%s\n\n", cripto);
    break;
    
    //=========================================================
    //=====================DESCRIPTOGRAFIA====================================
    case 1:
    printf("Digite a criptografia:\n");
    getchar();
    fgets(cripto, 1000, stdin);
    int tamC = strlen(cripto);
    for(i=0;i<tamC;i++){
        conversaoC[i] = cripto[i];
    }
    for(i=0;i<LIN;i++){
        conversaoX[i] = morse[i][1];
    }
    for(i = 0; i < tamC; i++){
        for(x = 0; x < LIN; x++){
            if(conversaoC[i] == conversaoX[x]){
                descripto[i] = morse[x][0];
            }
        }
    }
    printf("%s\n\n", descripto);
        break;
    default:
            printf("Numero incorreto...");
        break;
    }
    return 0;
    }