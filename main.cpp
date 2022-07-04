#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
#define TAM 4
#define VET 16

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"Portuguese");
    int M[TAM][TAM]{1,4,5,2,7,2,8,7,3,6,1,4,6,5,3,8}; // MATRIZ PRINCIPAL
    int T[TAM][TAM]{1,7,3,6,4,2,6,5,5,8,1,3,2,7,4,8}; // TRANSPOSTA
    int IL[TAM][TAM]{6,5,3,8,3,6,1,4,7,2,8,7,1,4,5,2}; // INVERTE LINHA
    int IC[TAM][TAM]{2,5,4,1,7,8,2,7,4,1,6,3,8,3,5,6}; // INVERTE COLUNA
    int vet1[VET]{5,5,5,5,5,5,5,5}, vet2[VET]{5,5,5,5,5,5,5,5}; //SALVAR CORDENADAS
    int vet3[VET]{5,5,5,5,5,5,5,5}, vet4[VET]{5,5,5,5,5,5,5,5}; //SALVAR CORDENADAS
    int i=0, j=0, selecao; // VARIAÇÃO LINHAS E COLUNAS
    int tabela_i, tabela_j; //IMPRESSÃO TABELA
    int cord1, cord2, cord3, cord4; // ENTRADA DE CORDENADAS PARA VALOR DA TABELA
    int chance=10, pos=0, ponto=0; //VARIAVEIS PARA ACRESCENTAR O PONTO E PARA GRAVAR A CORDENADA NO VETOR (POS)
    int s=0, set_01=0, verif;// (S) VERIFICAÇÃO DE IMPRESSÕES DE CORDENADA; (VERIF) VERIFICAÇÃO DE CORDENADAS; (SET_01) TROCAR MATRIZES;
    char iniciar; //(INICIAR) INICIAR O JOGO;

    ///INTERFACE INICIAL DO JOGO
    cout<<"Digite S para começar\n";
    cin>>iniciar;

    ///LAÇO PARA COMEÇAR O JOGO PRECIONANDO A TECLA S
    do {

        if(iniciar!='s'&&iniciar!='S'){
            cout<<"Inaválido !\n Digite S para começar\n";
            cin>>iniciar;
        }

    } while(iniciar!='s'&&iniciar!='S');

    system("cls");

    ///GERA NÚMERO ALEATÓRIO E SELECIONA MATRIZ
    selecao=rand()%4+1;

    ///SELECIONA QUAL TABELA VAI SER O JOGO
    switch (selecao){

    ///MATRIZ PRINCIPAL
    case 1:

        /// GERA MATRIZ PRINCIPAL PARA VISUALIZAÇÃO;
        cout<<"TEMPO DE VISUALIZAÇÃO:\n";
        for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

            cout<<endl;

            for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                    cout << M[i][j];
                    j++;
                    if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I)
                        i++;
                        j=0;
                    }

                }
                else{ //CONDIÇÃO PARA O RESTO DA TABELA
                    if(tabela_j%4==0){ //PARA CRIAR OS |
                        cout<<"|";
                    }
                    else { //PARA CRIAR OS ESPAÇOS
                        cout<<" ";
                    }
                }

            }

            cout << endl;
            if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                    cout<<"-";
                }
            }
            else{
                cout<<endl;
            }

        }

        Sleep(10000); //SEGUNDOS PARA VISUALISAÇÃO
        system("cls"); //LIMPA A TELA

        ///LAÇO PARA RODAR O JOGO
        while(chance>0&&ponto<8){
            i=0; j=0; //RESETA I E J PARA CONSTRUÇÃO DA PRÓXIMA TABELA;
            verif=0;

            ///GERA TABELA COM AS CORDENADAS SALVAS NOS VETORES
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y

                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(s<1){ //CASO NÃO SEJA A CORDENADA
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                        }
                        else{ //CONDIÇÃO PARA O RESTO DA TABELA
                            if(tabela_j%4==0){ //PARA CRIAR OS |
                                cout<<"|";
                            }
                            else { //PARA CRIAR OS ESPAÇOS
                                cout<<" ";
                            }
                        }
                    }

                    cout << endl;
                    if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                        for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                            cout<<"-";
                        }
                    }
                    else{
                        cout<<endl;
                    }
                }
                s=0;

            ///VERIFICAÇÃO DAS 1º CORDENADAS
            do{
                ///PEDE O PRIMEIRO PAR DE CORDENADAS
                cout<<endl<<"Digite o primeiro par\n";
                cout<<"Cordenada 1: ";
                cin>>cord1;
                cout<<"Cordenada 2: ";
                cin>>cord2;
                cord1--; cord2--; //TRANSFORMA AS CORDENADAS DE 1 A 4 PARA 0 A 3 DAS MATRIZES
                set_01=0;

                ///VERIFICAÇÃO SE VETOR É IGUAL A CORDENADA
                for(verif=0;verif<8;verif++){

                    if(vet1[verif]==cord1&&vet2[verif]==cord2){
                        set_01++;
                    }
                    if(vet3[verif]==cord1&&vet4[verif]==cord2){
                        set_01++;
                    }
                }

                ///VERIFICA SE AS CORDENADAS ESTÃO ENTRE 1 E 4
                if(cord1>3||cord1<0||cord2>3||cord2<0){
                    set_01++;
                }

                ///CASO VETOR FOR IGUAL A CORDENADA
                if(set_01>0){

                    cout<<"\nCORDENADAS INVÁLIDAS !";
                    Sleep(2000);

                    system("cls");

                    ///IMPRESSÃO DA TABELA
                    i=0; j=0;
                    verif=0;
                    cout<<"Vidas: "<<chance<<" / "<<"10";
                    for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                    cout<<endl;

                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y

                        if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                            for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                                if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[vet1[verif]][vet2[verif]];
                                    s++;
                                }

                                if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[vet3[verif]][vet4[verif]];
                                    s++;
                                }
                            }

                            if(s<1){ //CASO NÃO SEJA A CORDENADA
                                cout<<" ";
                            }

                            s=0;
                            j++;

                            if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                                i++;
                                j=0;
                            }

                        }
                        else{ //CONDIÇÃO PARA O RESTO DA TABELA
                            if(tabela_j%4==0){ //PARA CRIAR OS |
                                cout<<"|";
                            }
                            else { //PARA CRIAR OS ESPAÇOS
                                cout<<" ";
                            }
                        }
                    }

                    cout << endl;
                    if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                        for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                            cout<<"-";
                        }
                    }
                    else{
                        cout<<endl;
                    }


                }
                }

            }while(set_01>0); //FIM DA VERIFICAÇÃO

            system("cls"); //LIMPA A TELA
            i=0; j=0;//RESETA I E J PARA CONSTRUÇÃO DA PRÓXIMA TABELA;

            ///GERA A TABELA COM OS VALORES DAS CORDENADAS
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                for(tabela_j=1;tabela_j<16;tabela_j++){
                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(cord1==i&&cord2==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(s<1){
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                    }
                    else{ //CONDIÇÃO PARA O RESTO DA TABELA
                        if(tabela_j%4==0){ //PARA CRIAR OS |
                            cout<<"|";
                        }
                        else { //PARA CRIAR OS ESPAÇOS
                            cout<<" ";
                        }
                    }

                }

                cout << endl;
                if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                        cout<<"-";
                    }
                }
                else{
                    cout<<endl;
                }

            }

            cord1++; cord2++; // MOSTRA AS CORDENADAS DE 1 A 4


            ///VERIFICAÇÃO DAS 2º CORDENADAS
            do{
                ///REEMPRIME O PRIMEIRO PAR DE CORDENADAS E PEDE PELO SEGUNDO PAR
                cout<<"Digite o primeiro par\n";
                cout<<"Cordenada 1: "<<cord1;
                cout<<"\nCordenada 2: "<<cord2<<endl<<endl;
                cout<<"Digite o segundo par\n";
                cout<<"Cordenada 3: ";
                cin>>cord3;
                cout<<"Cordenada 4: ";
                cin>>cord4;
                cord1--; cord2--; cord3--; cord4--; //VOLTA PARA POSIÇÃO DE 0 A 3 DAS MATRIZES

                set_01=0;
                ///VERIFICAÇÃO SE VETOR É IGUAL A CORDENADA
                for(verif=0;verif<8;verif++){

                    if(vet1[verif]==cord3&&vet2[verif]==cord4){
                        set_01++;
                    }
                    if(vet3[verif]==cord3&&vet4[verif]==cord4){
                        set_01++;
                    }
                }

                ///VERIFICA SE AS CORDENADAS ESTÃO ENTRE 1 E 4
                if(cord3>3||cord3<0||cord4>3||cord4<0){
                    set_01++;
                }

                ///VERIFICA SE AS 1º CORDENDAS SÃO IGUAS AS 2º
                if(cord1==cord3&&cord2==cord4){
                    set_01++;
                }

                ///CASO VETOR OU A 1º CORDENADA FOR IGUAL A 2º CORDENADA
                if(set_01>0){

                    cout<<"\nCORDENADAS INVÁLIDAS !";
                    Sleep(2000);

                    system("cls");
                    i=0; j=0;
                    verif=0;

                    ///GERA A TABELA COM OS VALORES DAS CORDENADAS
                    cout<<"Vidas: "<<chance<<" / "<<"10";
                    for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                        cout<<endl;

                        ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                        for(tabela_j=1;tabela_j<16;tabela_j++){
                            if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                                for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                                    if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                        cout << M[vet1[verif]][vet2[verif]];
                                        s++;
                                    }

                                    if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                        cout << M[vet3[verif]][vet4[verif]];
                                        s++;
                                    }
                                }

                                if(cord1==i&&cord2==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[i][j];
                                    s++;
                                }

                                if(s<1){
                                cout<<" ";
                                }

                                s=0;
                                j++;

                                if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                                    i++;
                                    j=0;
                                }

                            }
                            else{ //CONDIÇÃO PARA O RESTO DA TABELA
                                if(tabela_j%4==0){ //PARA CRIAR OS |
                                    cout<<"|";
                                }
                                else { //PARA CRIAR OS ESPAÇOS
                                    cout<<" ";
                                }
                            }

                        }

                        cout << endl;
                        if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                            for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                                cout<<"-";
                            }
                        }
                        else{
                            cout<<endl;
                        }

                    }
                cord1++; cord2++; //QUANDO ENTRA NESTE IF E VOLTA PARA O INÍCIO DO (DO) A CORD1-- E CORD2--, POR ISSO CORD++;
                }
            }while(set_01>0);

            i=0; j=0;
            system("cls");

            ///IMPRIME A TABELA COM O PRIMEIRO PAR DE CORDENADS E COM O SEGUNDO PAR DE CORDENADAS
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                for(tabela_j=1;tabela_j<16;tabela_j++){
                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA IMPRIMIR AS CORDENADAS DOS VETORES
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA IMPRIMIR AS CORDENADAS DOS VETORES
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(cord1==i&&cord2==j){ //CONDIÇÃO PARA IMPRIMIR AS 1º CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(cord3==i&&cord4==j){ //CONDIÇÃO PARA IMPRIMIR AS 2º CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(s<1){
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                    }
                    else{ //CONDIÇÃO PARA O RESTO DA TABELA
                        if(tabela_j%4==0){ //PARA CRIAR OS |
                            cout<<"|";
                        }
                        else { //PARA CRIAR OS ESPAÇOS
                            cout<<" ";
                        }
                    }

                }

                cout << endl;
                if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                        cout<<"-";
                    }
                }
                else{
                    cout<<endl;
                }

            }
            Sleep(1000);

            ///SALVA AS CORDENADAS NOS VETORES E CONTA PONTO
            if(M[cord1][cord2]==M[cord3][cord4]){

                vet1[pos]=cord1;
                vet2[pos]=cord2;
                vet3[pos]=cord3;
                vet4[pos]=cord4;

                pos++;
                ponto++;

            }

            ///DECREMENTA AS CHANCES A CADA VEZ QUE ERRA OS VALORES
            else{
                chance--;
            }

            system("cls");
    }

        ///CONDIÇÃO PARA QUANDO MORRE POR VIDAS
        if(chance<1){
            cout<<"ACABOU SUAS VIDAS";
        }

        ///CONDIÇÃO PARA QUANDO VENCE O JOGO
        else{
            cout<<"\n\n\n\n\n\n\n\t\t\tCONGRATULATION... YOU WINED THE BIG MEMORY PLAY\n\n\n\n\n\n\n\n\n\n\n";
        }

        break;

    ///MATRIZ TRANSPOSTA
    case 2:
        cout<<"TEMPO DE VISUALIZAÇÃO:\n";
        ///COPIA OS VALORES DA MATRIZ PRINCIPAL PARA MATRIZ TRANSPOTA;
        for(tabela_i=0;tabela_i<4;tabela_i++){//GERA OS VALORES DAS LINHAS

            for(tabela_j=0;tabela_j<4;tabela_j++){//GERA OS VALORES DAS COLUNAS
                M[tabela_i][tabela_j]=T[tabela_i][tabela_j];
            }
        }
        tabela_i=0; tabela_j=0;

        /// GERA MATRIZ TRANS´POSTA PARA VISUALIZAÇÃO;
        for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

            cout<<endl;

            for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                    cout << M[i][j];
                    j++;
                    if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I)
                        i++;
                        j=0;
                    }

                }
                else{ //CONDIÇÃO PARA O RESTO DA TABELA
                    if(tabela_j%4==0){ //PARA CRIAR OS |
                        cout<<"|";
                    }
                    else { //PARA CRIAR OS ESPAÇOS
                        cout<<" ";
                    }
                }

            }

            cout << endl;
            if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                    cout<<"-";
                }
            }
            else{
                cout<<endl;
            }

        }

        Sleep(5000); //3s PARA VISUALISAÇÃO
        system("cls"); //LIMPA A TELA

        ///LAÇO PARA RODAR O JOGO
        while(chance>0&&ponto<8){
            i=0; j=0; //RESETA I E J PARA CONSTRUÇÃO DA PRÓXIMA TABELA;
            verif=0;

            ///GERA TABELA COM AS CORDENADAS SALVAS NOS VETORES
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y

                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(s<1){ //CASO NÃO SEJA A CORDENADA
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                        }
                        else{ //CONDIÇÃO PARA O RESTO DA TABELA
                            if(tabela_j%4==0){ //PARA CRIAR OS |
                                cout<<"|";
                            }
                            else { //PARA CRIAR OS ESPAÇOS
                                cout<<" ";
                            }
                        }
                    }

                    cout << endl;
                    if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                        for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                            cout<<"-";
                        }
                    }
                    else{
                        cout<<endl;
                    }
                }
                s=0;

            ///VERIFICAÇÃO DAS 1º CORDENADAS
            do{
                ///PEDE O PRIMEIRO PAR DE CORDENADAS
                cout<<endl<<"Digite o primeiro par\n";
                cout<<"Cordenada 1: ";
                cin>>cord1;
                cout<<"Cordenada 2: ";
                cin>>cord2;
                cord1--; cord2--; //TRANSFORMA AS CORDENADAS DE 1 A 4 PARA 0 A 3 DAS MATRIZES
                set_01=0;

                ///VERIFICAÇÃO SE VETOR É IGUAL A CORDENADA
                for(verif=0;verif<8;verif++){

                    if(vet1[verif]==cord1&&vet2[verif]==cord2){
                        set_01++;
                    }
                    if(vet3[verif]==cord1&&vet4[verif]==cord2){
                        set_01++;
                    }
                }

                ///VERIFICA SE AS CORDENADAS ESTÃO ENTRE 1 E 4
                if(cord1>3||cord1<0||cord2>3||cord2<0){
                    set_01++;
                }

                ///CASO VETOR FOR IGUAL A CORDENADA
                if(set_01>0){

                    cout<<"\nCORDENADAS INVÁLIDAS !";
                    Sleep(2000);

                    system("cls");

                    ///IMPRESSÃO DA TABELA
                    i=0; j=0;
                    verif=0;
                    cout<<"Vidas: "<<chance<<" / "<<"10";
                    for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                    cout<<endl;

                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y

                        if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                            for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                                if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[vet1[verif]][vet2[verif]];
                                    s++;
                                }

                                if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[vet3[verif]][vet4[verif]];
                                    s++;
                                }
                            }

                            if(s<1){ //CASO NÃO SEJA A CORDENADA
                                cout<<" ";
                            }

                            s=0;
                            j++;

                            if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                                i++;
                                j=0;
                            }

                        }
                        else{ //CONDIÇÃO PARA O RESTO DA TABELA
                            if(tabela_j%4==0){ //PARA CRIAR OS |
                                cout<<"|";
                            }
                            else { //PARA CRIAR OS ESPAÇOS
                                cout<<" ";
                            }
                        }
                    }

                    cout << endl;
                    if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                        for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                            cout<<"-";
                        }
                    }
                    else{
                        cout<<endl;
                    }


                }
                }

            }while(set_01>0); //FIM DA VERIFICAÇÃO

            system("cls"); //LIMPA A TELA
            i=0; j=0;//RESETA I E J PARA CONSTRUÇÃO DA PRÓXIMA TABELA;

            ///GERA A TABELA COM OS VALORES DAS CORDENADAS
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                for(tabela_j=1;tabela_j<16;tabela_j++){
                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(cord1==i&&cord2==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(s<1){
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                    }
                    else{ //CONDIÇÃO PARA O RESTO DA TABELA
                        if(tabela_j%4==0){ //PARA CRIAR OS |
                            cout<<"|";
                        }
                        else { //PARA CRIAR OS ESPAÇOS
                            cout<<" ";
                        }
                    }

                }

                cout << endl;
                if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                        cout<<"-";
                    }
                }
                else{
                    cout<<endl;
                }

            }

            cord1++; cord2++; // MOSTRA AS CORDENADAS DE 1 A 4


            ///VERIFICAÇÃO DAS 2º CORDENADAS
            do{
                ///REEMPRIME O PRIMEIRO PAR DE CORDENADAS E PEDE PELO SEGUNDO PAR
                cout<<"Digite o primeiro par\n";
                cout<<"Cordenada 1: "<<cord1;
                cout<<"\nCordenada 2: "<<cord2<<endl<<endl;
                cout<<"Digite o segundo par\n";
                cout<<"Cordenada 3: ";
                cin>>cord3;
                cout<<"Cordenada 4: ";
                cin>>cord4;
                cord1--; cord2--; cord3--; cord4--; //VOLTA PARA POSIÇÃO DE 0 A 3 DAS MATRIZES

                set_01=0;
                ///VERIFICAÇÃO SE VETOR É IGUAL A CORDENADA
                for(verif=0;verif<8;verif++){

                    if(vet1[verif]==cord3&&vet2[verif]==cord4){
                        set_01++;
                    }
                    if(vet3[verif]==cord3&&vet4[verif]==cord4){
                        set_01++;
                    }
                }

                ///VERIFICA SE AS CORDENADAS ESTÃO ENTRE 1 E 4
                if(cord3>3||cord3<0||cord4>3||cord4<0){
                    set_01++;
                }

                ///VERIFICA SE AS 1º CORDENDAS SÃO IGUAS AS 2º
                if(cord1==cord3&&cord2==cord4){
                    set_01++;
                }

                ///CASO VETOR OU A 1º CORDENADA FOR IGUAL A 2º CORDENADA
                if(set_01>0){

                    cout<<"\nCORDENADAS INVÁLIDAS !";
                    Sleep(2000);

                    system("cls");
                    i=0; j=0;
                    verif=0;

                    ///GERA A TABELA COM OS VALORES DAS CORDENADAS
                    cout<<"Vidas: "<<chance<<" / "<<"10";
                    for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                        cout<<endl;

                        ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                        for(tabela_j=1;tabela_j<16;tabela_j++){
                            if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                                for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                                    if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                        cout << M[vet1[verif]][vet2[verif]];
                                        s++;
                                    }

                                    if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                        cout << M[vet3[verif]][vet4[verif]];
                                        s++;
                                    }
                                }

                                if(cord1==i&&cord2==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[i][j];
                                    s++;
                                }

                                if(s<1){
                                cout<<" ";
                                }

                                s=0;
                                j++;

                                if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                                    i++;
                                    j=0;
                                }

                            }
                            else{ //CONDIÇÃO PARA O RESTO DA TABELA
                                if(tabela_j%4==0){ //PARA CRIAR OS |
                                    cout<<"|";
                                }
                                else { //PARA CRIAR OS ESPAÇOS
                                    cout<<" ";
                                }
                            }

                        }

                        cout << endl;
                        if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                            for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                                cout<<"-";
                            }
                        }
                        else{
                            cout<<endl;
                        }

                    }
                cord1++; cord2++; //QUANDO ENTRA NESTE IF E VOLTA PARA O INÍCIO DO (DO) A CORD1-- E CORD2--, POR ISSO CORD++;
                }
            }while(set_01>0);

            i=0; j=0;
            system("cls");

            ///IMPRIME A TABELA COM O PRIMEIRO PAR DE CORDENADS E COM O SEGUNDO PAR DE CORDENADAS
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                for(tabela_j=1;tabela_j<16;tabela_j++){
                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA IMPRIMIR AS CORDENADAS DOS VETORES
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA IMPRIMIR AS CORDENADAS DOS VETORES
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(cord1==i&&cord2==j){ //CONDIÇÃO PARA IMPRIMIR AS 1º CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(cord3==i&&cord4==j){ //CONDIÇÃO PARA IMPRIMIR AS 2º CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(s<1){
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                    }
                    else{ //CONDIÇÃO PARA O RESTO DA TABELA
                        if(tabela_j%4==0){ //PARA CRIAR OS |
                            cout<<"|";
                        }
                        else { //PARA CRIAR OS ESPAÇOS
                            cout<<" ";
                        }
                    }

                }

                cout << endl;
                if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                        cout<<"-";
                    }
                }
                else{
                    cout<<endl;
                }

            }
            Sleep(1000);

            ///SALVA AS CORDENADAS NOS VETORES E CONTA PONTO
            if(M[cord1][cord2]==M[cord3][cord4]){

                vet1[pos]=cord1;
                vet2[pos]=cord2;
                vet3[pos]=cord3;
                vet4[pos]=cord4;

                pos++;
                ponto++;

            }

            ///DECREMENTA AS CHANCES A CADA VEZ QUE ERRA OS VALORES
            else{
                chance--;
            }

            system("cls");
    }

        ///CONDIÇÃO PARA QUANDO MORRE POR VIDAS
        if(chance<1){
            cout<<"ACABOU SUAS VIDAS";
        }

        ///CONDIÇÃO PARA QUANDO VENCE O JOGO
        else{
            cout<<"\n\n\n\n\n\n\n\t\t\tCONGRATULATION... YOU WINED THE BIG MEMORY PLAY\n\n\n\n\n\n\n\n\n\n\n";
        }

        break;

    ///MATRIZ INVERTE COLUNA
    case 3:
        cout<<"TEMPO DE VISUALIZAÇÃO:\n";
        ///COPIA OS VALORES DA MATRIZ IC PARA MATRIZ PRIINCIPAL
        for(tabela_i=0;tabela_i<4;tabela_i++){//GERA OS VALORES DAS LINHAS

            for(tabela_j=0;tabela_j<4;tabela_j++){//GERA OS VALORES DAS COLUNAS
                M[tabela_i][tabela_j]=IC[tabela_i][tabela_j];
            }
        }
        tabela_i=0; tabela_j=0;

        /// GERA MATRIZ IC PARA VISUALIZAÇÃO;
        for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

            cout<<endl;

            for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                    cout << M[i][j];
                    j++;
                    if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I)
                        i++;
                        j=0;
                    }

                }
                else{ //CONDIÇÃO PARA O RESTO DA TABELA
                    if(tabela_j%4==0){ //PARA CRIAR OS |
                        cout<<"|";
                    }
                    else { //PARA CRIAR OS ESPAÇOS
                        cout<<" ";
                    }
                }

            }

            cout << endl;
            if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                    cout<<"-";
                }
            }
            else{
                cout<<endl;
            }

        }

        Sleep(5000); //3s PARA VISUALISAÇÃO
        system("cls"); //LIMPA A TELA

        ///LAÇO PARA RODAR O JOGO
        while(chance>0&&ponto<8){
            i=0; j=0; //RESETA I E J PARA CONSTRUÇÃO DA PRÓXIMA TABELA;
            verif=0;

            ///GERA TABELA COM AS CORDENADAS SALVAS NOS VETORES
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y

                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(s<1){ //CASO NÃO SEJA A CORDENADA
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                        }
                        else{ //CONDIÇÃO PARA O RESTO DA TABELA
                            if(tabela_j%4==0){ //PARA CRIAR OS |
                                cout<<"|";
                            }
                            else { //PARA CRIAR OS ESPAÇOS
                                cout<<" ";
                            }
                        }
                    }

                    cout << endl;
                    if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                        for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                            cout<<"-";
                        }
                    }
                    else{
                        cout<<endl;
                    }
                }
                s=0;

            ///VERIFICAÇÃO DAS 1º CORDENADAS
            do{
                ///PEDE O PRIMEIRO PAR DE CORDENADAS
                cout<<endl<<"Digite o primeiro par\n";
                cout<<"Cordenada 1: ";
                cin>>cord1;
                cout<<"Cordenada 2: ";
                cin>>cord2;
                cord1--; cord2--; //TRANSFORMA AS CORDENADAS DE 1 A 4 PARA 0 A 3 DAS MATRIZES
                set_01=0;

                ///VERIFICAÇÃO SE VETOR É IGUAL A CORDENADA
                for(verif=0;verif<8;verif++){

                    if(vet1[verif]==cord1&&vet2[verif]==cord2){
                        set_01++;
                    }
                    if(vet3[verif]==cord1&&vet4[verif]==cord2){
                        set_01++;
                    }
                }

                ///VERIFICA SE AS CORDENADAS ESTÃO ENTRE 1 E 4
                if(cord1>3||cord1<0||cord2>3||cord2<0){
                    set_01++;
                }

                ///CASO VETOR FOR IGUAL A CORDENADA
                if(set_01>0){

                    cout<<"\nCORDENADAS INVÁLIDAS !";
                    Sleep(2000);

                    system("cls");

                    ///IMPRESSÃO DA TABELA
                    i=0; j=0;
                    verif=0;
                    cout<<"Vidas: "<<chance<<" / "<<"10";
                    for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                    cout<<endl;

                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y

                        if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                            for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                                if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[vet1[verif]][vet2[verif]];
                                    s++;
                                }

                                if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[vet3[verif]][vet4[verif]];
                                    s++;
                                }
                            }

                            if(s<1){ //CASO NÃO SEJA A CORDENADA
                                cout<<" ";
                            }

                            s=0;
                            j++;

                            if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                                i++;
                                j=0;
                            }

                        }
                        else{ //CONDIÇÃO PARA O RESTO DA TABELA
                            if(tabela_j%4==0){ //PARA CRIAR OS |
                                cout<<"|";
                            }
                            else { //PARA CRIAR OS ESPAÇOS
                                cout<<" ";
                            }
                        }
                    }

                    cout << endl;
                    if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                        for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                            cout<<"-";
                        }
                    }
                    else{
                        cout<<endl;
                    }


                }
                }

            }while(set_01>0); //FIM DA VERIFICAÇÃO

            system("cls"); //LIMPA A TELA
            i=0; j=0;//RESETA I E J PARA CONSTRUÇÃO DA PRÓXIMA TABELA;

            ///GERA A TABELA COM OS VALORES DAS CORDENADAS
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                for(tabela_j=1;tabela_j<16;tabela_j++){
                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(cord1==i&&cord2==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(s<1){
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                    }
                    else{ //CONDIÇÃO PARA O RESTO DA TABELA
                        if(tabela_j%4==0){ //PARA CRIAR OS |
                            cout<<"|";
                        }
                        else { //PARA CRIAR OS ESPAÇOS
                            cout<<" ";
                        }
                    }

                }

                cout << endl;
                if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                        cout<<"-";
                    }
                }
                else{
                    cout<<endl;
                }

            }

            cord1++; cord2++; // MOSTRA AS CORDENADAS DE 1 A 4


            ///VERIFICAÇÃO DAS 2º CORDENADAS
            do{
                ///REEMPRIME O PRIMEIRO PAR DE CORDENADAS E PEDE PELO SEGUNDO PAR
                cout<<"Digite o primeiro par\n";
                cout<<"Cordenada 1: "<<cord1;
                cout<<"\nCordenada 2: "<<cord2<<endl<<endl;
                cout<<"Digite o segundo par\n";
                cout<<"Cordenada 3: ";
                cin>>cord3;
                cout<<"Cordenada 4: ";
                cin>>cord4;
                cord1--; cord2--; cord3--; cord4--; //VOLTA PARA POSIÇÃO DE 0 A 3 DAS MATRIZES

                set_01=0;
                ///VERIFICAÇÃO SE VETOR É IGUAL A CORDENADA
                for(verif=0;verif<8;verif++){

                    if(vet1[verif]==cord3&&vet2[verif]==cord4){
                        set_01++;
                    }
                    if(vet3[verif]==cord3&&vet4[verif]==cord4){
                        set_01++;
                    }
                }

                ///VERIFICA SE AS CORDENADAS ESTÃO ENTRE 1 E 4
                if(cord3>3||cord3<0||cord4>3||cord4<0){
                    set_01++;
                }

                ///VERIFICA SE AS 1º CORDENDAS SÃO IGUAS AS 2º
                if(cord1==cord3&&cord2==cord4){
                    set_01++;
                }

                ///CASO VETOR OU A 1º CORDENADA FOR IGUAL A 2º CORDENADA
                if(set_01>0){

                    cout<<"\nCORDENADAS INVÁLIDAS !";
                    Sleep(2000);

                    system("cls");
                    i=0; j=0;
                    verif=0;

                    ///GERA A TABELA COM OS VALORES DAS CORDENADAS
                    cout<<"Vidas: "<<chance<<" / "<<"10";
                    for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                        cout<<endl;

                        ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                        for(tabela_j=1;tabela_j<16;tabela_j++){
                            if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                                for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                                    if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                        cout << M[vet1[verif]][vet2[verif]];
                                        s++;
                                    }

                                    if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                        cout << M[vet3[verif]][vet4[verif]];
                                        s++;
                                    }
                                }

                                if(cord1==i&&cord2==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[i][j];
                                    s++;
                                }

                                if(s<1){
                                cout<<" ";
                                }

                                s=0;
                                j++;

                                if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                                    i++;
                                    j=0;
                                }

                            }
                            else{ //CONDIÇÃO PARA O RESTO DA TABELA
                                if(tabela_j%4==0){ //PARA CRIAR OS |
                                    cout<<"|";
                                }
                                else { //PARA CRIAR OS ESPAÇOS
                                    cout<<" ";
                                }
                            }

                        }

                        cout << endl;
                        if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                            for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                                cout<<"-";
                            }
                        }
                        else{
                            cout<<endl;
                        }

                    }
                cord1++; cord2++; //QUANDO ENTRA NESTE IF E VOLTA PARA O INÍCIO DO (DO) A CORD1-- E CORD2--, POR ISSO CORD++;
                }
            }while(set_01>0);

            i=0; j=0;
            system("cls");

            ///IMPRIME A TABELA COM O PRIMEIRO PAR DE CORDENADS E COM O SEGUNDO PAR DE CORDENADAS
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                for(tabela_j=1;tabela_j<16;tabela_j++){
                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA IMPRIMIR AS CORDENADAS DOS VETORES
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA IMPRIMIR AS CORDENADAS DOS VETORES
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(cord1==i&&cord2==j){ //CONDIÇÃO PARA IMPRIMIR AS 1º CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(cord3==i&&cord4==j){ //CONDIÇÃO PARA IMPRIMIR AS 2º CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(s<1){
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                    }
                    else{ //CONDIÇÃO PARA O RESTO DA TABELA
                        if(tabela_j%4==0){ //PARA CRIAR OS |
                            cout<<"|";
                        }
                        else { //PARA CRIAR OS ESPAÇOS
                            cout<<" ";
                        }
                    }

                }

                cout << endl;
                if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                        cout<<"-";
                    }
                }
                else{
                    cout<<endl;
                }

            }
            Sleep(1000);

            ///SALVA AS CORDENADAS NOS VETORES E CONTA PONTO
            if(M[cord1][cord2]==M[cord3][cord4]){

                vet1[pos]=cord1;
                vet2[pos]=cord2;
                vet3[pos]=cord3;
                vet4[pos]=cord4;

                pos++;
                ponto++;

            }

            ///DECREMENTA AS CHANCES A CADA VEZ QUE ERRA OS VALORES
            else{
                chance--;
            }

            system("cls");
    }

        ///CONDIÇÃO PARA QUANDO MORRE POR VIDAS
        if(chance<1){
            cout<<"ACABOU SUAS VIDAS";
        }

        ///CONDIÇÃO PARA QUANDO VENCE O JOGO
        else{
            cout<<"\n\n\n\n\n\n\n\t\t\tCONGRATULATION... YOU WINED THE BIG MEMORY PLAY\n\n\n\n\n\n\n\n\n\n\n";
        }

        break;

    ///MATRIZ INVERTE LINHA
    case 4:
        cout<<"TEMPO DE VISUALIZAÇÃO:\n";
        ///COPIA OS VALORES DA MATRIZ IL PARA MATRIZ PRIINCIPAL
        for(tabela_i=0;tabela_i<4;tabela_i++){//GERA OS VALORES DAS LINHAS

            for(tabela_j=0;tabela_j<4;tabela_j++){//GERA OS VALORES DAS COLUNAS
                M[tabela_i][tabela_j]=IL[tabela_i][tabela_j];
            }
        }
        tabela_i=0; tabela_j=0;

        /// GERA MATRIZ IL PARA VISUALIZAÇÃO;
        for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

            cout<<endl;

            for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                    cout << M[i][j];
                    j++;
                    if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I)
                        i++;
                        j=0;
                    }

                }
                else{ //CONDIÇÃO PARA O RESTO DA TABELA
                    if(tabela_j%4==0){ //PARA CRIAR OS |
                        cout<<"|";
                    }
                    else { //PARA CRIAR OS ESPAÇOS
                        cout<<" ";
                    }
                }

            }

            cout << endl;
            if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                    cout<<"-";
                }
            }
            else{
                cout<<endl;
            }

        }

        Sleep(5000); //3s PARA VISUALISAÇÃO
        system("cls"); //LIMPA A TELA

        ///LAÇO PARA RODAR O JOGO
        while(chance>0&&ponto<8){
            i=0; j=0; //RESETA I E J PARA CONSTRUÇÃO DA PRÓXIMA TABELA;
            verif=0;

            ///GERA TABELA COM AS CORDENADAS SALVAS NOS VETORES
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y

                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(s<1){ //CASO NÃO SEJA A CORDENADA
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                        }
                        else{ //CONDIÇÃO PARA O RESTO DA TABELA
                            if(tabela_j%4==0){ //PARA CRIAR OS |
                                cout<<"|";
                            }
                            else { //PARA CRIAR OS ESPAÇOS
                                cout<<" ";
                            }
                        }
                    }

                    cout << endl;
                    if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                        for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                            cout<<"-";
                        }
                    }
                    else{
                        cout<<endl;
                    }
                }
                s=0;

            ///VERIFICAÇÃO DAS 1º CORDENADAS
            do{
                ///PEDE O PRIMEIRO PAR DE CORDENADAS
                cout<<endl<<"Digite o primeiro par\n";
                cout<<"Cordenada 1: ";
                cin>>cord1;
                cout<<"Cordenada 2: ";
                cin>>cord2;
                cord1--; cord2--; //TRANSFORMA AS CORDENADAS DE 1 A 4 PARA 0 A 3 DAS MATRIZES
                set_01=0;

                ///VERIFICAÇÃO SE VETOR É IGUAL A CORDENADA
                for(verif=0;verif<8;verif++){

                    if(vet1[verif]==cord1&&vet2[verif]==cord2){
                        set_01++;
                    }
                    if(vet3[verif]==cord1&&vet4[verif]==cord2){
                        set_01++;
                    }
                }

                ///VERIFICA SE AS CORDENADAS ESTÃO ENTRE 1 E 4
                if(cord1>3||cord1<0||cord2>3||cord2<0){
                    set_01++;
                }

                ///CASO VETOR FOR IGUAL A CORDENADA
                if(set_01>0){

                    cout<<"\nCORDENADAS INVÁLIDAS !";
                    Sleep(2000);

                    system("cls");

                    ///IMPRESSÃO DA TABELA
                    i=0; j=0;
                    verif=0;
                    cout<<"Vidas: "<<chance<<" / "<<"10";
                    for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                    cout<<endl;

                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y

                        if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                            for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                                if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[vet1[verif]][vet2[verif]];
                                    s++;
                                }

                                if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[vet3[verif]][vet4[verif]];
                                    s++;
                                }
                            }

                            if(s<1){ //CASO NÃO SEJA A CORDENADA
                                cout<<" ";
                            }

                            s=0;
                            j++;

                            if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                                i++;
                                j=0;
                            }

                        }
                        else{ //CONDIÇÃO PARA O RESTO DA TABELA
                            if(tabela_j%4==0){ //PARA CRIAR OS |
                                cout<<"|";
                            }
                            else { //PARA CRIAR OS ESPAÇOS
                                cout<<" ";
                            }
                        }
                    }

                    cout << endl;
                    if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                        for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                            cout<<"-";
                        }
                    }
                    else{
                        cout<<endl;
                    }


                }
                }

            }while(set_01>0); //FIM DA VERIFICAÇÃO

            system("cls"); //LIMPA A TELA
            i=0; j=0;//RESETA I E J PARA CONSTRUÇÃO DA PRÓXIMA TABELA;

            ///GERA A TABELA COM OS VALORES DAS CORDENADAS
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                for(tabela_j=1;tabela_j<16;tabela_j++){
                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(cord1==i&&cord2==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(s<1){
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                    }
                    else{ //CONDIÇÃO PARA O RESTO DA TABELA
                        if(tabela_j%4==0){ //PARA CRIAR OS |
                            cout<<"|";
                        }
                        else { //PARA CRIAR OS ESPAÇOS
                            cout<<" ";
                        }
                    }

                }

                cout << endl;
                if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                        cout<<"-";
                    }
                }
                else{
                    cout<<endl;
                }

            }

            cord1++; cord2++; // MOSTRA AS CORDENADAS DE 1 A 4


            ///VERIFICAÇÃO DAS 2º CORDENADAS
            do{
                ///REEMPRIME O PRIMEIRO PAR DE CORDENADAS E PEDE PELO SEGUNDO PAR
                cout<<"Digite o primeiro par\n";
                cout<<"Cordenada 1: "<<cord1;
                cout<<"\nCordenada 2: "<<cord2<<endl<<endl;
                cout<<"Digite o segundo par\n";
                cout<<"Cordenada 3: ";
                cin>>cord3;
                cout<<"Cordenada 4: ";
                cin>>cord4;
                cord1--; cord2--; cord3--; cord4--; //VOLTA PARA POSIÇÃO DE 0 A 3 DAS MATRIZES

                set_01=0;
                ///VERIFICAÇÃO SE VETOR É IGUAL A CORDENADA
                for(verif=0;verif<8;verif++){

                    if(vet1[verif]==cord3&&vet2[verif]==cord4){
                        set_01++;
                    }
                    if(vet3[verif]==cord3&&vet4[verif]==cord4){
                        set_01++;
                    }
                }

                ///VERIFICA SE AS CORDENADAS ESTÃO ENTRE 1 E 4
                if(cord3>3||cord3<0||cord4>3||cord4<0){
                    set_01++;
                }

                ///VERIFICA SE AS 1º CORDENDAS SÃO IGUAS AS 2º
                if(cord1==cord3&&cord2==cord4){
                    set_01++;
                }

                ///CASO VETOR OU A 1º CORDENADA FOR IGUAL A 2º CORDENADA
                if(set_01>0){

                    cout<<"\nCORDENADAS INVÁLIDAS !";
                    Sleep(2000);

                    system("cls");
                    i=0; j=0;
                    verif=0;

                    ///GERA A TABELA COM OS VALORES DAS CORDENADAS
                    cout<<"Vidas: "<<chance<<" / "<<"10";
                    for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                        cout<<endl;

                        ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                        for(tabela_j=1;tabela_j<16;tabela_j++){
                            if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                                for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                                    if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                        cout << M[vet1[verif]][vet2[verif]];
                                        s++;
                                    }

                                    if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                        cout << M[vet3[verif]][vet4[verif]];
                                        s++;
                                    }
                                }

                                if(cord1==i&&cord2==j){ //CONDIÇÃO PARA SELECIONAR E IMPRIMIR AS CORDENADAS ESCOLHIDAS PELO JOGADOR
                                    cout << M[i][j];
                                    s++;
                                }

                                if(s<1){
                                cout<<" ";
                                }

                                s=0;
                                j++;

                                if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                                    i++;
                                    j=0;
                                }

                            }
                            else{ //CONDIÇÃO PARA O RESTO DA TABELA
                                if(tabela_j%4==0){ //PARA CRIAR OS |
                                    cout<<"|";
                                }
                                else { //PARA CRIAR OS ESPAÇOS
                                    cout<<" ";
                                }
                            }

                        }

                        cout << endl;
                        if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                            for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                                cout<<"-";
                            }
                        }
                        else{
                            cout<<endl;
                        }

                    }
                cord1++; cord2++; //QUANDO ENTRA NESTE IF E VOLTA PARA O INÍCIO DO (DO) A CORD1-- E CORD2--, POR ISSO CORD++;
                }
            }while(set_01>0);

            i=0; j=0;
            system("cls");

            ///IMPRIME A TABELA COM O PRIMEIRO PAR DE CORDENADS E COM O SEGUNDO PAR DE CORDENADAS
            cout<<"Vidas: "<<chance<<" / "<<"10";
            for(tabela_i=0;tabela_i<4;tabela_i++){  //LAÇO PARA IMPRESSÃO DA TABELA CORDENADAS X

                cout<<endl;

                ///LAÇO PARA IPRESSÃO DA TABELA CORDENADAS Y
                for(tabela_j=1;tabela_j<16;tabela_j++){
                    if(tabela_j%2==0&&tabela_j%4!=0){ //CONDIÇÃO PARA SELECIONAR O ESPAÇO NA TABELA

                        for(verif=0;verif<8;verif++){ //LAÇO DE VERIFICAÇÃO DAS POSIÇÕES DOS VETORES

                            if(vet1[verif]==i&&vet2[verif]==j){ //CONDIÇÃO PARA IMPRIMIR AS CORDENADAS DOS VETORES
                                cout << M[vet1[verif]][vet2[verif]];
                                s++;
                            }

                            if(vet3[verif]==i&&vet4[verif]==j){ //CONDIÇÃO PARA IMPRIMIR AS CORDENADAS DOS VETORES
                                cout << M[vet3[verif]][vet4[verif]];
                                s++;
                            }
                        }

                        if(cord1==i&&cord2==j){ //CONDIÇÃO PARA IMPRIMIR AS 1º CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(cord3==i&&cord4==j){ //CONDIÇÃO PARA IMPRIMIR AS 2º CORDENADAS ESCOLHIDAS PELO JOGADOR
                            cout << M[i][j];
                            s++;
                        }

                        if(s<1){
                            cout<<" ";
                        }

                        s=0;
                        j++;

                        if(j>3){ //RESETA AS COLUNAS (J) E ACREMENTA AS LINHAS (I);
                            i++;
                            j=0;
                        }

                    }
                    else{ //CONDIÇÃO PARA O RESTO DA TABELA
                        if(tabela_j%4==0){ //PARA CRIAR OS |
                            cout<<"|";
                        }
                        else { //PARA CRIAR OS ESPAÇOS
                            cout<<" ";
                        }
                    }

                }

                cout << endl;
                if (tabela_i<3){ //CONDIÇÃO PARA CRIAR AS LINHAS HORIZONTAIS
                    for(tabela_j=1;tabela_j<16;tabela_j++){ //LAÇO PARA CONSTRUIR AS LINHAS HORIZONTAIS
                        cout<<"-";
                    }
                }
                else{
                    cout<<endl;
                }

            }
            Sleep(1000);

            ///SALVA AS CORDENADAS NOS VETORES E CONTA PONTO
            if(M[cord1][cord2]==M[cord3][cord4]){

                vet1[pos]=cord1;
                vet2[pos]=cord2;
                vet3[pos]=cord3;
                vet4[pos]=cord4;

                pos++;
                ponto++;

            }

            ///DECREMENTA AS CHANCES A CADA VEZ QUE ERRA OS VALORES
            else{
                chance--;
            }

            system("cls");
    }

        ///CONDIÇÃO PARA QUANDO MORRE POR VIDAS
        if(chance<1){
            cout<<"ACABOU SUAS VIDAS";
        }

        ///CONDIÇÃO PARA QUANDO VENCE O JOGO
        else{
            cout<<"\n\n\n\n\n\n\n\t\t\tCONGRATULATION... YOU WINED THE BIG MEMORY PLAY\n\n\n\n\n\n\n\n\n\n\n";
        }

        break;
    }

    return 0;
}



