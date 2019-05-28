
#ifndef STATE_H
#define STATE_H

#include "Engine.h"

class Engine;

class State{
public:
	virtual ~State() {};

	virtual void Init() {};
	virtual void Cleanup() {};

	virtual void Pause() {};
	virtual void Resume() {};

	virtual void HandleEvents(Engine* engine) {};
	virtual void Update(Engine* engine) {};
	virtual void Draw(Engine* engine) = 0;
};

#endif