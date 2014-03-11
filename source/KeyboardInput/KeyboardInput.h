#pragma once

#include "Input/Input.h"

#include <list>

namespace FG
{
	class KeyboardInput : public Input
	{
	public:
		enum KEY_STATE
		{
			KEY_NONE,
			KEY_DOWN,
			KEY_PRESSING,
			KEY_UP,
		};

		KeyboardInput();
		virtual ~KeyboardInput();

		virtual void Initialize() override;
		virtual void Destroy() override;

		virtual void Start() override;
		virtual void End() override;

		virtual void OnMsg(UINT msg, WPARAM wParam, LPARAM lParam) override;

		void SetKeyState(int keyCode, KEY_STATE state);
		
		KEY_STATE GetKeyState(int keyCode) const;
		const std::list<int>& GetUpKeys() const;
		const std::list<int>& GetDownKeys() const;
	private:
		int GetKeyCode(WPARAM wParam, LPARAM lParam) const;
		KEY_STATE keys[0x91]; // 0x91 == VK_SCROLL, last enum

		std::list<int> downKeys, upKeys;
	};
}