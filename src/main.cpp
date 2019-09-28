#include <iostream>
#include <fstream>
#include "produto.hpp"
#include "categoria.hpp"
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include "cliente.hpp"

using namespace std;

string getString()
{
	string valor;
	getline(cin, valor);
	return valor;
}

template <typename T1>

T1 getInput()
{
	while (true)
	{
		T1 valor;
		cin >> valor;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Entrada inválida! Insira novamente: " << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			return valor;
		}
	}
}

void Estoque();
void Venda();

int main()
{

	int opcao_programa = -9;

	cout << "Bem vindo ao gerenciador do mercado!" << endl;
	cout << "Escolha entre uma dessas opções abaixo!" << endl;
	cout << endl;

	while (opcao_programa != 0)
	{
		cout << "(1) = Modo Venda" << endl;
		cout << "(2) = Modo Recomendação" << endl;
		cout << "(3) = Modo Estoque" << endl;
		cout << "(0) = Sair" << endl
			 << endl;

		cout << "Insira sua opção: ";
		opcao_programa = getInput<int>();
		cout << endl;

		switch (opcao_programa)
		{

		case 1:
		{
			Venda();
			break;
		}

		case 2:
		{

			break;
		}
		case 3:
		{
			Estoque();
			break;
		}

		case 0:
			break;

		default:
			cout << "Opção inválida!" << endl
				 << endl;
		}
	}

	return 0;
}

