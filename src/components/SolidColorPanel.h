//
//  SolidColorPanel.h
//  ofxInterface
//
//  Created by Gal Sasson on 8/13/14.
//
//

#ifndef __ofxInterface__SolidColorPanel__
#define __ofxInterface__SolidColorPanel__

#include <iostream>
#include "ofMain.h"

#include "ofxInterface.h"

namespace ofxInterface {


class SolidColorPanel : public ofxInterface::Node
{
public:
	SolidColorPanel() : lineWidth(2.0f){}
	void setup(float w, float h);

    void setBGColor(const ofColor& c) { bgColor = c; }
    void setStrokeColor(const ofColor& c) { strokeColor = c; }
	void setBackground(bool set) { bDrawBackground = set; }
	void setBorder(bool set) { bDrawBorder = set; }
	void setRounded(bool set) { bRounded = set; }
	void setRoundAngle(float ang) { roundAngle = ang; }

	float getLineWidth() const { return lineWidth; }
	void setLineWidth(float w){ lineWidth = w; }

	void draw();

private:
	bool bDrawBorder;
	bool bDrawBackground;
	bool bRounded;
	float roundAngle;

	ofColor bgColor;
	ofColor strokeColor;
	float lineWidth;
};

}   // namespace

#endif /* defined(__ofxInterface__SolidColorPanel__) */
