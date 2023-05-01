#include "ofApp.h"
#include <time.h>


//--------------------------------------------------------------
void ofApp::setup(){
	//Sound sample
	sound.load("DrumLoop.wav");
	sound.setLoop(true);
	sound.play();

	//Initializes spectrum to 0 brfore sound is played
	for (int i = 0; i < N; i++) {
		spectrum[i] = 0.0f;
	}

	gui.setup();

	gui.add(red.set("red", 255, 0, 255));
	gui.add(green.set("green", 0, 0, 255));
	gui.add(blue.set("blue", 0, 0, 255));
	gui.add(volume.set("volume", 0.5, 0.0, 5.0));
	gui.add(decay.set("decay", 0.5, 0.0, 1.0));


	fft = new float[200];
	for (int i = 0; i < 200; i++) {
		fft[i] = 0;
	}

	bands = 180;

	cam.setDistance(200);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSoundUpdate();

	sound.setVolume(volume);

	soundSpectrum = ofSoundGetSpectrum(bands);

	for (int i = 0; i < bands; i++) {
		fft[i] = fft[i] * decay;
		if (fft[i] < soundSpectrum[i]) {
			fft[i] = soundSpectrum[i];
		}
	}

	float *val = ofSoundGetSpectrum(N);

	for (int i = 0; i < N; i++) {
		spectrum[i] = spectrum[i] * 0.97;
		spectrum[i] = max(spectrum[i], val[i]);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	srand(time(NULL));


	ofBackground(0, 0, 0);

	ofSetColor(red, green, blue);

	for (int i = 0; i < bands; i++) {
		cam.begin();
		ofNoFill();
		ofDrawSphere(0, 0, fft[i] * 100);
		cam.end();
		//ofDrawCircle(rand() % 1000, rand() % 1000, fft[i] * 100);
	}


	ofFill();
	
	for (int i = 0; i < N; i++) {

		if (i == bandRad || i == bandVel) {
			ofSetColor(0, 0, 0);
		}
		else {
			ofSetColor(red, green, blue);
		}
		ofDrawRectangle(10 + i * 5, 700, 3, -spectrum[i] * 100);
	}

	gui.draw();

	string sliders = "";
	sliders += "Use the sliders above to adjust the color\n";
	sliders += "Use the slider above to adjust volume\n";
	sliders += "Use the slider above to adjust the decay\n";
	ofDrawBitmapString(sliders, 10, 150);

	string info = "";
	info += "Press [d] to play a drum\n";
	info += "Press [p] to play a piano\n";
	info += "Press [t] to play a trumpet\n";
	info += "Press [v] to play a violin \n";
	info += "Press [s] to stop the sounds\n";
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(info, 780, 50);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (key == 'p') {
		sound.load("PianoLoop.wav"); //sounds need to be downloaded
		sound.setLoop(true);
		sound.play();
	}

	if (key == 't') {
		sound.load("TrumpetLoop.wav");
		sound.setLoop(true);
		sound.play();
	}

	if (key == 'd') {
		sound.load("DrumLoop.wav");
		sound.setLoop(true);
		sound.play();
	}

	if (key == 'v') {
		sound.load("ViolinLoop.wav");
		sound.setLoop(true);
		sound.play();
	}

	if (key == 's') {
		sound.stop();
	}
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