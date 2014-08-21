#include <ctime>
#include <iostream>

#include "cromossomo.h"

Cromossomo::Cromossomo( Indice quantidade_genes ) : quantidade_genes_( quantidade_genes ), ultimo_item_( quantidade_genes - 1 ) {

    // Gera valores aleatorios para os genes do individuo
	for ( unsigned int i = 0; i < quantidade_genes_; ++i ) {
		srand(time(NULL) + i);
		cromossomo_.push_back( GerarValorAleatorio() );
	}
}

Cromossomo::~Cromossomo(void) {
	cromossomo_.clear();
}

void Cromossomo::Imprimir(void) {

    char x;
    
	std::cout << "[";
    
	for ( unsigned int i = 0; i < quantidade_genes_; ++i ) {
		// std::cout << i << ": ";
		x = cromossomo_[i] ? '1' : '0';
        std::cout << x;
        if( i < ultimo_item_ ) {
            std::cout << "\t";
        }
	}
	std::cout << "]";

}
