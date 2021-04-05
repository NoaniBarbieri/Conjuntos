/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//Autores: Eric Rabelo, Noani Barbieri, Angelo Depre e Arthur Vieira.

#include <stdio.h>
#define tamanho 100
#include <locale.h>

int main(){

    //Definindo vetores principais e auxiliares;
    int vet1[tamanho]={0}, vet2[tamanho]={0}, vet3[tamanho]={0},uniao[tamanho*2]={0};

    //Definindo contadores de elementos contidos em cada vetor;
    int cvet1=0, cvet2=0, cvet3=0, cuniao=0, cintersecao=0;

    //Quantidade de elementos pra adicionar e posicao do elemento para remover (Funcao 1 e 2);
    //q= quantidade de elementos que deseja adicionar no conjunto
    //pos= posicao do vetor que deseja remover. Ex: vet1[2]
    int q,ele;

    //Demais vari�veis;
    //i,j,k= variavel usada nos contadores
    //temp = variavel para armazenar um elemento e organizar o vetor em ordem crescente
    //a = verificar se o elemento esta contido no conjunto
    int a,i,j,k,escolha,escolha2, temp;

    //Definir o idioma para portugues
    setlocale(LC_ALL, "Portuguese");




    //while vai servir para o programa ficar reiniciando at� o usu�rio decidir sair;
    while(1){
        //Menu de op��es;
        printf("\n________________________________________________________\n\n");
        printf("  1. Inserir um elemento em um conjunto;\n");
        printf("  2. Remover um elemento de um conjunto;\n");
        printf("  3. Verificar se um elemento pertence a um conjunto;\n");
        printf("  4. Verificar se um conjunto e subconjunto de outro;\n");
        printf("  5. Realizar a uni�o de dois conjuntos;\n");
        printf("  6. Realizar a interse��o entre dois conjuntos;\n");
        printf("  7. Realizar a diferen�a entre dois conjuntos;\n");
        printf("  8. Realizar o produto cartesiano de dois conjuntos;\n");
        printf("  9. Imprimir os elementos de um conjunto;\n");
        printf(" 10. Para sair do programa.\n");
        printf("________________________________________________________\n\n");
        printf("Digite um n�mero correspondente a funcao que deseja usar\n");
        scanf("%i", &escolha);

        //Definir a escolha da fun��o;
        switch(escolha){

            //Funcao Inserir um elemento em um conjunto;
            case 1:
                printf("\nEscolha o conjunto que deseja inserir o elemento:\n");
                printf("1. Conjunto A\n");
                printf("2. Conjunto B\n");
                printf("3. Conjunto C\n");
                scanf("%i", &escolha);

                //Escolher o conjunto para inserir;
                switch(escolha){
                    case 1:
                        printf("\nDigite quantos elementos deseja adicionar:\n");
                        scanf("%i", &q);
                        if (q<=tamanho-cvet1){
                            for (i=cvet1; i<q+cvet1; ++i){
                                scanf("%d", &vet1[i]);
                            }
                            cvet1=cvet1+q;
                        }else{
                            printf("\nErro, %i elementos ultrapassa o tamanho do conjunto\n",q);
                            printf("Restam apenas %i vagas no conjunto\n\n",tamanho-cvet1);
                        }
                        //Tirando elementos repetidos
                        for( i = 0; i < cvet1; i++ ){
                            for( j = i + 1; j < cvet1;){
                                if( vet1[j] == vet1[i] ){
                                    for( k = j; k < cvet1; k++ )
                                    vet1[k] = vet1[k + 1];
                                    cvet1--;
                                }
                                else{
                                j++;
                                }
                            }
                        }
                        //Ordenando o vetor A
                        for (i=0;i<cvet1; i++)
                            for(j=i+1;j<cvet1;j++){
                                if (vet1[i]>vet1[j]){
                                    temp=vet1[i];
                                    vet1[i]=vet1[j];
                                    vet1[j]=temp;
                                }
                            }
                        //Imprimindo Vetor A
                        printf("\nA = {");
                        for (i=0; i<cvet1; ++i){
                            printf("%d",vet1[i]);
                            if (i<cvet1-1){
                                printf(",");
                            }
                        }
                        printf("}\n\n");
                        break;


                    case 2:
                        printf("\nDigite quantos elementos deseja adicionar:\n");
                        scanf("%i", &q);
                        if (q<=tamanho-cvet2){
                            for (i=cvet2; i<q+cvet2; ++i){
                                scanf("%d", &vet2[i]);
                            }
                            cvet2=cvet2+q;
                        }else{
                            printf("\nErro, %i elementos ultrapassa o tamanho do conjunto\n",q);
                            printf("Restam apenas %i vagas no conjunto\n\n",tamanho-cvet2);
                        }
                        //Tirando elementos repetidos
                        for( i = 0; i < cvet2; i++ ){
                            for( j = i + 1; j < cvet2;){
                                if( vet2[j] == vet2[i] ){
                                    for( k = j; k < cvet2; k++ )
                                    vet2[k] = vet2[k + 1];
                                    cvet2--;
                                }
                                else{
                                j++;
                                }
                            }
                        }
                        //Ordenando o vetor B
                        for (i=0;i<cvet2; i++)
                            for(j=i+1;j<cvet2;j++){
                                if (vet2[i]>vet2[j]){
                                    temp=vet2[i];
                                    vet2[i]=vet2[j];
                                    vet2[j]=temp;
                                }
                            }
                        //Imprimindo Vetor B
                        printf("\nB = {");
                        for (i=0; i<cvet2; ++i){
                            printf("%d",vet2[i]);
                            if (i<cvet2-1){
                                printf(",");
                            }
                        }
                        printf("}\n\n");
                        break;


                    case 3:
                        printf("\nDigite quantos elementos deseja adicionar:\n");
                        scanf("%i", &q);
                        if (q<=tamanho-cvet3){
                            for (i=cvet3; i<q+cvet3; ++i){
                                scanf("%d", &vet3[i]);
                            }
                            cvet3=cvet3+q;
                        }else{
                            printf("\nErro, %i elementos ultrapassa o tamanho do conjunto\n",q,tamanho-cvet3);
                            printf("Restam apenas %i vagas no conjunto\n\n",tamanho-cvet3);
                        }
                        //Tirando elementos repetidos
                        for( i = 0; i < cvet3; i++ ){
                            for( j = i + 1; j < cvet3;){
                                if( vet3[j] == vet3[i] ){
                                    for( k = j; k < cvet3; k++ )
                                    vet3[k] = vet3[k + 1];
                                    cvet3--;
                                }
                                else{
                                j++;
                                }
                            }
                        }
                        //Ordenando o vetor C
                        for (i=0;i<cvet3; i++)
                            for(j=i+1;j<cvet3;j++){
                                if (vet3[i]>vet3[j]){
                                    temp=vet3[i];
                                    vet3[i]=vet3[j];
                                    vet3[j]=temp;
                                }
                            }
                        //Imprimindo Vetor C
                        printf("\nC = {");
                        for (i=0; i<cvet3; ++i){
                            printf("%d",vet3[i]);
                            if (i<cvet3-1){
                                printf(",");
                            }
                        }
                        printf("}\n\n");
                        break;

                }
                break;

            //Funcao remover um elemento de um conjunto;
            case 2:
                printf("\nEscolha o conjunto que deseja remover o elemento:\n");
                printf("1. Conjunto A\n");
                printf("2. Conjunto B\n");
                printf("3. Conjunto C\n");
                scanf("%i", &escolha);

                //Escolher o conjunto para remover o elemento;
                switch(escolha){
                    case 1:
                        if (cvet1==0){
                           printf("\nErro! O conjunto A n�o possui elementos\n");
                        }
                        else{
                            //Imprimindo Vetor A
                            printf("\nA = {");
                            for (i=0; i<cvet1; ++i){
                                printf("%d",vet1[i]);
                                if (i<cvet1-1){
                                    printf(",");
                                }
                            }
                            printf("}\n\n");

                            //Remover o elemento:
                            printf("\nDigite o elemento que deseja remover:\n");
                            scanf("%i", &ele);
                            for (i=0,j=0;i<cvet1;i++){
                                if (ele!=vet1[i]){
                                    j=j+1;
                                }
                            }
                            if (j>=cvet1){
                                printf("\nO elemento %d n�o pertence ao conjunto A\n",ele);
                            }
                            else{
                                for (i=0; i<cvet1; ++i){
                                    if (vet1[i]==ele){
                                    cvet1=cvet1-1;
                                        for (j=i; j<cvet1; ++j){
                                            vet1[j]=vet1[j+1];
                                        }
                                    }
                                }
                            //Imprimindo Novamente o vetor A
                            printf("\nA = {");
                            for (i=0; i<cvet1; ++i){
                                printf("%d",vet1[i]);
                                if (i<cvet1-1){
                                    printf(",");
                                }
                            }
                            printf("}\n\n");
                            }
                        }

                        break;


                    case 2:
                        if (cvet2==0){
                           printf("\nErro! O conjunto B n�o possui elementos\n");
                        }
                        else{
                            //Imprimindo Vetor B
                            printf("\nB = {");
                            for (i=0; i<cvet2; ++i){
                            printf("%d",vet2[i]);
                                if (i<cvet2-1){
                                    printf(",");
                                }
                            }
                            printf("}\n\n");

                            //Remover o elemento:
                            printf("\nDigite o elemento que deseja remover:\n");
                            scanf("%i", &ele);
                            for (i=0,j=0;i<cvet2;i++){
                                if (ele!=vet2[i]){
                                    j=j+1;
                                }
                            }
                            if (j>=cvet2){
                                printf("\nO elemento %d n�o pertence ao conjunto B\n",ele);
                            }
                            else{
                                for (i=0; i<cvet2; ++i){
                                    if (vet2[i]==ele){
                                    cvet2=cvet2-1;
                                        for (j=i; j<cvet2; ++j){
                                            vet2[j]=vet2[j+1];
                                        }
                                    }
                                }
                            //Imprimindo Novamente o vetor B
                            printf("\nB = {");
                            for (i=0; i<cvet2; ++i){
                                printf("%d",vet2[i]);
                                if (i<cvet2-1){
                                    printf(",");
                                }
                            }
                            printf("}\n\n");
                            }
                        }
                        break;


                    case 3:
                        if (cvet3==0){
                           printf("\nErro! O conjunto C n�o possui elementos\n");
                        }
                        else{
                            //Imprimindo Vetor C
                            printf("\nC = {");
                            for (i=0; i<cvet3; ++i){
                                printf("%d",vet3[i]);
                                if (i<cvet3-1){
                                    printf(",");
                                }
                            }
                            printf("}\n\n");

                            //Remover o elemento:
                            printf("\nDigite o elemento que deseja remover:\n");
                            scanf("%i", &ele);
                            for (i=0,j=0;i<cvet3;i++){
                                if (ele!=vet3[i]){
                                    j=j+1;
                                }
                            }
                            if (j>=cvet3){
                                printf("\nO elemento %d n�o pertence ao conjunto C\n",ele);
                            }
                            else{
                                for (i=0; i<cvet3; ++i){
                                    if (vet3[i]==ele){
                                    cvet3=cvet3-1;
                                        for (j=i; j<cvet3; ++j){
                                            vet3[j]=vet3[j+1];
                                        }
                                    }
                                }
                            //Imprimindo Novamente o vetor C
                            printf("\nA = {");
                            for (i=0; i<cvet3; ++i){
                                printf("%d",vet3[i]);
                                if (i<cvet3-1){
                                    printf(",");
                                }
                            }
                            printf("}\n\n");
                            }
                        }
                        break;
            }
                break;

            case 3:
                printf("\nEscolha o conjunto que deseja verificar se o elemento pertence:\n");
                printf("1. Conjunto A\n");
                printf("2. Conjunto B\n");
                printf("3. Conjunto C\n");
                scanf("%i", &escolha);

                //Escolher o conjunto para verificar se o elemento est� contido
                switch(escolha){
                    case 1:
                        printf("\nDigite o elemento que deseja verificar se pertence ao conjunto A:\n");
                        scanf("%d",&a);
                        for (i=0,j=0;i<cvet1;i++){
                            if (a==vet1[i]){
                                printf("\nO elemento %d pertence ao conjunto A\n",a);
                            }
                            else{
                                j=j+1;
                                if (j>=cvet1){
                                    printf("\nO elemento %d n�o pertence ao conjunto A\n",a);
                                }
                            }
                        }
                        break;

                    case 2:
                        printf("\nDigite o elemento que deseja verificar se pertence ao conjunto B:\n");
                        scanf("%d",&a);
                        for (i=0,j=0;i<cvet2;i++){
                            if (a==vet2[i]){
                                printf("\nO elemento %d pertence ao conjunto B\n",a);
                            }
                            else{
                                j=j+1;
                                if (j>=cvet2){
                                    printf("\nO elemento %d n�o pertence ao conjunto B\n",a);
                                }
                            }
                        }
                        break;

                    case 3:
                        printf("\nDigite o elemento que deseja verificar se pertence ao conjunto C:\n");
                        scanf("%d",&a);
                        for (i=0,j=0;i<cvet3;i++){
                            if (a==vet3[i]){
                                printf("\nO elemento %d pertence ao conjunto C\n",a);
                            }
                            else{
                                j=j+1;
                                if (j>=cvet3){
                                    printf("\nO elemento %d nao pertence ao conjunto C\n",a);
                                }
                            }
                        }
                        break;

                }
                break;

            case 4:
                printf("\nEscolha o subconjunto:\n");
                printf("1. Conjunto A\n");
                printf("2. Conjunto B\n");
                printf("3. Conjunto C\n");
                scanf("%i", &escolha);
                switch(escolha){
                    case 1:
                        printf("\nEscolha o conjunto:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            case 1:
                                printf("\nA e subconjunto de A\n");
                                break;

                            case 2:
                                for (i=0;i<cvet1;++i){
                                    for (j=0; j<cvet2;++j){
                                        if (vet1[i]==vet2[j]){
                                            a=a+1;
                                        }
                                    }
                                }
                                if (a==cvet1){
                                    printf("O conjunto A � subconjunto de B");
                                }
                                else{
                                    printf("O conjunto A n�o � subconjunto de B");
                                }
                                a=0;
                                break;

                            case 3:
                                for (i=0;i<cvet1;++i){
                                    for (j=0; j<cvet3;++j){
                                        if (vet1[i]==vet3[j]){
                                            a=a+1;
                                        }
                                    }
                                }
                                if (a==cvet1){
                                    printf("O conjunto A � subconjunto de C");
                                }
                                else{
                                    printf("O conjunto A n�o � subconjunto de C");
                                }
                                a=0;
                                break;

                        }
                        break;

                    case 2:
                        printf("\nEscolha o conjunto:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            case 1:
                                for (i=0;i<cvet2;++i){
                                    for (j=0; j<cvet1;++j){
                                        if (vet2[i]==vet1[j]){
                                            a=a+1;
                                        }
                                    }
                                }
                                if (a==cvet2){
                                    printf("O conjunto B � subconjunto de A");
                                }
                                else{
                                    printf("O conjunto B n�o � subconjunto de A");
                                }
                                a=0;
                                break;

                            case 2:
                                printf("\nB � subconjunto de B\n");
                                break;

                            case 3:
                                for (i=0;i<cvet2;++i){
                                    for (j=0; j<cvet3;++j){
                                        if (vet2[i]==vet3[j]){
                                            a=a+1;
                                        }
                                    }
                                }
                                if (a==cvet2){
                                    printf("O conjunto B � subconjunto de C");
                                }
                                else{
                                    printf("O conjunto B n�o � subconjunto de C");
                                }
                                a=0;
                                break;


                        }
                        break;


                    case 3:
                        printf("\nEscolha o conjunto:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            case 1:
                                for (i=0;i<cvet3;++i){
                                    for (j=0; j<cvet1;++j){
                                        if (vet3[i]==vet1[j]){
                                            a=a+1;
                                        }
                                    }
                                }
                                if (a==cvet3){
                                    printf("O conjunto C � subconjunto de A");
                                }
                                else{
                                    printf("O conjunto C n�o � subconjunto de A");
                                }
                                a=0;
                                break;

                            case 2:
                                for (i=0;i<cvet3;++i){
                                    for (j=0; j<cvet2;++j){
                                        if (vet3[i]==vet2[j]){
                                            a=a+1;
                                        }
                                    }
                                }
                                if (a==cvet3){
                                    printf("O conjunto B � subconjunto de C");
                                }
                                else{
                                    printf("O conjunto B n�o � subconjunto de C");
                                }
                                a=0;
                                break;

                            case 3:
                                printf("\nC � subconjunto de C\n");
                                break;

                        }
                        break;
                }
                break;

            case 5:
                printf("\nEscolha o primeiro conjunto para realizar a uni�o:\n");
                printf("1. Conjunto A\n");
                printf("2. Conjunto B\n");
                printf("3. Conjunto C\n");
                scanf("%i", &escolha);
                switch(escolha){
                    case 1:
                        printf("\nEscolha o segundo conjunto para realizar a uni�o:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            case 1:
                                printf("\nA U A= {");
                                for (i=0; i<cvet1; ++i){
                                    printf("%d",vet1[i]);
                                    if (i<cvet1-1){
                                        printf(",");
                                    }
                                }
                                printf("}\n\n");
                                break;

                            case 2:
                                //Criando o vetor uniao A U B
                                for (i=0; i<cvet1; ++i){
                                    uniao[i]=vet1[i];
                                }
                                for (i=0; i<cvet1+cvet2; ++i){
                                    uniao[i+cvet1]=vet2[i];
                                }
                                cuniao=cvet1+cvet2;

                                //Tirando elementos repetidos
                                for( i = 0; i < cuniao; i++ ){
                                    for( j = i + 1; j < cuniao;){
                                        if( uniao[j] == uniao[i] ){
                                            for( k = j; k < cuniao; k++ )
                                            uniao[k] = uniao[k + 1];
                                            cuniao--;
                                        }
                                        else{
                                        j++;
                                        }
                                    }
                                }
                                //Ordenando o vetor
                                for (i=0;i<cuniao; i++)
                                    for(j=i+1;j<cuniao;j++){
                                        if (uniao[i]>uniao[j]){
                                        temp=uniao[i];
                                        uniao[i]=uniao[j];
                                        uniao[j]=temp;
                                        }
                                    }
                                //Print vetor UNIAO
                                printf("\nA U B= {");
                                for (i=0; i<cuniao; ++i){
                                    printf("%d",uniao[i]);
                                    if (i<cuniao-1){
                                        printf(",");
                                    }
                                }
                                printf("}\n\n");
                                //resetando vetor uniao

                                cuniao=0;
                                break;


                            case 3:
                                //Criando o vetor uniao A U C
                                for (i=0; i<cvet1; ++i){
                                    uniao[i]=vet1[i];
                                }
                                for (i=0; i<cvet1+cvet3; ++i){
                                    uniao[i+cvet1]=vet3[i];
                                }
                                cuniao=cvet1+cvet3;

                                //Tirando elementos repetidos
                                for( i = 0; i < cuniao; i++ ){
                                    for( j = i + 1; j < cuniao; ){
                                        if( uniao[j] == uniao[i] ){
                                            for( k = j; k < cuniao; k++ )
                                            uniao[k] = uniao[k + 1];
                                            cuniao--;
                                        }
                                        else{
                                        j++;
                                        }
                                    }
                                }
                                //Ordenando o vetor
                                for (i=0;i<cuniao; i++)
                                    for(j=i+1;j<cuniao;j++){
                                        if (uniao[i]>uniao[j]){
                                        temp=uniao[i];
                                        uniao[i]=uniao[j];
                                        uniao[j]=temp;
                                        }
                                    }
                                //Print vetor UNIAO
                                printf("\nA U C= {");
                                for (i=0; i<cuniao; ++i){
                                    printf("%d",uniao[i]);
                                    if (i<cuniao-1){
                                        printf(",");
                                    }
                                }
                                printf("}\n\n");

                                //resetando vetor uniao

                                cuniao=0;
                                break;
                        }
                        break;
                    case 2:
                        printf("\nEscolha o segundo conjunto para realizar a uni�o:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            case 1:
                                //Criando o vetor uniao B U A (O MESMO DE A U B, ent�o s� copiei do caso de cima)
                                for (i=0; i<cvet1; ++i){
                                    uniao[i]=vet1[i];
                                }
                                for (i=0; i<cvet1+cvet2; ++i){
                                    uniao[i+cvet1]=vet2[i];
                                }
                                cuniao=cvet1+cvet2;

                                //Tirando elementos repetidos
                                for( i = 0; i < cuniao; i++ ){
                                    for( j = i + 1; j < cuniao; ){
                                        if( uniao[j] == uniao[i] ){
                                            for( k = j; k < cuniao; k++ )
                                            uniao[k] = uniao[k + 1];
                                            cuniao--;
                                        }
                                        else{
                                        j++;
                                        }
                                    }
                                }
                                //Ordenando o vetor
                                for (i=0;i<cuniao; i++)
                                    for(j=i+1;j<cuniao;j++){
                                        if (uniao[i]>uniao[j]){
                                        temp=uniao[i];
                                        uniao[i]=uniao[j];
                                        uniao[j]=temp;
                                        }
                                    }
                                //Print vetor UNIAO
                                printf("\nB U A= {");
                                for (i=0; i<cuniao; ++i){
                                    printf("%d",uniao[i]);
                                    if (i<cuniao-1){
                                        printf(",");
                                    }
                                }
                                printf("}\n\n");

                                //resetando vetor uniao

                                cuniao=0;
                                break;

                            case 2:
                                //Print vetor UNIAO
                                printf("\nB U B= {");
                                for (i=0; i<cvet2; ++i){
                                    printf("%d",vet2[i]);
                                    if (i<cvet2-1){
                                        printf(",");
                                    }
                                }
                                printf("}\n\n");


                            case 3:
                                //Criando o vetor uniao B U C
                                for (i=0; i<cvet2; ++i){
                                    uniao[i]=vet2[i];
                                }
                                for (i=0; i<cvet2+cvet3; ++i){
                                    uniao[i+cvet2]=vet3[i];
                                }
                                cuniao=cvet2+cvet3;

                                //Tirando elementos repetidos
                                for( i = 0; i < cuniao; i++ ){
                                    for( j = i + 1; j < cuniao; ){
                                        if( uniao[j] == uniao[i] ){
                                            for( k = j; k < cuniao; k++ )
                                            uniao[k] = uniao[k + 1];
                                            cuniao--;
                                        }
                                        else{
                                        j++;
                                        }
                                    }
                                }
                                //Ordenando o vetor
                                for (i=0;i<cuniao; i++)
                                    for(j=i+1;j<cuniao;j++){
                                        if (uniao[i]>uniao[j]){
                                        temp=uniao[i];
                                        uniao[i]=uniao[j];
                                        uniao[j]=temp;
                                        }
                                    }
                                //Print vetor UNIAO
                                printf("\nB U C= {");
                                for (i=0; i<cuniao; ++i){
                                    printf("%d",uniao[i]);
                                    if (i<cuniao-1){
                                        printf(",");
                                    }
                                }
                                printf("}\n\n");

                                //resetando vetor uniao

                                cuniao=0;
                                break;
                        }
                        break;
                    case 3:
                        printf("\nEscolha o segundo conjunto para realizar a uni�o:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            case 1:
                                //Criando o vetor uniao C U A (O MESMO DE A U C, ent�o s� copiei do caso de cima)
                                for (i=0; i<cvet1; ++i){
                                    uniao[i]=vet1[i];
                                }
                                for (i=0; i<cvet1+cvet3; ++i){
                                    uniao[i+cvet1]=vet3[i];
                                }
                                cuniao=cvet1+cvet3;

                                //Tirando elementos repetidos
                                for( i = 0; i < cuniao; i++ ){
                                    for( j = i + 1; j < cuniao; ){
                                        if( uniao[j] == uniao[i] ){
                                            for( k = j; k < cuniao; k++ )
                                            uniao[k] = uniao[k + 1];
                                            cuniao--;
                                        }
                                        else{
                                        j++;
                                        }
                                    }
                                }
                                //Ordenando o vetor
                                for (i=0;i<cuniao; i++)
                                    for(j=i+1;j<cuniao;j++){
                                        if (uniao[i]>uniao[j]){
                                        temp=uniao[i];
                                        uniao[i]=uniao[j];
                                        uniao[j]=temp;
                                        }
                                    }

                                //Print vetor UNIAO
                                printf("\nC U A= {");
                                for (i=0; i<cuniao; ++i){
                                    printf("%d",uniao[i]);
                                    if (i<cuniao-1){
                                        printf(",");
                                    }
                                }
                                printf("}\n\n");

                                //resetando vetor uniao

                                cuniao=0;
                                break;

                            case 2:
                                //Criando o vetor uniao C U B (O MESMO DE B U C, ent�o s� copiei do caso de cima)
                                for (i=0; i<cvet2; ++i){
                                    uniao[i]=vet2[i];
                                }
                                for (i=0; i<cvet2+cvet3; ++i){
                                    uniao[i+cvet2]=vet3[i];
                                }
                                cuniao=cvet2+cvet3;

                                //Tirando elementos repetidos
                                for( i = 0; i < cuniao; i++ ){
                                    for( j = i + 1; j < cuniao; ){
                                        if( uniao[j] == uniao[i] ){
                                            for( k = j; k < cuniao; k++ )
                                            uniao[k] = uniao[k + 1];
                                            cuniao--;
                                        }
                                        else{
                                        j++;
                                        }
                                    }
                                }
                                //Ordenando o vetor
                                for (i=0;i<cuniao; i++)
                                    for(j=i+1;j<cuniao;j++){
                                        if (uniao[i]>uniao[j]){
                                        temp=uniao[i];
                                        uniao[i]=uniao[j];
                                        uniao[j]=temp;
                                        }
                                    }

                                //Print vetor UNIAO
                                printf("\nC U B= {");
                                for (i=0; i<cuniao; ++i){
                                    printf("%d",uniao[i]);
                                    if (i<cuniao-1){
                                        printf(",");
                                    }
                                }
                                printf("}\n\n");

                                //resetando vetor uniao

                                cuniao=0;
                                break;
                            case 3:
                                //Print vetor UNIAO
                                printf("\nC U C= {");
                                for (i=0; i<cvet3; ++i){
                                    printf("%d",vet3[i]);
                                    if (i<cvet3-1){
                                        printf(",");
                                    }
                                }
                                printf("}\n\n");
                                break;

                        }
                        break;

                }
                break;


        //case 6: Realiza a interse��o entre dois vetores
         case 6:
                printf("\nEscolha o primeiro conjunto para realizar a interse��o:\n");
                printf("1. Conjunto A\n");
                printf("2. Conjunto B\n");
                printf("3. Conjunto C\n");
                scanf("%i", &escolha);

                int intersecao[tamanho] = {0};

                switch(escolha){
                    case 1:
                        printf("\nEscolha o segundo conjunto para realizar a interse��o:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            //Realiza a interse��o entre A e A
                            case 1:
                                    for(i=0; i < cvet1; i++){
                                        printf("\nA int. A = {");
                                        for (i=0; i<cvet1; ++i){
                                            printf("%d",vet1[i]);
                                            if (i<cvet1-1){
                                                printf(",");
                                            }
                                        }
                                        printf("}\n\n");
                                    }

                            //Realiza a interse��o entre A e B
                            case 2:
                                for(i=0; i < cvet1; i++){
                                    for(j=0; j < cvet2; j++){
                                        if (vet1[i] == vet2[j]){
                                            intersecao[cintersecao] = vet1[i];
                                            cintersecao = cintersecao + 1;
                                        }
                                    }
                                }
                                for(i=0; i<cintersecao; i++){
                                    printf("\nA int. B = {");
                                        for (i=0; i<cintersecao; ++i){
                                            printf("%d",intersecao[i]);
                                            if (i<cintersecao-1){
                                                printf(",");
                                            }
                                        }
                                        printf("}\n\n");
                                    }
                                break;

                            //Realiza a interse��o entre A e C
                            case 3:
                                for(i=0; i< cvet1; i++){
                                    for(j=0; j < cvet3; j++){
                                        if (vet1[i] == vet3[j]){
                                            intersecao[cintersecao] = vet1[i];
                                            cintersecao = cintersecao + 1;
                                        }
                                    }
                                }
                               for(i=0; i<cintersecao; i++){
                                    printf("\nA int. C = {");
                                        for (i=0; i<cintersecao; ++i){
                                            printf("%d",intersecao[i]);
                                            if (i<cintersecao-1){
                                                printf(",");
                                            }
                                        }
                                        printf("}\n\n");
                                    }
                                break;


                        }
                            break;
                    case 2:
                        printf("\nEscolha o segundo conjunto para realizar a interse��o:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            //Realiza a interse��o entre B e A
                            case 1:
                                for(i=0; i < cvet2; i++){
                                    for(j=0; j < cvet1; j++){
                                        if (vet2[i] == vet1[j]){
                                            intersecao[cintersecao] = vet1[i];
                                            cintersecao = cintersecao + 1;
                                        }
                                    }
                                }
                                for(i=0; i<cintersecao; i++){
                                    printf("\nB int. A = {");
                                        for (i=0; i<cintersecao; ++i){
                                            printf("%d",intersecao[i]);
                                            if (i<cintersecao-1){
                                                printf(",");
                                            }
                                        }
                                        printf("}\n\n");
                                    }
                                break;
                            //Realiza a interse��o entre B e B
                            case 2:
                                   for(i=0; i < cvet2; i++){
                                        printf("\nB int. B = {");
                                        for (i=0; i<cvet2; ++i){
                                            printf("%d",vet2[i]);
                                            if (i<cvet2-1){
                                                printf(",");
                                            }
                                        }
                                        printf("}\n\n");
                                    }


                            //Realiza a interse��o entre B e C
                            case 3:
                                for(i=0; i < cvet2; i++){
                                    for(j=0; j < cvet3; j++){
                                        if (vet2[i] == vet3[j]){
                                            intersecao[cintersecao] = vet1[i];
                                            cintersecao = cintersecao + 1;
                                        }
                                    }
                                }
                                for(i=0; i<cintersecao; i++){
                                    printf("\nB int. C = {");
                                        for (i=0; i<cintersecao; ++i){
                                            printf("%d",intersecao[i]);
                                            if (i<cintersecao-1){
                                                printf(",");
                                            }
                                        }
                                        printf("}\n\n");
                                    }
                                break;


                        }
                    break;
                    case 3:
                        printf("\nEscolha o segundo conjunto para realizar a interse��o:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                           //Realiza a interse��o entre C e A
                            case 1:
                                for(i=0; i < cvet3; i++){
                                	for(j=0; j < cvet1; j++){
                                        if (vet3[i] == vet1[j]){
                                            intersecao[cintersecao] = vet1[i];
                                            cintersecao = cintersecao + 1;
                                        }
                                	}
                                }
                                for(i=0; i<cintersecao; i++){
                                    printf("\nC int. A = {");
                                        for (i=0; i<cintersecao; ++i){
                                            printf("%d",intersecao[i]);
                                            if (i<cintersecao-1){
                                                printf(",");
                                            }
                                        }
                                        printf("}\n\n");
                                    }
                                break;

                            //Realiza a interse��o entre C e B
                            case 2:
                                for(i=0; i < cvet3; i++){
                                    for(j=0; j < cvet2; j++){
                                        if (vet3[i] == vet2[j]){
                                            intersecao[cintersecao] = vet1[i];
                                            cintersecao = cintersecao + 1;
                                        }
                                    }
                                }
                               for(i=0; i<cintersecao; i++){
                                    printf("\nC int. B = {");
                                        for (i=0; i<cintersecao; ++i){
                                            printf("%d",intersecao[i]);
                                            if (i<cintersecao-1){
                                                printf(",");
                                            }
                                        }
                                        printf("}\n\n");
                                    }
                                break;

                            //Realiza a interse��o entre C e C
                            case 3:
                                for(i=0; i < cvet3; i++){
                                        printf("\nC int. C = {");
                                        for (i=0; i<cvet3; ++i){
                                            printf("%d",vet3[i]);
                                            if (i<cvet3-1){
                                                printf(",");
                                            }
                                        }
                                        printf("}\n\n");
                                    }

                        }
                        break;
                }
                break;

        //case 7 Realiza a diferen�a de dois vetores:
            case 7:
                printf("\nEscolha o primeiro conjunto para realizar a diferen�a:\n");
                printf("1. Conjunto A\n");
                printf("2. Conjunto B\n");
                printf("3. Conjunto C\n");
                scanf("%i", &escolha);
                int diferenca[tamanho] = {0};
                switch(escolha){
                    case 1:
                        printf("\nEscolha o segundo conjunto para realizar a diferen�a:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            case 1:
                                i=0;
                                printf("\nA - A = {");
                                while (i<cvet1){
                                    printf("%d",vet1[i]);
                                    ++i;
                                }
                                if (i<cvet1-1)
                                    printf(", ");
                                printf("}\n\n");
                                break;
                                //A com A

                            case 2:

                                if(cvet1!=0 && cvet2!=0){
                                    printf("\nA - B = {");
                                    temp = 0;

                                    for (i=0;i<cvet1;i++){
                                            k = 0;

                                        for (j=0;j<cvet2;j++){
                                            if (vet1[i]==vet2[j])k++;
                                        }

                                        if (k == 0){
                                            diferenca[temp] = vet1[i];
                                            temp++;
                                        }
                                    }

                                    for(i = 0; i < temp; i++){
                                        printf("%d", diferenca[i]);
                                        if (i<temp-1)
                                            printf(", ");
                                    }
                                    printf("}");
                                }

                                else printf("\nErro! O conjunto A e B n�o possui elementos\n");

                                break;
                                //A com B

                            case 3:

                                if(cvet1!=0 && cvet3!=0){
                                    printf("\nA - C = {");
                                    temp = 0;

                                    for (i=0;i<cvet1;i++){
                                            k = 0;

                                        for (j=0;j<cvet3;j++){
                                            if (vet1[i]==vet3[j])k++;
                                        }

                                        if (k == 0){
                                            diferenca[temp] = vet1[i];
                                            temp++;
                                        }
                                    }

                                    for(i = 0; i < temp; i++){
                                        printf("%d", diferenca[i]);
                                        if (i<temp-1)
                                            printf(", ");
                                    }
                                    printf("}");
                                }
                                else printf("\nErro! O conjunto A e C n�o possui elementos\n");

                                break;
                               //A com C
                        }
                        break;
                    case 2:
                        printf("\nEscolha o segundo conjunto para realizar a diferen�a:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            case 1:

                                if(cvet2!=0 && cvet1!=0){
                                    printf("\nB - A = {");
                                    temp = 0;

                                    for (i=0;i<cvet2;i++){
                                            k = 0;

                                        for (j=0;j<cvet1;j++){
                                            if (vet2[i]==vet1[j])k++;
                                        }

                                        if (k == 0){
                                            diferenca[temp] = vet2[i];
                                            temp++;
                                        }
                                    }

                                    for(i = 0; i < temp; i++){
                                        printf("%d", diferenca[i]);
                                        if (i<temp-1)
                                            printf(", ");
                                    }
                                    printf("}");
                                }

                                else printf("\nErro! O conjunto B e A n�o possui elementos\n");

                                break;
                                //B com A


                            case 2:
                                i=0;
                                printf("\nB - B = {");
                                while (i<cvet2){
                                    printf("%d",vet2[i]);
                                    ++i;
                                }
                                if (i<cvet2-1)
                                    printf(", ");
                                printf("}\n\n");
                                break;
                                //B com B

                            case 3:

                                if(cvet2!=0 && cvet3!=0){
                                    printf("\nB - C = {");
                                    temp = 0;

                                    for (i=0;i<cvet2;i++){
                                            k = 0;

                                        for (j=0;j<cvet3;j++){
                                            if (vet2[i]==vet3[j])k++;
                                        }

                                        if (k == 0){
                                            diferenca[temp] = vet2[i];
                                            temp++;
                                        }
                                    }

                                    for(i = 0; i < temp; i++){
                                        printf("%d  ", diferenca[i]);
                                        if (i<temp-1)
                                            printf(", ");
                                    }
                                    printf("}");
                                }

                                else printf("\nErro! O conjunto B e C n�o possui elementos\n");

                                break;
                                //B com C
                        }
                        break;
                    case 3:
                        printf("\nEscolha o segundo conjunto para realizar a diferen�a:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i", &escolha);
                        switch(escolha){
                            case 1:

                                if(cvet3!=0 && cvet1!=0){
                                    printf("\nC - A = {");
                                    temp = 0;

                                    for (i=0;i<cvet3;i++){
                                            k = 0;

                                        for (j=0;j<cvet1;j++){
                                            if (vet3[i]==vet1[j])k++;
                                        }

                                        if (k == 0){
                                            diferenca[temp] = vet3[i];
                                            temp++;
                                        }
                                    }

                                    for(i = 0; i < temp; i++){
                                        printf("%d", diferenca[i]);
                                        if (i<temp-1)
                                            printf(", ");
                                    }
                                    printf("}");
                                }

                                else printf("\nErro! O conjunto C e A n�o possui elementos\n");

                                break;
                                //C com A

                            case 2:

                                if(cvet3!=0 && cvet2!=0){
                                    printf("\nC - B = {");
                                    temp = 0;

                                    for (i=0;i<cvet3;i++){
                                            k = 0;

                                        for (j=0;j<cvet2;j++){
                                            if (vet3[i]==vet2[j])k++;
                                        }

                                        if (k == 0){
                                            diferenca[temp] = vet3[i];
                                            temp++;
                                        }
                                    }

                                    for(i = 0; i < temp; i++){
                                        printf("%d", diferenca[i]);
                                        if (i<temp-1)
                                            printf(", ");
                                    }
                                    printf("}");
                                }

                                else printf("\nErro! O conjunto C e B n�o possui elementos\n");

                                break;
                                //C com B

                            case 3:
                                i=0;
                                printf("\nC U C = {");
                                while (i<cvet3){
                                    printf("%d   ",vet3[i]);
                                    ++i;
                                }
                                if (i<cvet3-1)
                                    printf(", ");
                                printf("}\n\n");
                                break;
                                //C com C
                        }
                        break;

                }
                break;

            //Realizar o produto carteziano de dois conjuntos;
            case 8:
               printf("\nEscolha o primeiro conjunto que deseja realiazar o Produto Cartesiano:\n");
                printf("1. Conjunto A\n");
                printf("2. Conjunto B\n");
                printf("3. Conjunto C\n");
                scanf("%i", &escolha);
                switch(escolha){
                    case 1:
                        printf("\n Escolha o segundo conjunto para o Produto Cartesiano:\n");
                        printf("1. Conjunto A\n");
                        printf("2. Conjunto B\n");
                        printf("3. Conjunto C\n");
                        scanf("%i",&escolha2);
                        if(escolha2==1){
                            //Verifica se algum ou ambos conjuntos s�o vazios
                            if(cvet1==0){
                                    printf("Conjuntos vazios");
                                    break;
                            }
                            else{
                                //Caso o conjunto nao seja vazio ele ir� imprimir o primeiro elemento do primeito conjunto e todos do segundo, ap�s serem utilizados todos do segundo ele ir� adicionar 1 ao i e ir� imprimir o produto at� q i seja menor q o tamanho do conjunto
                                i=0;
                                printf("AxA={");
                                for(i=0;i<cvet1;i++){
                                    for(j=0;j<cvet1;j++){
                                        printf("(%d,%d)",vet1[i],vet1[j]);
                                        if(i<cvet1-1 || j<cvet1-1){
                                            printf(",");
                                        }
                                    }
                                }
                                printf("}");
                            }
                            }
                        else{
                            if(escolha2==2){
                                //Verifica se h� 1 ou mais conjuntos vazios
                                    if(cvet1==0 && cvet2==0){
                                            printf("Conjuntos vazios");
                                            break;
                                    }
                                    else{
                                        if(cvet1==0){
                                            printf("Conjunto A vazio");
                                            break;
                                        }
                                        else{
                                            if(cvet2==0){
                                                printf("Conjunto B vazio");
                                                break;
                                            }
                                            else{
                                                //Caso o conjunto nao seja vazio ele ir� imprimir o primeiro elemento do primeito conjunto e todos do segundo, ap�s serem utilizados todos do segundo ele ir� adicionar 1 ao i e ir� imprimir o produto at� q i seja menor q o tamanho do conjunto
                                                i=0;
                                                printf("AxB={");
                                                for(i=0;i<cvet1;i++){
                                                    for(j=0;j<cvet2;j++){
                                                        printf("(%d,%d)",vet1[i],vet2[j]);
                                                        if(i<cvet1-1 || j<cvet2-1){
                                                            printf(",");
                                                        }
                                                    }
                                                }
                                                printf("}");
                                            }
                                        }
                                    }
                            }
                            else{
                                if(escolha2==3){
                                    //Verifica se possui algum conjunto vazio
                                        if(cvet1==0 && cvet3==0){
                                            printf("Conjuntos vazios");
                                        }
                                        else{
                                            if(cvet1==0){
                                                printf("Conjunto A vazio");
                                            }
                                            else{
                                                if(cvet3==0){
                                                    printf("Conjunto C vazio");
                                                }
                                                else{
                                                    //Caso o conjunto nao seja vazio ele ir� imprimir o primeiro elemento do primeito conjunto e todos do segundo, ap�s serem utilizados todos do segundo ele ir� adicionar 1 ao i e ir� imprimir o produto at� q i seja menor q o tamanho do conjunto
                                                    i=0;
                                                    printf("AxC={");
                                                    for(i=0;i<cvet1;i++){
                                                        for(j=0;j<cvet3;j++){
                                                            printf("(%d,%d)",vet1[i],vet3[j]);
                                                            if(i<cvet1-1 || j<cvet3-1){
                                                                printf(",");
                                                            }
                                                        }
                                                    }
                                                    printf("}");
                                                }
                                            }
                                        }
                                }
                            }
                        }
                    case 2:
                        if(escolha==2){
                            printf("\n Escolha o segundo conjunto para o Produto Cartesiano:\n");
                            printf("1. Conjunto A\n");
                            printf("2. Conjunto B\n");
                            printf("3. Conjunto C\n");
                            scanf("%i",&escolha2);
                            if(escolha2==1){
                                    //Verifica existencia de algum onjunto vazio
                                if(cvet1==0 && cvet2==0){
                                    printf("Conjuntos vazios");
                                    break;
                                }
                                else{
                                    if(cvet1==0){
                                        printf("Conjunto A vazio");
                                        break;
                                    }
                                    else{
                                        if(cvet2==0){
                                            printf("Conjunto B Vazio");
                                            break;
                                        }
                                        else{
                                            //Caso o conjunto nao seja vazio ele ir� imprimir o primeiro elemento do primeito conjunto e todos do segundo, ap�s serem utilizados todos do segundo ele ir� adicionar 1 ao i e ir� imprimir o produto at� q i seja menor q o tamanho do conjunto
                                            i=0;
                                            printf("BxA={");
                                            for(i=0;i<cvet2;i++){
                                                for(j=0;j<cvet1;j++){
                                                    printf("(%d,%d)",vet2[i],vet1[j]);
                                                    if(i<cvet2-1 || j<cvet1-1){
                                                        printf(",");
                                                    }
                                                }
                                            }
                                            printf("}");
                                        }
                                    }
                                }
                            }
                            else{
                                if(escolha2==2){
                                    //Verifica existencia de algum conjunto vazio
                                        if(cvet2==0){
                                            printf("Conjunto B Vazio");
                                        }
                                        else{
                                            //Caso o conjunto nao seja vazio ele ir� imprimir o primeiro elemento do primeito conjunto e todos do segundo, ap�s serem utilizados todos do segundo ele ir� adicionar 1 ao i e ir� imprimir o produto at� q i seja menor q o tamanho do conjunto
                                            i=0;
                                            printf("BxB={");
                                            for(i=0;i<cvet2;i++){
                                                for(j=0;j<cvet2;j++){
                                                    printf("(%d,%d)",vet2[i],vet2[j]);
                                                    if(i<cvet2-1 || j<cvet2-1){
                                                        printf(",");
                                                    }
                                                }
                                            }
                                            printf("}");
                                        }
                                }
                                else{
                                    if(escolha2==3){
                                        //Verifica existencia de algum conjunto vazio
                                            if(cvet3==0 && cvet2==0){
                                                printf("Conjuntos vazios");
                                                break;
                                            }
                                            else{
                                                if(cvet2==0){
                                                    printf("Conjunto B vazio");
                                                    break;
                                                }
                                                else{
                                                    if(cvet3==0){
                                                        printf("Conjunto C vazio");
                                                        break;
                                                    }
                                                    else{
                                                        //Caso o conjunto nao seja vazio ele ir� imprimir o primeiro elemento do primeito conjunto e todos do segundo, ap�s serem utilizados todos do segundo ele ir� adicionar 1 ao i e ir� imprimir o produto at� q i seja menor q o tamanho do conjunto
                                                        i=0;
                                                        printf("BxC={");
                                                        for(i=0;i<cvet2;i++){
                                                            for(j=0;j<cvet3;j++){
                                                                printf("(%d,%d)",vet2[i],vet3[j]);
                                                                if(i<cvet2-1 || j<cvet3-1){
                                                                    printf(",");
                                                                }
                                                            }
                                                        }
                                                        printf("}");
                                                    }
                                                }
                                            }
                                    }
                                }
                            }
                        }
                    case 3:
                        if(escolha==3){
                            printf("\n Escolha o segundo conjunto para o Produto Cartesiano:\n");
                            printf("1. Conjunto A\n");
                            printf("2. Conjunto B\n");
                            printf("3. Conjunto C\n");
                            scanf("%i",&escolha2);
                            if(escolha2==1){
                                    //varifica se existe algum conjunto vazio
                                    if(cvet1==0 && cvet3==0){
                                        printf("Conjuntos vazios");
                                        break;
                                    }
                                    else{
                                        if(cvet1==0){
                                            printf("Conjunto A vazio");
                                            break;
                                        }
                                        else{
                                            if(cvet3==0){
                                                printf("Conjunto C vazio");
                                                break;
                                            }
                                            else{
                                                //Caso o conjunto nao seja vazio ele ir� imprimir o primeiro elemento do primeito conjunto e todos do segundo, ap�s serem utilizados todos do segundo ele ir� adicionar 1 ao i e ir� imprimir o produto at� q i seja menor q o tamanho do conjunto
                                                i=0;
                                                printf("CxA={");
                                                for(i=0;i<cvet3;i++){
                                                    for(j=0;j<cvet1;j++){
                                                        printf("(%d,%d)",vet3[i],vet1[j]);
                                                        if(i<cvet3-1 || j<cvet1-1){
                                                            printf(",");
                                                        }
                                                    }
                                                }
                                                printf("}");
                                            }
                                        }
                                    }
                            }
                            else{
                                if(escolha2==2){
                                    //Verifica se extiste algum conjunto vazio
                                        if(cvet2==0 && cvet3==0){
                                            printf("Conjuntos vazios");
                                            break;
                                        }
                                        else{
                                            if(cvet2==0){
                                                printf("Conjunto B vazio");
                                                break;
                                            }
                                            else{
                                                if(cvet3==0){
                                                    printf("Conjunto C vazio");
                                                    break;
                                                }
                                                else{
                                                    //Caso o conjunto nao seja vazio ele ir� imprimir o primeiro elemento do primeito conjunto e todos do segundo, ap�s serem utilizados todos do segundo ele ir� adicionar 1 ao i e ir� imprimir o produto at� q i seja menor q o tamanho do conjunto
                                                    i=0;
                                                    printf("CxB={");
                                                    for(i=0;i<cvet3;i++){
                                                        for(j=0;j<cvet2;j++){
                                                            printf("(%d,%d)",vet3[i],vet2[j]);
                                                            if(i<cvet3-1 || j<cvet2-1){
                                                                printf(",");
                                                            }
                                                        }
                                                    }
                                                    printf("}");
                                                }
                                            }
                                        }
                                }
                                else{
                                    if(escolha2==3){
                                        //Verifica se algum conjunto � vazio
                                            if(cvet3==0){
                                                printf("Conjuntos vazios");
                                                break;
                                            }
                                            else{
                                                //Caso o conjunto nao seja vazio ele ir� imprimir o primeiro elemento do primeito conjunto e todos do segundo, ap�s serem utilizados todos do segundo ele ir� adicionar 1 ao i e ir� imprimir o produto at� q i seja menor q o tamanho do conjunto
                                                i=0;
                                                printf("CxC={");
                                                for(i=0;i<cvet3;i++){
                                                    for(j=0;j<cvet3;j++){
                                                        printf("(%d,%d)",vet3[i],vet3[j]);
                                                        if(i<cvet3-1 || j<cvet3-1){
                                                            printf(",");
                                                        }
                                                    }
                                                }
                                                printf("}");
                                            }
                                            }
                                        }
                            }
                        }
                }
                break;
            // Funcao que Imprime os elementos de um conjunto;
            case 9:
                printf("\nEscolha o conjunto que deseja imprimir:\n");
                printf("1. Conjunto A\n");
                printf("2. Conjunto B\n");
                printf("3. Conjunto C\n");
                scanf("%i", &escolha);

                switch(escolha){
                    case 1:
                        printf("\nA = {");
                        for (i=0; i<cvet1; ++i){
                            printf("%d",vet1[i]);
                            if (i<cvet1-1){
                                printf(",");
                            }
                        }
                        printf("}\n\n");
                        break;


                    case 2:
                        printf("\nB = {");
                        for (i=0; i<cvet2; ++i){
                            printf("%d",vet2[i]);
                            if (i<cvet2-1){
                                printf(",");
                            }
                        }
                        printf("}\n\n");
                        break;

                    case 3:
                        printf("\nC = {");
                        for (i=0; i<cvet3; ++i){
                            printf("%d",vet3[i]);
                            if (i<cvet3-1){
                                printf(",");
                            }
                        }
                        printf("}\n\n");
                        break;
                }
                break;

            case 10:
               return 0;

            default:
                printf("\n Opera��o Inv�lida\n");
                break;
        }
    }
}
