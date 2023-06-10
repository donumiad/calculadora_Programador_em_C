#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Este programa implementa uma calculadora do tipo programador com as seguintes fun��es e limita��es:
*  Ela ir� receber o valor digitado em decimal, e mostrar� o mesmo valor na forma hexadecimal, octal e binaria
*  O valor digitado pelo usu�rio ter� um limite de 10 digitos.
*  E ser� poss�vel fezer o pera��es de soma, subtra��o, divis�o e multiplica��o
*/


#define REJECT_KEY() (printf("\b \b"))
void MostraOperandos(char entrada, long int operandos[]);
int Transformacao(char entrada, char valor_digitado[], int tranforma_char_int[]);
void operacao(long int* resultadoOperacao, long int operandos[]);
void ZerarArray(int tranforma_char_int[], char valor_Digitado[]);


//****************************DECLARA��O DAS VARI�VEIS GLOBAIS*********************************************
const int TAM_MAXIMO_VALOR_DIGITADO = 10;
int itera = 0;                       //Variavel usada para as itera��es no la�o for
char flagMarcaOperacao = '_';           // 
bool flagTrocaPosOperando = false;   //Esta flag troca o local onde o valor digitado pelo usu�rio vai ser alocado no array "operandos" 
bool sinalInserido = false;          //Marca se o usu�rio ja tinha inserido um simbolo de opera��o. true -> sim, false -> n�o.
char flagNumeroNegativo = '_';         // Marca se o usu�rio quer digitar um numero negativo 0 -> n�o, 1 -> sim
//*********************************************************************************************************




