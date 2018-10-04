/*
 * Copyright (c) 2015-2017, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include "board-if.hpp"

using namespace Board;

// ----------------------------------------------------------------------------
int
main()
{
	GpioE11::setOutput();
	GpioE13::setOutput();
	GpioE11::set();
	GpioE13::reset();

	//	while(1) {
//		GpioE11::toggle();
//		modm::delayMilliseconds(500);
//	}

	Board::initializeInterfaceBoard();


	//using Rx = GpioInputD6;
	//using Tx = GpioOutputD5;
	Usart2::connect<GpioD6::Rx, GpioD5::Tx>();
	Usart2::initialize<Board::systemClock, 115200>();

	static const uint8_t hello[] = "\nHello World\n";
	Usart2::write(hello, sizeof(hello));

//	Usart2::discardReceiveBuffer();
	while (1)
	{
		GpioE11::toggle();
		GpioE13::toggle();


//		static uint8_t c = 'A';
//		Usart2::write(c);
//		++c;
//		if (c > 'Z') {
//			c = 'A';
//		}
//		modm::delayMilliseconds(500);

		uint8_t c2;
		if(Usart2::read(&c2, 1) == 1) {
			static const uint8_t str[] = "You typed: ";
			Usart2::write(str, sizeof(str));
			Usart2::write(c2);
			Usart2::write('\n');
		}

	}

	return 0;
}
