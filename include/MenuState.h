#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"
//#include "GameState.h"
#include "Engine.h"
#include "UI.h"

class MenuState : public State {

public:
	virtual ~MenuState() {};

	virtual void Init() override;

	virtual void HandleEvents(Engine* engine) override;
	virtual void Draw(Engine* engine) override;

private:
	ImageUIElementPtr m_splashUI;
//	ImageUIElementPtr m_instructionsUI;

	bool showInstructions;
};

#endif