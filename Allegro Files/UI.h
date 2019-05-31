#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <string>
#include <allegro5/allegro.h>
#include "pch.h"

class UIElement
{
public:
	virtual ~UIElement() {};

	virtual void DrawToTarget(ALLEGRO_BITMAP* renderTarget) = 0;
	virtual void DrawToScreen() = 0;
};

class ImageUIElement : UIElement{
public:
	ImageUIElement() {};
	ImageUIElement(const char* fileName);
	virtual ~ImageUIElement();

	virtual void DrawToTarget(ALLEGRO_BITMAP* renderTarget) override;
	virtual void DrawToScreen() override;

private:
	ALLEGRO_BITMAP* m_image;
};

typedef std::unique_ptr<ImageUIElement> ImageUIElementPtr;

#endif /* UI_hpp */