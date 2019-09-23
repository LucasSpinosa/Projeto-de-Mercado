#ifndef CATEGORIA_HPP
#define CATEGORIA_HPP

#include <iostream>
#include <string>

using namespace std;

//Classe
	class Categoria{

//Atributos
	private:
	string Nome;

//Métodos

	public:
	Categoria();
	Categoria(string Nome);
	~Categoria();
	string getNome();
	void setNome(string Nome);
};

#endif
