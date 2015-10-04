#include "circle.h"
Circle::Circle(){
    
}

void Circle::setup(ofVec2f _newPos, ofVec2f _oldPos, ofColor _color){
    color = _color;
    newPosition = _newPos;
    oldPosition = _oldPos;
    currentPosition = oldPosition;
    dimension = 40;
}

void Circle::update(float pct){
    ofVec2f direction = newPosition - oldPosition;
    currentPosition = direction * pct;
}

void Circle::draw(){
    ofSetColor(color);
    ofCircle(currentPosition, dimension);
}

void Circle::setNewPosition(ofVec2f _pos){
    newPosition = _pos;
}