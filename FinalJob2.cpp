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
void print( const vector< individual > &, bool );
void print( const individual &, int, bool );
void print( const product & );
void print( const bool [ ], int );
bool generateGene( );
void selectInd( vector< individual > &, vector< int > &,  int, bool = true );
void crossover( vector< bool * > &, const vector< bool * > &, const vector< int > &, int , int );
void mutation( vector< bool * > &, int , int );
int getBestFitness( vector< individual > & );
void createPopulation( vector< bool * > &, int );
void calcFitness( bool [ ], int, individual &, vector< product > & );
void setallproduct( vector< product > & );


int main()
{
	int mutationRate = 10;
	int ring = 3;
	int sizePopulation = 4;
	int numGenes = 5;
	int numGenerations = 10;
	int crossoverRate = 80;	
	vector< product > allproduct( 15 );
	vector< bool * > population( sizePopulation );
	vector< bool * > populationSelected( sizePopulation );
	vector< individual > popDecod( sizePopulation );
	vector< int > selectedIndividuals( sizePopulation );
	const double MAXWEIGHT = 10000; //getMaxWeight( allproduct );
	const double MAXVALUE = 1000; //getMaxWeight( allproduct );
		
	cout << "Programa para calcular o fitness de um gene usando aloca" << char(135) << char(198) << "o din" << char(131) << "mica de mem" << char(162) << "ria!\n\n";
	
	int k = 0;
	while( k < 1 )
	{
		k++;
		
		srand(( int ) time( 0 ));
		
		cout << "Gerando gene: \n\n";
		
		createPopulation( population, numGenes );
		print(population, numGenes);
		setallproduct( allproduct );
		
//		cout << "\nSele" << char(135) << char(198) << "o, crusamento, e muta" << char(135) << char(198) << "o dos genes!\n";
//		
//		for( int n = 0; n < sizePopulation; n++ )
//		{
//			 calcFitness( population[ n ], numGenes, popDecod[ n ], allproduct );
//		}
//		
//		for ( int i = 0; i < numGenerations; i++ )
//		{
//			cout << "\nIniciando processo de sele" << char(135) << char(198) << "o\n\n";
//			print( popDecod, false );
//			selectInd( popDecod, selectedIndividuals, ring );
//			cout << "Iniciando o processo de cruzamento\n";
//			crossover( populationSelected, population, selectedIndividuals, numGenes, crossoverRate );
//			cout << "Iniciando o processo de mutacao\n";
//			mutation( populationSelected, numGenes, mutationRate );
//			
//			for( int i = 0; i < population.size( ); i++ )
//			{
//				*population[ i ] = *populationSelected[ i ];
//				calcFitness( population[ i ], numGenes, popDecod[ i ], allproduct );
//				
//				delete [ ] populationSelected[ i ];
//				populationSelected[ i ] = 0;
//			}
//			
//			//cout << "Gera" << char(135) << char(198) << "o " << i << '\t' << "Melhor fitness: " << popDecod[ getBestFitness( popDecod ) ].fitness << '\n';
//			cout << "\n=========================================\n";
//		}
//		
//		for( unsigned int n = 0; n < population.size( ); n++ )
//		{
//			delete [ ] population[ n ];
//		}
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

void createPopulation( vector< bool * > &pop, int numGenes )
{
	for ( unsigned int i = 0; i < pop.size( ); i++ )
	{
		pop[ i ] =  new bool[ numGenes ];
		for ( int j = 0; j < numGenes; j++ )
			pop[ i ][ j ] = generateGene( );
	}
}

bool generateGene()
{
	if( ( rand() % 100 + 1 ) <= 50 )
		return false;
		else return true;
}

void selectInd( vector< individual > &popDecod, vector< int > &selectedIndividuals,  int ring )
{
	int n;
	unsigned int winner;
	unsigned int competitor;
	for ( unsigned int i = 0; i < popDecod.size( ); i++ )
		{
			n = ring;
			winner = rand( ) % popDecod.size( );			
			while( n > 0 )
			{	
				competitor = rand( ) % popDecod.size( );
				
				if( popDecod[ competitor ].fitness > popDecod[ winner ].fitness )
				{
					winner = competitor;
				}
				
				n--;
			}
			
			selectedIndividuals[ i ] = winner;
		}
}


void crossover( vector< bool * > &popSel, const vector< bool * > &pop, const vector< int > &selectedIndividuals, int numGenes, int crossoverRate )
{
	bool temp;
	unsigned int cutPoint;
	
	if ( rand( ) % 100 + 1 < crossoverRate )
		cutPoint = rand( ) % numGenes + 1;
	else
		cutPoint = pop.size( );
	
	
	for( int i = 0; i < pop.size( ); i += 2 )
	{
		popSel[ i ]     =  new bool[ numGenes ];
		popSel[ i + 1 ] =  new bool[ numGenes ];
		for ( int j = 0; j < numGenes; j++ )
		{
			if( j < cutPoint )
			{
				popSel[ i ][ j ] = pop[ selectedIndividuals[ i ] ];
				popSel[ i + 1 ][ j ] = pop[ selectedIndividuals[ i + 1 ] ];
			}
			else
			{
				popSel[ i ][ j ] = pop[ selectedIndividuals[ i + 1 ] ];
				popSel[ i + 1 ][ j ] = pop[ selectedIndividuals[ i ] ];
			}
		}
	}
}

void mutation( vector< bool * > &popSel, int numGenes, int mutationRate )
{
	for( int i = 0; i < popSel.size( ); i++ )
	{
		for ( int j = 0; j < numGenes; j++ )
			if ( rand( ) % 100 + 1 < mutationRate )
			{
				if ( popSel[ i ][ j ] )
					popSel[ i ][ j ] = false;
				else
					popSel[ i ][ j ] = true;
			}
	}
}

int getBestFitness( vector< individual > & popDecod )
{
	unsigned int indexBest = 0;	
	for ( unsigned int i = 1; i < popDecod.size(); i++ )
		if ( popDecod[ i ].fitness > popDecod[ indexBest ].fitness )
			indexBest = i;
			
	return indexBest;
}

void calcFitness( bool chrom [ ], int numGenes, individual &ind, vector< product > & allproduct, const double MAXWEIGHT, const double MAXVALUE )
{
	ind.fitness = 0;
	
	for( int i = 0; i < numGenes; i++ )
		if( chrom[ i ] )
		{
			ind.fenotipo.push_back( allproduct[ i ] );
			
			if( allproduct[ i ].weight == 0 )
			{
				cout << "ERROR: allproduct[ i ].weight == 0";
				cin >> allproduct[ i ].weight;
			}
			
			ind.fitness += allproduct[ i ].value/MAXVALUE + MAXWEIGHT/allproduct[ i ].weight;
		}
}

void print(vector< bool * > &pop, int numGenes)
{
	for ( unsigned int i = 0; i < pop.size(); i++ )
		print( pop[ i ], numGenes );
}

void print( const individual &ind, int indexInd, bool isPrintFenotipo )
{
	cout << "Individuo " <<  indexInd << '\t' << "Fitness = " << ind.fitness << "\n\n";
	
	if( isPrintFenotipo )
		for( unsigned int i = 0; i < ind.fenotipo.size( ); i++ )
			print( ind.fenotipo[ i ] );	
}

void print( const product &prod )
{
	cout << "Peso: " << prod.weight << '\t' << "Valor: " << prod.value << "\n\n"; 
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

void print( const vector< individual > &popDecod, bool isPrintFenotipo )
{
	for ( unsigned int i = 0; i < popDecod.size( ); i++ )
		print( popDecod[ i ], i,  isPrintFenotipo);	
}
