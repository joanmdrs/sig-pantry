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

char menuConsumo(void);

void cadastrarConsumo(void);

/*

ChaveC* telaPesquisarConsumo(void);

Consumo* pegarConsumo(ChaveC*);

void pesquisarConsumo(void);

ChaveC* telaExcluirConsumo(void);

void excluirLogicamenteC(Consumo*);

void excluirConsumo(void);

ChaveC* telaAlterarConsumo(void);

void alterarTudoC(Consumo*);

void alterarItemC(Consumo*);

void alterarConsumo(void);
*/
void listarConsumos(void);

