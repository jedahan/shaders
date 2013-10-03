#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
		
	//we load a font and tell OF to make outlines so we can draw it as GL shapes rather than textures
	font.loadFont("type/verdana.ttf", 100, true, false, true, 0.4, 72);
	#ifdef TARGET_OPENGLES
	shader.load("shaders_gles/noise.vert","shaders_gles/noise.frag");
	#else
	if(ofGetGLProgrammableRenderer()){
		shader.load("shaders_gl3/noise.vert", "shaders_gl3/noise.frag");
	}else{
		shader.load("shaders/noise.vert", "shaders/noise.frag");
	}
	#endif

	doShader = true;	
}

//--------------------------------------------------------------
void testApp::update(){
    if(ofGetFrameNum() % (int)ofGetFrameRate()/2==0){
        shader.load("shaders_gl3/noise.vert", "shaders_gl3/noise.frag");
    }
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(225);
	ofDrawBitmapString("'s' toggles shader", 10, 20);

	ofSetColor(245, 58, 135);
	ofFill();
	
	if( doShader ){
		shader.begin();
			//we want to pass in some varrying values to animate our type / color 
			shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
			shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
			
			//we also pass in the mouse position and window size
			shader.setUniform2f("mouse", mX, mY);
	}
	
		//finally draw our text
		font.drawStringAsShapes("openFrameworks", 90, 260);
	
	if( doShader ){
		shader.end();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	if( key == 's' ){
		doShader = !doShader;
	}	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
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

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

