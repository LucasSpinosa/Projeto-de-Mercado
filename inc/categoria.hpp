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
	string Tipos_de_produtos;

//Métodos

	public:
	Categoria();
	Categoria(string Nome);
	Categoria(string Nome, string Tipos_de_produtos);
	~Categoria();
	string getNome();
	void setNome(string Nome);
	string getTipos();
	void setTipos(string Tipos_de_produtos);
};

#endif
