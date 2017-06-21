#include "StandardInc.h"
#include "Mana.h"

void Mana::SetMana(float h)
{
	this->mana = h;
}

float Mana::GetMana()
{
	return mana;
}

void Mana::ManaDown(float h)
{
	mana -= h;
}

void Mana::ManaUp(float h)
{
	mana += h;
}

void Mana::SetMaxMana(float h)
{
	mana = h;
}

float Mana::GetMaxMana()
{
	return mana;
}