#pragma once

#include <iostream>

#include "cromossomo.h"
#include "trapfive.h"

class Individuo {

public:
	typedef unsigned int Indice;
	typedef Individuo* Ponteiro;
	typedef std::vector<std::vector<Indice>> TipoMatrizBlocos;

	// Constantes estaticas
	static const Indice quantidade_blocos_ = 20;
	static const Indice quantidade_genes_por_bloco_ = 5;
	static bool ja_importou_matriz;

private:
	Cromossomo cromossomo_;
	unsigned int fitness_;
	TipoMatrizBlocos matriz_blocos_;
	Indice Individuo::CalcularTrapFive();

public:
	Individuo( Indice quantidade_genes );
	inline void Imprimir(void) { std::cout << "Fitness deste individuo: " << fitness_ << "\n"; /* return cromossomo_.Imprimir(); */  }
    inline ~Individuo() {  }
	Cromossomo::TipoGene ObterGeneNoIndice( Cromossomo::Indice i ) { return cromossomo_.ObterGeneNoIndice( i ); }
	Cromossomo::Indice ObterIndiceGeneAleatorio( void ) { return cromossomo_.ObterIndiceGeneAleatorio(); }
	void InverterGeneNoIndice( Cromossomo::Indice i ) { return cromossomo_.InverterGeneNoIndice( i ); }
	void DefinirValorGeneNoIndice( Cromossomo::Indice i, Cromossomo::TipoGene x ) { return cromossomo_.DefinirValorGeneNoIndice( i, x ); }
	void Individuo::LerMatrizBlocos( void );
	inline Indice ObterFitness( void ) { return fitness_; }
	inline Indice CalcularEObterFitness( void ) { return Individuo::CalcularTrapFive(); }

};
