#include <iostream>
#include <vector>

bool vis[26];

void rebootVis(int tam){
	for(int i = 0; i <=  tam; i++){
		vis[i] = false;
	}
}

void dfs(int v, std:: vector <int> list[]){
	vis[v] = true;
	for(int i : list[v]){
		if(!vis[i]){
			dfs(i, list);
		}
	}
}

int main(void){
	char letraMaxima;
	std:: string letras;
	int casos, tam, cont;
	bool ver = false;
	scanf("%i", &casos);
	std:: getline(std:: cin, letras);
	std:: cin.ignore();
	for(int i = 0; i < casos; i++){
		if(ver == true){
			printf("\n\n");
		}
		scanf("%c", &letraMaxima);
		tam = letraMaxima - 65;
		rebootVis(tam);
		std:: cin.ignore();
		std:: vector <int> listaDeAdj[tam + 5];
		std:: getline(std:: cin, letras);
		while(letras != "\0"){
			listaDeAdj[letras[0] - 65].push_back(letras[1] - 65);
			listaDeAdj[letras[1] - 65].push_back(letras[0] - 65);
			std:: getline(std:: cin, letras);
		}
		cont = 0;
		for(int j = 0; j <= tam; j++){
			if(!vis[j]){
				dfs(j, listaDeAdj);
				cont++;
			}
		}
		printf("%i", cont);
		ver = true;
	}
	printf("\n");
}
