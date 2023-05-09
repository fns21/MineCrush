#ifndef __DRAW__
#define __DRAW__

void menu_draw(ALLEGRO_BITMAP* buff, ALLEGRO_BITMAP* title, ALLEGRO_BITMAP* button[], int button_selection[]);

void jogar_draw (ALLEGRO_FONT* font, ALLEGRO_BITMAP* background[], ALLEGRO_BITMAP* button[], ALLEGRO_BITMAP* ore[], int button_selection[], MATRIX* matriz, int N, int easteregg, float angle, int score, char* Score, int type, int quant);

void como_jogar_draw(ALLEGRO_FONT* font, ALLEGRO_BITMAP* background, ALLEGRO_BITMAP* button[], int button_selection[], char* ComoJogar, int ingame);

void melhores_resultados_draw(ALLEGRO_FONT* font, ALLEGRO_BITMAP* background[], ALLEGRO_BITMAP* button[], int button_selection[], char* MelhoresResultados, int x, int y);

void creditos_draw(ALLEGRO_FONT* font, ALLEGRO_BITMAP* title, ALLEGRO_BITMAP* background, ALLEGRO_BITMAP* button[], int button_selection[], char* Creditos, int y);

void fim_fase_draw(ALLEGRO_FONT* font, ALLEGRO_BITMAP* background[], ALLEGRO_BITMAP* ore[]);

void fim_jogo_draw(ALLEGRO_FONT* font, ALLEGRO_BITMAP* background[], ALLEGRO_SAMPLE* sound[], int result);

#endif