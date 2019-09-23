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

    fstream arquivo;

    int opcao = -1;

    while(opcao != 0){
    cout << "Modo Venda - Opções" << endl << endl;
    cout << "(1) = Registrar categoria" << endl; //FEITO
    cout << "(2) = Listar categorias" << endl; //FEITO
    cout << "(3) = Registrar produtos" << endl; //+-FEITO (PRECISA CHEGAR SE O PRODUTO OU CATEGORIA JÁ EXISTE
    cout << "(4) = Listar produtos" << endl; //FEITO
    cout << "(5) = Editar quantidade de um produto" << endl;
    cout << "(0) = Sair" << endl << endl; //FEITO

    cout << "Insira sua opção: ";
    opcao = getInput < int> ();
    cout << endl;

    switch (opcao){
        case 1:
        {
        	int leitura = 0;
            string Nome_categoria;
            string Tipos_de_produtos;
            
            cout << "Nome da categoria: ";
            Nome_categoria = getString();

            arquivo.open("Categorias.txt", ios::in);
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
               arquivo.open("Categorias.txt", ios::out | ios::app);


            cout << "Tipos de produtos que se encaixam nessa categoria: ";
            Tipos_de_produtos = getString();

            Categoria categoria(Nome_categoria, Tipos_de_produtos);

            arquivo << categoria.getNome() << endl;
            arquivo << "Tipos de Produtos: " << categoria.getTipos() << endl << endl;

            cout << endl;

            arquivo.close();
           }

            break; 
           }

        case 2:
        {
        	arquivo.open("Categorias.txt", ios::in);

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
        		cout << "Não foi possível ler o arquivo. Tente registrar uma categoria e tente novamente";
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
        	int Quantidade;
        	float Preco;

 		   cout << "Insira o nome do produto: ";
 		   Nome_produto = getString();
 		   produto.setNome(Nome_produto);

 		   cout << "Insira a categoria do produto: ";
           Nome_categoria = getString();
           categoria.setNome(Nome_categoria);
           categorias.push_back(categoria);

        //cout << "Insira as categorias do produto. Quando terminar, digite 1" << endl;
        //while(Nome_categoria != "1"){
         //       categoria.setNome(Nome_categoria);
          //      categorias.push_back(categoria);
        //}

        		   arquivo.open("Estoque.txt", ios::out | ios::app);

        		   produto.setCategoria(categorias);

        		   cout << "Insira o tipo do produto: ";
        		   Tipo_produto = getString();
        		   produto.setTipo(Tipo_produto);

        		   cout << "Insira a quantidade do produto: ";
                   Quantidade = getInput<int>();
                   produto.setQuantidade(Quantidade);

                   cout << "Insira o preço do produto: ";
                   Preco = getInput<float>();
                   produto.setPreco(Preco);

                   arquivo << "Nome: " << produto.getNome() << endl;
                   arquivo << "Categorias: ";

                   for(int i = 0; i < categorias.size(); i++){
                	   arquivo << categorias[i].getNome();
                   }

                   arquivo << endl;

                   arquivo << "Tipo: " << produto.getTipo() << endl;
                   arquivo << "Quantidade: " << produto.getQuantidade() << endl;
                   arquivo << "Preço: R$ " << fixed << setprecision(2) << produto.getPreco() << endl << endl;

        	break;
    }
        case 4:
        {
               	arquivo.open("Estoque.txt", ios::in);

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
               		cout << "Não foi possível ler o arquivo. Tente registrar um produto e tente novamente";
               	}

               	arquivo.close();

               	break;
               }

        case 5:
        {

        	break;
        }

        case 0:
        	break;

        default:
        	cout << "Opção inválida!" << endl << endl;
        	break;
    }
    }

return 0;
}