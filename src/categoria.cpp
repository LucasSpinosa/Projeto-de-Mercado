#include <iostream>
#include "categoria.hpp"

using namespace std;

Categoria::Categoria(){
	setNome("");
}

Categoria::Categoria(string Nome){
	setNome(Nome);
}


Categoria::~Categoria(){
}

string Categoria::getNome(){
	return Nome;
}

void Categoria::setNome(string Nome){
	this->Nome = Nome;
}
