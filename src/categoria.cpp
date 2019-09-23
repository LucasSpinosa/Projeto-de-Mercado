#include <iostream>
#include "categoria.hpp"

using namespace std;

Categoria::Categoria(){
	setNome("");
	setTipos("");
}

Categoria::Categoria(string Nome){
	setNome(Nome);
	setTipos("");
}

Categoria::Categoria(string Nome, string Tipos_de_produtos){
	setNome(Nome);
	setTipos(Tipos_de_produtos);
}

Categoria::~Categoria(){
}

string Categoria::getNome(){
	return Nome;
}

void Categoria::setNome(string Nome){
	this->Nome = Nome;
}

string Categoria::getTipos(){
	return Tipos_de_produtos;
}

void Categoria::setTipos(string Tipos_de_produtos){
	this->Tipos_de_produtos = Tipos_de_produtos;
}


