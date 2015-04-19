#pragma once 

#include "ofMain.h"
#include "ofxUI.h"
#include "circle.h"
#include "penner.h"

class ofApp : public ofBaseApp 
{
public:
	void setup();
	void update();
	void draw();
	void exit(); 

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	ofxUISuperCanvas *gui;
    ofxUIDropDownList *ddl;
	void guiEvent(ofxUIEventArgs &e);

    float proximity;
    int n_circles;
    string easyngFunction;
    
    vector<Circle> circles;
    vector<ofColor> palette;
    //Circle myCircle;
    float pct;
    float currIter, totalIter;
    
};