// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#pragma once

class Drawable {
public:
	virtual void animation() = 0;
	virtual void draw() = 0;
	virtual ~Drawable() = default;
};
