#pragma once

class Object;
class Component;

struct Message
{
	enum MessageType
	{
		OnCollide,
		OnPlayerKillEnemy
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

	Object* sender;
	Object* target;
	MessageType type;
};

class MessageManager
{
public:
	static void SendMessage(Object* from, Object* target, Message::MessageType message, void* data);
	static void SendMessage(Object* from, Object* target, Message::MessageType message, int data);
	static void SendMessage(Object* from, Object* target, Message::MessageType message, float data);
	static void SendMessage(Object* from, Object* target, Message::MessageType message, double data);
	static void SendMessage(Object* from, Object* target, Message::MessageType message, long long int data);
	static void SendMessage(Object* from, Object* target, Message::MessageType message, char data);
private:
	static queue<shared_ptr<Message>> messages;
	static void Update();

	template<typename T>
	static bool IsListener(Component* c);

	friend class Scene;
};

class ICollideEventListener
{
public:
	virtual void OnCollide(Object* otherObject) = 0;
};

class IKillEnemyListener
{
public:
	virtual void OnKillEnemy(Object* enemy, int score, int exp) = 0;
};