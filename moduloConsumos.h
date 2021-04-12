typedef struct consumo Consumo;
struct consumo {
    char quantItens[10];
    Produto itens[100];
    char dataConsumo[11];
    char horaConsumo[6];
    char status[10];
};

char menuConsumo(void);

Consumo* telaCadastrarConsumo(void);

void telaPesquisarConsumo(Consumo*);

void telaExcluirConsumo(Consumo*);

void telaAlterarConsumo(Consumo*);

void telaListarConsumos(void);
