#include <iostream>
#include "populacao.h"

Populacao::Populacao( unsigned int quantidade_individuos, unsigned int quantidade_genes ) : quantidade_individuos_( quantidade_individuos ) {

	std::cout << "Iniciando a geracao de populacao inicial com " << quantidade_individuos << " individuos, cada um com " << quantidade_genes << " genes\n";

	for ( unsigned int i = 0; i < quantidade_individuos_; ++i ) {
		individuos_.push_back( new Individuo( quantidade_genes ) );
		std::cout << "Adicionado novo individuo aa populacao\n";
	}

}

void Populacao::Imprimir(void) {

	for ( unsigned int i = 0; i < individuos_.size(); ++i ) {
		std::cout << i << ": ";
		individuos_[i]->Imprimir();
		std::cout << "\n";
	}

}

Populacao::VetorIndividuos Populacao::SelecionarCasal() {

	Individuo::Ponteiro base = ObterIndividuoAleatorio();

	Individuo::Ponteiro par1;
	do {
		par1 = ObterIndividuoAleatorio();
	}
	while( base == par1 );

	Individuo::Ponteiro par2;
	do {
		par2 = ObterIndividuoAleatorio();
	}
	while( base == par2 || par1 == par2 );

	Populacao::VetorIndividuos casal;
	casal.push_back( par1 );
	casal.push_back( par2 );

    std::cout << "\nBase:\t";
	base->Imprimir();
    
	std::cout << "\nPar 1:\t";
    par1->Imprimir();
    
    std::cout << "\nPar 2:\t";
	par2->Imprimir();

	return casal;
}

Individuo::Ponteiro Populacao::EncontrarMelhorIndividuo() {

	Individuo::Ponteiro melhor_individuo = ObterIndividuoNoIndice(0);

	for( Indice i = 1; i < quantidade_individuos_; ++i ) {
		if ( ObterIndividuoNoIndice(i)->ObterFitness() > melhor_individuo->ObterFitness() ) {
			melhor_individuo = ObterIndividuoNoIndice(i);
		}
	}

	return melhor_individuo;

}

Individuo::Ponteiro Populacao::EncontrarPiorIndividuo() {

	Individuo::Ponteiro pior_individuo = ObterIndividuoNoIndice(0);

	for( Indice i = 1; i < quantidade_individuos_; ++i ) {
		if ( ObterIndividuoNoIndice(i)->ObterFitness() < pior_individuo->ObterFitness() ) {
			pior_individuo = ObterIndividuoNoIndice(i);
		}
	}

	return pior_individuo;

}

Individuo::Ponteiro Populacao::EncontrarIndividuoMedio() {

	Individuo::Ponteiro pior_individuo = ObterIndividuoNoIndice(0);
	Individuo::Ponteiro individuo_medio = ObterIndividuoNoIndice(0);
	Individuo::Ponteiro melhor_individuo = ObterIndividuoNoIndice(0);

	for( Indice i = 1; i < quantidade_individuos_; ++i ) {
		if (
			ObterIndividuoNoIndice(i)->ObterFitness() > pior_individuo->ObterFitness()
			&&
			ObterIndividuoNoIndice(i)->ObterFitness() < melhor_individuo->ObterFitness()
		) {
			individuo_medio = ObterIndividuoNoIndice(i);
		}
	}
	
	return individuo_medio;

}