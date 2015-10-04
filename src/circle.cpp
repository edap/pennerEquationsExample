#include "circle.h"
Circle::Circle(){
    
}

void Circle::setup(ofVec2f _newPos, ofVec2f _oldPos, ofColor _color){
    color = _color;
    newPosition = _newPos;
    oldPosition = _oldPos;
    dimension = 40;
    direction = newPosition - oldPosition;
}

void Circle::update(float pct){
    currentPosition = oldPosition + direction * pct;
}

void Circle::draw(){
    ofSetColor(color);
    ofCircle(currentPosition, dimension);
}

void Circle::setNewPosition(ofVec2f _pos){
    oldPosition = newPosition;
    newPosition = _pos;
    direction = newPosition - oldPosition;
}