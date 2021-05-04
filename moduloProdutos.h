typedef struct produto Produto;

struct produto {
    char codBarras[14];
    char dataValidade[11];
    char nomeItem[51];
    char local[20];
    int quant;
    char status[2];
    struct produto *prox;
};

typedef struct chaveP ChaveP;

struct chaveP {
    char codBarras[14];
    char dataValidade[11];
};

char menuProdutos(void);

void gravarProduto(Produto*);

void mostraCabecalho(void);

void mostraProdutosControle(Produto*);

void mostraProdutos(Produto*);

void exibeProduto(Produto*);

Produto* telaCadastrarProduto(void);

void cadastrarProduto(void);

Produto* pegarProdutoPeloCod(ChaveP*);

char telaTipoPesq(void);

void pesquisarProduto(void);

ChaveP* telaExcluirProduto(void);

void excluirProdutoLogicamente(Produto*);

void excluirProduto(void);

ChaveP* telaAlterarProduto(void);

Produto* telaAlterarTudo();

char* telaAlterarValidade(void);

char* telaAlterarDesc(void);

char* telaAlterarLocal(void);

char* telaAlterarQuant(void);

void regravarProduto(Produto*);

void regravarCampo(Produto*);

void alterarProduto(void);

void listarProdutos(void);