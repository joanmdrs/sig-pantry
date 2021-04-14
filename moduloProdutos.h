typedef struct produto Produto;
struct produto {
    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char local[10];
    char status[10];
    char quant[10];
};

char menuProdutos(void);

Produto* telaCadastrarProduto(void);

void gravarProduto(Produto*);

void cadastrarProduto(void);

Produto* buscaProduto(char);

char telaPesquisarProduto(void);

void pesquisarProduto(void);

void exibeProduto(Produto*);

char* telaExcluirProduto(void);

Produto* buscaProdutoPorCodBarra(char*);

void excProduto(Produto*);

void excluirProduto(void);

char* telaAlterarProduto(void);

void atualizarProduto(Produto*);

void alterarProduto(void);

void telaListarProdutos(void);