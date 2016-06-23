#pragma once

// interface class
class Scene {
public:
    Scene(){};
    virtual ~Scene(){};
    virtual void update(){};
    virtual void draw(){};
};
