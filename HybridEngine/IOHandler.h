#pragma once
class IOHandler {
	
public:
	IOHandler();
	IOHandler(const IOHandler&);
	~IOHandler();
	void init();
	void keyDown(int);
	void keyUp(int);
	bool isKeyDown(int);


private:
	bool m_keys[256];
};

