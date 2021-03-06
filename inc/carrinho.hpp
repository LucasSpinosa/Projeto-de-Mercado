#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <iostream>
#include "produto.hpp"
#include <vector>

//Classe
class Carrinho{

//Atributos
private:
vector <Produto> produtos;
float ValorVenda;
float ValorDesconto;
float ValorFinal;


//Métodos Construtores e Destrutores
public:
Carrinho();
Carrinho(vector <Produto> produtos, float ValorVenda, float ValorDesconto, float ValorFinal);
~Carrinho();

//Métodos Acessores
vector <Produto> getProdutos();
void setProdutos (vector <Produto> produtos);

float getValorVenda();
void setValorVenda(float ValorVenda);

float getValorDesconto();
void setValorDesconto(float ValorDesconto);

float getValorFinal();
void setValorFinal(float ValorFinal);

void imprime_dados();
};


#endif
