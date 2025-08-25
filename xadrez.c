#include <stdio.h>
#include <time.h>
#include <locale.h> //Correção de acentuação
#include <unistd.h> //Para usar Sleep()
#define limpar while (getchar() != '\n')

void movimentoRainha(int movimento){//movimento recebe o valor de movimentoRainha

    if(movimento > 0){//se movimento(que recebeu o valor de movimentoRainha) for maior que 0, executa o código
        printf(" < Esquerda");
        movimentoRainha(movimento - 1);//Chama o própio void movimentoRainha novamente diminuindo em 1 no valor recebido dentro da primeira chamada em int main()
    }
}
void movimentoBispo(int movimento){

    while (movimento > 0)
    {
        for(int i = 0; i < 1; i++){//Gera o movimento para direita uma vezes

        printf("Direita > ");

        }

        movimento--;//Decrementa o valor de movimento em 1, para que o loop se repita conforme a quantidasde de casas escolhida(recebidas em movimnetoBispo)
        printf("Cima ^ ");
    }
}
void movimentoTorre(int movimento){

    if(movimento > 0){
        printf("Direita > ");
        movimentoTorre(movimento - 1);
    }
}

int main(){
    setlocale(LC_ALL, "portuguese");

    int opcoesMenu = 0, peca = 0, movimentoQuantCasas = 0, movimentoCavalo = 1;


    //Menu Inicial loop
    do{
        printf("\n\n---------------------\n");
        printf("     MENU INICIAL");
        printf("\n---------------------\n\n");
        printf("Escolha uma opção:\n\n");
        printf("1 - Inicar\n");
        printf("2 - Regras\n");
        printf("3 - Sair...\n\n");
        scanf("%d", &opcoesMenu);
        limpar;

        if(opcoesMenu == 1){//Se for selecionado 1 sai do loop Menu

            printf("\nIniciando...");
            sleep(2); //Timer de espera

        }else if(opcoesMenu == 2){//Se for selecionado 2 mostra as regras

            printf("\nREGRAS\n\n");
            printf("A Rainha sempre se move para a ESQUERDA, diga quantas casas irá querer mover.\n");
            printf("O Bispo sempre se move para a DIAGONAL DIREITA, diga quantas casas irá querer mover.\n");
            printf("A Torre sempre se move para a DIREITA, diga quantas casas irá querer mover.\n");
            printf("O Cavalo sempre se move para a DIREITA 2 vezes e 1 para a ESQUERDA.");
            
            sleep(3);
            continue;

        }else if(opcoesMenu == 3){//Se for selecionado 3 encerra o programa

            printf("\nSaindo...");
            sleep(2);
            return(0);

        }else{//Se for selecionado algo diferente do que está no Menu repete o loop Menu

            limpar;//Limpa o \n do buffer
            printf("\nOpção inválida, tente novamente...");
            sleep(2);
            continue;
        }

        printf("\n\nQual peça irá mover: \n\n");
        printf("1 - Rainha\n");
        printf("2 - Bispo\n");
        printf("3 - Torre\n");
        printf("4 - Cavalo\n");
        printf("5 - Sair...\n\n");
        scanf("%d", &peca);
        limpar;

        if(peca == 1){
            
            printf("\nQuantas casas irá andar: ");
            scanf("%d", &movimentoQuantCasas);

            printf("\n\nMOVIMENTO RAINHA\n\n");
            movimentoRainha(movimentoQuantCasas);// Chama o Void de movimento da Rainha e atribui a ele o valor de movimentoQuantCasas

        } else if(peca == 2){

            printf("\nQuantas casas irá andar: ");
            scanf("%d", &movimentoQuantCasas);

            printf("\n\nMOVIMENTO BISPO\n\n");
            movimentoBispo(movimentoQuantCasas); // Chama o Void de movimento do Bispo e atribui a ele o valor de movimentoQuantCasas

        } else if(peca == 3){

            printf("\nQuantas casas irá andar: ");
            scanf("%d", &movimentoQuantCasas);

            printf("\n\nMOVIMENTO TORRE\n\n");
            movimentoTorre(movimentoQuantCasas);// Chama o Void de movimento da Torre e atribui a ele o valor de movimentoQuantCasas

        } else if(peca == 4){

            printf("\nMOVIMENTO CAVALO\n\n");

            while(1){//Inicia o loop com o mivimento sendo 1, após decrementa o movimento em 1

                if(movimentoCavalo <= 2){ //Faz com que o movimento "Cima ^" seja repetido duas vezes

                    printf("Cima ^ ");
                    movimentoCavalo++;
                    continue;

                }else{

                    printf("Direita > ");
                    break;
                }
            }
        }else if(peca == 5){//Se for selecionado 5 encerra o programa

            printf("\nSaindo...");
            sleep(2);
            return(0);

        }else{//Se for selecionado algo diferente do que está no Menu repete o loop Menu

            limpar;// Limpa o \n do buffer
            printf("\nOpção inválida, tente novamente...");
            sleep(2);
            continue;
        }
    } while (1);
}
