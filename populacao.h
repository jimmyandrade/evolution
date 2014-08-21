#pragma once

#include <vector>
#include "individuo.h"

class Populacao {

	private:
	typedef unsigned int Indice;
    typedef unsigned int Quantidade;
    const Quantidade quantidade_individuos_;
    typedef std::vector<Individuo::Ponteiro> VetorIndividuos;
    VetorIndividuos individuos_;

	public:
    Populacao( unsigned int quantidade_individuos, unsigned int quantidade_genes );
    void Imprimir(void);
    VetorIndividuos SelecionarCasal(void);
    
    /* Escolhe aleatoriamente o indice de um individuo */
    inline unsigned int ObterIndiceIndividuoAleatorio(void) { return rand() % individuos_.size(); }
    
    /* Escolhe aleatoriamente um individuo o retorna um ponteiro para ele */
    inline Individuo::Ponteiro ObterIndividuoAleatorio(void) { return individuos_[ObterIndiceIndividuoAleatorio()]; }
    
    inline Individuo::Ponteiro ObterIndividuoNoIndice( unsigned int i ) { return individuos_[i]; }

	inline void SubstituirIndividuoNoIndice( Individuo::Indice i, Individuo::Ponteiro individuo ) { individuos_[i] = individuo; }

    inline Cromossomo::TipoGene ObterGene( Individuo::Indice i, Individuo::Indice j ) { return ObterIndividuoNoIndice(i)->ObterGeneNoIndice(j); }

	Individuo::Ponteiro EncontrarMelhorIndividuo();
	Individuo::Ponteiro EncontrarPiorIndividuo();
	Individuo::Ponteiro EncontrarIndividuoMedio();

};

