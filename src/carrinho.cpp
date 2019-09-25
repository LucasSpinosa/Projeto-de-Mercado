#include "carrinho.hpp"
#include <iostream>

using namespace std;

Carrinho::Carrinho(){
    setValorVenda(0.0f);
    setValorDesconto(0.0f);
    setValorFinal(0.0f);
}

Carrinho::Carrinho(vector <Produto> produtos, float ValorVenda, float ValorDesconto, float ValorFinal){
	setProdutos(produtos);
	setValorVenda(ValorVenda);
	setValorDesconto(ValorDesconto);
	setValorFinal(ValorFinal);
}

vector <Produto> Carrinho::getProdutos(){
	return produtos;
}

void Carrinho::setProdutos (vector <Produto> produtos){
	this->produtos = produtos;
}

float Carrinho::getValorVenda(){
	return ValorVenda;
}

void Carrinho::setValorVenda(float ValorVenda){
	this->ValorVenda = ValorVenda;
}

float Carrinho::getValorDesconto(){
	return ValorDesconto;
}

void Carrinho::setValorDesconto(float ValorDesconto){
	this->ValorDesconto = ValorDesconto;
}

float Carrinho::getValorFinal(){
	return ValorFinal;
}

void Carrinho::setValorFinal(float ValorFinal){
	this->ValorFinal = ValorFinal;
}