int main() {
    //************************DECLARA��O DAS VARI�VEIS******************************************************

    char entrada;                                          //Ir� receber o dado digitado pelo usu�rio
    long int resultadoOperacao = 0;
    long int operandos[] = { 0, 0 };                      //armazena os dois operandos para fazer a opera��o desejada
    int tranforma_char_int[] = {0,0,0,0,0,0,0,0,0,0};     //Array usado como auxiliar para transformar os valores de char para int
    char valor_Digitado[] = {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'}; //Armazena a entrada

    /*  - O array valor_Digitado[] serve para receber os dados digitados pelo usu�rio e foi inicializado com '_'.
    *   - Toda vez que o usu�rio digitar um valor valido, este digito ser� tamb�m armazenado em tranforma_char_int[]
    *   - Depois os digitos seram convertidos no valor real. Por exemplo, caso o usu�rio digite 4 e depois 5, o digito
    *    4 ser� armazenado em valor_Digitado[0] e tranforma_char_int[0], e o digito 5 em valor_Digitado[1] 
    *    tranforma_char_int[1], e ent�o ser� feito opera��es para que no array operandos[] seja armazenado o long int 45.  
    */
    //********************************************************************************************************


    printf_s("[Calculadora]\n");
    //***********************INICIO DO PROGRAMA***************************************************************
    do {
        entrada = _getche();
        //system("cls");
        if (entrada >= '0' && entrada <= '9') {      //testa se � um caractere est� entre 0 e 9.

            operandos[flagTrocaPosOperando] = Transformacao(entrada, valor_Digitado, tranforma_char_int); //Retorna o numero ja em inteiro
            //MostraOperandos(entrada, operandos);


        }
        else {                 //Testa se foi digitado um operador
            switch (entrada)
            {

            case '/':
            case '*':
            case '+':
                if (operandos[flagTrocaPosOperando] != 0 || operandos[!(flagTrocaPosOperando)] != 0) {
                    if (sinalInserido == false) {  // Essa � a primeira vez que o usu�rio digita um sinal de opera��o?
                        sinalInserido = true;      //Sim! ent�o marca a flag,
                        flagNumeroNegativo = '_';
                        flagMarcaOperacao = entrada;
                        flagTrocaPosOperando = !(flagTrocaPosOperando); //Sim! troca a posi��o de armazenagem dos operandos
                        ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                    }
                    else {                         //N�o!
                        if (valor_Digitado[0] == '_') {      // O usu�rio j� inserio algum valor?
                            REJECT_KEY();
                            break;                           // N�o! Ignora o caractere inserido
                        }
                        else {
                            operacao(&resultadoOperacao, operandos);  // Sim! Chama a fun��o para executar a opera��o desejada
                            sinalInserido = false;
                            flagTrocaPosOperando = !(flagTrocaPosOperando);
                            flagMarcaOperacao = entrada;
                            ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                        }
                    }
                    break;
                }
                REJECT_KEY();
                break;

            case '-':

                if (sinalInserido == false && flagNumeroNegativo != entrada) {         // � o primeiro sinal de opera��o?
                    if (valor_Digitado[0] == '_') {   // Sim! O usu�rio j� digitou algum valor num�rico?
                        flagNumeroNegativo = entrada;       //N�o digitou nenhum valor numerico! Ent�o marca flag que o usu�rio quer inserir um valornegativo
                    }
                    else if (operandos[flagTrocaPosOperando] != 0 || operandos[!(flagTrocaPosOperando)] != 0) {
                        sinalInserido = true;      //Sim! ent�o marca a flag,
                        flagNumeroNegativo = '_';
                        flagMarcaOperacao = entrada;
                        flagTrocaPosOperando = !(flagTrocaPosOperando); //Sim! troca a posi��o de armazenagem dos operandos
                        ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                    }
                    
                }
                else {                         //N�o!
                    if (operandos[flagTrocaPosOperando] == 0 && operandos[!(flagTrocaPosOperando)] == 0) {      // O usu�rio j� inserio algum valor?
                        REJECT_KEY();
                        break;                           // N�o! Ignora o caractere inserido
                        
                    }
                    else {
                        operacao(&resultadoOperacao, operandos);  // Sim! Chama a fun��o para executar a opera��o desejada
                        sinalInserido = false;
                        flagTrocaPosOperando = !(flagTrocaPosOperando);
                        flagMarcaOperacao = entrada;
                        ZerarArray(tranforma_char_int, valor_Digitado);    //sim! Zera os arrays valor_Digitado[] e tranforma_char_int[]
                    }
                }
                break;

            case '\r':
                //fazer tratamento de erro sobre ter digitado um operando ou n�o
                if ((operandos[flagTrocaPosOperando] != 0 && resultadoOperacao != 0) || (operandos[flagTrocaPosOperando] != 0 && operandos[!(flagTrocaPosOperando)] != 0)
                    || (operandos[!(flagTrocaPosOperando)] != 0 && resultadoOperacao != 0)) {
                    operacao(&resultadoOperacao, operandos);
                    sinalInserido = false;
                    flagTrocaPosOperando = !(flagTrocaPosOperando);
                    ZerarArray(tranforma_char_int, valor_Digitado);
                }
                break;
            case ' ':
                break;
            case '\b':

                printf(" \b");
                break;

            default:
                REJECT_KEY();
                break;
            }
        }
        

    } while (entrada != 'p' && entrada != 'P');
 
    return 0;
}


int Transformacao(char entrada, char valor_digitado[], int tranforma_char_int[]) {
    /*O valor digitado pelo usu�rio � do tipo CHAR, logo deve ser transformado em inteiro para realizar as devidas opera��es.
    * a transforma��o ser� feita da seguinte maneira:
    *           - um loop FOR vai verificar quantos digitos ja foram digitados atrav�s da verifica��o da existencia do caractere
    *        "_" ou se o loop tiver chegado ao fim do array.
    *           - ap�s isso, ser� feito outro loop FOR para multiplicar cada digito conforme a posi��o em que est� no array
    *           - por exemplo: caso o usu�rio tenha digitado 2 numeros, a vari�vel itera ser� igual a 1.
    *           - ent�o o segundo FOR ir� multiplicar o digito mais a direita por 1, depois multiplicar o segundo digito
    *        por 10 e somar o resultado com o primeiro.
    *
    */
    long int numero_transformado = 0;
    long int fator_de_multiplicacao[] = { 1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };
    int aux = 0, contador_do_fator = 9;

    //Adiciona o caracter digitado pelo usu�rio no array valor_Digitado***********************
    for (int itera = 0; itera < TAM_MAXIMO_VALOR_DIGITADO; itera++) {
        if (valor_digitado[itera] == '_') {
            valor_digitado[itera] = entrada;
            tranforma_char_int[itera] = entrada - '0';
            break;
        }
    }

    //   Este loop transforma todos os caracteres armazenado no array transforma_char_int em um unico dado no formato LONG INT
    //e armazena na vari�vel numero_transformado.
    for (int itera = 0; itera < TAM_MAXIMO_VALOR_DIGITADO; itera++) {   //Percorre o array para verificar em qual dezena
        if (valor_digitado[itera] == '_' || itera == 9) {             //foi digitado o ultimo digito
            if (itera == 9) {                       //Verifica se foi digitado todos os 10 digitos                              
                for (aux = itera; aux >= 0; aux--) {
                    numero_transformado += tranforma_char_int[aux] * fator_de_multiplicacao[contador_do_fator];
                    contador_do_fator--;
                }
                break;
            }
            else {    // Caso n�o tenha sido digitado 10 digitos, transforma os que foram digitados
                for (aux = itera - 1; aux >= 0; aux--) {
                    numero_transformado += tranforma_char_int[aux] * fator_de_multiplicacao[contador_do_fator];
                    contador_do_fator--;
                }
                break;
            }
        }
    }
    if (flagNumeroNegativo == '-') {
        return ((-1) * (numero_transformado));
    }
    else {
        return numero_transformado;
    }
}


void operacao(long int *resultadoOperacao, long int operandos[]) {
    // long int resultOperacao = *resultadoOperacao;
    if (*resultadoOperacao == 0) {
        switch (flagMarcaOperacao)
        {
        case '+':
            *resultadoOperacao = operandos[0] + operandos[1];
            break;
        case '-':
            *resultadoOperacao = operandos[0] - operandos[1];
            break;
        case '*':
            *resultadoOperacao = operandos[0] * operandos[1];
            break;
        case '/':
            *resultadoOperacao = operandos[0] / operandos[1];  //tratar erro de divis�o por zero
            break;
        case '=':
            printf_s("\nusu�rio solicitou a opera��o resultado\n");
            break;
        default:
            break;
        }
    }
    else {
        switch (flagMarcaOperacao)
        {
        case '+':
            *resultadoOperacao = *resultadoOperacao + operandos[flagTrocaPosOperando];
            break;
        case '-':
            *resultadoOperacao = *resultadoOperacao - operandos[flagTrocaPosOperando];
            break;
        case '*':
            *resultadoOperacao = *resultadoOperacao * operandos[flagTrocaPosOperando];
            break;
        case '/':
            *resultadoOperacao = *resultadoOperacao / operandos[flagTrocaPosOperando];
            break;
        case '=':
            printf_s("\nusu�rio solicitou a opera��o resultado\n");
            break;
        default:
            break;
        }
    }
    operandos[0] = 0;
    operandos[1] = 0;
    printf("\33[2K");
    printf("%d", *resultadoOperacao);
    

    return;
}

void ZerarArray(int tranforma_char_int[], char valor_Digitado[]) {

    for (itera = 0; itera < TAM_MAXIMO_VALOR_DIGITADO; itera++) {
        tranforma_char_int[itera] = 0;
        valor_Digitado[itera] = '_';
    } 
    return;
}

void MostraOperandos(char entrada, long int operandos[]) {
    system("cls");
    printf_s("%d", operandos[0]);
    if (flagMarcaOperacao != '_') {
        printf_s(" %c %d ",entrada, operandos[1]);
    }
    return;
}