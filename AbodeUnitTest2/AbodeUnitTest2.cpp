#include "pch.h"
#include "CppUnitTest.h"
#include "../AbodeOfTheArisenv0.0.1/AbodeMain.cpp"
#include "../AbodeOfTheArisenv0.0.1/Player.cpp"
#include "../AbodeOfTheArisenv0.0.1/Zombie.cpp"
#include "../AbodeOfTheArisenv0.0.1/Room.cpp"
#include "../AbodeOfTheArisenv0.0.1/Item.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AbodeUnitTest2
{
	TEST_CLASS(AbodeUnitTest2)
	{
	public:
		
		// Test a couple of combinations of north & south
		// Initially - all input must be the same case
		TEST_METHOD(Poc_playerInput)
		{
			string command = "MOVE NORTH";
			Assert::AreEqual("north", playerChoice(command, command).c_str());

			command = "move south";
			Assert::AreEqual("south", playerChoice(command, command).c_str());

			command = "Move south";
			Assert::AreNotEqual("south", playerChoice(command, command).c_str());
		}

		// test east - both working combinations
		//   mixed case command - should return ERROR (for now) - could also test Not equal
		//   leading white space - fails in current version
		TEST_METHOD(Poc_playerInputEast)
		{
			string command = "MOVE EAST";
			Assert::AreEqual("east", playerChoice(command, command).c_str());

			command = "move east";
			Assert::AreEqual("east", playerChoice(command, command).c_str());

			command = "Move east";
			Assert::AreEqual("ERROR", playerChoice(command, command).c_str());

			command = " Move east";
			Assert::AreEqual("east", playerChoice(command, command).c_str());
		}
	};
}
