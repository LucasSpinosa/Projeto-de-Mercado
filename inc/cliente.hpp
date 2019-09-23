#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <iostream>

using namespace std;

//Classe
class Cliente{

//Atributos
private:
	string Nome;
	int Idade;
	string Email;
	long int CPF;
	string Data_de_Cadastro;
	string Socio;

//Métodos
public:
	Cliente();
	~Cliente();

	string getNome();
	void setNome(string Nome);

	int getIdade();
	void setIdade(int Idade);

	string getEmail();
	void setEmail(string Email);

	long int getCPF();
	void setCPF(long int CPF);

	string getData_de_Cadastro();
	void setData_de_Cadastro(string Data_de_Cadastro);

	string getSocio();
	void setSocio(string Socio);

};

#endif
