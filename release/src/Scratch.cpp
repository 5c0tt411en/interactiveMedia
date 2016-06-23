#include "Scratch.hpp"

ScratchScene::ScratchScene(){
    myImage1.loadImage("./Scratch/sky.jpg");
    myImage2.loadImage("./Scratch/halloween.jpg");
    myImage2.rotate90(3);

    if (ofRandom(1)<0.5){
        myImage1.draw(0,0);
    } else {
        myImage2.draw(0,0);
    }
    
    
    setup();
}
ScratchScene::~ScratchScene(){
}

void ScratchScene::setup(){
    for (int i =0; i<75; i++){
        for (int j =0; j<30; j++){
            part[i][j].x = (float)0.04*i;
            part[i][j].y = (float)0.04*j +0.02;
        }
    }
}

void ScratchScene::update(){
    counter++;
    poss = osc::getpos(config::USE_DUMMY_DATA);
}

void ScratchScene::draw(){
    ofPushStyle();
        myImage2.draw(0, 0, 0.7, 1 );
    
    ofSetColor(0,0,0,150);
    for (int i =0; i<75; i++){
        for (int j =0; j<30; j++){
            ofCircle(part[i][j].x,part[i][j].y,0.04);
        }
    }
    ofSetColor(255,255,255);
    for(auto it = poss.begin(); it != poss.end(); it++){
        ofCircle(*it, 0.02);
        for (int i =0; i<75; i++){
            for (int j =0; j<30; j++){
                if(part[i][j].x-0.03 < it->x && it->x < part[i][j].x+0.03){
                    if(part[i][j].y-0.03 < it->y && it->y < part[i][j].y+0.03){
                        part[i][j].x = 0;
                        part[i][j].y = 0;
                    }
                }
            }
        }
    }
    
    if (counter%400 == 0){
        for (int i =0; i<75; i++){
            for (int j =0; j<30; j++){
                for (int i =0; i<75; i++){
                    for (int j =0; j<30; j++){
                        part[i][j].x = (float)0.04*i;
                        part[i][j].y = (float)0.04*j;
                    }
                }
            }
        }
    }
    ofPopStyle();
}
