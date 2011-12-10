/*
 *  ofxAssets.h
 *  openFrameworks
 *
 *  Created by Rick Companje on 12 dec '11. Temporary solution until ofxAssets is fully templatable
 *
 */

#pragma once

#include "ofMain.h"

class ofxImageAssets {
public:
	
	void add(string filename, bool preload=true);
	
    ofImage &operator[](const string& filename);

	map<string, ofImage*> assets;
};
