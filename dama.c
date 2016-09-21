//Gustavo Fernandes da Cruz Lima    BEC
//arrumar peças que sobreponhem peças do mesmo time //if(col+1lin+1=='B'){return 0;}

#include <stdio.h>
#include <stdlib.h>

#define N 8

//imprime parte gráfica da matriz
void imprimematriz(char **M){

	int i,j;

	for(i=-1;i<N;i++){
        for(j=-1;j<N;j++){
            if (i == -1) {
                if (j == -1)
                printf("    ");
                else
                printf(" %d  ",j);
            } else if (j == -1) {
                printf(" %d  ",i);
            } else {
                printf("[%c] ",M[i][j]);
            }
        }
        printf("\n");
    }

}


char **initialize() {
    char **M;
    int i,j;

    //aloca espaço da matriz
    M = (char **)calloc(N, sizeof(char *));
    for(i=0;i<N;i++)
        M[i]=(char *)calloc(N, sizeof(char));

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            M[i][j]='-';//espaco em branco

    //impressão das peças pretas
    for (i = 0; i < 3; i++)
    {
    	if (i % 2 == 0)
    	{
    		j=1;
    	}else{
    		j=0;
    	}
    	while(j<N){
    		M[i][j] = 'P';
    		j+=2;
    	}
    }


    //impressão das peças brancas
    for (i = 5; i < N; i++)
    {
    	if (i % 2 == 0)
    	{
    		j=1;
    	}else{
    		j=0;
    	}
    	while(j<N){
    		M[i][j] = 'B';
    		j+=2;
    	}
    }

    return M;
}

int step(char **M, int lin, int col, char gamer, int lado){

	//condições de movimentação de peça, se não conseguir movimentar retorna 0, senão 1.

    if(lin < 0 || lin >= N ||
       col < 0 || col >= N ||
       M[lin][col] == '-' ){

		        return 0;
    }else{

        //verifica se o lado escolhido foi a direita
        if (lado == 'd')
        {  //condição de peça branca
            if (gamer == 'B'){
                if (M[lin - 1][col + 1] == 'P' || M[lin - 1][col + 1] == 'p'){
                    //come peça se der
                if (M[lin-2][col+2] == 'P' || M[lin-2][col+2] == 'B' || M[lin-2][col+2] == 'p' || M[lin-2][col+2] == 'b'){
                     return 0;
                 }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (col+2>N || col+2<0 || lin-2>N || lin-2<0)
                    {
                        return 0;
                    }else{
                    
                        M[lin][col] = '-';
                        M[lin-1][col+1] = '-';
                        lin -= 2;
                        col += 2;
                        M[lin][col] = gamer;
                        return 1;
                    
                    }
                    
                 }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                    if ((lin-1)>N || (lin-1)<0 || (col+1)>N || (col+1)<0)
                    {
                        return 0;
                    }else{
                        M[lin][col] = '-';
                        M[lin - 1][col + 1] = gamer;
                        return 1;
                    }
                    
                }
            //condição peça preta
            }else if (gamer == 'P'){
                if (M[lin+ 1][col+ 1] == 'B' || M[lin+ 1][col+ 1] == 'b'){
                    //come peça se der
                    if(M[lin+2][col+2] == 'B' || M[lin+2][col+2] == 'P' || M[lin+2][col+2] == 'b' || M[lin+2][col+2] == 'p'){
                        return 0;
                    }else{
                        //verifica se linha e coluna que a peça irá existe
                        if (lin+2>N || lin+2<0 || col+2>N || col+2<0)
                        {
                            return 0;
                        }else{
                            M[lin][col]='-';
                            M[lin+1][col+1]='-';
                            lin+=2;
                            col+=2;
                            M[lin][col] = gamer;
                            return 1;
                        }
                        
                    }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (lin+1>N || lin+1<0 || col+1>N || col+1<0)
                    {
                        return 0;
                    }else{
                        M[lin][col] = '-';
                        lin++;
                        col++;
                        M[lin][col] = gamer;
                        return 1;
                    }
                    
                }
            }

        }else if (lado == 'e'){
            if (gamer == 'B'){
                if (M[lin-1][col-1] == 'P' || M[lin-1][col-1] == 'p'){
                    //comer peças
                    if(M[lin-2][col-2] == 'P' || M[lin-2][col-2] == 'B' || M[lin-2][col-2] == 'p' || M[lin-2][col-2] == 'b'){
                        return 0;
                    }else{
                        //verifica se linha e coluna que a peça irá existe
                        if (lin-2>N || lin-2<0 || col-2>N || col+2<0)
                        {
                            return 0;
                        }else{
                            M[lin][col] = '-';
                            M[lin-1][col-1]= '-';
                            lin-=2;
                            col-=2;
                            M[lin][col] = gamer;
                            return 1;
                        }
                    }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                   if (lin-1>N || lin-1<0 || col-1>N || col-1<0)
                   {
                       return 0;
                   }else{
                        M[lin][col] = '-';
                        lin--;
                        col--;
                        M[lin][col] = gamer;
                        return 1;      
                   }
                }
            }else if (gamer == 'P'){
                if (M[lin+1][col-1] == 'B' || M[lin+1][col-1] == 'b'){
                    //função de comer peças
                    if(M[lin+2][col-2] == 'B' || M[lin+2][col-2] == 'P' || M[lin+2][col-2] == 'b' || M[lin+2][col-2] == 'p'){
                        return 0;
                    }else{
                        //verifica se linha e coluna que a peça irá existe
                        if (lin+2>N || lin+2<0 || col-2>N || col-2<0)
                        {
                            return 0;
                        }else{
                            M[lin][col] = '-';
                            M[lin+1][col-1] = '-';
                            lin+=2;
                            col-=2;
                            M[lin][col] = gamer;
                            return 1;
                        }
                    }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (lin+1>N || lin+1<0 || col-1>N || col-1<0)
                    {
                        return 0;
                    }else{
                        M[lin][col] = '-';
                        lin++;
                        col--;
                        M[lin][col] = gamer;
                        return 1;
                    }

                }
            }
        }

    }

}
//verifica se há peças para tornarem damas
void tornadama(int lin, int col, char gamer, char **M){

    for (int i = 0; i < N; i++)
    {
        if(M[0][i] == 'B'){
            M[0][i] = 'b';
        }
    }
    
    for (int j = 0; j < N; j++)
    {
        if(M[7][j] == 'P'){
            M[7][j] = 'p';
        }
    }

}

