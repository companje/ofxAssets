/*
 *  ofxImageAssets.cpp
 *  openFrameworks
 *
 *  Created by Rick Companje on 12 dec '11. Temporary solution until ofxAssets is fully templatable
 *
 */

#include "ofxImageAssets.h"

void ofxImageAssets::add(string filename, bool preload) {
	ofImage *asset = new ofImage();
	
	ofLog(OF_LOG_VERBOSE, "ofxImageAssets::add(\"" + filename + "\", preload=" + (preload ? "true" : "false") + ")");
    
    // in case of BAD_ACCESS error see http://forum.openframeworks.cc/index.php/topic,7910.0.html
    
    if (!asset->loadImage(filename)) {
		ofLog(OF_LOG_ERROR, "Image not found: " + filename);
		std::exit(1);
	};
    	
	assets[filename] = asset;
}

ofImage& ofxImageAssets::operator[](const string& filename) {
	if (!assets[filename]) add(filename);
	return *assets[filename];
}