typedef struct compra Compra;

struct compra {
    char quantItens[10];
    Produto itens[100];
    float valorItem[100];
    float valorCompra;
    char dataCompra[11];
    char horaCompra[6];
    char status[10];
};

typedef struct chave Chave;

struct chave{
    char dataCompra[11];
    char horaCompra[6];
};

char menuCompras(void);

Compra* telaCadastrarCompra(void);

void cadastrarCompra(void);

void gravarCompra(Compra*);

Chave* telaPesquisarCompra(void);

Chave* telaExcluirCompra(void);

Compra* pegarCompra(Chave*);

void pesquisarCompra(void);

void exibirCompra(Compra*);

void exclusaoLogicaCompra(Compra*);

void excluirCompra(void);

void telaAlterarCompra(Compra*);

void telaListarCompras(void);