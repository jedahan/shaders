#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);

		void mouseMoved(int x, int y );
		
		ofTrueTypeFont font;
		ofShader shader;
        float amplitude, period, speed;
		bool doShader;

        float mX, mY;
};

