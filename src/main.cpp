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
fstream arquivo1, arquivo2, arquivo3;
			string linhas_do_arquivo;

			string Nome_cliente;
			int Idade;
			string Email;
			string CPF;
			string Socio;

			int verificacao = 0;
			int verificacao2 = 0;
			
			cout << "Por favor, insira o nome do cliente: ";
			Nome_cliente = getString();
			cout << endl;

			//Abrindo o arquivo de Clientes para ver se o nome consta na lista.
			arquivo1.open("doc/Clientes/Clientes.txt", ios::in);

			//Se conseguir abrir
			if (arquivo1.is_open()){
				string linhas_do_arquivo;
				while(getline(arquivo1, linhas_do_arquivo)){
					if(linhas_do_arquivo == Nome_cliente){
						verificacao++;
						arquivo1.close();
					}
				}
				arquivo1.close();
			}

			//Se não abrir ou se o cliente não consta no banco de dados
			if(verificacao == 0){

				//Adicionando cliente no banco de dados de clientes
				arquivo1.open("doc/Clientes/Clientes.txt", ios:: out | ios::app);
				arquivo1 << Nome_cliente << endl;
				arquivo1.close();

				cout << "Cliente não encontrado! Realizando cadastro..." << endl << endl;

				cout << "Informe a idade do cliente: ";
				Idade = getInput <int> ();

				cout << "Informe o email do cliente: ";
				Email = getString();

				cout << "Informe o CPF do cliente (somente números): ";
				CPF = getString();
				
				cout << endl << "O cliente deseja se tornar sócio?" << endl;
				cout << "Responda Sim ou Não: ";
				Socio = getString();
				cout << endl;

				Cliente cliente (Nome_cliente, Idade, Email, CPF);

				//Adicionando cliente no banco de dados de sócios se ele quiser ser sócio
				if(Socio == "Sim"){
				arquivo2.open("doc/Clientes/Sócios.txt", ios::out | ios::app);
				arquivo2 << cliente.getNome() << endl;
				arquivo2.close();
				}

				//Criando arquivo do cliente
				arquivo3.open("doc/Clientes/" + cliente.getNome() + ".txt", ios::out | ios::app);
				arquivo3 << cliente.getNome() << endl;
				arquivo3 << cliente.getIdade() << endl;
				arquivo3 << cliente.getEmail() << endl;
				arquivo3 << cliente.getCPF() << endl;
				arquivo3.close();
			}

			//Se abrir
			//Verificando se o cliente é sócio
			else if(verificacao != 0){
				arquivo1.open("doc/Clientes/Sócios.txt", ios::in);
				if (arquivo1.is_open()){
				string linhas_do_arquivo;
				while(getline(arquivo1, linhas_do_arquivo)){
					if(linhas_do_arquivo == Nome_cliente){
						verificacao2++;
						arquivo1.close();
					}
				}
				arquivo1.close();
			}
			if(verificacao2 == 0){
					cout << "Esse cliente não é sócio. Ele deseja se tornar um?" << endl;
					cout << "Responda Sim ou Não: ";
					Socio = getString();

					cout << endl;

					if(Socio == "Sim"){
						arquivo1.open("doc/Clientes/Sócios.txt", ios::out | ios::app);
						arquivo1 << Nome_cliente << endl;
						arquivo1.close();
					}
				}
			}
}	


//Função do modo Estoque
void Estoque(){
		fstream arquivo, arquivo2;

			int opcao_venda = -1;

			while (opcao_venda != 0)
			{
				cout << "Modo Venda - Opções" << endl
					 << endl;
				cout << "(1) = Registrar categoria" << endl;
				cout << "(2) = Listar categorias" << endl;
				cout << "(3) = Registrar produtos" << endl;
				cout << "(4) = Listar produtos" << endl; 
				cout << "(5) = Editar quantidade de um produto" << endl; 
				cout << "(6) = Editar preço de um produto" << endl; 
				cout << "(0) = Sair" << endl << endl;

				cout << "Insira sua opção: ";
				opcao_venda = getInput<int>();
				cout << endl;

				switch (opcao_venda)
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