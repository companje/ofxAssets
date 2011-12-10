/*
 *  ofxVideoAssets.cpp
 *  openFrameworks
 *
 *  Created by Rick Companje on 2/25/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxVideoAssets.h"

void ofxVideoAssets::add(string filename, bool preload) {
	ofVideoPlayer *mov = new ofVideoPlayer();
	
	ofLog(OF_LOG_VERBOSE, "ofxAssets::add(\"" + filename + "\", preload=" + (preload ? "true" : "false") + ")");
	
	if (!mov->loadMovie(filename)) {
		ofLog(OF_LOG_ERROR, "Movie not found: " + filename);
		std::exit(1);
	};
	
	assets[filename] = mov;
}

ofVideoPlayer& ofxVideoAssets::operator[](const string& filename) {
	if (!assets[filename]) add(filename);
	return *assets[filename];
}