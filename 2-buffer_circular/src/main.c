/* Teste de um buffer circular
 *
 * Este programa serve para implementar e testar uma implementacao de buffer
 * circular
 */

#include <stdio.h>
#include <ctype.h>

char buffer[5];
char *head = &(buffer[0]); //aponta para a primeira posição do buffer
char *tail = &(buffer[4]); //aponta para a última posição do buffer
char *write = &(buffer[0]); //aponta para a próxima posição que o buffer pode escrever

void adicionar_buffer(char c) {
	//Se o buffer estiver cheio, nada é adicionado
	if (write == tail+1){
		return;
	}

	//Se o buffer não estiver cheio, o caractere é adicionado
	//na posição apontada pelo ponteiro write e ele é incrementado,
	//para atualizar a próxima posição de inserção do buffer
	else{
		*write = c;
	        (write)++;
	};
	
	return;

}

void remover_buffer() {
	//Buffer não está vazio, portanto, todas as posições do
	//buffer são deslocadas em 1 para a esquerda, removendo o
	//caractere salvo na posição 0 dele
	if (write!=head){
		for (int i=0; i<5; i++)
			buffer[i] = buffer[i+1];
		(write)--;
	}

	//No caso do buffer vazio, nada acontece
	else
		return;
	return;
}

void imprimir_buffer() {
	char *read = &(buffer[0]); //Aponta para a posição do buffer a ser impressa
	for(read; read<write; read++){	
		if (read<write-1) //Impressão nao chegou a fim, portando, não temos uma quebra de linha no print
			printf("%c ", (*read));
		if (read == write-1) //Impressão chegou na última posição não vazia do buffer, portanto, temos quebra de linha
			printf("%c\n", (*read));
	}

	read = &(buffer[0]);

	int x = write-head;

	//Caso o buffer esteja vazio, imprimimos somente uma quebra de linha
	if (x==0)
		printf("\n");
	return;
}

int main() {

  char c;

  do {
    scanf("%c", &c);
   
    if (c == '\n') 
	    break;
    else{
	    //Se a entrada é um número, adicionamos um caractere no buffer
	    if(isdigit(c))
		    adicionar_buffer(c);
	    //Caso contrário, uma letra, removemos um caractere
	    else
		    remover_buffer();
	    //Ao fim de cada iteração, imprimimos o buffer
	    imprimir_buffer();
    }

  } while (1);

  return 0;
}
