#include <fstream>
#include <iostream>

#include "trapfive.h"
#include "evolucaodiferencial.h"
#include "populacao.h"

void EvolucaoDiferencial::Executar() {

    std::cout << "Usando tamanho de cromossomo " << quantidade_cromossomos_individuo_ << "\n";

    Populacao populacao_inicial( quantidade_individuos_populacao_, quantidade_cromossomos_individuo_ );

	std::cout << "Gerada populacao inicial";

    for ( unsigned int p = 0; p < quantidade_maxima_populacoes_; ++p ) {
    
        std::cout << "Trabalhando com populacao geracao " << p << "\n";
        
		Individuo::Indice fitness_individuo_inicial, fitness_individuo_mutante;

        for ( unsigned int i = 0;  i < quantidade_individuos_populacao_ ;  ++i ) {
            
            std:: cout << "Trabalhando com individuo numero " << i << "\n";
            
            /* Escolhe aleatoriamente o indice de um individuo */
            unsigned int indice_individuo_aleatorio = populacao_inicial.ObterIndiceIndividuoAleatorio();
            std::cout << "Indice do individuo aleatorio: " << indice_individuo_aleatorio << "\n";
            
            Individuo::Ponteiro individuo_aleatorio = populacao_inicial.ObterIndividuoNoIndice(indice_individuo_aleatorio);
            
            //std::cout << "Genes do individuo aleatorio:\n";
            //individuo_aleatorio->Imprimir(); std::cout << "\n";
            
            /* Escolhe aleatoriamente o indice de uma variavel */
            unsigned int indice_gene_aleatorio = individuo_aleatorio->ObterIndiceGeneAleatorio();
            std::cout << "Gene aleatorio: " << indice_gene_aleatorio << "\n";
            
            Cromossomo::TipoGene gene_crossover = individuo_aleatorio->ObterGeneNoIndice(indice_gene_aleatorio);
            
            Populacao solucao_teste = populacao_inicial;

			fitness_individuo_inicial = solucao_teste.ObterIndividuoNoIndice( i )->ObterFitness();

            std::cout << "Individuo atual (antes):\n";
            (solucao_teste.ObterIndividuoNoIndice( i ))->Imprimir();
            std::cout << "\n";
            
            for ( unsigned int j = 0; j < quantidade_cromossomos_individuo_; ++j ) {
                
                //std::cout << "Trabalhando com o gene " << j << "\n";
                
                if ( HaveraPerturbacao() || j == indice_gene_aleatorio ) {
                    //std::cout << "Havera perturbacao.\n";
                    
                    /* Testa a possibilidade de haver mutacao. A taxa eh definida por mutacao_ */
                    if (HaveraMutacao()) {
                        //std::cout << "Havera mutacao\n";
                        solucao_teste.ObterIndividuoNoIndice( i )->InverterGeneNoIndice( j );
                        //std::cout << "Inversao de bit do gene " << j << " concluida\n";
                    }
                    else {
                        //std::cout << "Havera crossover\n";
                        solucao_teste.ObterIndividuoNoIndice( i )->DefinirValorGeneNoIndice(j , gene_crossover);
                        //std::cout << "Crossover no gene " << j << " finalizado\n";
                    }

                }

            } // fim para
            
			fitness_individuo_mutante = solucao_teste.ObterIndividuoNoIndice( i )->CalcularEObterFitness();

			if( fitness_individuo_mutante > fitness_individuo_inicial ) {
				std::cout << "Houve melhora.\n";
				populacao_inicial.SubstituirIndividuoNoIndice ( i, solucao_teste.ObterIndividuoNoIndice( i ) );
			}

            std::cout << "Individuo atual (depois):\n";
            (solucao_teste.ObterIndividuoNoIndice( i ))->Imprimir();
            std::cout << "\n";
            
			std::cout << "Melhor individuo: ";
			(solucao_teste.EncontrarMelhorIndividuo())->Imprimir();
			std::cout << "\n";

			std::cout << "Pior individuo: ";
			(solucao_teste.EncontrarPiorIndividuo())->Imprimir();
			std::cout << "\n";

			std::cout << "Individuo medio: ";
			(solucao_teste.EncontrarIndividuoMedio())->Imprimir();
			std::cout << "\n";

        } // fim para

    }
    
}

EvolucaoDiferencial::~EvolucaoDiferencial() {
    
}