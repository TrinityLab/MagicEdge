#include "StandardInc.h"
#include "Mana.h"

void Mana::SetMana(float h)
{
	this->mana = h;

	if (mana > maxMana)
		mana = maxMana;

	if (mana < 0)
		mana = 0;
}

float Mana::GetMana()
{
	return mana;
}

void Mana::ManaDown(float h)
{
	mana -= h;
	if (mana < 0)
		mana = 0;
}

void Mana::ManaUp(float h)
{
	mana += h;
	if (mana > maxMana)
		mana = maxMana;
}

void Mana::SetMaxMana(float h)
{
	mana = h;
}

float Mana::GetMaxMana()
{
	return mana;
}