#include <iostream>
#include <fstream>
#include "produto.hpp"
#include "categoria.hpp"
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

string getString(){
        string valor;
        getline(cin, valor);
        return valor;
}

template <typename T1>

T1 getInput(){
        while(true){
        T1 valor;
        cin >> valor;
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Entrada inválida! Insira novamente: " << endl;
        }
        else{
            cin.ignore(32767, '\n');
            return valor;
        }
}
}

int main(){

	int opcao_programa = -9;

	cout << "Bem vindo ao gerenciador do mercado!" << endl;
	cout << "Escolha entre uma dessas opções abaixo!" << endl;
	cout << endl;

	cout << "(1) = Modo Venda" << endl;
	cout << "(2) = Modo Recomendação" << endl;
	cout << "(3) = Modo Estoque" << endl;
	cout << "(0) = Sair" << endl << endl;

	cout << "Insira sua opção: ";
	opcao_programa = getInput <int> ();
	cout << endl;

	switch(opcao_programa){

	case 1:
	{

		break;
	}

	case 2:
	{

		break;
	}
	case 3:
	{

		fstream arquivo;

		    int opcao_venda = -1;

		    while(opcao_venda != 0){
		    cout << "Modo Venda - Opções" << endl << endl;
		    cout << "(1) = Registrar categoria" << endl; //FEITO
		    cout << "(2) = Listar categorias" << endl; //FEITO
		    cout << "(3) = Registrar produtos" << endl; //FEITO
		    cout << "(4) = Listar produtos" << endl; //FEITO
		    cout << "(5) = Editar quantidade de um produto" << endl;
		    cout << "(0) = Sair" << endl << endl; //FEITO

		    cout << "Insira sua opção: ";
		    opcao_venda = getInput < int> ();
		    cout << endl;

		    switch (opcao_venda){
		        case 1:
		        {
		        	int leitura = 0;
		            string Nome_categoria;

		            cout << "Nome da categoria: ";
		            Nome_categoria = getString();

		            arquivo.open("doc/Categorias.txt", ios::in);
		            if(arquivo.is_open()){
		            	string linha;

		                while(getline(arquivo, linha)){
		            	        if(linha == Nome_categoria){
		            	        	leitura++;
		            	        	arquivo.close();
		            	        }
		            	           }
		                arquivo.close();
		            	     }

		            if(leitura != 0){
			        	cout << endl << "Categoria já registrada!" << endl << endl;
		            }


		            else{
		               arquivo.open("doc/Categorias.txt", ios::out | ios::app);

		            Categoria categoria(Nome_categoria);

		            arquivo << categoria.getNome() << endl;

		            cout << endl;

		            arquivo.close();
		           }

		            break;
		           }

		        case 2:
		        {
		        	arquivo.open("doc/Categorias.txt", ios::in);

		        	cout << "Categorias registradas" << endl << endl;

		        	if(arquivo.is_open()){
		        		string linha;

						 cout << "--------------------------------------------------------" << endl;
		        		while(getline(arquivo, linha)){
		        		         cout << linha << endl;
		        		       }
				         cout << "-------------------------------------------------------------" << endl << endl;
		        	}

		        	else{
		        		cout << "Não foi possível ler o arquivo. Tente registrar uma categoria e tente novamente" << endl;
		        	}

		        	arquivo.close();

		        	break;
		        }

		        case 3:{

		        	Produto produto;
		        	vector <Categoria> categorias;
		        	Categoria categoria;
		        	string Nome_categoria;
		        	string Nome_produto;
		        	string Tipo_produto;
		        	int Quantidade_produto;
		        	int Quantidade_categorias;
		        	float Preco;

		        	int leitura = 0;
		        	int leitura_2 = 0;

		 		   cout << "Insira o nome do produto: ";
		 		   Nome_produto = getString();
		 		   produto.setNome(Nome_produto);

		 		   arquivo.open("doc/Estoque.txt", ios::in);
		 		   if(arquivo.is_open()){
		 			   string linha;

		 			   while(getline(arquivo, linha)){
		 				   if(linha == Nome_produto){
		 					   leitura++;
		 					   arquivo.close();
		 				   }
		 			   }
		 			   arquivo.close();
		 		   }

		 		  if(leitura != 0){
		 		 	       cout << endl << "Produto já registrado!" << endl << endl;
		 		           }

		 		   else{

		 		   cout << "Insira o número de categorias do produto: ";
		           Quantidade_categorias = getInput<int>();

		           cout << endl;

		           for(int i = 0; i < Quantidade_categorias; i++){

		           cout << "Insira a categoria: ";
		           Nome_categoria = getString();

		           arquivo.open("doc/Categorias.txt", ios::in);
		           if(arquivo.is_open()){
		         	   string linha;

		         	   while(getline(arquivo, linha)){
		         		   if(linha == Nome_categoria){
		            		   leitura_2++;
		          			   arquivo.close();
		        		   }
		           	   }
		              arquivo.close();
		            }

		           if(leitura_2 == 0){
		        	   cout << endl << "Categoria não registrada!" << endl << endl;
		             }

		           else{

		           categoria.setNome(Nome_categoria);
		           categorias.push_back(categoria);
		           }
		        }
		        		   arquivo.open("doc/Estoque.txt", ios::out | ios::app);

		        		   produto.setCategoria(categorias);

		        		   cout << endl;

		        		   cout << "Insira o tipo do produto: ";
		        		   Tipo_produto = getString();
		        		   produto.setTipo(Tipo_produto);

		        		   cout << "Insira a quantidade do produto: ";
		                   Quantidade_produto = getInput<int>();
		                   produto.setQuantidade(Quantidade_produto);

		                   cout << "Insira o preço do produto: ";
		                   Preco = getInput<float>();
		                   produto.setPreco(Preco);

		                   arquivo << produto.getNome() << endl;
		                   arquivo << "Categorias: ";

		                   for(int i = 0; i < categorias.size(); i++){
		                	   arquivo << categorias[i].getNome() << " ";
		                   }

		                   arquivo << endl;

		                   arquivo << "Tipo: " << produto.getTipo() << endl;
		                   arquivo << "Quantidade de " << produto.getNome() <<": " << produto.getQuantidade() << endl;
		                   arquivo << "Preço: R$ " << fixed << setprecision(2) << produto.getPreco() << endl << endl;
		                   cout << endl;
		 		   }

		 		arquivo.close();

		        break;
		    }

		        case 4:
		        {
		               	arquivo.open("doc/Estoque.txt", ios::in);

		               	cout << "Produtos registrados" << endl << endl;

		               	if(arquivo.is_open()){
		               		string linha;

		       				 cout << "--------------------------------------------------------" << endl;
		               		while(getline(arquivo, linha)){
		               		         cout << linha << endl;
		               		       }
		       		         cout << "-------------------------------------------------------------" << endl << endl;
		               	}

		               	else{
		               		cout << "Não foi possível ler o arquivo. Tente registrar um produto e tente novamente" << endl;
		               	}

		               	arquivo.close();

		               	break;
		               }

		        case 5:
		        {

		        	string Nome_produto;
		        	int Quantidade;
		        	int leitura = 0;

		        	cout << "Insira o nome do produto: ";
		        	Nome_produto = getString();

		        	//Checando se esse produto está registrado

		           arquivo.open("doc/Estoque.txt", ios::in);
		 		   if(arquivo.is_open()){
		 			   string linha;

		 			   while(getline(arquivo, linha)){
		 				   if(linha == Nome_produto){
		 					   leitura++;
		 					   arquivo.close();
		 				   }
		 			   }
		 			   arquivo.close();
		 		   }

		 		  if(leitura == 0){
		 		 	       cout << endl << "Produto não registrado!" << endl << endl;
		 		   }

		 		  //Se o produto existe...

				  cout << "Informe a quantidade nova do produto: ";
		 		  Quantidade = getInput <int> ();

		 		  fstream arquivo2;

		 		  arquivo.open("doc/Estoque.txt", ios::in);
		 		  arquivo2.open("doc/Temporario.txt", ios::out);

		 		  string linha_lida;

		 		  while(getline(arquivo, linha_lida)){
		 			  linha_lida += '\n';
		 			  arquivo2 << linha_lida;
		 		  }

		 		  arquivo.close();
		 		  arquivo2.close();


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
	break;

	case 0:
		break;

	default:
		cout << "Opção inválida!" << endl << endl;
	}

return 0;
}
