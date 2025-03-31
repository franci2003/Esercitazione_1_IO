#include <fstream>
#include <iostream>
#include <iomanip>

// funzione per mappare i valori nel nuovo intervallo
double mapvalue(double x)
{
	return -1+(x-1)*(2+1)/(5-1);
}

int main()
{
	// devo aprire il file
	std::ifstream fstr("data.txt");
	
	// faccio un if per vedere se ci sono problemi con l'apertura del file 
	if(fstr.fail())
	{
		std::cerr << "Non è stato possibile aprire il file" << std::endl;
		return 1;
	}
	
	
	// devo scrivere i risultati su un file di output 
	std::ofstream outstr("result.txt");
	
	// faccio un if per vedere se ci sono problemi con l'apertura del file
	if(outstr.fail())
	{
		std::cerr << "Non è stato possibile aprire il file" << std::endl;
		return 1;
	}
	
	outstr << std::scientific;
	
	
	double val;
	int i=0;
	double sum=0;
	
	// leggo tutti i valori del file, li mappo nel nuovo intervallo e calcolo la media
	while(fstr>>val)
	{
		double mapped_value = mapvalue(val);
		i++; // incremento il contatore
		sum+=mapped_value; // sommo il valore mappato
		double mean=sum/i; // calcolo la media 
		
		// scrivo i valori ottenuti sul file di output
		outstr << std::setw(4) << i << ". " << mean << std::endl;
	}
	
	// chiudo i file
	fstr.close();
	outstr.close();
	
	
	

	
	
	
    return 0;
}
