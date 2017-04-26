#pragma once

#include "StandardInc.h"
#include "Object.h"

class TexturedObject : public Object
{
private:
	SDL_Texture* texture;
	SDL_Rect srcRect;
protected:
	virtual void Render() override;
	virtual void OnCreated() override;
	virtual void OnDestroyd() override;
	virtual void Update() override;
public:
	TexturedObject(string name);
	void SetTexture(SDL_Texture* texture);
	void SetSrcRect(SDL_Rect srcRect);
	SDL_Rect GetSrcRect();
	SDL_Texture* GetTexture();
};