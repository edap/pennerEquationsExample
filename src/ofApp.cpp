#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    proximity = 150;
    n_circles = 40;
    
    //set GUI
    ddl = NULL;
    gui = new ofxUISuperCanvas("Penner's Functions");
    string textString = "Press G to toggle the menu";
    gui->addTextArea("textarea", textString, OFX_UI_FONT_SMALL);
    gui->addSpacer();
    gui->addSlider("proximity", 0.0, 400.0, proximity);
    gui->addSpacer();
    vector<string> items;
    items.push_back("LINEAr");
    items.push_back("OUT ELASTIC");
    items.push_back("IN ELASTIC");
    items.push_back("IN OUT ELASTIC");
    items.push_back("IN SINE");
    items.push_back("OUT SINE");
    items.push_back("IN OUT SINE");
    items.push_back("IN CUBIC");
    items.push_back("OUT CUBIC");
    items.push_back("IN OUT CUBIC");
    items.push_back("IN QUINT");
    items.push_back("OUT QUINT");
    items.push_back("IN OUT QUINT");
    items.push_back("IN CIRC");
    items.push_back("OUT CIRC");
    items.push_back("IN OUT CIRC");
    items.push_back("IN BACK");
    items.push_back("OUT BACK");
    items.push_back("IN OUT BACK");
    items.push_back("IN QUAD");
    items.push_back("OUT QUAD");
    items.push_back("IN OUT QUAD");
    items.push_back("IN QUART");
    items.push_back("OUT QUART");
    items.push_back("IN OUT QUART");
    items.push_back("IN BOUNCE");
    items.push_back("OUT BOUNCE");
    items.push_back("IN OUT BOUNCE");
    ddl = gui->addDropDownList("Choose the easing functions", items);
    ddl->setAllowMultiple(false);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
    gui->loadSettings("guiSettings.xml");
    
    // Set circles and colors
    palette.push_back(ofColor(143,45,86));
    palette.push_back(ofColor(122,193,179));
    palette.push_back(ofColor(255,188,66));
    palette.push_back(ofColor(243,255,189));
    palette.push_back(ofColor(255,22,84));
    
    int selected_color = 0;
    for (int i = 1; i < n_circles; i++) {
        if(n_circles % palette.size() == 0){
            ofRandomize(palette);
            selected_color = 0;
        }else{
            selected_color = i;
        }
        
        Circle tempCircle;
        tempCircle.setup(
                         ofVec2f(ofRandom(i*10,500), ofRandom(i*10,500)),
                         ofVec2f(ofRandom(i*10,500), ofRandom(i*10,500)),
                         palette[selected_color]
        );
        circles.push_back(tempCircle);
    }
    pct = 0.0;
    currIter = 0.0;
    totalIter = 100.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (currIter < totalIter) {
        currIter++;
    }
    
    if ( easyngFunction == "IN OUT ELASTIC") {
        pct = Penner::easeInOutElastic(currIter, 0.0, 1.0, totalIter);
    }else if ( easyngFunction == "OUT ELASTIC") {
        pct = Penner::easeOutElastic(currIter, 0.0, 1.0, totalIter);
    }else if ( easyngFunction == "IN ELASTIC") {
        pct = Penner::easeInElastic(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN OUT SINE"){
        pct = Penner::easeInSine(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "OUT SINE"){
        pct = Penner::easeOutSine(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN SINE"){
        pct = Penner::easeInOutSine(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN OUT CUBIC"){
        pct = Penner::easeInCubic(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "OUT CUBIC"){
        pct = Penner::easeOutCubic(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN CUBIC"){
        pct = Penner::easeInOutCubic(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN OUT QUINT"){
        pct = Penner::easeInQuint(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "OUT QUINT"){
        pct = Penner::easeOutQuint(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN QUINT"){
        pct = Penner::easeInOutQuint(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN OUT CIRC"){
        pct = Penner::easeInCirc(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "OUT CIRC"){
        pct = Penner::easeOutCirc(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN CIRC"){
        pct = Penner::easeInOutCirc(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN OUT BACK"){
        pct = Penner::easeInBack(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "OUT BACK"){
        pct = Penner::easeOutBack(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN BACK"){
        pct = Penner::easeInOutBack(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN OUT QUAD"){
        pct = Penner::easeInQuad(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "OUT QUAD"){
        pct = Penner::easeOutQuad(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN QUAD"){
        pct = Penner::easeInOutQuad(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN OUT QUART"){
        pct = Penner::easeInQuart(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "OUT QUART"){
        pct = Penner::easeOutQuart(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN QUART"){
        pct = Penner::easeInOutQuart(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN OUT EXPO"){
        pct = Penner::easeInExpo(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "OUT EXPO"){
        pct = Penner::easeOutExpo(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN EXPO"){
        pct = Penner::easeInOutExpo(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN OUT BOUNCE"){
        pct = Penner::easeInBounce(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "OUT BOUNCE"){
        pct = Penner::easeOutBounce(currIter, 0.0, 1.0, totalIter);
    }else if(easyngFunction == "IN BOUNCE"){
        pct = Penner::easeInOutBounce(currIter, 0.0, 1.0, totalIter);
    }else{
        pct = Penner::linear(currIter, 0.0, 1.0, totalIter);
    }
    for (int i = 0; i<circles.size(); i++) {
      circles[i].update(pct);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color1, color2;
    color1.set(100, 0, 255);
    color2.set(0, 0, 100);
    ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
    
    for (int i = 0; i<circles.size(); i++) {
        circles[i].draw();
    }
}
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName(); 
	int kind = e.widget->getKind(); 
	
    if(name == "proximity"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		proximity = slider->getScaledValue(); 		
	}

    if(ddl != NULL){
        vector<string> names = ddl->getSelectedNames();
        for(vector<string>::iterator it = names.begin(); it != names.end(); ++it){
            easyngFunction = *it;
        }
    }
}

//--------------------------------------------------------------
void ofApp::exit(){
    delete gui;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) 
    {            
        case 'g':
        {
            gui->toggleVisible(); 
        }
            break; 
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //do not move the circles when selecting from the menu
    if ((gui->isEnabled()&& x > 220) || gui->isEnabled() == false){
        for (int i = 0; i<circles.size(); i++) {
            circles[i].setNewPosition(
                ofVec2f(
                      ofRandom(x - proximity, x + proximity),
                      ofRandom(y - proximity, y + proximity)
                )
            );
        }
        currIter = 0.0;
    }
    
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
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
}

