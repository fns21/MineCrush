#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include "init.h"
#include "draw.h"
#include "update.h"

#define ALTURA_TELA 1050
#define LARGURA_TELA 1920

int temp2;

void menu_draw(ALLEGRO_BITMAP* buff, ALLEGRO_BITMAP* title, ALLEGRO_BITMAP* button[], int button_selection[]){

    ALLEGRO_COLOR color[5];

    //colore botão se mouse estiver em cima
    for(int i = 0; i < 5; i++){
        if(button_selection[i])
            color[i] =  al_map_rgba_f(1.0, 1.0, 1.0, 0.1);
        else    
            color[i] = al_map_rgb(255, 255, 255);
    }
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(buff, 0, 0, 0);
    al_draw_bitmap(title, LARGURA_TELA / 2 - al_get_bitmap_width(title) / 2, ALTURA_TELA / 2 - 350, 0);
    al_draw_tinted_bitmap(button[0], color[0], LARGURA_TELA / 2 - al_get_bitmap_width(button[0]) / 2, ALTURA_TELA / 2 + 50, 0);
    al_draw_tinted_bitmap(button[1], color[1], LARGURA_TELA / 2 - al_get_bitmap_width(button[1]) / 2, ALTURA_TELA / 2 + 100, 0);
    al_draw_tinted_bitmap(button[2], color[2], LARGURA_TELA / 2 - al_get_bitmap_width(button[2]) / 2, ALTURA_TELA / 2 + 150, 0);
    al_draw_tinted_bitmap(button[3], color[3], LARGURA_TELA / 2 - al_get_bitmap_width(button[3]) / 12, ALTURA_TELA / 2 + 220, 0);
    al_draw_tinted_bitmap(button[4], color[4], LARGURA_TELA / 2 - al_get_bitmap_width(button[4]) / 2, ALTURA_TELA / 2 + 220, 0);
    al_flip_display();

}

void jogar_draw (ALLEGRO_FONT* font, ALLEGRO_BITMAP* background[], ALLEGRO_BITMAP* button[], ALLEGRO_BITMAP* ore[], int button_selection[], MATRIX* matriz, int N, int easteregg, float angle, int score, char* Score, int type, int quant){

    ALLEGRO_COLOR color;
    int temp = score;
    int count = 0;
    char fase[3];
    int lvl;
    char cont[2];
    
    while(temp != 0){
        temp /= 10;
        count++;
    }
    char* pont = malloc(sizeof(char) * count+1);
    //colore botão se mouse estiver em cima
    if(button_selection[5])
        color = al_map_rgba_f(1.0, 1.0, 1.0, 0.4);
    else
        color = al_map_rgb(255, 255, 255);

    al_clear_to_color(al_map_rgb(0, 0, 0));

    if(!easteregg)
        al_draw_bitmap(background[4], 0, 0, 0);
    else
        al_draw_tinted_bitmap(background[5], al_map_rgba_f(0.7, 0.7, 0.7, 0.2), 0, 0, 0);
    
    sprintf(pont, "%d", score);
    al_draw_bitmap(background[6], 350, 450, 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), 530, 570, 0, pont);
    al_draw_text(font, al_map_rgb(0, 0, 0), 520, 730, 0, Score);
    al_draw_bitmap(ore[type], 720, 550, 0);
    sprintf(cont, "%d", quant);
    al_draw_text(font, al_map_rgb(0, 0, 0), 880, 580, 0, cont);

    if(score < 1000)
        temp2 = 1;

    else{
        lvl = ceil(score / 1000);
        temp2 = log2(lvl) + 2;
    }

    sprintf(fase, "%d", temp2);
    al_draw_bitmap(background[7], 20, -20, 0);


    al_draw_text(font, al_map_rgb(0, 0, 0), 67, 120, 0, "====FASE====");
    al_draw_text(font, al_map_rgb(0, 0, 0), 165, 170, 0, fase);

    al_draw_tinted_bitmap(button[5], color, LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2, ALTURA_TELA / 2 + 320, 0);
    for(int i = 1; i < N; i++){
        for(int j = 0; j < N-1; j++){
            if(matriz->piece[i][j].ore != 0 && (matriz->piece[i][j].selec[0] == 1 || matriz->piece[i][j].selec[1] == 1)){
                if(matriz->piece[i][j].special == 1)
                    al_draw_rotated_bitmap(ore[matriz->piece[i][j].ore + 5], al_get_bitmap_width(ore[matriz->piece[i][j].ore])/2, al_get_bitmap_height(ore[matriz->piece[i][j].ore])/2,
                    matriz->piece[i][j].x + al_get_bitmap_width(ore[matriz->piece[i][j].ore])/2 + matriz->piece[i][j].mvx, matriz->piece[i][j].y + al_get_bitmap_height(ore[matriz->piece[i][j].ore])/2 + matriz->piece[i][j].mvy, angle, 0);
                else
                    al_draw_rotated_bitmap(ore[matriz->piece[i][j].ore], al_get_bitmap_width(ore[matriz->piece[i][j].ore])/2, al_get_bitmap_height(ore[matriz->piece[i][j].ore])/2,
                    matriz->piece[i][j].x + al_get_bitmap_width(ore[matriz->piece[i][j].ore])/2 + matriz->piece[i][j].mvx, matriz->piece[i][j].y + al_get_bitmap_height(ore[matriz->piece[i][j].ore])/2 + matriz->piece[i][j].mvy, angle, 0);
                }
            else{  
                if(matriz->piece[i][j].special == 1)
                    al_draw_bitmap(ore[matriz->piece[i][j].ore + 5], matriz->piece[i][j].x, matriz->piece[i][j].y + matriz->piece[i][j].mvy, 0);
                else         
                    al_draw_bitmap(ore[matriz->piece[i][j].ore], matriz->piece[i][j].x, matriz->piece[i][j].y + matriz->piece[i][j].mvy, 0);
                }

        }
    }
    al_flip_display();
    free(pont);
}

