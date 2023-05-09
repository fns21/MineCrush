#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "init.h"
#include "update.h"
#include "draw.h"

#define ALTURA_TELA 1050
#define LARGURA_TELA 1920

void menu_update(ALLEGRO_EVENT event, ALLEGRO_BITMAP* button[], ALLEGRO_SAMPLE* sound[], int button_selection[], int* estado){

    switch (event.type) 
    {
        //verifica se o mouse está em cima do botão
        case ALLEGRO_EVENT_MOUSE_AXES:
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[0]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[0]) / 2 - 48 &&     //aresta x botão Jogar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[0]) / 2 + 270 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[0]) / 2 + 60)          //aresta y botão Jogar
                button_selection[0] = 1;
            else    
                button_selection[0] = 0;
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[1]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[1]) / 2 - 48 &&     //aresta x botão ComoJogar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[1]) / 2 + 320 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[1]) / 2 + 110)         //aresta y botão ComoJogar
                button_selection[1] = 1;
            else    
                button_selection[1] = 0;
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[2]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[2]) / 2 - 48 &&     //aresta x botão MelhoresResultados
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[2]) / 2 + 370 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[2]) / 2 + 160)         //aresta y botão MelhoresResultados
                button_selection[2] = 1;
            else    
                button_selection[2] = 0;
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[3]) / 2 + 260 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[3]) / 2 - 48 &&     //aresta x botão Sair
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[3]) / 2 + 440 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[3]) / 2 + 230)          //aresta y botão Sair
                button_selection[3] = 1;
            else    
                button_selection[3] = 0;
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[4]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[4]) / 2 - 250 &&     //aresta x botão Créditos
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[4]) / 2 + 440 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[4]) / 2 + 230)          //aresta y botão Créditos
                button_selection[4] = 1;
            else    
                button_selection[4] = 0;
            break;
        //verifica se botão foi pressionado  e toca som 
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[0]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[0]) / 2 - 48 &&     //aresta x botão Jogar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[0]) / 2 + 270 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[0]) / 2 + 60){         //aresta y botão Jogar
                al_play_sample(sound[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                *estado = 1;   
            }
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[1]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[1]) / 2 - 48 &&     //aresta x botão ComoJogar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[1]) / 2 + 320 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[1]) / 2 + 110){        //aresta y botão ComoJogar
                al_play_sample(sound[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                *estado = 2;
            }
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[2]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[2]) / 2 - 48 &&     //aresta x botão MelhoresResultados
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[2]) / 2 + 370 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[2]) / 2 + 160){        //aresta y botão MelhoresResultados
                al_play_sample(sound[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                al_play_sample(sound[1], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                al_play_sample(sound[2], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                *estado = 3;
            }
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[3]) / 2 + 260 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[3]) / 2 - 48 &&     //aresta x botão Sair
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[3]) / 2 + 440 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[3]) / 2 + 230){         //aresta y botão Sair
                al_play_sample(sound[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                *estado = 4;
            }
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[4]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[4]) / 2 - 250 &&     //aresta x botão Créditos
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[4]) / 2 + 440 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[4]) / 2 + 230){         //aresta y botão Créditos
                al_play_sample(sound[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                *estado = 5;
            }
            break;
    }

}

int check_combination(MATRIX* matrix, int N) {
    int i, j, k, current_element, match_count = 0;
    for (i = 1; i < N; i++){
        for (j = 0; j < N-1; j++){
            if(matrix->piece[i][j].ore != 0)
                current_element = matrix->piece[i][j].ore;

            // Verifica combinações na horizontal
            int horizontal_count = 1;
            for (k = j + 1; k < N-1; k++){
                if (matrix->piece[i][k].ore == current_element && matrix->piece[i][k].ore != 11)
                    horizontal_count++;
                else
                    break;
            }
            if (horizontal_count >= 3){
                match_count++;
            }

            // Verifica combinações na vertical
            int vertical_count = 1;
            for (int k = i + 1; k < N; k++){
                if (matrix->piece[k][j].ore == current_element && matrix->piece[k][j].ore != 11)
                    vertical_count++;
                else
                    break;
            }

            if (vertical_count >= 3) {
                match_count++;
            }
        }
    }

    return match_count;
}

