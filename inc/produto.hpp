#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>
#include <iostream>
#include <vector>
#include "categoria.hpp"

using namespace std;

//Classe
class Produto{

//Atributos
private:
	vector <Categoria> categorias;
	string Nome;
	int Quantidade;
	float Preco;

//Métodos
public:

	Produto();
	Produto(vector<Categoria> categorias, string Nome, int Quantidade, float Preco);
	~Produto();

	vector <Categoria> getCategoria();
	void setCategoria (vector <Categoria> categorias);
	
	string getNome();
	void setNome(string Nome);

	int getQuantidade();
	void setQuantidade(int Quantidade);

	float getPreco();
	void setPreco(float Preco);
};

#endif
