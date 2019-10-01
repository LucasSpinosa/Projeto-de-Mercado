----------------------------------------------------- Seção 1 – Sobre o programa --------------------------------------------------------------

Este programa contém dois modos de operação: Modo Venda e Modo Estoque.

O Modo Venda é responsável pelo sistema de clientes cadastrados e também é por ele que é realizado a venda de produtos.
O Modo Estoque é responsável pelo gerenciamento de estoque de produtos da loja.

O programa possui uma lista de dependências para poder ser executado e funcionar corretamente:

- É necessário compilar e executar o programa usando o arquivo Makefile.

- É preciso ter o compilador G++ instalado no computador para poder ser realizada a compilação dos arquivos e execução do programa pelo arquivo Makefile.

- O programa depende dos arquivos encontrados nas pastas bin, doc, inc, obj, src para poder funcionar. Nessas pastas são encontradas bibliotecas como "categoria.hpp" e "cliente.hpp", além das pastas Cliente e Estoque, que contém os arquivos de textos gerados e usados nos modos de operação do programa.

-----------------------------------------------------------------------------------------------------------------------------------------------


----------------------------------------------------- Seção 2 – Executando o programa ---------------------------------------------------------

Para executar o programa é necessário usar o arquivo Makefile. Siga os seguintes passos:

1. Abra o prompt de comando e, nele, vá até a pasta desse programa, EP1.

2. Digite "make".

3. Digite "make run".

Pronto, agora o programa está sendo executado.

-----------------------------------------------------------------------------------------------------------------------------------------------


--------------------------------------------- Seção 3 – Sobre os modos de operação do programa ------------------------------------------------

MODO VENDA


Como dito antes, no Modo Venda é possível usar o sistema de cadastro de cliente e realizar vendas.

Há cinco opções de operação no modo venda:

(1) = Listar clientes
(2) = Visualizar dados de um cliente
(3) = Remover sócio
(4) = Tornar sócio
(5) = Realizar venda

Agora será explicado o que cada opção faz.

-----------------------------------------------------------------------------------------------------------------------------------------------

(1) = Listar clientes: Exibe o nome de todos os clientes cadastrados no estabelecimento.

(2) = Visualizar dados de um cliente: Exibe os dados de um cliente cadastrado no estabelecimento.
	
	°Nome
	°Idade
	°Telefone
	°Email
	°CPF
	°Sócio (se é um cliente sócio ou não).

(3) = Remover sócio: Faz com que um cliente deixe de ser sócio do estabelecimento.

(4) = Tornar sócio: Faz com que um cliente se torne sócio do estabelecimento.

(5) = Realizar venda: realiza vendas no estabelecimento.

Primeiramente, é verificado se o cliente está registrado no estabelecimento ou não. Isso é feito informando o nome dele. 

-Caso esteja, os dados do cliente são lidos e armazenados. 
-Caso não, deve ser informado os dados do cliente para que ocorra o seu cadastro.

Após isso, deve ser informado os nomes dos produtos para que eles sejam adicionados no carrinho de compras. É então exibida a quantidade disponível no estoque. Deve ser informada a quantidade desejada pelo cliente. Essa quantidade é adicionada ao carrinho.

Para parar a adição de produtos, basta digitar 0 e pressionar a tecla Enter.

Por fim, é exibida os detalhes da compra: a lista de produtos comprados (incluindo a quantidade de cada produto e o valor total a ser pago por essa quantidade), o valor da venda, o valor do desconto oferecido ao cliente, caso seja sócio, e o valor total da compra.

-Caso a quantidade desejada seja maior que a quantidade disponível no estoque, a compra é cancelada.
-Caso a compra tenha sido executada com sucesso, a quantidade dos produtos no estoque é reajustada.
-----------------------------------------------------------------------------------------------------------------------------------------------


MODO ESTOQUE

No Modo Estoque é realizado o cadastro de produtos e categorias de produtos. É também por esse modo que é possível ajustar a quantidade e preço dos produtos cadastrados.

No Modo Estoque temos seis opções:

(1) = Registrar categoria
(2) = Listar categorias
(3) = Registrar produtos
(4) = Listar produtos
(5) = Editar quantidade de um produto
(6) = Editar preço de um produto

-----------------------------------------------------------------------------------------------------------------------------------------------

(1) = Registrar categoria: Deve ser informado o nome da categoria. Essa categoria é então registrada no bando de dados.

(2) = Listar categorias: É listada todas as categorias registradas.

(3) = Registrar produtos: É registrado produtos no estoque do estabelecimento.

Primeiramente, deve ser informado o nome do produto.

Segundamente, deve ser informado o número de categorias na qual o produto se encaixa. Após isso, deve ser informado o nome das categorias. Essas categorias já devem estar registradas para poderem ser usadas aqui.

Terceiramente, deve ser inserida a quantidade do produto.

Por fim, deve ser inserido o preço do produto.


(4) = Listar produtos: É exibido os produtos registrados no banco de dados

	°Nome do produto
	°Quantidade do produto
	°Preço do produto


(5) = Editar quantidade de um produto: Informa-se o nome do produto e então deve ser informada a nova quantidade dele no estoque. A quantidade no bando de dados é apagado e o valor informado é inserido.

(6) = Editar preço de um produto: Informa-se o nome do produto e então deve ser informada o novo preço dele. O preço no bando de dados é apagado e o valor informado é inserido.

