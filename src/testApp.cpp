#include "testApp.h"

void testApp::setup(){
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
		
	//we load a font and tell OF to make outlines so we can draw it as GL shapes rather than textures
	font.loadFont("type/verdana.ttf", 100, true, false, true, 0.4, 90);
	
	shader.load("shaders/noise");

	doShader = true;
    amplitude = 128;
    speed = 1;
    period = 16;
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    // live coding!
    if(ofGetFrameNum() % (int)ofGetFrameRate()/2==0){
        shader.load("shaders/noise");
    }
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(225);
	ofDrawBitmapString("'s' toggles shader", 10, 20);
	ofDrawBitmapString("'f' toggles fullscreen", 10, 30);
	ofDrawBitmapString("'o/p' changes amplitude", 10, 40);
	ofDrawBitmapString("'k/l' changes period", 10, 50);
	ofDrawBitmapString("'m/n' changes speed", 10, 60);

	ofSetColor(245, 58, 135);
	ofFill();
	
	if( doShader ){
		shader.begin();
			//we want to pass in some varrying values to animate our type / color 
			shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
			shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
			
			//we also pass in the mouse position, window size, time and other parameters
			shader.setUniform2f("mouse", mX, mY);
            shader.setUniform1f("width", ofGetWidth());
            shader.setUniform1f("height", ofGetHeight());
            shader.setUniform1f("time", ofGetElapsedTimef());
            shader.setUniform1f("amplitude", amplitude);
            shader.setUniform1f("period", period);
            shader.setUniform1f("speed", speed);
	}

    // draw our text
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
        ofRotateZ(ofGetElapsedTimef()*10);
        ofSetColor(0,0,0);

        ofRect(0,0,ofGetWidth()-200,ofGetHeight()-200);
        ofSetColor(255,255,255);
        font.drawStringAsShapes("school for poetic", -font.stringWidth("school for poetic")/2, -50);
        font.drawStringAsShapes("computation", -font.stringWidth("computation")/2, 50);
    ofPopMatrix();
	
	if( doShader ){
		shader.end();
	}
}

void testApp::keyPressed  (int key){ 
	if( key == 's' ){
		doShader = !doShader;
	} else if (key == 'f'){
        ofToggleFullscreen();
    } else if (key == 'o'){
        amplitude*=2;
    } else if (key == 'p'){
        amplitude/=2;
    } else if (key == 'k'){
        period*=2;
    } else if (key == 'l'){
        period/=2;
    } else if (key == 'm'){
        speed*=2;
    } else if (key == 'n'){
        speed/=2;
    }
}

void testApp::mouseMoved(int x, int y ){
    // Only update the mouse coordinates if inside the window
    if(x>0 && x<ofGetWidth()) {
        if(y>0 && y<ofGetHeight()){
            // Map the mouse coordinates to 0.0-1.0 for our shader
            mX = x/(float)ofGetWidth();
            mY = y/(float)ofGetHeight();
        }
    }
}