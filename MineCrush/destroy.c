#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include "destroy.h"

void disp_destroy(ALLEGRO_DISPLAY* disp){

    al_destroy_display(disp);
}

void bitmap_destroy(ALLEGRO_BITMAP* button[], ALLEGRO_BITMAP* background[], ALLEGRO_BITMAP* title, ALLEGRO_BITMAP* ore[]){

    for(int i = 0; i < 6; i++)
        al_destroy_bitmap(button[i]);
    for(int j = 0; j < 9; j++)
        al_destroy_bitmap(background[j]);
    for(int k = 0; k < 13; k++)
        al_destroy_bitmap(ore[k]);
    al_destroy_bitmap(title);
}

void queue_destroy(ALLEGRO_EVENT_QUEUE* queue){

    al_destroy_event_queue(queue);
}

void font_destroy(ALLEGRO_FONT* font){

    al_destroy_font(font);
}

void stream_destroy(ALLEGRO_AUDIO_STREAM* music[]){

    for(int i = 0; i < 4; i++)
        al_destroy_audio_stream(music[i]);
}

void audio_destroy(ALLEGRO_SAMPLE* sound[]){

    for(int i = 0; i < 6; i++)
        al_destroy_sample(sound[i]);
}

void timer_destroy(ALLEGRO_TIMER* timer){

    al_destroy_timer(timer);
}

void mouse_cursor_destroy(ALLEGRO_MOUSE_CURSOR* pickaxe){

    al_destroy_mouse_cursor(pickaxe);
}
