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
	string Nome;
	int Idade;
	string Telefone;
	string Email;
	string CPF;
	string Socio;

//Métodos
public:

	Cliente();
	Cliente(string Nome, int Idade, string Telefone, string Email, string CPF, string Socio);
	~Cliente();

	string getNome();
	void setNome(string Nome);

	int getIdade();
	void setIdade(int Idade);

	string getTelefone ();
	void setTelefone(string Telefone);

	string getEmail();
	void setEmail(string Email);

	string getCPF();
	void setCPF(string CPF);

	string getSocio();
	void setSocio(string Socio);
};

#endif
