typedef struct compra Compra;

struct compra {
    long int codCompra;
    char dataCompra[11];
    char horaCompra[9];
    int quant;
    double valor;
    char status;
    
};

typedef struct item Item;

struct item {
    long int codCompra;
    char descricao[51];
    int quant;
    double valor;
};

char menuCompras(void);

void cadastrarCompra(void);

void gravarCompra(Compra*);

void gravarItem(Item*);

void exibirCompra(Compra*);

void exibirItem(Item*);

long int telaPesquisarCompra(void);

Compra* pegarCompra(long int);

void pesquisarCompra(void);

long int telaExcluirCompra(void);

void excluirCompraLog(Compra*);

void excluirCompra(void);

long int telaAlterarCompra(void);

char* telaPreencheData(void);

char* telaPreencheHora(void);

double telaPreencheValor(void);

char telaEscolha(void);

void regravarCompra(Compra*);

void alterarCompra(void);

void listarCompras(void);
