#ifndef __DESTROY__
#define __DESTROY__

void disp_destroy(ALLEGRO_DISPLAY* disp);

void bitmap_destroy(ALLEGRO_BITMAP* button[], ALLEGRO_BITMAP* background[], ALLEGRO_BITMAP* title, ALLEGRO_BITMAP* ore[]);

void queue_destroy(ALLEGRO_EVENT_QUEUE* queue);

void font_destroy(ALLEGRO_FONT* font);

void stream_destroy(ALLEGRO_AUDIO_STREAM* music[]);

void audio_destroy(ALLEGRO_SAMPLE* sound[]);

void timer_destroy(ALLEGRO_TIMER* timer);

void mouse_cursor_destroy(ALLEGRO_MOUSE_CURSOR* pickaxe);

#endif