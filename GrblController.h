//
// Created by oy753c on 7/1/24.
//

#ifndef CANDLE_GRBLCONTROLLER_H
#define CANDLE_GRBLCONTROLLER_H

#include <string>

class GrblController {
public:
	GrblController& receiveLine(std::string) {
		return *this;
	}

	GrblController& sendLine(std::string) {
		return *this;
	}

};

#endif //CANDLE_GRBLCONTROLLER_H