//faz a verificação para dama e indica se será uma jogada comum ou de dama
int verificadama(int lin, int col, char gamer){

    if (gamer == 'p' || gamer == 'b')
    {
        return 1;
    }else{
        return 0;
    }
}

int dama(int lin, int col, char gamer, char **M, char lado){

    char direcao;

    free(M);
    printf("indique a direcao da peça (c -> cima b -> baixo)\n");
    scanf("%c",&direcao);
    fflush(stdin);
    getchar();
    //gamer branco dama
    if (gamer == 'b')
    {
        //gamer branco para cima
        if (direcao == 'c')
        {
            //gamer branco para cima e direita
            if (lado == 'd')
            {
                if (M[lin - 1][col + 1] == 'P' || M[lin - 1][col + 1] == 'p' ){
                    //come peça se der
                if (M[lin-2][col+2] == 'P' || M[lin+2][col+2] == 'B' || M[lin-2][col+2] == 'p' || M[lin+2][col+2] == 'b'){
                     return 0;
                 }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (col+2>N || col+2<0 || lin-2>N || lin-2<0)
                    {
                        return 0;
                    }else{
                    
                        M[lin][col] = '-';
                        M[lin-1][col+1] = '-';
                        lin -= 2;
                        col += 2;
                        M[lin][col] = 'b';
                        return 1;
                    
                    }
                    
                 }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (lin-1>N || lin-1<0 || col+1>N || col+1<0)
                    {
                        return 0;
                    }else{
                        M[lin][col] = '-';
                        M[lin - 1][col + 1] = 'b';
                        return 1;
                    }
                    
                }

             
            }else if (lado == 'e')
            {
                if (M[lin-1][col-1] == 'P' || M[lin-1][col-1] == 'p'){
                    //comer peças
                    if(M[lin-2][col-2] == 'P' || M[lin-2][col-2] == 'B' || M[lin-2][col-2] == 'p' || M[lin-2][col-2] == 'b'){
                        return 0;
                    }else{
                        //verifica se linha e coluna que a peça irá existe
                        if (lin-2>N || lin-2<0 || col-2>N || col+2<0)
                        {
                            return 0;
                        }else{
                            M[lin][col] = '-';
                            M[lin-1][col-1]= '-';
                            lin-=2;
                            col-=2;
                            M[lin][col] = 'b';
                            return 1;
                        }
                    }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                   if (lin-1>N || lin-1<0 || col-1>N || col-1<0)
                   {
                       return 0;
                   }else{
                        M[lin][col] = '-';
                        lin--;
                        col--;
                        M[lin][col] = 'b';
                        return 1;      
                   }
                }
            }
        }else if (direcao == 'b')
        {
            if (lado == 'd')
            {
                if (M[lin+ 1][col+ 1] == 'P' || M[lin+ 1][col+ 1] == 'p' ){
                    //come peça se der
                    if(M[lin+2][col+2] == 'B' || M[lin+2][col+2] == 'P' || M[lin+2][col+2] == 'b' || M[lin+2][col+2] == 'p'){
                        return 0;
                    }else{
                        //verifica se linha e coluna que a peça irá existe
                        if (lin+2>N || lin+2<0 || col+2>N || col+2<0)
                        {
                            return 0;
                        }else{
                            M[lin][col]='-';
                            M[lin+1][col+1]='-';
                            lin+=2;
                            col+=2;
                            M[lin][col] = 'b';
                            return 1;
                        }
                        
                    }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (lin+1>N || lin+1<0 || col+1>N || col+1<0)
                    {
                        return 0;
                    }else{
                        M[lin][col] = '-';
                        lin++;
                        col++;
                        M[lin][col] = 'b';
                        return 1;
                    }  
                }   
            }else if (lado == 'e')
            {
                if (M[lin+1][col-1] == 'P' || M[lin+1][col-1] == 'p'){
                    //função de comer peças
                    if(M[lin+2][col-2] == 'B' || M[lin+2][col-2] == 'P' || M[lin+2][col-2] == 'b' || M[lin+2][col-2] == 'p'){
                        return 0;
                    }else{
                        //verifica se linha e coluna que a peça irá existe
                        if (lin+2>N || lin+2<0 || col-2>N || col-2<0)
                        {
                            return 0;
                        }else{
                            M[lin][col] = '-';
                            M[lin+1][col-1] = '-';
                            lin+=2;
                            col-=2;
                            M[lin][col] = 'b';
                            return 1;
                        }
                    }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (lin+1>N || lin+1<0 || col-1>N || col-1<0)
                    {
                        return 0;
                    }else{
                        M[lin][col] = '-';
                        lin++;
                        col--;
                        M[lin][col] = 'b';
                        return 1;
                    }

                }
            }
        }
    }else if (gamer == 'p')
    {
        if (direcao == 'c')
        {
            if (lado == 'd')
            {
                if (M[lin - 1][col + 1] == 'B' || M[lin - 1][col + 1] == 'b' ){
                    //come peça se der
                if (M[lin-2][col+2] == 'P' || M[lin+2][col+2] == 'B' || M[lin-2][col+2] == 'p' || M[lin+2][col+2] == 'b'){
                     return 0;
                 }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (col+2>N || col+2<0 || lin-2>N || lin-2<0)
                    {
                        return 0;
                    }else{
                    
                        M[lin][col] = '-';
                        M[lin-1][col+1] = '-';
                        lin -= 2;
                        col += 2;
                        M[lin][col] = 'p';
                        return 1;
                    
                    }
                    
                 }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (lin-1>N || lin-1<0 || col+1>N || col+1<0)
                    {
                        return 0;
                    }else{
                        M[lin][col] = '-';
                        M[lin - 1][col + 1] = 'p';
                        return 1;
                    }
                    
                }

            }else if (lado == 'e')
            {
                if (M[lin-1][col-1] == 'B' || M[lin-1][col-1] == 'b'){
                    //comer peças
                    if(M[lin-2][col-2] == 'P' || M[lin-2][col-2] == 'B' || M[lin-2][col-2] == 'p' || M[lin-2][col-2] == 'b'){
                        return 0;
                    }else{
                        //verifica se linha e coluna que a peça irá existe
                        if (lin-2>N || lin-2<0 || col-2>N || col+2<0)
                        {
                            return 0;
                        }else{
                            M[lin][col] = '-';
                            M[lin-1][col-1]= '-';
                            lin-=2;
                            col-=2;
                            M[lin][col] = 'p';
                            return 1;
                        }
                    }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                   if (lin-1>N || lin-1<0 || col-1>N || col-1<0)
                   {
                       return 0;
                   }else{
                        M[lin][col] = '-';
                        lin--;
                        col--;
                        M[lin][col] = 'p';
                        return 1;      
                   }
                }
            }
        }else if (direcao == 'b')
        {
            if (lado == 'd')
            {
                    if (M[lin+ 1][col+ 1] == 'P' || M[lin+ 1][col+ 1] == 'p' ){
                    //come peça se der
                    if(M[lin+2][col+2] == 'B' || M[lin+2][col+2] == 'P' || M[lin+2][col+2] == 'b' || M[lin+2][col+2] == 'p'){
                        return 0;
                    }else{
                        //verifica se linha e coluna que a peça irá existe
                        if (lin+2>N || lin+2<0 || col+2>N || col+2<0)
                        {
                            return 0;
                        }else{
                            M[lin][col]='-';
                            M[lin+1][col+1]='-';
                            lin+=2;
                            col+=2;
                            M[lin][col] = 'b';
                            return 1;
                        }
                        
                    }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (lin+1>N || lin+1<0 || col+1>N || col+1<0)
                    {
                        return 0;
                    }else{
                        M[lin][col] = '-';
                        lin++;
                        col++;
                        M[lin][col] = 'b';
                        return 1;
                }    }
            }else if (lado =='e')
            {
                if (M[lin+1][col-1] == 'P' || M[lin+1][col-1] == 'p'){
                    //função de comer peças
                    if(M[lin+2][col-2] == 'B' || M[lin+2][col-2] == 'P' || M[lin+2][col-2] == 'b' || M[lin+2][col-2] == 'p'){
                        return 0;
                    }else{
                        //verifica se linha e coluna que a peça irá existe
                        if (lin+2>N || lin+2<0 || col-2>N || col-2<0)
                        {
                            return 0;
                        }else{
                            M[lin][col] = '-';
                            M[lin+1][col-1] = '-';
                            lin+=2;
                            col-=2;
                            M[lin][col] = 'b';
                            return 1;
                        }
                    }
                }else{
                    //verifica se linha e coluna que a peça irá existe
                    if (lin+1>N || lin+1<0 || col-1>N || col-1<0)
                    {
                        return 0;
                    }else{
                        M[lin][col] = '-';
                        lin++;
                        col--;
                        M[lin][col] = 'b';
                        return 1;
                    }

                }
            }
        }
    }

}

