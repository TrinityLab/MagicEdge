#pragma once

class Viewer : public Object
{
public:
	Viewer(string name);
	void Update() override;
	void Render() override;
	void OnCreated() override;
	void OnDestroyd() override;
};