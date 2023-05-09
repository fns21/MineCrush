#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
#include "destroy.h"

#define ALTURA_TELA 1050
#define LARGURA_TELA 1920

int main(){

    ALLEGRO_TIMER* timer;
    ALLEGRO_DISPLAY* disp = NULL;
    ALLEGRO_BITMAP* background[9];
    ALLEGRO_BITMAP* title;
    ALLEGRO_BITMAP* ore[13];
    ALLEGRO_FONT* font;
    ALLEGRO_FONT* font2;
    ALLEGRO_BITMAP* button[6];
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_EVENT event;
    ALLEGRO_SAMPLE* sound[6];
    ALLEGRO_AUDIO_STREAM* music[4];
    ALLEGRO_MOUSE_CURSOR* pickaxe;
    char* file[4], value[10];
    MATRIX* matriz;
    STATE game;
    MISSION* missao;
    char* como_jogar, *melhores_resultados, *creditos, *pont;
    int button_selection[7];
    int linorcol = 9, estado = 0, result;
    int easteregg = 0, tutorial = 0;
    float angle = 0;
    int score;
    int type, quant;

    srand (time(NULL));

    file[0] = "resources/ComoJogar.txt";
    file[1] = "resources/MelhoresResultados.txt";
    file[2] = "resources/Creditos.txt";
    file[3] = "resources/Score.txt";

    bool al_exit = false;
    bool ready = false;
    bool redraw = true;

    int x, y, z;

    //instalações
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "teclado");
    must_init(al_install_mouse(), "mouse");

    //inicializa eventos
    queue = al_create_event_queue();
    must_init(queue, "queue");
    timer = al_create_timer(1.0 / 60.0);
    must_init(timer, "timer");

    //inicializa addons
    must_init(al_init_font_addon(), "font addon");
    must_init(al_init_ttf_addon(), "ttf addon");
    must_init(al_init_image_addon(), "image addon");
    must_init(al_init_primitives_addon(), "primitives");

    //inicializa recursos
    disp = disp_init();
    font = font_init(24);
    font2 = font_init(56);
    button_init(button);
    background_init(background);
    title = title_menu_init();
    sound_init(sound);
    music_init(music);
    pickaxe = mouse_cursor_init();
    ore_init(ore);
    como_jogar = arq_init(file[0]);
    melhores_resultados = arq_init(file[1]);
    creditos = arq_init(file[2]);
    pont = arq_init(file[3]);
    missao = missao_init();
    mission_att(&type, &quant);

    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "audio codecs");
    must_init(al_reserve_samples(16), "reserve samples");

    //fila de eventos
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());
    
    x = LARGURA_TELA / 2;
    al_start_timer(timer);
    while(!al_exit){
        al_wait_for_event(queue, &event);
        if(event.keyboard.keycode == ALLEGRO_KEY_ENTER){
            strcpy(value, "");
            ready = true;
        }
        easteregg_update(event, value);
        if((event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) || (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
            al_exit = 1;
        game = estado;
        //lógica
        switch(game){
            case MENU:
                y = 950;
                z = 950; 
                score = 0;
                matriz = matrix_init(linorcol);
                menu_update(event, button, sound, button_selection, &estado);
                redraw = true;
                game = estado;
            case JOGAR:
                jogar_update(event, button, ore, sound, button_selection, &estado, matriz, linorcol, &tutorial, &angle, &score, missao, &type, &quant);
                if(tutorial == 1)
                    como_jogar_draw(font, background[1], button, button_selection, como_jogar, tutorial);
                else
                    game = estado;
                redraw = true;
                break;
            case COMOJOGAR:
                como_jogar_update(event, button, sound, button_selection, &estado);
                redraw = true;
                game = estado;
                break;
            case MELHORESRESULTADOS:
                melhores_resultados_update(event, button, sound, button_selection, &estado, &y);
                redraw = true;
                game = estado;
                break;
            case SAIR:
                al_exit = 1;
                break;
            case CREDITOS:
                creditos_update(event, button, sound, button_selection, &estado, &z);
                redraw = true;
                game = estado;
                break;
            case FIMFASE:
                matriz = matrix_init(linorcol);
                fim_fase_update(sound, &estado);
                al_rest(2);
                game = estado;
                redraw = true;
                break;
            case FIMJOGO:
                result = fim_jogo_update(score, pont, file[3], &estado);
                al_rest(5);
                redraw = true;
                game = estado;
                break;
        }


        if(al_exit)
            break;

        //audiovisual
        if(redraw && al_is_event_queue_empty(queue)){
            al_attach_audio_stream_to_mixer(music[0], al_get_default_mixer());
            if(game == 0){
                al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
                al_detach_audio_stream(music[1]);
                al_detach_audio_stream(music[2]);
                al_detach_audio_stream(music[3]);
                menu_draw(background[0], title, button, button_selection); 
                al_stop_samples();
            }
            if(game == 1){
                al_detach_audio_stream(music[0]);
                jogar_draw(font, background, button, ore, button_selection, matriz, linorcol, easteregg, angle, score, pont, type, quant);
                al_set_mouse_cursor(disp, pickaxe);
                al_attach_audio_stream_to_mixer(music[1], al_get_default_mixer());
                if(strcmp(value, "herobrine") == 0 || strcmp(value, "HEROBRINE") == 0){
                    al_play_sample(sound[3], 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
                    al_attach_audio_stream_to_mixer(music[3], al_get_default_mixer());
                    easteregg = 1;
                    strcpy(value, "");
                }
                else if(ready){
                    al_stop_samples();
                    al_detach_audio_stream(music[3]);
                    easteregg = 0;
                    ready = false;
                }
            }                  
            if(game == 2)
                como_jogar_draw(font, background[1], button, button_selection, como_jogar, tutorial);
            if(game == 3)
                melhores_resultados_draw(font, background, button, button_selection, pont, x, y);
            if(game == 5){
                al_detach_audio_stream(music[0]);
                creditos_draw(font, title, background[1], button, button_selection, creditos, z);
                al_attach_audio_stream_to_mixer(music[2], al_get_default_mixer());
            }
            if(game == 6){
                fim_fase_draw(font2, background, ore);
            }
            if(game == 7){
                fim_jogo_draw(font2, background, sound, result);
            }
            redraw = false;
        }
    }

    //destroi e desaloca
    bitmap_destroy(button, background, title, ore);
    disp_destroy(disp);
    queue_destroy(queue);   
    font_destroy(font);
    stream_destroy(music);
    audio_destroy(sound);
    timer_destroy(timer);
    mouse_cursor_destroy(pickaxe);
    free(como_jogar);
    free(melhores_resultados);
    free(creditos);
    free(pont);
    free(missao);
    return 0;
}