int remove_combination(MATRIX* matrix, int N, int* score, MISSION* missao) {
    
    int i, j, k, h = 0, v = 1, current_element;
    for (i = 1; i < N; i++){
        for (j = 0; j < N-1; j++){
            if(matrix->piece[i][j].ore != 0)
                current_element = matrix->piece[i][j].ore;

            // Verifica combinações na horizontal e remove
            int horizontal_count = 1;
            for (k = j + 1; k < N-1; k++){
                if (matrix->piece[i][k].ore == current_element && matrix->piece[i][k].ore != 11)
                    horizontal_count++;
                else
                    break;
            }
            
            if (horizontal_count == 3){
                for (k = j; k < j + horizontal_count; k++){
                    missao->ore = matrix->piece[i][k].ore;
                    missao->cont = 3;
                    matrix->piece[i][k].ore = 0;
                    *score += 10;
                    if(matrix->piece[i][k].special == 1){
                        matrix->piece[i][k].special = 0; 
                        while(h < N-1){
                            if(matrix->piece[i][h].ore != 11){
                                matrix->piece[i][h].ore = 0;
                                *score += 10;
                            }
                            h++;
                        }
                    } 
                } 
                return 1;
            }
            else if(horizontal_count == 5){
                for (k = j; k < j + horizontal_count; k++){
                    missao->ore = matrix->piece[i][k].ore;
                    missao->cont = 5;
                    matrix->piece[i][k].ore = 0; 
                    *score += 10;
                } 
                matrix->piece[i][k-1].ore = 12;
                return 1;
            }
            else if(horizontal_count == 4){
                for (k = j; k < j + horizontal_count-1; k++){
                    missao->ore = matrix->piece[i][k].ore;
                    missao->cont = 4;
                    matrix->piece[i][k].ore = 0; 
                    *score += 10;
                } 
                *score += 10;
                matrix->piece[i][k].special = 1;
                return 1;
            }

            // Verifica combinações na vertical e remove
            int vertical_count = 1;
            for (int k = i + 1; k < N; k++){
                if (matrix->piece[k][j].ore == current_element && matrix->piece[k][j].ore != 11)
                    vertical_count++;
                else
                    break;
            }

            if (vertical_count == 3) {
                for (k = i; k < i + vertical_count; k++){
                    missao->ore = matrix->piece[k][j].ore;
                    missao->cont = 3;
                    matrix->piece[k][j].ore = 0;
                    *score += 10;
                    if(matrix->piece[k][j].special == 1){
                        matrix->piece[k][j].special = 0; 
                        while(v < N){
                            if(matrix->piece[v][j].ore != 11){
                                matrix->piece[v][j].ore = 0;
                                *score += 10;
                            }
                            v++;
                        }
                    } 
                } 
                return 1;
            }
            else if(vertical_count == 5){
                for (k = i; k < i + vertical_count; k++){
                    missao->ore = matrix->piece[k][j].ore;
                    missao->cont = 5;
                    matrix->piece[k][j].ore = 0; 
                    *score += 10;
                } 
                matrix->piece[k-1][j].ore = 12;
                return 1;
            }

            else if(vertical_count == 4){
                for (k = i; k < i + vertical_count-1; k++){
                    missao->ore = matrix->piece[k][j].ore;
                    missao->cont = 4;
                    matrix->piece[k][j].ore = 0; 
                    *score += 10;
                } 
                *score += 10;
                matrix->piece[k][j].special = 1;
                return 1;
            }
        }
    }
    return 0;
}

