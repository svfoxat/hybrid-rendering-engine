#include "IOHandler.h"

IOHandler::IOHandler() {}
IOHandler::IOHandler(const IOHandler& other) {}
IOHandler::~IOHandler() {}


void IOHandler::init() {
	int i;
	for (i = 0; i < 256; i++)
	{
		m_keys[i] = false;
	}
	return;
}


void IOHandler::keyDown(int input) {
	m_keys[input] = true;
	return;
}


void IOHandler::keyUp(int input) {
	m_keys[input] = false;
	return;
}


bool IOHandler::isKeyDown (int key) {
	return m_keys[key];
}
