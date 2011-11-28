/*
 *  ofxAssets.h
 *  openFrameworks
 *
 *  Created by Rick Companje on 2/25/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef OFX_ASSETS
#define OFX_ASSETS

#include "ofMain.h"

class ofxAssets {
public:
	
	void add(string filename, bool preload=true);
	
    ofVideoPlayer &operator[](const string& filename);

	map<string, ofVideoPlayer*> assets;
};

#endif