void switch_elem(int* a, int* b){

    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
int exist_blank_space(MATRIX* matrix, int N){

    int i, j;
    for (i = 1; i < N; i++){
        for (j = 0; j < N-1; j++){
            if(matrix->piece[i][j].ore == 0)
                return 1;
        }
    }
    return 0;
}

void fill_empty_spaces(MATRIX* matrix, int N, int t){

    int aleat;
    for (int i = N-1; i > 0; i--) {
        for (int j = 0; j < N-1; j++) {
            if(matrix->piece[i][j].ore == 0){
                if(matrix->piece[i-1][j].y + matrix->piece[i-1][j].mvy < matrix->piece[i][j].y){
                    matrix->piece[i-1][j].mvy++;
                    matrix->piece[i-1][j].mvy*=1.6;
                }
                else{
                    switch_elem(&matrix->piece[i-1][j].ore, &matrix->piece[i][j].ore);
                    switch_elem(&matrix->piece[i-1][j].special, &matrix->piece[i][j].special);
                    matrix->piece[i-1][j].mvy = 0;
                }
                if(matrix->piece[1][j].ore == 0 && t == 1){
                    matrix->piece[0][j].ore = rand() % 5 + 1;
                }
                else if(matrix->piece[1][j].ore == 0 && t > 1){
                    aleat = rand() % (15-t) + 1;
                    matrix->piece[0][j].ore = rand() % 5 + 1;
                    if(aleat == 1)
                        matrix->piece[0][j].ore = 11;
                }

            }
        }
    }
}

int end_game(MATRIX* matrix, int N){
    int row, col, ore;
    bool has_possible_match = false;
    
    // Check horizontal matches
    for (row = 1; row < N; row++) {
        for (col = 0; col < N-1; col++) {
            if(matrix->piece[row][col].ore != 11)
                ore = matrix->piece[row][col].ore;
            if (ore == 0 || ore == 11) continue; 
            
            if ((matrix->piece[row][col+1].ore == ore || matrix->piece[row][col+2].ore == ore)) {
                if ((row > 1 && matrix->piece[row-1][col].ore == ore && matrix->piece[row][col].ore != 11) ||
                    (row < N-1 && matrix->piece[row+1][col].ore == ore && matrix->piece[row][col].ore != 11) ||
                    (col > 0 && matrix->piece[row][col-1].ore == ore && matrix->piece[row][col].ore != 11) ||
                    (col < N-3 && matrix->piece[row][col+3].ore == ore && matrix->piece[row][col].ore != 11)) {
                    has_possible_match = true;
                }
            }

        }
    }
    
    // Check vertical matches
    for (row = 1; row < N; row++) {
        for (col = 0; col < N-1; col++) {
            if(matrix->piece[row][col].ore != 11)
                ore = matrix->piece[row][col].ore;
            if (ore == 0 || ore == 11) continue; 

            if ((matrix->piece[row+1][col].ore == ore || matrix->piece[row+2][col].ore == ore)) {
                if ((row > 1 && matrix->piece[row-1][col].ore == ore && matrix->piece[row][col].ore != 11) ||
                    (row < N-3 && matrix->piece[row+3][col].ore == ore && matrix->piece[row][col].ore != 11) ||
                    (col > 0 && matrix->piece[row][col-1].ore == ore && matrix->piece[row][col].ore != 11) ||
                    (col < N-1 && matrix->piece[row][col+1].ore == ore && matrix->piece[row][col].ore != 11)) {
                    has_possible_match = true;
                 }
            }
        }
    }
    
    if (!has_possible_match) {
        return 1;
    }
    
    return 0;
}


void easteregg_update(ALLEGRO_EVENT event, char* value){

    if(event.type == ALLEGRO_EVENT_KEY_CHAR)
        if(strlen(value) <= 9){
            char key[] = {event.keyboard.unichar, '\0'};
            if(event.keyboard.unichar >= 'A' && event.keyboard.unichar <= 'Z')
                strcat(value, key);
            else if(event.keyboard.unichar >= 'a' && event.keyboard.unichar <= 'z')
                strcat(value, key);
        }
}

void mission_att(int* ore, int* quant){

    *ore = rand() % 5 + 1;
    *quant = rand() % 8 + 1;
}

void mission_update(MISSION* missao, int* ore, int* quant, int* score){

    if(*ore == missao->ore)
        *quant = *quant - missao->cont;
    if(*quant <= 0){
        *score += 100;
        mission_att(ore, quant);
    }
}


void jogar_update(ALLEGRO_EVENT event, ALLEGRO_BITMAP* button[], ALLEGRO_BITMAP* ore[], ALLEGRO_SAMPLE* sound[], int* button_selection, int* estado, MATRIX* matriz, int N, int* tutorial, float* angle, int* score, MISSION* missao, int* type, int* quant){
    
    static GAMESTATE state = SELECIONANDO;    
    static int key_count = 0;
    static int selec = 0;
    int diff;
    static int obj = 1000;
    static int t = 1;
    switch(event.type){
        case ALLEGRO_EVENT_TIMER:
            if(*score >= obj){
                *estado = 6;
                t++;
                obj *= 2;
            }
            *angle += 0.1;
            if(state == COMBINANDO){
                if(exist_blank_space(matriz, N)){
                    fill_empty_spaces(matriz, N, t);
                    if(!exist_blank_space(matriz, N)){
                        if(remove_combination(matriz, N, score, missao)){
                            al_play_sample(sound[5], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                            mission_update(missao, type, quant, score);
                        }
                        if(end_game(matriz, N) == 1)
                            *estado = 7;
                        state = COMBINANDO;
                    }
                }
                else{
                    state = SELECIONANDO;
                }
            }
            if(state == TROCANDO){
                for (int k = 1; k < N; k++) {
                    for (int l = 0; l < N-1; l++) {
                        if(matriz->piece[k][l].selec[0] == 1 && matriz->piece[k][l+1].selec[1] == 1){
                            diff = (matriz->piece[k][l].x + matriz->piece[k][l].mvx) - (matriz->piece[k][l+1].x + matriz->piece[k][l+1].mvx);
                            if(diff < 110){
                                matriz->piece[k][l].mvx+=2;
                                matriz->piece[k][l+1].mvx-=2;
                            } 
                            else if(diff == 110){
                                switch_elem(&matriz->piece[k][l].ore, &matriz->piece[k][l+1].ore);
                                switch_elem(&matriz->piece[k][l].special, &matriz->piece[k][l+1].special);
                                if(matriz->piece[k][l+1].ore == 12){
                                    int ore = matriz->piece[k][l].ore;
                                    int cont = 0;
                                    for(int m = 1; m < N; m++)
                                        for(int n = 0; n < N-1; n++){
                                            if(matriz->piece[m][n].ore == ore){
                                                missao->ore = matriz->piece[m][n].ore;
                                                missao->cont = cont++;
                                                matriz->piece[m][n].ore = 0;
                                                *score += 10;
                                            }
                                        }
                                    matriz->piece[k][l+1].ore = 0;
                                    selec = 1;
                                }
                                if(!check_combination(matriz, N) && selec != 1){
                                    matriz->piece[k][l].mvx = 0;
                                    matriz->piece[k][l+1].mvx = 0;
                                    selec = 1;
                                }
                                else{
                                    remove_combination(matriz, N, score, missao);
                                    al_play_sample(sound[5], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                                    mission_update(missao, type, quant, score);
                                    matriz->piece[k][l].mvx = 0;
                                    matriz->piece[k][l+1].mvx = 0;
                                    matriz->piece[k][l].selec[0] = 0;
                                    matriz->piece[k][l+1].selec[1] = 0;
                                    selec = 0;
                                }
                            } 
                        }
                        else if(matriz->piece[k][l].selec[0] == 1 && matriz->piece[k][l-1].selec[1] == 1){
                            diff = (matriz->piece[k][l].x + matriz->piece[k][l].mvx) - (matriz->piece[k][l-1].x + matriz->piece[k][l-1].mvx);
                            if(diff > -110){
                                matriz->piece[k][l].mvx-=2;
                                matriz->piece[k][l-1].mvx+=2;
                            }
                            else if(diff == -110){
                                switch_elem(&matriz->piece[k][l].ore, &matriz->piece[k][l-1].ore);
                                switch_elem(&matriz->piece[k][l].special, &matriz->piece[k][l-1].special);
                                if(matriz->piece[k][l-1].ore == 12){
                                    int ore = matriz->piece[k][l].ore;
                                    int cont = 0;
                                    for(int m = 1; m < N; m++)
                                        for(int n = 0; n < N-1; n++){
                                            if(matriz->piece[m][n].ore == ore){
                                                missao->ore = matriz->piece[m][n].ore;
                                                missao->cont = cont++;
                                                matriz->piece[m][n].ore = 0;
                                                *score += 10;
                                            }
                                        }
                                    matriz->piece[k][l-1].ore = 0;
                                    selec = 1;
                                }
                                if(!check_combination(matriz, N) && selec != 1){
                                    matriz->piece[k][l].mvx = 0;
                                    matriz->piece[k][l-1].mvx = 0;
                                    selec = 1;
                                }
                                else{
                                    remove_combination(matriz, N, score, missao);
                                    al_play_sample(sound[5], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                                    mission_update(missao, type, quant, score);
                                    matriz->piece[k][l].mvx = 0;
                                    matriz->piece[k][l-1].mvx = 0;
                                    matriz->piece[k][l].selec[0] = 0;
                                    matriz->piece[k][l-1].selec[1] = 0;
                                    selec = 0;
                                }
                            }
                        }
                        else if(matriz->piece[k][l].selec[0] == 1 && matriz->piece[k+1][l].selec[1] == 1){
                            diff = (matriz->piece[k][l].y + matriz->piece[k][l].mvy) - (matriz->piece[k+1][l].y + matriz->piece[k+1][l].mvy);
                            if(diff < 110){
                                    matriz->piece[k][l].mvy+=2;
                                    matriz->piece[k+1][l].mvy-=2;
                            }
                            else if(diff == 110){
                                switch_elem(&matriz->piece[k][l].ore, &matriz->piece[k+1][l].ore);
                                switch_elem(&matriz->piece[k][l].special, &matriz->piece[k+1][l].special);
                                if(matriz->piece[k+1][l].ore == 12){
                                    int ore = matriz->piece[k][l].ore;
                                    int cont = 0;
                                    for(int m = 1; m < N; m++)
                                        for(int n = 0; n < N-1; n++){
                                            if(matriz->piece[m][n].ore == ore){
                                                missao->ore = matriz->piece[m][n].ore;
                                                missao->cont = cont++;
                                                matriz->piece[m][n].ore = 0;
                                                *score += 10;
                                            }
                                        }
                                    matriz->piece[k+1][l].ore = 0;
                                    selec = 1;
                                }
                                if(!check_combination(matriz, N) && selec != 1){
                                    matriz->piece[k][l].mvy = 0;
                                    matriz->piece[k+1][l].mvy = 0;
                                    selec = 1;
                                }
                                else{
                                    remove_combination(matriz, N, score, missao);
                                    al_play_sample(sound[5], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                                    mission_update(missao, type, quant, score);
                                    matriz->piece[k][l].mvy = 0;
                                    matriz->piece[k+1][l].mvy = 0;
                                    matriz->piece[k][l].selec[0] = 0;
                                    matriz->piece[k+1][l].selec[1] = 0;
                                    selec = 0;
                                }
                            }
                        }
                        else if(matriz->piece[k][l].selec[0] == 1 && matriz->piece[k-1][l].selec[1] == 1){
                            diff = (matriz->piece[k][l].y + matriz->piece[k][l].mvy) - (matriz->piece[k-1][l].y + matriz->piece[k-1][l].mvy);
                            if(diff > -110){
                                    matriz->piece[k][l].mvy-=2;
                                    matriz->piece[k-1][l].mvy+=2;
                            }    
                            else if(diff == -110){
                                switch_elem(&matriz->piece[k][l].ore, &matriz->piece[k-1][l].ore);
                                switch_elem(&matriz->piece[k][l].special, &matriz->piece[k-1][l].special);
                                if(matriz->piece[k-1][l].ore == 12){
                                    int ore = matriz->piece[k][l].ore;
                                    int cont = 0;
                                    for(int m = 1; m < N; m++)
                                        for(int n = 0; n < N-1; n++){
                                            if(matriz->piece[m][n].ore == ore){
                                                missao->ore = matriz->piece[m][n].ore;
                                                missao->cont = cont++;
                                                matriz->piece[m][n].ore = 0;
                                                *score += 10;
                                            }
                                        }
                                    matriz->piece[k-1][l].ore = 0;
                                    selec = 1;
                                }
                                if(!check_combination(matriz, N) && selec != 1){
                                    matriz->piece[k][l].mvy = 0;
                                    matriz->piece[k-1][l].mvy = 0;
                                    selec = 1;
                                }
                                else{
                                    remove_combination(matriz, N, score, missao);
                                    al_play_sample(sound[5], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                                    mission_update(missao, type, quant, score);
                                    matriz->piece[k][l].mvy = 0;
                                    matriz->piece[k-1][l].mvy = 0;
                                    matriz->piece[k][l].selec[0] = 0;
                                    matriz->piece[k-1][l].selec[1] = 0;
                                    selec = 0;
                                }
                            }
                        }
                        if(selec == 0){
                            state = COMBINANDO;
                        }
                    }
                }
            }
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2 + 48 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[5]) / 2 - 55 &&      //aresta x botão Voltar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[5]) / 2 + 530 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[5]) / 2 + 320){         //aresta y botão Voltar
                al_play_sample(sound[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                if(*estado == 1)
                    if(al_show_native_message_box(NULL, "Sair do Jogo", "Você tem certeza que deseja sair do jogo?", "Você perderá todo o seu progresso!", NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1)
                        *estado = 0;
            }
            if(state == SELECIONANDO){
                for(int i = 1; i < N; i++){
                    for(int j = 0; j < N-1; j++){
                        matriz->piece[i][j].mvx = 0;
                        matriz->piece[i][j].mvy = 0;
                        if(event.mouse.x >= matriz->piece[i][j].x && event.mouse.x <= matriz->piece[i][j].x + al_get_bitmap_width(ore[matriz->piece[i][j].ore]) &&
                        event.mouse.y >= matriz->piece[i][j].y && event.mouse.y <= matriz->piece[i][j].y + al_get_bitmap_height(ore[matriz->piece[i][j].ore]) && matriz->piece[i][j].ore != 11){
                            if(matriz->piece[i][j].selec[0] == 0 && selec < 1){
                                al_play_sample(sound[4], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                                matriz->piece[i][j].selec[0] = 1;
                                selec++;
                            }
                            else if(matriz->piece[i][j].selec[0] == 1 && selec < 2){
                                matriz->piece[i][j].selec[0] = 0;
                                selec--;
                            }
                            if(matriz->piece[i-1][j].selec[0] == 1 && selec < 2){
                                al_play_sample(sound[4], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                                matriz->piece[i][j].selec[1] = 1;
                                selec++;
                            }
                            else if(matriz->piece[i+1][j].selec[0] == 1 && selec < 2){
                                al_play_sample(sound[4], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                                matriz->piece[i][j].selec[1] = 1;
                                selec++;
                            }
                            else if(matriz->piece[i][j-1].selec[0] == 1 && selec < 2){
                                al_play_sample(sound[4], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                                matriz->piece[i][j].selec[1] = 1;
                                selec++;
                            }
                            else if(matriz->piece[i][j+1].selec[0] == 1 && selec < 2){
                                al_play_sample(sound[4], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                                matriz->piece[i][j].selec[1] = 1;
                                selec++;
                            }
                            if(selec == 2)
                                state = TROCANDO;
                        }
                    }
                }
            } 
            break;               
        case ALLEGRO_EVENT_KEY_CHAR:
                //tutorial in game
                if(event.keyboard.keycode == ALLEGRO_KEY_F1)
                    key_count++;
                if(key_count == 1)
                    *tutorial = 1;
                else{
                    *tutorial = 0;
                    key_count = 0;
                }
            break;
            //verifica se o mouse está em cima do botão
        case ALLEGRO_EVENT_MOUSE_AXES:
                if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2 + 48 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[5]) / 2 - 55 &&      //aresta x botão Voltar
                event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[5]) / 2 + 530 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[5]) / 2 + 320)          //aresta y botão Voltar
                    button_selection[5] = 1;
                else    
                    button_selection[5] = 0;
            break;
    } 
}


void como_jogar_update(ALLEGRO_EVENT event, ALLEGRO_BITMAP* button[], ALLEGRO_SAMPLE* sound[], int button_selection[], int* estado){

    switch(event.type){
        //verifica se o mouse está em cima do botão
        case ALLEGRO_EVENT_MOUSE_AXES:
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[5]) / 2 - 48 &&      //aresta x botão Voltar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[5]) / 2 + 540 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[5]) / 2 + 330)          //aresta y botão Voltar
                button_selection[5] = 1;
            else    
                button_selection[5] = 0;
            break;
        //verifica se botão foi pressionado e toca som 
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[5]) / 2 - 48 &&      //aresta x botão Voltar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[5]) / 2 + 540 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[5]) / 2 + 330){         //aresta y botão Voltar
                al_play_sample(sound[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                if(*estado == 2)
                    *estado = 0;
            }
            break;
    }    
}

void melhores_resultados_update(ALLEGRO_EVENT event, ALLEGRO_BITMAP* button[], ALLEGRO_SAMPLE* sound[], int button_selection[], int* estado, int* y){

    switch(event.type){
        //animação de subida rápida
        case ALLEGRO_EVENT_TIMER:
            if(*y >= 100)
                *y -= 10;
            break;
        //verifica se o mouse está em cima do botão
        case ALLEGRO_EVENT_MOUSE_AXES:
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[5]) / 2 - 48 &&      //aresta x botão Voltar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[5]) / 2 + 540 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[5]) / 2 + 330)          //aresta y botão Voltar
                button_selection[5] = 1;
            else    
                button_selection[5] = 0;
            break;
        //verifica se botão foi pressionado  e toca som 
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[5]) / 2 - 48 &&      //aresta x botão Voltar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[5]) / 2 + 540 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[5]) / 2 + 330){         //aresta y botão Voltar
                al_stop_samples();
                al_play_sample(sound[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                *estado = 0;
            }
            break;
    }  
}

void creditos_update(ALLEGRO_EVENT event, ALLEGRO_BITMAP* button[], ALLEGRO_SAMPLE* sound[], int button_selection[], int* estado, int* z){

    switch(event.type){
        //animação de subida lenta
        case ALLEGRO_EVENT_TIMER:
                *z -= 1;
            break;
        //verifica se o mouse está em cima do botão
        case ALLEGRO_EVENT_MOUSE_AXES:
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[5]) / 2 - 48 &&      //aresta x botão Voltar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[5]) / 2 + 540 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[5]) / 2 + 330)          //aresta y botão Voltar
                button_selection[5] = 1;
            else    
                button_selection[5] = 0;
            break;
        //verifica se botão foi pressionado  e toca som 
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            if (event.mouse.x >= LARGURA_TELA / 2 - al_get_bitmap_width(button[5]) / 2 + 58 && event.mouse.x <= LARGURA_TELA / 2 + al_get_bitmap_width(button[5]) / 2 - 48 &&      //aresta x botão Voltar
            event.mouse.y >= ALTURA_TELA / 2 - al_get_bitmap_height(button[5]) / 2 + 540 && event.mouse.y <= ALTURA_TELA / 2 + al_get_bitmap_height(button[5]) / 2 + 330){         //aresta y botão Voltar
                al_play_sample(sound[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                *estado = 0;
            }
            break;
    }  
}

void fim_fase_update(ALLEGRO_SAMPLE* sound[], int* estado){
    *estado = 1;
}

int fim_jogo_update(int score, char* pont, char* file, int* estado){

    FILE* arquivo;
    int temp = score;
    int count = 0;
    int valor;

    while (temp != 0) {
        temp /= 10;
        count++;
    }

    char* line = malloc(sizeof(char) * (count+1));

    arquivo = fopen(file, "r+");
    if (arquivo != NULL) {
        fgets(line, count+1, arquivo);
        sscanf(line, "%d", &valor);
        if (score > valor) {
            rewind(arquivo);
            fprintf(arquivo, "%d\n", score);
            *estado = 0;
            fclose(arquivo);
            free(line);
            return 1;
        }
    } 
    else
        printf("Erro ao abrir arquivo.\n");
    *estado = 0;
    return 0;
}