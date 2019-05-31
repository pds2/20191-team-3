#include <allegro5/allegro.h>
#include "MenuState.h"
//#include "GameState.h"
#include"pch.h"
void MenuState::Init(){
	m_splashUI = std::make_unique<ImageUIElement>("inicio.png");
//	m_instructionsUI = std::make_unique<ImageUIElement>("instructions.bmp");
}

void MenuState::HandleEvents(Engine* engine){
	while (engine->pollEvent()){
		if (engine->getEvent().type == ALLEGRO_EVENT_KEY_DOWN){
			if (engine->getEvent().keyboard.keycode == ALLEGRO_KEY_SPACE){
			//	if (!showInstructions){
			//		showInstructions = true;
			//	}
			//	else{
					engine->ChangeState(std::make_unique<GameState>());
			//	}
			}
			if (engine->getEvent().keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				engine->Quit();
			}
		}
		else if (engine->getEvent().type  == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			engine->Quit();
		}
	}
}

void MenuState::Draw(Engine* engine){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	if (!showInstructions){
		m_splashUI->DrawToScreen();
	}
//	else{
//		m_instructionsUI->DrawToScreen();
//	}
}