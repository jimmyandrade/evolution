#pragma once

#include <cstdlib>
#include <iostream>

#include "trapfive.h"

class EvolucaoDiferencial {

	private:
    
    typedef unsigned int Quantidade;
    typedef float Taxa;
    
    /* Quantidade maxima de populacoes geradas por este algoritmo */
    const Quantidade quantidade_maxima_populacoes_;
    
    /* Quantidade de individuos numa populacao */
    const Quantidade quantidade_individuos_populacao_;
    
    /* Quantidade de genes que um cromossomo armazenara */
    const Quantidade quantidade_cromossomos_individuo_;

	const Quantidade quantidade_blocos_;

	const Quantidade quantidade_genes_por_bloco_;
    
    /* Taxas de perturbacao e mutacao a serem usadas pelo algoritmo */
    const Taxa perturbacao_;
    const Taxa mutacao_;
    
    inline bool HaveraPerturbacao() {
        double r = ((double) rand() / (RAND_MAX));
        //std::cout << r << " < " << perturbacao_ << " \n";
        return r < perturbacao_;
    }
    inline bool HaveraMutacao() {
        double r = ((double) rand() / (RAND_MAX));
        //std::cout << r << " < " << mutacao_ <<"\n";
        return r < mutacao_;
    }
    inline unsigned int ObterIndiceAleatorioParaGene() { return rand() % quantidade_cromossomos_individuo_; }

	public:
    EvolucaoDiferencial(
                        Quantidade quantidade_maxima_populacoes = 3,
                        Quantidade quantidade_individuos_populacao = 5,
                        Quantidade quantidade_cromossomos_individuo = 4,
                        Taxa perturbacao = 0.8,
                        Taxa mutacao = 0.2,
						Quantidade quantidade_blocos = 20,
						Quantidade quantidade_genes_por_bloco = 5 ) :

        quantidade_maxima_populacoes_( quantidade_maxima_populacoes ),
        quantidade_individuos_populacao_( quantidade_individuos_populacao ),
        quantidade_cromossomos_individuo_( quantidade_cromossomos_individuo ),
        perturbacao_( perturbacao ),
        mutacao_( mutacao ),
		quantidade_blocos_( quantidade_blocos ),
		quantidade_genes_por_bloco_( quantidade_genes_por_bloco )
    { Executar(); };
    
    ~EvolucaoDiferencial();
    
    void Executar();
    
};

