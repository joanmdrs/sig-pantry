typedef struct compra Compra;

struct compra {
    char dataCompra[11];
    char horaCompra[6];
    char valorCompra[10];
    char quantItens[10];
    Produto itens[100];
    char status[12];
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

void exibirCompra(Compra*);

Chave* telaPesquisarCompra(void);

Chave* telaExcluirCompra(void);

Compra* pegarCompra(Chave*);

void pesquisarCompra(void);

void excluirLogicamente(Compra*);

void excluirCompra(void);

Chave* telaAlterarCompra();

void alterarTudo(Compra*);

void alterarItem(Compra*);

void alterarCompra(void);