#include<allegro5/allegro5.h>
#include<stdio.h>
#include<allegro5/allegro_font.h>

int main (){
	al_init();
	al_install_keyboard();

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_DISPLAY* disp = al_create_display(640, 400);
	ALLEGRO_FONT* font = al_create_builtin_font();
	ALLEGRO_EVENT event;

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	
	bool redraw = true;
	int lefttoright = 0;
	int uptodown = 0;
	int lefttoout = 0;

	al_start_timer(timer);
	while(1){
		al_wait_for_event(queue, &event);
		switch(event.type){
			case ALLEGRO_EVENT_TIMER:
				redraw = true;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				break;
			case ALLEGRO_EVENT_KEY_DOWN:
				lefttoright += 10;

		}
		if(redraw && al_is_event_queue_empty(queue)){
			al_clear_to_color(al_map_rgb(192, 192, 192));
			al_draw_text(font, al_map_rgb(0, 33, 0), lefttoright, uptodown, lefttoout, "Welcome");
			al_flip_display();
			redraw = false;
	        }
	}
}
