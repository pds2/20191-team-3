#include "UI.h"
#include "Engine.h"
#include "pch.h"
#include<iostream>


ImageUIElement::ImageUIElement(const char* fileName)
{
	m_image = al_load_bitmap(fileName);
	if (m_image == NULL) {
		std::cout << "ERROR\n";
	}
}

ImageUIElement::~ImageUIElement()
{
	if (m_image != nullptr)
	{
		al_destroy_bitmap(m_image);
	}
}

void ImageUIElement::DrawToTarget(ALLEGRO_BITMAP* renderTarget)
{
	al_set_target_bitmap(renderTarget);
	al_draw_bitmap(m_image, 0, 0, 0);
}

void ImageUIElement::DrawToScreen()
{
	al_set_target_backbuffer(Engine::getInstance().display);
	al_draw_bitmap(m_image, 0, 0, 0);
}