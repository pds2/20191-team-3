#include "pch.h"
#include "Engine.h"
#include <memory>
#include "State.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

double Engine::m_lastFrameTime = 0.0;
std::unique_ptr<Engine> Engine::m_instance;

Engine::Engine(): m_running(true){
	Init();
}

double Engine::getDeltaTime(){
	return al_get_time() - m_lastFrameTime;
}

void Engine::Init(){
	//Initialise the Allegro library
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	display = al_create_display(m_screenWidth, m_screenHeight);
	al_set_window_title(display, "Fire Emblem");

	al_install_keyboard();

	eventQueue = al_create_event_queue();
	redrawQueue = al_create_event_queue();
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());

	redrawTimer = al_create_timer(1.0f / FPS);
	al_register_event_source(redrawQueue, al_get_timer_event_source(redrawTimer));
	al_start_timer(redrawTimer);

	srand((int)time(NULL));
	/// VER VER VER VER VER VER VER VER VER VER VER VER VER VER VER VER
	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "Resources");
	al_change_directory(al_path_cstr(path, '/'));  // change the working directory
	al_destroy_path(path);

	defaultFont = al_load_font("PTS75F.ttf", 16, 0);
}

void Engine::Cleanup() {
	al_destroy_font(defaultFont);

	// cleanup all m_states
	while (!m_states.empty()) {
		m_states.back()->Cleanup();
		m_states.pop_back();
	}

	al_destroy_timer(redrawTimer);

	al_destroy_display(display);
}

void Engine::ChangeState(std::unique_ptr<State> state) {
	// cleanup the current state
	if (!m_states.empty()) {
		m_states.back()->Cleanup();
		m_states.pop_back();
	}

	// store and init the new state
	m_states.push_back(std::move(state));
	m_states.back()->Init();
}

void Engine::PushState(std::unique_ptr<State> state) {
	// pause current state
	if (!m_states.empty()) {
		m_states.back()->Pause();
	}

	// store and init the new state
	m_states.push_back(std::move(state));
	m_states.back()->Init();
}

void Engine::PopState() {
	// cleanup the current state
	if (!m_states.empty()) {
		m_states.back()->Cleanup();
		m_states.pop_back();
	}

	// resume previous state
	if (!m_states.empty()) {
		m_states.back()->Resume();
	}
}

void Engine::HandleEvents() {
	// let the state handle events
	m_states.back()->HandleEvents(this);
}

void Engine::Update() {
	// let the state update the game
	m_states.back()->Update(this);
	m_lastFrameTime = al_get_time();
}

void Engine::Draw() {
	// let the state draw the screen
	m_states.back()->Draw(this);
}