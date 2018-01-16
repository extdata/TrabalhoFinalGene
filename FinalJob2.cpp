#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
using std::vector;


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

void print( vector< bool * > &, int );
void print( vector< individual > &, int );
void print( const individual & );
void print( const product & );
void print( const bool [ ], int  );
bool generateGene();
void createPopulation( vector< bool * > &, int );
double calcFitness( bool [ ], int, individual &, vector< product > & );
void setallproduct( vector< product > & );

int main()
{
	int sizePopulation = 4;
	int numGenes = 4;
	int numGenerations = 5;	
	vector< product > allproduct( 15 );
	vector< bool * > population( sizePopulation );
	vector< individual > popDecod( sizePopulation );
		
	cout << "Programa para calcular o fitness de um gene usando aloca" << char(135) << char(198) << "o din" << char(131) << "mica de mem" << char(162) << "ria!\n";
	
	int k = 0;
	while( k < 10 )
	{
		srand(( int ) time( 0 ));
		
		createPopulation( population, numGenes );
		print(population, numGenes);
		setallproduct( allproduct );
		
		for ( int i = 0; i < numGenerations; i++ )
			for( int n = 0; n < sizePopulation; n++ )
			{
				 calcFitness( population[n], numGenes, popDecod[ n ], allproduct );
				 print( popDecod[ n ] );
			}
			
		delete [ ] ;
		
	}
}

void setallproduct( vector< product > &allproduct )
{
	allproduct[ 0 ].weight = 100;
	allproduct[ 0 ].value = 1000;
	
	allproduct[ 1 ].weight = 1;
	allproduct[ 1 ].value = 10000;
	
	allproduct[ 2 ].weight = 10;
	allproduct[ 2 ].value = 100;
	
	allproduct[ 3 ].weight = 1000;
	allproduct[ 3 ].value = 10;
	
	allproduct[ 4 ].weight = 100;
	allproduct[ 4 ].value = 10;
	
	allproduct[ 5 ].weight = 10;
	allproduct[ 5 ].value = 10000;
	
	allproduct[ 6 ].weight = 100;
	allproduct[ 6 ].value = 1;
	
	allproduct[ 7 ].weight = 10;
	allproduct[ 7 ].value = 10000;
	
	allproduct[ 8 ].weight = 1000;
	allproduct[ 8 ].value = 10;
	
	allproduct[ 9 ].weight = 1;
	allproduct[ 9 ].value = 1;
	
	allproduct[ 10 ].weight = 100;
	allproduct[ 10 ].value = 100000;
	
	allproduct[ 11 ].weight = 1000;
	allproduct[ 11 ].value = 100;
	
	allproduct[ 12 ].weight = 10000;
	allproduct[ 12 ].value = 10000;
	
	allproduct[ 13 ].weight = 10;
	allproduct[ 13 ].value = 10;
	
	allproduct[ 14 ].weight = 1;
	allproduct[ 14 ].value = 1000;
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

double calcFitness( bool chrom [ ], int numGenes, individual &ind, vector< product > & allproduct )
{
	ind.fitness = 0;
	
	cout << "N" << char(163) << "mero de genes gerado:  " << numGenes << '\n'; 
	print( chrom, numGenes );
	
	for( int i = 0; i < numGenes; i++ )
		if( chrom[ i ] )
		{
			ind.fenotipo.push_back( allproduct[ i ] );
			
			cout << "C" << char(160) << "lculo do Fitness do indiv" << char(161) << "duo!\n";
			
			print( ind.fenotipo[ ind.fenotipo.size( ) - 1 ] );
			
			print( ind );
			
			if( allproduct[ i ].weight == 0 )
			{
				cout << "ERROR: allproduct[ i ].weight == 0";
				cin >> allproduct[ i ].weight;
			}
			
			ind.fitness += allproduct[ i ].value + 1 / allproduct[ i ].weight;
			
			cout << "Fitness do indiv" << char() << "duo: " << ind.fitness << '\n';
		}
		
}

void print(vector< bool * > &pop, int numGenes)
{
	for ( int i = 0; i < pop.size(); i++ )
		print( pop[ i ], numGenes );
}

void print( const individual &ind )
{
	cout << "Fitness = " << ind.fitness << '\n';
	
	for( int i = 0; i < ind.fenotipo.size( ); i++ )
	{
		print( ind.fenotipo[ i ] );
	}
}

void print( const product &prod )
{
	cout << "Peso: " << prod.weight << '\t' << "Valor: " << prod.value << '\n'; 
}

void print( const bool chr [ ], int  numGenes )
{
	for ( int j = 0; j < numGenes; j++ )
		if( chr[ j ] )
			cout << 1 << '\t';
		else
			cout << 0 << '\t';
		cout << "\n";
}