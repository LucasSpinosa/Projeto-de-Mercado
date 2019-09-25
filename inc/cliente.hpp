#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <iostream>
#include <vector>
#include "categoria.hpp"

using namespace std;

//Classe
class Cliente{

//Atributos
private:
	vector <Categoria> categorias;
	string Nome;
	int Idade;
	string Email;
	string CPF;

//Métodos
public:

	Cliente();
	Cliente(string Nome, int Idade, string Email, string CPF);
	~Cliente();

	vector <Categoria> getCategoria();
	void setCategoria (vector <Categoria> categorias);

	string getNome();
	void setNome(string Nome);

	int getIdade();
	void setIdade(int Idade);

	string getEmail();
	void setEmail(string Email);

	string getCPF();
	void setCPF(string CPF);
};

#endif
