#ifndef __UPDATE__
#define __UPDATE__

typedef enum GAMESTATE{
    TROCANDO,
    SELECIONANDO,
    COMBINANDO
} GAMESTATE;

void menu_update(ALLEGRO_EVENT event, ALLEGRO_BITMAP* button[], ALLEGRO_SAMPLE* sound[], int* button_selection, int* estado);

void easteregg_update(ALLEGRO_EVENT, char* value);

void mission_att(int* ore, int* quant);

void jogar_update(ALLEGRO_EVENT event, ALLEGRO_BITMAP* button[], ALLEGRO_BITMAP* ore[], ALLEGRO_SAMPLE* sound[], int* button_selection, int* estado, MATRIX* matriz, int N, int* tutorial, float* angle, int* score, MISSION* missao, int* type, int* quant);

void como_jogar_update(ALLEGRO_EVENT event, ALLEGRO_BITMAP* button[], ALLEGRO_SAMPLE* sound[], int* button_selection, int* estado);

void melhores_resultados_update(ALLEGRO_EVENT event, ALLEGRO_BITMAP* button[], ALLEGRO_SAMPLE* sound[], int button_selection[], int* estado, int* y);

void creditos_update(ALLEGRO_EVENT event, ALLEGRO_BITMAP* button[], ALLEGRO_SAMPLE* sound[], int button_selection[], int* estado, int* y);

void fim_fase_update(ALLEGRO_SAMPLE* sound[], int* estado);

int fim_jogo_update(int score, char* pont, char* file, int* estado);

#endif