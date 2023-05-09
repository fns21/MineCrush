#ifndef __INIT__
#define __INIT__

typedef enum STATE{
    MENU,
    JOGAR, 
    COMOJOGAR,
    MELHORESRESULTADOS,
    SAIR,
    CREDITOS,
    FIMFASE,
    FIMJOGO
} STATE;

typedef struct PIECE{
    int x; 
    int y;
    int mvx;
    int mvy;
    int ore;
    int selec[2];
    int special;
} PIECE;

typedef struct MATRIX{
    PIECE piece[9][8];
} MATRIX;

typedef struct MISSION{
    int ore;
    int cont;
} MISSION;

void must_init(bool test, const char *description);

ALLEGRO_DISPLAY* disp_init();

ALLEGRO_FONT* font_init();

void background_init(ALLEGRO_BITMAP* background[]);

ALLEGRO_BITMAP* title_menu_init();

void button_init(ALLEGRO_BITMAP* button[]);

void sound_init(ALLEGRO_SAMPLE* sound[]);

void music_init(ALLEGRO_AUDIO_STREAM* music[]);

ALLEGRO_BITMAP* mouse_sprite_init();

ALLEGRO_BITMAP* tip_init();

ALLEGRO_MOUSE_CURSOR* mouse_cursor_init();

char* arq_init ();

void ore_init(ALLEGRO_BITMAP* ore[]);

bool linear_combination(MATRIX* matriz, int i, int j);

bool columnar_combination(MATRIX* matriz, int i, int j);

MATRIX* matrix_init(int N);

MISSION* missao_init();

#endif