//Função do modo Venda
void Venda(){

fstream arquivo;

			int opcao_venda = -1;

			while (opcao_venda != 0)
			{
				cout << "Modo Venda - Opções" << endl << endl;
				cout << "(1) = Listar clientes" << endl;
				cout << "(2) = Visualizar dados de um cliente" << endl;
				cout << "(3) = Realizar venda" << endl;
				cout << "(0) = Sair" << endl << endl;

				cout << "Insira sua opção: ";
				opcao_venda = getInput<int>();
				cout << endl;

				switch (opcao_venda)
				{
				case 1:
				{
					arquivo.open("doc/Clientes/Clientes.txt", ios::in);

					if (arquivo.is_open())
					{
						string linha;
						
						cout << "--------------------------------------------------------" << endl;
						while (getline(arquivo, linha))
						{
							cout << linha << endl;
						}
						cout << "-------------------------------------------------------------" << endl << endl;

						arquivo.close();
					}

					else
					{
					cout << endl << "Não há clientes registrados. Não foi possível abrir o arquivo" << endl << endl;
					}

					break;
				}

				case 2:
				{
					string Nome_cliente;

					cout << "Insira o nome do cliente: ";
					Nome_cliente = getString();

					cout << endl;

					arquivo.open("doc/Clientes/" + Nome_cliente + ".txt");
					if (arquivo.is_open())
					{			
						string linhas_lidas;
						for (int i = 0; i < 6; i++)
						{
							getline(arquivo, linhas_lidas);
							if(i == 0){
								cout << "Nome: " + linhas_lidas << endl;
							}

							if(i == 1){
								cout << "Idade: " + linhas_lidas << endl;
							}

							if(i == 2){
								cout << "Telefone: " + linhas_lidas << endl;
							}

							if(i == 3){
								cout << "Email: " + linhas_lidas << endl;
							}

							if(i == 4){
								cout << "CPF: " + linhas_lidas << endl;
							}

							if(i == 5){
								cout << "Sócio: " + linhas_lidas << endl << endl;
							}
						}
						arquivo.close();
					}

					else
					{
					cout << "Não foi possível exibir os dados do cliente, pois ele não está cadastrado." << endl << endl;
					}

					break;
				}

				case 3:
				{

					string linhas_do_arquivo;

					//Dados do Cliente
					string Nome_cliente;
					int Idade;
					string Telefone;
					string Email;
					string CPF;
					string Socio = "Exemplo";

					int verificacao = 0;
					int verificacao_2 = 0;

					cout << "Por favor, insira o nome do cliente: ";
					Nome_cliente = getString();
					cout << endl;

					arquivo.open("doc/Clientes/Clientes.txt", ios::in);
					if (arquivo.is_open())
					{
						string linha;

						while (getline(arquivo, linha))
						{
							if (linha == Nome_cliente)
							{
								verificacao++;
								arquivo.close();
							}
						}
						arquivo.close();
					}

					if (verificacao == 0)
					{
					arquivo.open("doc/Clientes/Clientes.txt", ios:: out | ios::app);
					arquivo << Nome_cliente << endl;
					arquivo.close();

					cout << "Cliente não encontrado. Realizando cadastrado." << endl << endl;

					cout << "Informe a idade do cliente: ";
					Idade = getInput <int> ();

					cout << "Informe o telefone do cliente: ";
					Telefone = getString();

					cout << "Informe o email do cliente: ";
					Email = getString();

					cout << "Informe o CPF do cliente: ";
					CPF = getString();

					cout << "O cliente deseja se tornar sócio?" << endl;
					cout << "Responda com Sim ou Não: ";
					Socio = getString();
					
					cout << endl;
					
					Cliente cliente;

					arquivo.open("doc/Clientes/" + Nome_cliente + ".txt", ios::out);
					arquivo << cliente.getNome() << endl;
					arquivo << cliente.getIdade() << endl;
					arquivo << cliente.getTelefone() << endl;
					arquivo << cliente.getEmail() << endl;
					arquivo << cliente.getCPF() << endl;
					arquivo << cliente.getSocio() << endl;
					}

					else if (verificacao == 1){
						arquivo.open("doc/Clientes" + Nome_cliente + ".txt", ios::in);
						
						Cliente cliente;

						string linhas_lidas;

						for(int i = 0; i < 6; i++){
							getline(arquivo, linhas_lidas);
							if (i == 0){
								cliente.setNome(linhas_lidas);
								cout << i << ": " << linhas_lidas;
							}

							if(i == 1){
								cliente.setIdade(0);
								cout << i << ": " << linhas_lidas;
							}

							if(i == 2){
								cliente.setTelefone(linhas_lidas);
								cout << i << ": " << linhas_lidas;
							}

							if(i == 3){
								cliente.setEmail(linhas_lidas);
								cout << i << ": " << linhas_lidas;
							}

							if(i == 4){
								cliente.setCPF(linhas_lidas);
								cout << i << ": " << linhas_lidas;
							}

							if(i == 5){
								cliente.setSocio(linhas_lidas);
								if(linhas_do_arquivo == "Não"){
									verificacao_2++;
								}
								cout << i << ": " << linhas_lidas;
							}
						}
						arquivo.close();
						
						if(verificacao_2 != 0){
							cout << "Esse cliente não é sócio. Ele deseja se tornar um?" << endl;
							cout << "Responda Sim ou Não: ";
							
							Socio = getString();
						
							cout << endl;

						if(Socio == "Sim"){
							cliente.setSocio("Sim");
							
							vector <string> linhas;
							arquivo.open("doc/Clientes" + Nome_cliente + ".txt", ios::in);

						while(getline(arquivo, linhas_do_arquivo)){
							linhas.push_back(linhas_do_arquivo);
						}
						arquivo.close();

						arquivo.open("doc/Clientes" + Nome_cliente + ".txt", ios::out);
						
						for(int i = 0; i < linhas.size(); i++){
							if(i == 5){
								linhas[i] = "Sim";
							}
							arquivo << linhas[i];
						}
						}
					}
				}
					break;
				}
				
				case 0:
					break;

				default:
					cout << "Opção inválida!" << endl << endl;
					break;
				}
			}
		}

