#pragma once
#include "ofMain.h"

class Circle{
public:
    Circle();
    void setup(ofVec2f vec1, ofVec2f vec2, ofColor color);
    void draw();
    void update(float pct);
    void setNewPosition(ofVec2f pos);
    
    ofVec2f newPosition;
    ofVec2f oldPosition;
    ofVec2f currentPosition;
    ofColor color;
    int dimension;
};
