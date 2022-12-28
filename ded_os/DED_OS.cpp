#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>

int main()
{	
	int i = 0;
	int Time = 0;

	std::cout << "Enter the frequency of creating new desktop in milliseconds: ";
	std::cin >> Time;
	std::cout << "Press F12 to start/stop the program\n" << std::endl;

	while (true)
	{
		if (GetKeyState(VK_F12))
		{
			keybd_event(0x5B, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			keybd_event(0x11, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			keybd_event(0x44, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));

			keybd_event(0x44, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			keybd_event(0x11, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			keybd_event(0x5B, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			keybd_event(0x5B, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			keybd_event(0x31, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			keybd_event(0x31, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			keybd_event(0x32, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			keybd_event(0x32, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			keybd_event(0x33, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			keybd_event(0x33, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			keybd_event(0x5B, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			std::this_thread::sleep_for(std::chrono::milliseconds(Time));
			std::cout << "Desktops created: " << ++i << std::endl;
		}
	}
	return 0;
}