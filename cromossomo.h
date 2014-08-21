#pragma once
#include <cstdlib>
#include <ctime>
#include <vector>

class Cromossomo {

public:
	typedef bool TipoGene;
	typedef unsigned int Indice;
	typedef Cromossomo* Ponteiro;

private:
	typedef std::vector<TipoGene> VetorGenes;
	const Indice quantidade_genes_;
	const Indice ultimo_item_;
	VetorGenes cromossomo_;

	inline static TipoGene GerarValorAleatorio(void) { return ( rand() % 2 == 1 ) ? true : false; }
	
	/* Escolhe aleatoriamente uma variavel e retorna seu valor */
    inline TipoGene ObterGeneAleatorio() { return cromossomo_[ObterIndiceGeneAleatorio()]; }

public:
	Cromossomo( Indice quantidade_genes_ );
	~Cromossomo(void);

	inline TipoGene ObterGeneNoIndice( Indice i ) { return cromossomo_[i]; }
	
	/* Escolhe aleatoriamente o indice de uma variavel */
	inline Cromossomo::Indice ObterIndiceGeneAleatorio(void) { return (Cromossomo::Indice) rand() % quantidade_genes_; }

	inline void DefinirValorGeneNoIndice( Indice i, TipoGene x ) { cromossomo_[i] = x; }
	inline void InverterGeneNoIndice( Indice i ) { DefinirValorGeneNoIndice(i, !ObterGeneNoIndice(i)); }

	void Cromossomo::Imprimir();

};

