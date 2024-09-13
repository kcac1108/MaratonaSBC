#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
		
	cin >> N;
	long long lista[N], maior = 0, qtdbits;	// Lista dos numeros de entrada
	
	for(int i = 0; i < N; i++)
	{
		cin >> lista[i];
		
		if(lista[i] > maior)
		{
			maior = lista[i];
		}
	}
	
	qtdbits = floor(log2(maior))+1;	// Quantidade de bits do maior numero da lista
	long long potencias[qtdbits], pote;
	
	for(int i = 0; i < qtdbits; i++)
	{
		potencias[i] = 0;
	}
	
	for(int i = 0; i < N; i++)
	{
		while(lista[i] != 0)
		{
			pote = floor((double)log2((double)lista[i]));	// Descobre o lugar onde o numero vai entrar na lista
			potencias[pote] += pow(2, pote);
			lista[i] -= pow(2, pote);
		}	
	}
	
	for(int i = 0; i < N; i++)
	{
		int resp = 0;
		
		for(long long j = 0; j < qtdbits; j++)
		{
			if(potencias[j] != 0)
			{
				resp += pow(2, j);
				potencias[j] -= pow(2, j);
			}
		}
		cout << resp << " ";
	}
	cout << endl;
	
	return 0;
}
