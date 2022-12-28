#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;
void game(int);
string palavra_aleatoria();
string palavra_masc(int);
void exibe_status(string, int, int);
void limpa_tela();
void menu_inicial();

int main(){

    srand((unsigned)time(NULL));
    menu_inicial();

}

void limpa_tela(){

    system("CLS");

}
void menu_inicial(){

    int opcao;
    do{
  
        limpa_tela();

        cout << "\nBem vindo ao Jogo da Forca!";
        cout << "\n[1] Jogar Solo";
        cout << "\n[2] Jogar Duo";
        cout << "\n[3] Sobre";
        cout << "\n[4] Sair";
        cout << "\n\nEscolha uma opcao e aperte Enter\n";

        cin >> opcao;

        switch(opcao){

            case 1:
                
                game(1);

                break;

            case 2:
                
                game(2);

                break;

            case 3:
                
                limpa_tela();

                cout << "\nJogo criado por Kevin em 2022\n\n";

                system("pause");

                break;

            case 4:

                cout << "\nSaindo!!!";

                break;

            default:

                cout << "Escolha Inválida";

                exit(EXIT_FAILURE);
                break;
        }
    }while(opcao < 4);
}
string palavra_aleatoria(){

    string palavras[63] = {"abacaxi", "banana","caixa","queijo","suco","aveia","agressivo","assinado"
,"assistir","assumir","assunto","classe","classico","classificacao","colossal"
,"compasso","compromisso","confessar","depressa","depressao","essencial"
,"estresse","excesso","fossil","fracasso","grosseria","grosso","impossivel","impresso"
,"interesse","intromissao","missao","necessario","necessitar","nossa","obsessao"
,"osso","passado","passagem","passar","passaro","passatempo","passeio","passivo"
,"passo","permissao","pessimista","pessimo","pessoa"," possibilidade","possivel"
,"possuir","pressa","processo","professor","profissao","progresso","promessa"
,"sessenta", "sossego","sucesso","vassoura"};

    int id = rand() % 63;

    string palavra = palavras[id];

    return palavra;

}
string palavra_masc(int tamanho){

    string palavra_mascarada;

    int i = 0;

    while(i < tamanho){

        palavra_mascarada += "_";

        i++;

    }

    return palavra_mascarada;

}
void exibe_status(string palavra_mascarada, int tamanho, int tent_rest, string letras_tentadas, string mensagem){

    cout << "\nPalavra: " << palavra_mascarada << "\nTamanho da palavra: " << tamanho;

    cout << "\nTentativas restantes: " << tent_rest;

    cout << "\nLetras Testadas: ";

    for(int i = 0; i < letras_tentadas.size(); i++){

        cout << letras_tentadas[i] << ", ";

    }

    cout << mensagem;

}

void game(int n_jogadores){
    
    limpa_tela();

    cout << "\nJogo iniciado!!\n\n";

    string palavra;

    if(n_jogadores == 1){

    palavra = palavra_aleatoria();

    }else{

        cout << "Informe uma palara a ser advinhada pelo outro jogador:\n";

        cin >> palavra;

    }
    

    int tamanho = palavra.size();

    int i = 0;

    string letras_tentadas;

    string palavra_mascarada = palavra_masc(tamanho);

    int tent_feitas = 0, tent_totais = 10;

    char letra;

    string mensagem = "\nComecando!!!";

    bool repetiu = false;

    char opcao;

    while(palavra != palavra_mascarada && tent_totais - tent_feitas > 0){

        limpa_tela();

        exibe_status(palavra_mascarada, tamanho,tent_totais - tent_feitas, letras_tentadas, mensagem);
        
        mensagem = "";
        
        cout << "\n\nDigite uma letra:\n";

        cin >> letra;

        letra = tolower(letra);

        for(int y = 0; y < tent_feitas; y++){

            if(letras_tentadas[y] == letra){

                mensagem = "\nEsta letra ja foi testada!";

                repetiu = true;

            }

        }

        if(repetiu == false){

            letras_tentadas += letra;

            //percorre a palavra real para verificar se a letra arriscada está presente

            for(i = 0; i < tamanho; i++){

                if(palavra[i] == letra){

                    palavra_mascarada[i] = palavra[i];

                }

            }

        tent_feitas++;

        }

        repetiu = false;

    }

    if(palavra_mascarada == palavra){

        limpa_tela();
        cout << "\nParabens, Voce Ganhou!!\n\n";
        
        cout << "Deseja jogar outra partida?\n[S]Sim   [N]Nao\n";

        cin >> opcao;

        opcao = toupper(opcao);

    }else{

        limpa_tela();
        cout << "\nQue pena, Voce Perdeu!\n\n";
        
        cout << "Deseja jogar outra partida?\n[S]Sim   [N]Nao\n";

        cin >> opcao;

        opcao = toupper(opcao);

    }

    if(opcao == 'S'){

        game(n_jogadores);

    }else{

        cout << "\nAté Mais...";
        
    }

}
