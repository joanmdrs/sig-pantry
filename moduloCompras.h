typedef struct compra Compra;

struct compra {
    char codBarras[14];
    char nomeItem[51];
    char dataValidade[11];
    char quant[10];
    char valorItem[10];
};

char menuCompras(void);

Compra* telaCadastrarCompra(void);

void telaPesquisarCompra(void);

void telaExcluirCompra(void);

void telaAlterarCompra(void);

void telaListarCompras(void);