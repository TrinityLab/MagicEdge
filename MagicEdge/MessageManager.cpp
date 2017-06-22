#include "StandardInc.h"
#include "MessageManager.h"
#include "Object.h"

queue<shared_ptr<Message>> MessageManager::messages;

void MessageManager::SendMessage(Object* from, Object* target, Message::MessageType message, void* data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_ptr = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::SendMessage(Object* from, Object* target, Message::MessageType message, int data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_i = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::SendMessage(Object* from, Object* target, Message::MessageType message, long long int data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_l = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::SendMessage(Object* from, Object* target, Message::MessageType message, float data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_f = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::SendMessage(Object* from, Object* target, Message::MessageType message, double data)
{
	shared_ptr<Message> msg = make_shared<Message>();
	msg->data_d = data;
	msg->sender = from;
	msg->target = target;
	msg->type = message;

	messages.push(msg);
}

void MessageManager::SendMessage(Object* from, Object* target, Message::MessageType message, char data)
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
		shared_ptr<Message> msg = messages.front();

		switch (msg->type)
		{
		case Message::OnCollide:
			for (Component* c : msg->target->components)
			{
				if (IsListener<ICollideEventListener>(c))
					dynamic_cast<ICollideEventListener*>(c)->OnCollide(msg->sender);
			}
			break;
		case Message::OnPlayerKillEnemy:
			for (Component* c : msg->target->components)
			{
				if (IsListener<IKillEnemyListener>(c))
					dynamic_cast<IKillEnemyListener*>(c)->OnKillEnemy(msg->sender, (msg->data_l & 0xffffffff) >> 32, msg->data_l & 0x00000000ffffffff);
			}
			break;
		}

		messages.pop();
	}
}

template<typename T>
bool MessageManager::IsListener(Component* c)
{
	if (dynamic_cast<T*>(c))
		return true;

	return false;
}