//Função do modo Estoque
void Estoque(){
		fstream arquivo, arquivo2;

			int opcao_estoque = -1;

			while (opcao_estoque != 0)
			{
				cout << "Modo Estoque - Opções" << endl << endl;
				cout << "(1) = Registrar categoria" << endl;
				cout << "(2) = Listar categorias" << endl;
				cout << "(3) = Registrar produtos" << endl;
				cout << "(4) = Listar produtos" << endl; 
				cout << "(5) = Editar quantidade de um produto" << endl; 
				cout << "(6) = Editar preço de um produto" << endl; 
				cout << "(0) = Sair" << endl << endl;

				cout << "Insira sua opção: ";
				opcao_estoque = getInput<int>();
				cout << endl;

				switch (opcao_estoque)
				{
				case 1:
				{
					int leitura = 0;
					string Nome_categoria;

					cout << "Nome da categoria: ";
					Nome_categoria = getString();

					arquivo.open("doc/Estoque/Categorias.txt", ios::in);
					if (arquivo.is_open())
					{
						string linha;

						while (getline(arquivo, linha))
						{
							if (linha == Nome_categoria)
							{
								leitura++;
								arquivo.close();
							}
						}
						arquivo.close();
					}

					if (leitura != 0)
					{
						cout << endl
							 << "Categoria já registrada!" << endl
							 << endl;
					}

					else
					{
						arquivo.open("doc/Estoque/Categorias.txt", ios::out | ios::app);

						Categoria categoria(Nome_categoria);

						arquivo << categoria.getNome() << endl;

						cout << endl;

						arquivo.close();
					}

					break;
				}

				case 2:
				{
					arquivo.open("doc/Estoque/Categorias.txt", ios::in);

					if (arquivo.is_open())
					{
						string linha;
						cout << "Categorias registradas" << endl
							 << endl;

						cout << "--------------------------------------------------------" << endl;
						while (getline(arquivo, linha))
						{
							cout << linha << endl;
						}
						cout << "-------------------------------------------------------------" << endl
							 << endl;
					}

					else
					{
						cout << "Não foi possível ler o arquivo. Tente registrar uma categoria e tente novamente!" << endl
							 << endl;
					}

					arquivo.close();

					break;
				}

				case 3:
				{

					Produto produto;
					vector<Categoria> categorias;
					Categoria categoria;
					string Nome_categoria;
					string Nome_produto;
					int Quantidade_produto;
					int Quantidade_categorias;
					float Preco;

					int leitura = 0;
					int leitura_2 = 0;
					int leitura_3 = 0;

					cout << "Insira o nome do produto: ";
					Nome_produto = getString();
					produto.setNome(Nome_produto);

					arquivo.open("doc/Estoque/Estoque.txt", ios::in);
					if (arquivo.is_open())
					{
						string linha;

						while (getline(arquivo, linha))
						{
							if (linha == Nome_produto)
							{
								leitura++;
								arquivo.close();
							}
						}
						arquivo.close();
					}

					if (leitura != 0)
					{
						cout << endl
							 << "Produto já registrado!" << endl
							 << endl;
					}

					else
					{

						cout << "Insira o número de categorias do produto: ";
						Quantidade_categorias = getInput<int>();

						cout << endl;

						for (int i = 0; i < Quantidade_categorias; i++)
						{

							cout << "Insira a categoria: ";
							Nome_categoria = getString();

							arquivo.open("doc/Estoque/Categorias.txt", ios::in);
							if (arquivo.is_open())
							{
								string linha;

								while (getline(arquivo, linha))
								{
									if (linha == Nome_categoria)
									{
										leitura_2++;
										arquivo.close();
									}
								}
								arquivo.close();
							}

							if (leitura_2 == 0)
							{
								leitura_3++;
								cout << endl
									 << "Categoria não registrada! Registre ela primeiro e tente novamente!" << endl
									 << endl;
									 break;
							}

							else if (leitura_2 != 0)
							{

								categoria.setNome(Nome_categoria);
								categorias.push_back(categoria);
							}
						}
						
						if(leitura_3 != 0){
							break;
						}

						else if (leitura_3 == 0){
						produto.setCategoria(categorias);

						arquivo.open("doc/Estoque/Estoque.txt", ios::out | ios::app);
						arquivo << produto.getNome() << endl;
						arquivo.close();

						cout << endl;

						arquivo.open("doc/Estoque/" + produto.getNome() + ".txt", ios::out | ios::app);

						cout << "Insira a quantidade do produto: ";
						Quantidade_produto = getInput<int>();
						produto.setQuantidade(Quantidade_produto);
						arquivo << produto.getQuantidade() << endl;

						cout << "Insira o preço do produto: ";
						Preco = getInput<float>();
						produto.setPreco(Preco);
						arquivo << fixed << setprecision(2) << produto.getPreco() << endl;

						for (int i = 0; i < categorias.size(); i++)
						{
							arquivo << categorias[i].getNome() << endl;
						}

						cout << endl;
					}

					arquivo.close();
				}
					break;
				}

				case 4:
				{
					arquivo.open("doc/Estoque/Estoque.txt", ios::in);

					cout << "Produtos registrados" << endl
						 << endl;

					if (arquivo.is_open())
					{
						string linha_estoque;
						string linha_produto;
						vector <string> linhas_lidas;

						cout << "-------------------------------------------------------------" << endl;
						while (getline(arquivo, linha_estoque))
						{
							cout << linha_estoque << endl;
							arquivo2.open("doc/Estoque/" + linha_estoque + ".txt", ios::in);

							for(int i = 0; i <= 1; i++){
								getline(arquivo2, linha_produto);
								if (i == 0)
								{
									cout << "Quantidade de " + linha_estoque + ": " + linha_produto << endl;
								}

								if(i == 1){
									cout << "Preço: R$ " + linha_produto << endl << endl;
								}	
							}

							arquivo2.close();
						}
						cout << "-------------------------------------------------------------" << endl
							 << endl;
					}

					else
					{
						cout << "Não foi possível ler o arquivo. Tente registrar um produto e tente novamente!" << endl
							 << endl;
					}

					arquivo.close();

					break;
				}

				case 5:
				{
					vector<string> linhas;
					string Nome_produto;
					int Quantidade;
					int leitura = 0;

					arquivo.open("doc/Estoque/Estoque.txt", ios::in);
					if (arquivo.is_open())
					{
						arquivo.close();
					}

					else
					{
						cout << "Não foi possível abrir o arquivo. Registre um produto e tente novamente!" << endl
							 << endl;
						break;
					}

					cout << "Insira o nome do produto: ";
					Nome_produto = getString();

					arquivo.open("doc/Estoque/"+ Nome_produto + ".txt", ios::in);
					if (arquivo.is_open())
					{
						leitura++;
						string linha;
						while (getline(arquivo, linha))
						{
							linhas.push_back(linha);
						}
						arquivo.close();
					}

					if (leitura == 0)
					{
						cout << endl
							 << "Produto não registrado!" << endl
							 << endl;
						break;
					}

					cout << "Informe a quantidade nova do produto: ";
					Quantidade = getInput<int>();

					arquivo.open("doc/Estoque/"+ Nome_produto + ".txt", ios::out);
					
					for(int i = 0; i < linhas.size(); i++){
						if(i == 0){
							arquivo << to_string(Quantidade) << endl;
						}
						else{
							arquivo << linhas[i] << endl;
						}
					}

					arquivo.close();

					cout << endl;

					break;
				}

			case 6:
				{

					vector<string> linhas;
					string Nome_produto;
					float Preco_novo;
					int leitura = 0;

					arquivo.open("doc/Estoque/Estoque.txt", ios::in);
					if (arquivo.is_open())
					{
						arquivo.close();
					}

					else
					{
						cout << "Não foi possível abrir o arquivo. Registre um produto e tente novamente!" << endl
							 << endl;
						break;
					}

					cout << "Insira o nome do produto: ";
					Nome_produto = getString();

					arquivo.open("doc/Estoque/"+ Nome_produto + ".txt", ios::in);
					if (arquivo.is_open())
					{
						leitura++;
						string linha;
						while (getline(arquivo, linha))
						{
							linhas.push_back(linha);
						}
						arquivo.close();
					}

					if (leitura == 0)
					{
						cout << endl
							 << "Produto não registrado!" << endl
							 << endl;
						break;
					}

					cout << "Informe o preço novo do produto: ";
					Preco_novo = getInput<float>();

					arquivo.open("doc/Estoque/"+ Nome_produto + ".txt", ios::out);
					
					for(int i = 0; i < linhas.size(); i++){
						if(i == 1){
							arquivo << fixed << setprecision(2) << Preco_novo << endl;
						}
						else{
							arquivo << linhas[i] << endl;
						}
					}

					arquivo.close();

					cout << endl;

					break;
				}

				case 0:
					break;

				default:
					cout << "Opção inválida!" << endl
						 << endl;
					break;
				}
			}
		}