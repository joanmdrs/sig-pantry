typedef struct consumo Consumo;

struct consumo {
    long int codConsumo;
    char dataConsumo[11];
    char horaConsumo[9];
    int quant;
    double valor;
    char status;
};

void gravarConsumo(Consumo*);

void exibirConsumo(Consumo*);

long int preencheCodConsumo(void);

char* preencheDataConsumo(void);

char* preencheHoraConsumo(void);

char* preencheQuantConsumo(void);

double preencheValorConsumo(void);

char menuConsumo(void);

void cadastrarConsumo(void);

long int telaPesquisarConsumo(void);

Consumo* pegarConsumo(long int);

void pesquisarConsumo(void);

long int telaExcluirConsumo(void);

void excluirConsumoLog(Consumo*);

void excluirConsumo(void);

long int telaAlterarConsumo(void);

char telaEscolhaConsumo(void);

void regravarConsumo(Consumo*);

void alterarConsumo(void);

void listarConsumos(void);

