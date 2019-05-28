#ifndef ENGINE_H
#define ENGINE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
#include "State.h"
#include <memory>
#include "pch.h"
class State;

class Engine{

public:
	Engine();
	//~Engine();

	void Init();
	void Cleanup();

	void HandleEvents();
	void Update();
	void Draw();


	void ChangeState(std::unique_ptr<State> state);
	void PushState(std::unique_ptr<State> state);
	void PopState();

	

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	ALLEGRO_EVENT event;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_EVENT_QUEUE *redrawQueue;

	bool pollEvent() { return al_get_next_event(eventQueue, &event); }
	ALLEGRO_EVENT getEvent() { return event; }
	void WaitForEvent() { al_wait_for_event(eventQueue, &event); }

	ALLEGRO_DISPLAY *display;

	const int m_screenWidth = 1366;
	const int m_screenHeight = 768;

	static double getDeltaTime();

	static Engine& getInstance() {
		if (m_instance == nullptr){
			m_instance = std::make_unique<Engine>();
		}
		return *m_instance;
	}

	ALLEGRO_FONT* defaultFont;

private:
	static std::unique_ptr<Engine> m_instance;

	std::vector<std::unique_ptr<State>> m_states;

	bool m_running;

	const float FPS = 120.0f;

	ALLEGRO_TIMER *redrawTimer;

	static double m_lastFrameTime;

};
#endif