#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

void print( vector< bool * > &, int );
bool generateGene();
void createPopulation( vector< bool * > &, int );
double calcFitness( bool [ ] chrom, int, individual &, vector< product > &, double, double );

struct product
{
	double weight;
	double value;
};

struct individual
{
	double fitness;
	vector< product > fenotipo;
};

void setallproduct( vector< bool * >  & );

int main()
{
	int sizePopulation = 10;
	int numGenes = 15;
	int numGenerations = 100;
	char answer;
	
	vector< product > allproduct( 15 );
	
	
	cout << "Programa para calcular o fitness de um gene!\n";
	
	
	
	cout << "Quer fazer uma nova itera" << char() << char() << "o?\n";
	cout << "Digite s para continuar e n para encerrar!";
	cin >> answer;
	
	while( anwser != n )
	{
		srand( ( int ) time( 0 ) );
		
		vector< bool * > population( sizePopulation );
		
		vector< individual > popDecod( sizePopulation );
		
	
		createPopulation( population, numGenes );
		printGenes( population, numGenes);
		setallproduct( allproduct );
		
		for ( int i = 0; i < numGenerations; i++ )
		{
			for( n = 0; n < sizePopulation; n++ )
				 popDecod[ n ].fitness = calcFitness( population[ n ], numGenes, popDecod[ n ], allproduct )
		}
		
	
	}
	
	
	//função delete bool[]
}

void setallproduct( vector< product > &allproduct )
{
	allproduct[ 0 ].weight = 100;
	allproduct[ 0 ].value = 1000;
	
	allproduct[ 1 ].weight = 1;
	allproduct[ 1 ].value = 10000;
	
	allproduct[ 1 ].weight = 10;
	allproduct[ 1 ].value = 100;
	
	allproduct[ 0 ].weight = 1000;
	allproduct[ 0 ].value = 10;
	
	allproduct[ 1 ].weight = 100;
	allproduct[ 1 ].value = 10;
	
	allproduct[ 1 ].weight = 10;
	allproduct[ 1 ].value = 10000;
	
	allproduct[ 0 ].weight = 100;
	allproduct[ 0 ].value = 1;
	
	allproduct[ 1 ].weight = 10;
	allproduct[ 1 ].value = 10000;
	
	allproduct[ 0 ].weight = 1000;
	allproduct[ 0 ].value = 10;
	
	allproduct[ 0 ].weight = 1;
	allproduct[ 0 ].value = 1;
	
	allproduct[ 1 ].weight = 100;
	allproduct[ 1 ].value = 100000;
	
	allproduct[ 1 ].weight = 1000;
	allproduct[ 1 ].value = 100;
	
	allproduct[ 0 ].weight = 10000;
	allproduct[ 0 ].value = 10000;
	
	allproduct[ 1 ].weight = 10;
	allproduct[ 1 ].value = 10;
	
	allproduct[ 1 ].weight = 1;
	allproduct[ 1 ].value = 1000;
}

bool generateGene()
{
	if( ( rand() % 100 + 1 ) <= 50 )
		return false;
		else return true;
}

void createPopulation( vector< bool * > &pop, int numGenes )
{
	for ( int i = 0; i < pop.size(); i++ )
	{
			pop[ i ] =  new bool[ numGenes ];
			for ( int j = 0; j < numGenes; j++ )
			     pop[ i ][ j ] = generateGene( );
		
	}
}

double calcFitness( bool [ ] chrom, int numGenes, individual &ind, vector< product > & allproduct, double Pmax, double Vmax )
{
	int fitness = 0;
	
	for( int i = 0; i < numGenes; i++ )
		if( chrom[ i ] )
		{
			ind.fenotipo.push_back( allproduct[ i ] );
			fitness += allproduct[ i ].value / Vmax + Pmax/ allproduct[ i ].weight;
		}
}

void crossoverGenes( )
{
	
}

void mutationGenes( )
{
	
}

void printGenes( vector< bool * > &pop, int numGenes )
{
	for ( int i = 0; i < pop.size(); i++ )
	{
		for ( int j = 0; j < numGenes; j++ )
			if( pop[ i ][ j ] )
				cout << 1 << '\t';
			else
				cout << 0 << '\t';
		cout << "\n";
	}
}

void print( )
{
	
}
