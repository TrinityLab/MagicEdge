#include "StandardInc.h"
#include "MessageManager.h"

queue<shared_ptr<Message>> MessageManager::messages;

void MessageManager::SendMessage(void* from, IEventListener* target, Message::MessageType message, void* data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_ptr = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::SendMessage(void* from, IEventListener* target, Message::MessageType message, int data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_i = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::SendMessage(void* from, IEventListener* target, Message::MessageType message, long long int data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_l = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::SendMessage(void* from, IEventListener* target, Message::MessageType message, float data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_f = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::SendMessage(void* from, IEventListener* target, Message::MessageType message, double data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_d = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::SendMessage(void* from, IEventListener* target, Message::MessageType message, char data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_c = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::Update()
{
	while (messages.size() > 0)
	{
		shared_ptr<Message> msg = messages.back();

		switch (msg->type)
		{
		case Message::OnCollide:
			((ICollideEventListener*)msg->target)->OnObjectCollide(msg->data_ptr);
			break;
		case Message::OnTakeDamage:
			break;
		case Message::OnAttack:
			break;
		}

		messages.pop();
	}
}