int statusjogo(char **M){

    int k = 0,l = 0;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if (M[i][j]=='B')
            {
                k++;
            }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if (M[i][j]=='P')
            {
                l++;
            }

    if (k != 0 && l != 0)
    {
    	return -1;
    }else if (l == 0)
    {
    	return 1;
    }else if (k == 0)
    {
    	return 2;
    }
}




void game(void){

	char **tabuleiro;
	char gamer = 'B';
	int lin, col;
	int jogoativo =-1;
  char lado = '\0';

	tabuleiro = initialize();

    free(tabuleiro);

	while(jogoativo == -1){

	imprimematriz(tabuleiro);
	printf("digite a linha e coluna da peça %c\n",gamer);
	scanf("%d %d",&lin,&col);
	getchar();
	fflush(stdin);

	printf("digite qual lado a peça irá(d -> direita ou e -> esquerda): \n");
  scanf("%c",&lado);
	fflush(stdin);
    getchar();

    if ( verificadama(lin,col,gamer) == 1)
    {
        dama(lin,col,gamer,tabuleiro,lado);
    }else{

        if ( !step(tabuleiro,lin,col,gamer,lado)){

        printf("jogada inválida, refaça-a.\n");
        continue;
        }
    }

    tornadama(lin,col,gamer,tabuleiro);

    jogoativo = statusjogo(tabuleiro);

        //alterna as peças brancas e pretas
        if (gamer == 'B')
        {
            gamer = 'P';
        }else if (gamer == 'P')
        {
            gamer = 'B';
        }

    }

    if(jogoativo == 1){
        printf("As peças brancas ganharam\n");
    }else{
        printf("as peças pretas ganharam\n");
    }
}

int main(void)
{
    game();

    return 0;
}
