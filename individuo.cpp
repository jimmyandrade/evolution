#include <cstdlib>
#include <fstream>

#include "individuo.h"

Individuo::Individuo( Indice quantidade_genes ) : cromossomo_( Cromossomo( quantidade_genes ) ) {
	LerMatrizBlocos();
	CalcularTrapFive();
}

Individuo::Indice Individuo::CalcularTrapFive(void) {

	Indice contagem;
    Indice total = 0;
	Indice posicao_bloco = 0;

    for ( Indice i=0 ; i < quantidade_blocos_;  ++i ) {
        contagem = 0;
        for ( Indice j=0 ; j < quantidade_genes_por_bloco_; ++j ) {
			posicao_bloco = matriz_blocos_[i][j] - 1;
			//std::cout << "Posicao no bloco eh " << posicao_bloco << ", definida pelos indices " << i << " e " << j << "\n";
			//system( "pause" );
			if ( cromossomo_.ObterGeneNoIndice( posicao_bloco ) == true ) {
				++contagem;
			}
        }
		if ( contagem == 5 ) {
			total += contagem;
		}
		else {
			total += ( 4 - contagem );
		}
    }

	fitness_ = total;
	return total;

}

void Individuo::LerMatrizBlocos( void ) {

	std::ifstream Entrada( "trap5.txt", std::ifstream::in );

	if ( !Entrada.is_open() ) {
		std::cerr << "Erro. Arquivo do trap five nao encontrado.";
		return;
	}

	unsigned int indice = 0;

	matriz_blocos_.resize( quantidade_blocos_ );

	for ( unsigned int i = 0; i < quantidade_blocos_; ++i ) {

		matriz_blocos_[i].resize( quantidade_genes_por_bloco_ );

		for ( unsigned int j = 0; j < quantidade_genes_por_bloco_; ++j ) {
			Entrada >> indice;
			matriz_blocos_[i][j] = indice;
			//std::cout << indice << "\t";
		}
		//std::cout << "\n";
	}

	//system("pause");

}