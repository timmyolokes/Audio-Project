#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Circle.h"

#define N 256

class ofApp : public ofBaseApp{

	public:

		float spectrum[N];
		int bandRad = 2;
		int bandVel = 100;

		float time0 = 0;


		void setup();
		void update();
		void draw();


		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		ofxPanel gui;
		
		ofParameter<int> red;
		ofParameter<int> green;
		ofParameter<int> blue;
		ofParameter<float> volume;
		ofParameter<float> decay;

		ofSoundPlayer sound;
		ofEasyCam cam;

		float *fft;
		float *soundSpectrum;
		int bands;
};
