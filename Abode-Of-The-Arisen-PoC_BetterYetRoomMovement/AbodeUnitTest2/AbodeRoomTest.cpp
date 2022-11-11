#include "pch.h"
#include "CppUnitTest.h"
#include "../AbodeOfTheArisenv0.0.1/Room.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AbodeUnitTest3
{
	TEST_CLASS(AbodeUnitTest3)
	{
	public:
		// copy of enum, until we move this into a header file
		enum Rooms { HALLWAY = 0, BATHROOM = 1, BEDROOM = 2, ERROR = 99 };

		// Test creating & returning the room names
		TEST_METHOD(roomName)
		{
			Room room1(HALLWAY);
			Assert::AreEqual("HALLWAY", room1.getRoomName().c_str());
			Room room2(BATHROOM);
			Assert::AreEqual("BATHROOM", room2.getRoomName().c_str());
			Room room3(BEDROOM);
			Assert::AreEqual("BEDROOM", room3.getRoomName().c_str());
			Room roomX(15);
			Assert::AreEqual("Somewhere", roomX.getRoomName().c_str());
		}
	};
}