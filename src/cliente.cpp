#include <string>
#include <iostream>
#include "cliente.hpp"

using namespace std;

Cliente::Cliente(){
	setNome("");
	setIdade(0);
	setEmail("");
	setCPF("");
	setSocio("");
}

Cliente::Cliente(string Nome, int Idade, string Telefone, string Email, string CPF, string Socio){
	setNome(Nome);
	setIdade(Idade);
	setEmail(Email);
	setTelefone(Telefone);
	setCPF(CPF);
	setSocio(Socio);
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

string Cliente::getTelefone(){
	return Telefone;
}

void Cliente::setTelefone(string Telefone){
	this->Telefone = Telefone;
}

string Cliente::getEmail(){
	return Email;
}
	
void Cliente::setEmail(string Email){
	this->Email = Email;
}

string Cliente::getCPF(){
	return CPF;
}

void Cliente::setCPF(string CPF){
	this->CPF = CPF;
}

string Cliente::getSocio(){
	return Socio;
}

void Cliente::setSocio(string Socio){
	this->Socio = Socio;
}