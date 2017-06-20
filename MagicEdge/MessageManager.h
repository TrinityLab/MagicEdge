#pragma once

#include "Object.h"

interface IEventListener
{

};

interface ICollideEventListener : IEventListener
{
public:
	virtual void OnObjectCollide(void* otherTrigger) {};
};

struct Message
{
	enum MessageType
	{
		OnCollide,
		OnTakeDamage,
		OnAttack
	};

	union
	{
		void* data_ptr;
		int data_i;
		float data_f;
		double data_d;
		long long int data_l;
		char data_c;
	};

	void* sender;
	IEventListener* target;
	MessageType type;
};

class MessageManager
{
public:
	static void SendMessage(void* from, IEventListener* target, Message::MessageType message, void* data);
	static void SendMessage(void* from, IEventListener* target, Message::MessageType message, int data);
	static void SendMessage(void* from, IEventListener* target, Message::MessageType message, float data);
	static void SendMessage(void* from, IEventListener* target, Message::MessageType message, double data);
	static void SendMessage(void* from, IEventListener* target, Message::MessageType message, long long int data);
	static void SendMessage(void* from, IEventListener* target, Message::MessageType message, char data);
private:
	static queue<shared_ptr<Message>> messages;
	static void Update();

	friend class Scene;
};

