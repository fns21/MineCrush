#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include "init.h"

void must_init(bool test, const char *description){
    
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

ALLEGRO_DISPLAY* disp_init(){

    ALLEGRO_DISPLAY* disp;

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 8, ALLEGRO_SUGGEST);
    
    disp = al_create_display(1920, 1050);
    must_init(disp, "display");
    al_set_window_title(disp, "MineCrush");
    return disp;
}

ALLEGRO_FONT* font_init(int i){
    ALLEGRO_FONT* font = al_load_ttf_font("resources/Minecraft_Font.ttf", i, 0);
    must_init(font, "font");
    return font;
}

void background_init(ALLEGRO_BITMAP* background[]){

    background[0] = al_load_bitmap("resources/Sprites/PNG/Backgrounds/Minecraft.jpg");
    must_init(background[0], "background 0");
    background[1] = al_load_bitmap("resources/Sprites/PNG/Backgrounds/Dirt_Background.png");
    must_init(background[1], "background 1");
    background[2] = al_load_bitmap("resources/Sprites/PNG/Other/Score.png");
    must_init(background[2], "background 2");
    background[3] = al_load_bitmap("resources/Sprites/PNG/Backgrounds/Brick_Minecraft.jpg");
    must_init(background[3], "background 3");
    background[4] = al_load_bitmap("resources/Sprites/PNG/Backgrounds/Steve_Field.png");
    must_init(background[4], "background 4");
    background[5] = al_load_bitmap("resources/Sprites/PNG/Backgrounds/Herobrine.png");
    must_init(background[5], "background 5");
    background[6] = al_load_bitmap("resources/Sprites/PNG/Other/Book.png");
    must_init(background[6], "background 6");
    background[7] = al_load_bitmap("resources/Sprites/PNG/Other/Sign.png");
    must_init(background[7], "background 7");
    background[8] = al_load_bitmap("resources/Sprites/PNG/Other/Level_complete.png");
    must_init(background[8], "background 8");
}

ALLEGRO_BITMAP* title_menu_init(){

    ALLEGRO_BITMAP* title;

    title = al_load_bitmap("resources/Sprites/PNG/Other/MINE-CRUSH.png");
    must_init(title, "background");
    return title;

}
void button_init(ALLEGRO_BITMAP* button[]){

    button[0] = al_load_bitmap("resources/Sprites/PNG/Buttons/Jogar.png");
    must_init(button[0], "botão Jogar");
    button[1] = al_load_bitmap("resources/Sprites/PNG/Buttons/ComoJogar.png");
    must_init(button[1], "botão Como Jogar");
    button[2] = al_load_bitmap("resources/Sprites/PNG/Buttons/MelhoresResultados.png");
    must_init(button[2], "botão Melhores Resultados");
    button[3] = al_load_bitmap("resources/Sprites/PNG/Buttons/Sair.png");
    must_init(button[3], "botão Sair");
    button[4] = al_load_bitmap("resources/Sprites/PNG/Buttons/Creditos.png");
    must_init(button[4], "botão Creditos");
    button[5] = al_load_bitmap("resources/Sprites/PNG/Buttons/Voltar.png");
    must_init(button[5], "botão Voltar");
}

void sound_init(ALLEGRO_SAMPLE* sound[]){


    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(128);

    sound[0] = al_load_sample("resources/Audio/Button_Sound.ogg");
    must_init(sound[0], "Sound 0");
    sound[1] = al_load_sample("resources/Audio/Village_Hero.ogg");
    must_init(sound[1], "Sound 1");
    sound[2] = al_load_sample("resources/Audio/Firework.ogg");
    must_init(sound[2], "Sound 2");
    sound[3] = al_load_sample("resources/Audio/Thunder.ogg");
    must_init(sound[3], "Sound 3"); 
    sound[4] = al_load_sample("resources/Audio/Xp.ogg");
    must_init(sound[4], "Sound 4");
    sound[5] = al_load_sample("resources/Audio/Anvil.ogg");
    must_init(sound[5], "Sound 5");    
}

void music_init(ALLEGRO_AUDIO_STREAM* music[]){

    music[0] = al_load_audio_stream("resources/Audio/Mutation.ogg", 2, 2048);
    must_init(music[0], "music 0");
    music[1] = al_load_audio_stream("resources/Audio/Aria_Math.ogg", 2, 2048);
    must_init(music[1], "music 1");
    music[2] = al_load_audio_stream("resources/Audio/Wet_Hands.ogg", 2, 2048);
    must_init(music[2], "music 2");
    music[3] = al_load_audio_stream("resources/Audio/Herobrine.ogg", 2, 2048);
    must_init(music[3], "music 3");
    al_set_audio_stream_playmode(music[0], ALLEGRO_PLAYMODE_LOOP);
    al_set_audio_stream_playmode(music[1], ALLEGRO_PLAYMODE_LOOP);
    al_set_audio_stream_playmode(music[2], ALLEGRO_PLAYMODE_LOOP);
    al_set_audio_stream_playmode(music[3], ALLEGRO_PLAYMODE_LOOP);
}

