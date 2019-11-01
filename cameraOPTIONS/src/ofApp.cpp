#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//GUI SETUP
	gui.setup();
	gui.add(toggle1.setup("Play", false));
	gui.add(intSlider.setup("Rotations", 0, 0, 10));
	gui.add(toggle2.setup("Mirror", false));
	gui.add(toggle3.setup("Color Draw", false));

	camWidth = 640;
	camHeight = 480;
	indX = 0;
	vidcam.setDesiredFrameRate(30);
	vidcam.initGrabber(640, 480);

	//Video Pixel Objects
	videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
	videoTexture.allocate(videoInverted);
	ofSetVerticalSync(true);

	//Horizon Pixel Objects
	horizontalInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
	horizontalTexture.allocate(videoInverted);
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
	vidcam.update();
	
	ofPixels &pixels = vidcam.getPixels();
	ofColor green(0, 255, 0);
	//ofSetColor(green);
	ofColor color;
	ofColor color2;
	for (int y = 0; y < 480; y++) {
		ofColor color = pixels.getColor(indX, y);
		//ofSetColor(color);
		videoInverted.setColor(indX, y, color);
		if (toggle3) {
			videoInverted.setColor(indX, y, green);
		}
	}

	ofPixels &horizon = vidcam.getPixels();
	for (int x = 0; x < 640; x++) {
		ofColor color2 = horizon.getColor(x, indY);
		horizontalInverted.setColor(x, indY, color2);
		if (toggle3) {
			horizontalInverted.setColor(x, indY, green);
		}
	}

	//ofColor color = pixels.getColor(0, 0);
	videoInverted.setColor(0, 0, color);
	videoInverted.rotate90(intSlider);
	videoInverted.mirror(toggle2, false);

	horizontalInverted.setColor(0, 0, color2);
	horizontalInverted.rotate90(intSlider);
	horizontalInverted.mirror(toggle2, false);


	
	if (toggle1) {
		horizontalTexture.loadData(horizontalInverted);
		videoTexture.loadData(videoInverted);
		
	}

	if (indX >= 640) {
		indX = 0;
	}
	indX += 1;

	if (indY >= 480) {
		indY = 0;
	}
	indY += 1;



}

//--------------------------------------------------------------
void ofApp::draw(){
	vidcam.draw(camWidth, 300);
	videoTexture.draw(0, 300, camWidth, camHeight);
	horizontalTexture.draw(camWidth+camWidth, 300, camWidth, camHeight);
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
