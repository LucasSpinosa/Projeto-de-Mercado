#include <string>
#include <iostream>
#include "produto.hpp"

using namespace std;

Produto::Produto(){
	setNome("");
	setQuantidade(0);
	setPreco(0.0f);
}

Produto::Produto(vector<Categoria> categorias, string Nome, int Quantidade, float Preco){
	setCategoria(categorias);
	setNome(Nome);
	setQuantidade(Quantidade);
	setPreco(Preco);
}


Produto::~Produto(){
}

vector <Categoria> Produto::getCategoria(){
	return categorias;
   }

void Produto::setCategoria (vector <Categoria> categorias){
	this->categorias = categorias;
}

string Produto::getNome(){
	return Nome;
}

void Produto::setNome(string Nome){
	this->Nome = Nome;
}

int Produto::getQuantidade(){
	return Quantidade;
}

void Produto::setQuantidade(int Quantidade){
	this->Quantidade = Quantidade;
}


float Produto::getPreco(){
	return Preco;
}

void Produto::setPreco(float Preco){
	this->Preco = Preco;
}