ALLEGRO_BITMAP* mouse_sprite_init(){

    ALLEGRO_BITMAP* mouse_sprite;

    mouse_sprite = al_load_bitmap("resources/Sprites/PNG/Other/Pickaxe_Cursor.png");
    must_init(mouse_sprite, "mouse sprite");
    return mouse_sprite;
}

ALLEGRO_MOUSE_CURSOR* mouse_cursor_init(){

    ALLEGRO_MOUSE_CURSOR* pickaxe;

    pickaxe = al_create_mouse_cursor(mouse_sprite_init(), 0, 0);
    return pickaxe;
}

char* arq_init (char* file){
    FILE* arq;
    char* text;
    long int size;

    arq = fopen(file, "r");
    if (!arq) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    fseek(arq, 0, SEEK_END);
    size = ftell(arq);
    rewind(arq);

    text = malloc(sizeof(char) * (size + 1));
    if (!text) {
        perror("Erro de alocação de memória");
        exit(1);
    }

    if (fread(text, sizeof(char), size, arq) != size) {
        perror("Erro ao ler arquivo");
        exit(1);
    }

    text[size-1] = '\0';

    fclose(arq);
    return text;
}

void ore_init(ALLEGRO_BITMAP* ore[]){

    ore[0] = al_load_bitmap("resources/Sprites/PNG/Ores/Vazio.png");
    must_init(ore[0], "Vazio");
    ore[1] = al_load_bitmap("resources/Sprites/PNG/Ores/Diamond_Sprite.png");
    must_init(ore[1], "Diamante");
    ore[2] = al_load_bitmap("resources/Sprites/PNG/Ores/Emerald_Sprite.png");
    must_init(ore[2], "Esmeralda");
    ore[3] = al_load_bitmap("resources/Sprites/PNG/Ores/Gold_Ore_Sprite.png");
    must_init(ore[3], "Ouro");
    ore[4] = al_load_bitmap("resources/Sprites/PNG/Ores/Lapis_Lazuli_Sprite.png");
    must_init(ore[4], "Lapis Lazuli");
    ore[5] = al_load_bitmap("resources/Sprites/PNG/Ores/Redstone_Sprite.png");
    must_init(ore[5], "Redstone");
    ore[6] = al_load_bitmap("resources/Sprites/PNG/Ores/Diamond_Block_Sprite.png");
    must_init(ore[6], "Diamond Block");
    ore[7] = al_load_bitmap("resources/Sprites/PNG/Ores/Emerald_Block_Sprite.png");
    must_init(ore[7], "Emerald Block");
    ore[8] = al_load_bitmap("resources/Sprites/PNG/Ores/Gold_Block_Sprite.png");
    must_init(ore[8], "Gold Block");
    ore[9] = al_load_bitmap("resources/Sprites/PNG/Ores/Lapis_Lazuli_Block_Sprite.png");
    must_init(ore[9], "Lapis Lazuli Block");
    ore[10] = al_load_bitmap("resources/Sprites/PNG/Ores/Redstone_Block_Sprite.png");
    must_init(ore[10], "Redstone Block");
    ore[11] = al_load_bitmap("resources/Sprites/PNG/Ores/Bedrock_Block_Sprite.png");
    must_init(ore[11], "Bedrock");
    ore[12] = al_load_bitmap("resources/Sprites/PNG/Ores/Nether_Star_Sprite.png");
    must_init(ore[12], "Nether Star");
}


bool linear_combination(MATRIX* matriz, int i, int j){

    if(j >= 2)
        if(matriz->piece[i][j].ore == matriz->piece[i][j-1].ore && matriz->piece[i][j].ore == matriz->piece[i][j-2].ore)
            return true;
    return false;
}

bool columnar_combination(MATRIX* matriz, int i, int j){

    if(i >= 2)
        if(matriz->piece[i][j].ore == matriz->piece[i-1][j].ore && matriz->piece[i][j].ore == matriz->piece[i-2][j].ore)
            return true;
    return false;
}

MATRIX* matrix_init(int N){

    int x, y;
    MATRIX *matrix = malloc(sizeof(MATRIX));

    y = -60;
    // Inicializa as 64 peças
    for (int i = 0; i < N; i++) {
        x = 910;
        for (int j = 0; j < N-1; j++) {
            matrix->piece[i][j].x = x+=110;
            matrix->piece[i][j].y = y;
            matrix->piece[i][j].ore = rand() % 5 + 1;
            //impede inicialização com combinações 
            while(linear_combination(matrix, i, j) || columnar_combination(matrix, i, j))
                matrix->piece[i][j].ore = rand() % 5 + 1;
            matrix->piece[i][j].selec[0] = 0;
            matrix->piece[i][j].selec[1] = 0;
            matrix->piece[i][j].special = 0;
            matrix->piece[i][j].mvx = 0;
            matrix->piece[i][j].mvy = 0;
        }
        y += 110;
    }
    return matrix;
}

MISSION* missao_init(){

    MISSION* missao = malloc(sizeof(MISSION));
    missao -> ore = 0;
    missao -> cont = 0;
    return missao;
}