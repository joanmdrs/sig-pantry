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
void telaPesquisarProduto(Produto*);
void telaExcluirProduto(void);
void telaAlterarProduto(void);
void telaListarProdutos(void);