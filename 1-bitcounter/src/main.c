/* Contador de bits
 * Nome: Giulia Steck - 173458
 *
 * Este programa conta o numero de bits em um byte
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {

  unsigned char entrada;
  unsigned int tmp;
  unsigned int n_bits;
  unsigned int bitstestados = 0;

  /* Ler entrada em hexadecimal */
  scanf("%x", &tmp);
  entrada = (unsigned char)tmp;
  
  n_bits = 0;

  while (bitstestados < 8){
	  //Caso o bit avaliado seja igual a 1, 
	  //a variável contadora é incrementada.
	  if (entrada & 0X01)
		  n_bits ++;
	  else
		  n_bits = n_bits;

	  bitstestados++;
	  
	  //Depois de um bit ser avaliado, o operador >>
	  //faz um 'right shift', inserindo um zero à es-
	  //querda, possibilitando que o próximo bit seja
	  //lido
	  entrada = entrada >> 1;
  }
  

  /* Escrever numero de bits */
  printf("%d\n", n_bits);
  return 0;
}
