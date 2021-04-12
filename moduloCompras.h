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

char menuCompras(void);

Compra* telaCadastrarCompra(void);

void telaPesquisarCompra(Compra*);

void telaExcluirCompra(Compra*);

void telaAlterarCompra(Compra*);

void telaListarCompras(void);