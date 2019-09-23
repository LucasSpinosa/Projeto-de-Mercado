#include <string>
#include <iostream>
#include "cliente.hpp"

using namespace std;

Cliente::Cliente(){
	setNome("");
	setIdade(0);
	setEmail("");
	setCPF(0);
	setData_de_Cadastro("");
	setSocio("");
}

Cliente::~Cliente(){
}

string Cliente::getNome(){
	return Nome;
}

void Cliente::setNome(string Nome){
	this->Nome = Nome;
}

int Cliente::getIdade(){
	return Idade;
}

void Cliente::setIdade(int Idade){
	this->Idade = Idade;
}

string Cliente::getEmail(){
	return Email;
}

void Cliente::setEmail(string Email){
	this->Email = Email;
}

long int Cliente::getCPF(){
	return CPF;
}

void Cliente::setCPF(long int CPF){
	this->CPF = CPF;
}

string Cliente::getData_de_Cadastro(){
	return Data_de_Cadastro;
}

void Cliente::setData_de_Cadastro(string Data_de_Cadastro){
	this->Data_de_Cadastro = Data_de_Cadastro;
}

string Cliente::getSocio(){
	return Socio;
}

void Cliente::setSocio(string Socio){
	this->Socio = Socio;
}