void como_jogar_draw(ALLEGRO_FONT* font, ALLEGRO_BITMAP* background, ALLEGRO_BITMAP* button[], int button_selection[], char* ComoJogar, int ingame){

    ALLEGRO_COLOR color;

    //colore botão se mouse estiver em cima
    if(button_selection[5])
        color = al_map_rgba_f(1.0, 1.0, 1.0, 0.4);
    else
        color = al_map_rgb(255, 255, 255);

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_multiline_text(font, al_map_rgb(255, 255, 255), 200, 100, 1920, 0, 0, ComoJogar);
    if(!ingame)
        al_draw_tinted_bitmap(button[5], color, LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2, ALTURA_TELA / 2 + 320, 0);
    al_flip_display();
}

void melhores_resultados_draw(ALLEGRO_FONT* font, ALLEGRO_BITMAP* background[], ALLEGRO_BITMAP* button[], int button_selection[], char* Score, int x, int y){

    ALLEGRO_COLOR color;

    //colore botão se mouse estiver em cima
    if(button_selection[5])
        color = al_map_rgba_f(1.0, 1.0, 1.0, 0.4);
    else
        color = al_map_rgb(255, 255, 255);

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(background[3], 0, 0, 0);
    al_draw_bitmap(background[2], LARGURA_TELA / 2 - 350, y, 0);
    al_draw_multiline_text(font, al_map_rgb(0, 0, 0), x, y + 50, 1920, 0, ALLEGRO_ALIGN_CENTRE, "Melhores Resultados");
    al_draw_text(font, al_map_rgb(0, 0, 0), LARGURA_TELA/2, y + 350, 0, Score);
    al_draw_tinted_bitmap(button[5], color, LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2, ALTURA_TELA / 2 + 320, 0);
    al_flip_display();
}

void creditos_draw(ALLEGRO_FONT* font, ALLEGRO_BITMAP* title, ALLEGRO_BITMAP* background, ALLEGRO_BITMAP* button[], int button_selection[], char* Creditos, int z){
    
    ALLEGRO_COLOR color;

    //colore botão se mouse estiver em cima
    if(button_selection[5])
        color = al_map_rgba_f(1.0, 1.0, 1.0, 0.4);
    else
        color = al_map_rgb(255, 255, 255);

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_bitmap(title, LARGURA_TELA / 2 - al_get_bitmap_width(title) / 2, z, 0);
    al_draw_multiline_text(font, al_map_rgb(255, 255, 255), 200, z, 1720, 0, 0, Creditos); 
    al_draw_tinted_bitmap(button[5], color, LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2, ALTURA_TELA / 2 + 320, 0);
    al_flip_display();
}

void fim_fase_draw(ALLEGRO_FONT* font, ALLEGRO_BITMAP* background[], ALLEGRO_BITMAP* ore[]){
    char fase[3];
    al_draw_bitmap(background[8], LARGURA_TELA / 2 - al_get_bitmap_width(background[8])/2, ALTURA_TELA/ 2 - al_get_bitmap_height(background[8])/2, 0);
    al_draw_text(font, al_map_rgb(255, 255, 255), 720, 620, 0, "============");
    sprintf(fase, "%d", temp2-1);
    al_draw_text(font, al_map_rgb(255, 255, 255), LARGURA_TELA / 2, ALTURA_TELA/2 - 60, 0, fase);

    al_flip_display();
}

void fim_jogo_draw(ALLEGRO_FONT* font, ALLEGRO_BITMAP* background[], ALLEGRO_SAMPLE* sound[], int result){

    al_draw_filled_rectangle(0, 0, LARGURA_TELA, ALTURA_TELA, al_map_rgba_f(1.0, 0.0, 0.0, 0.2));
    if(result == 1){
        al_play_sample(sound[2], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        al_draw_text(font, al_map_rgb(0, 0, 0), 720, 500, 0, "PARABENS");
        al_draw_text(font, al_map_rgb(0, 0, 0), 720, 600, 0, "NOVO RECORDE");
    }
    else
        al_draw_text(font, al_map_rgb(255, 255, 255), 770, 450, 0, "FIM DE JOGO");

    al_flip_display();
}

